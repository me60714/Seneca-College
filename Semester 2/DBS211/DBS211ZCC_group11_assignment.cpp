///////////////////////////////////////
//              GROUP 11             //
// --------------------------------- //
//    Name   : Kabbo Samin Yasar     //
//    Email  : ksyasar@myseneca.ca   //
//    ID     : 142591205             //
// --------------------------------- //
//    Name   : Sarthak Gulati        //
//    Email  : sgulati12@myseneca.ca //
//    ID     : 164730194             //
// --------------------------------- //
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
///////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <occi.h>
#include <cstring>

using oracle::occi::Connection;
using oracle::occi::Environment;

using namespace oracle::occi;
using namespace std;

struct Employee
{
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char extension[10];
	char email[100];
	char officecode[10];
	int reportsTo;
	char jobTitle[50];
};

int menu(void);


//1. Find Employee
int findEmployee(Connection *conn, int employeeNumber, struct Employee *emp);
void displayEmployee(Connection *conn, struct Employee emp);

//2. Employees Report
void displayAllEmployees(Connection *conn);

//3. Add Employee
void insertEmployee(Connection *conn, struct Employee emp);
void getEmployee(struct Employee *emp);

//4. update employee
void updateEmployee(Connection *conn, int employeeNumber);

//5. delete employee
void deleteEmployee(Connection *conn, int employeeNumber);

int main()
{

	// OCCI VARIABLES
	Environment *env = nullptr;
	Connection *conn = nullptr;

	// USER VARIABLES
	string str;
	string user = "dbs211_212zc10"; // provided username
	string pass = "27073282";		// provided password
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	int menuSelection;
	int selectedNumber;
	Employee e;

	try // try segement for connecting the database and running the query
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, srv);

		//the loop of menu
		do
		{
			menuSelection = menu();

			switch (menuSelection)
			{
			case 0:
				cout << "Goodbye\n";
				break;
			case 1:
				cout << "Enter Employee Number: ";
				cin >> selectedNumber;
				if (findEmployee(conn, selectedNumber, &e))
				{
					displayEmployee(conn, e);
				}
				else
				{
					cout << "Employee " << selectedNumber << " does not exist." << endl;
				}
				break;
			case 2:
				displayAllEmployees(conn);
				break;
			case 3:
				getEmployee(&e);
				insertEmployee(conn, e);
				break;
			case 4:
				cout << "Enter Employee Number: ";
				cin >> selectedNumber;
				updateEmployee(conn, selectedNumber);
				break;
			case 5:
				cout << "Enter Employee Number: ";
				cin >> selectedNumber;
				deleteEmployee(conn, selectedNumber);
				break;
			default:
				cout << "Invalid selection. Try again.\n";
				break;
			}

		} while (menuSelection != 0);

		env->terminateConnection(conn);			//terminates connection with oracle
		Environment::terminateEnvironment(env); //cleans up memory
	}
	catch (SQLException &sqlExcp)
	{
		std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	} // error check if something goes wrong with the appropiate error code

	return 0;
}

int menu(void)
{
	int choice;
	
	// display the menu
	cout << "\n********************* HR Menu *********************\n";
	cout << "1) Find Employee\n";
	cout << "2) Employees Report\n";
	cout << "3) Add Employee\n";
	cout << "4) Update Employee\n";
	cout << "5) Remove Employee\n";
	cout << "0) Exit";
	cout << "\nEnter an option (0-5): ";

	cin >> choice;

	return choice;
}

//1. Find Employee
int findEmployee(Connection *conn, int employeeNumber, struct Employee *emp)
{
	int finded = 0;

	Statement *stmt = conn->createStatement("SELECT * FROM employees WHERE employeenumber = :1");
	stmt->setInt(1, employeeNumber);
	ResultSet *rs = stmt->executeQuery();

	// if find the employee
	if (rs->next())
	{
		// copy the employee data to the Employee structure
		emp->employeeNumber = rs->getInt(1);
		string str = rs->getString(2);
		strcpy(emp->lastName, str.c_str());
		string str1 = rs->getString(3);
		strcpy(emp->firstName, str1.c_str());
		string str2 = rs->getString(4);
		strcpy(emp->extension, str2.c_str());
		string str3 = rs->getString(5);
		strcpy(emp->email, str3.c_str());
		string str4 = rs->getString(6);
		strcpy(emp->officecode, str4.c_str());
		emp->reportsTo = rs->getInt(7);
		string str5 = rs->getString(8);
		strcpy(emp->jobTitle, str5.c_str());
		
		// set the return data to 1, means find the employee
		finded = 1;
	}

	return finded;
}

void displayEmployee(Connection *conn, struct Employee emp)
{
	//search the employee number
	Statement *stmt = conn->createStatement("SELECT * FROM employees WHERE employeenumber = :1");
	stmt->setInt(1, emp.employeeNumber);
	ResultSet *rs = stmt->executeQuery();

	//print the employee data
	cout << "--------------Employee Information--------------" << endl;
	cout << "Employee Number : " << emp.employeeNumber << endl;
	cout << "Last Name : " << emp.lastName << endl;
	cout << "First Name : " << emp.firstName << endl;
	cout << "Extension :" << emp.extension << endl;
	cout << "Email :" << emp.email << endl;
	cout << "Office Code :" << emp.officecode << endl;
	cout << "Manager ID: " << emp.reportsTo << endl;
	cout << "Job Title :" << emp.jobTitle << endl;
}

//2. Employees Report
void displayAllEmployees(Connection *conn)
{
	std::cout << "" << endl;

	Statement *stmt1 = conn->createStatement();
	ResultSet *rs1 = stmt1->executeQuery("SELECT e1.employeenumber, e1.firstname||' '||e1.lastname, e1.email, e2.phone, e1.extension, e2.firstname ||' '||e2.lastname FROM employees e1 LEFT JOIN (SELECT  employeenumber, firstname, lastname, email, phone, extension, reportsto FROM employees LEFT OUTER JOIN offices USING(officecode)) e2 ON e2.employeenumber = e1.employeenumber order by e1.employeenumber"); // this is the sql statement that we usually run in oracle

	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
	std::cout << "ID"
			  << "\t\t"
			  << "Employee Name"
			  << "\t\t"
			  << "Email"
			  << "\t\t\t\t\t"
			  << "Phone"
			  << "\t\t\t"
			  << "Extension"
			  << "\t"
			  << "Manager Name" << endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

	//simple print statements, that arranges and prints the table format

	while (rs1->next())
	{
		int empID = rs1->getInt(1);
		string Name = rs1->getString(2);
		string email = rs1->getString(3);
		string phone = rs1->getString(4);
		string ext = rs1->getString(5);
		string NameMangr = rs1->getString(6);
		std::cout << empID << "\t\t" << Name << "\t\t" << email << "\t\t" << phone << "\t\t" << ext << "\t\t" << NameMangr << endl;
	} // loop statement that prints the data
}

void getEmployee(struct Employee *emp)
{
	// input the employee data
	cout << endl << "-------------- New Employee Information -------------" << endl;
	cout << "Employee Number: ";
	cin >> emp->employeeNumber;
	cout << "Last Name: ";
	cin >> emp->lastName;
	cout << "First Name: ";
	cin >> emp->firstName;
	cout << "Extension: ";
	cin >> emp->extension;
	cout << "Email: ";
	cin >> emp->email;
	cout << "Office Code: 1\n";
	strcpy(emp->officecode, "1");
	cout << "Manager ID: 1002\n";
	emp->reportsTo = 1002;
	cout << "Job Title: ";
	cin >> emp->jobTitle;
}

//3. Add Employee
void insertEmployee(Connection *conn, struct Employee emp)
{
	//first find the employee exist or not
	if (findEmployee(conn, emp.employeeNumber, &emp) == 0)
	{
		// if the employee number does not exist, then add this number and its other data.
		Statement *stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO employees VALUES(:1,:2,:3,:4,:5,:6,:7,:8) ");
		stmt->setInt(1, emp.employeeNumber);
		stmt->setString(2, emp.lastName);
		stmt->setString(3, emp.firstName);
		stmt->setString(4, emp.extension);
		stmt->setString(5, emp.email);
		stmt->setString(6, emp.officecode);
		stmt->setInt(7, 1002);
		stmt->setString(8, emp.jobTitle);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);

		cout << "The new employee is added successfully. " << endl;
	}
	else
	{
		// if the employee exist, print the proper output.
		cout << "\nAn employee with the same employee number exists. \n";
	}
}

//4. Update Employee
void updateEmployee(Connection *conn, int employeeNumber)
{
	struct Employee empp;
	char duplicate[10];
	
	//first find if the employee exist or not
	if (findEmployee(conn, employeeNumber, &empp) != 1)
	{
		// if not, print the proper output.	
		cout << "The employee with ID " << employeeNumber << " does not exist." << endl;
	}
	else if (findEmployee(conn, employeeNumber, &empp) == 1)
	{
		//if the employee exist, print his/her name
		cout << "Last Name: " << empp.lastName << endl;
		cout << "First Name: " << empp.firstName << endl
			 << "Extension: ";
		cin >> duplicate;

		//update the employee's extension
		Statement *stmt = conn->createStatement();
		stmt->setSQL("UPDATE employees SET extension= :1 WHERE employeenumber= :2");
		stmt->setString(1, duplicate);
		stmt->setInt(2, employeeNumber);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		cout << "The employee's extension is updated successfully.\n";
	}
}

//5. delete employee
void deleteEmployee(Connection *conn, int employeeNumber)
{
	struct Employee empp;

	// first find if the employee exist or not
	if (findEmployee(conn, employeeNumber, &empp) != 1)
	{
		//if not, print the proper output.
		cout << "The employee with ID " << employeeNumber << " does not exist." << endl;
	}
	else if (findEmployee(conn, employeeNumber, &empp) == 1)
	{
		//if the employee exist, delete its data
		Statement *stmt = conn->createStatement();
		stmt->setSQL("DELETE FROM employees WHERE employeenumber=: 1");
		stmt->setInt(1, employeeNumber);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		cout << "The employee with ID " << employeeNumber << " is deleted successfully." << endl;
	}
}