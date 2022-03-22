-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Nov.10.2021
-- Purpose: Lab 6 DBS311 NEE
-- ***********************

SET SERVEROUTPUT ON

-- Question 1 –-
-- Write a store procedure that gets an integer number n and calculates and displays its factorial.

-- Q1 Solution –-

CREATE OR REPLACE PROCEDURE factorial(n INTEGER) AS
val INTEGER := 1;
BEGIN
    FOR i IN REVERSE 1..n LOOP
        val := val * i;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(n || '!= ' || val);
END;
/
BEGIN
   factorial(2);
   factorial(3);
END;
/
-- Question 2 –-
-- The company wants to calculate the employees’ annual salary:
-- The first year of employment, the amount of salary is the base salary which is $10,000.
-- Every year after that, the salary increases by 5%.
-- Write a stored procedure named calculate_salary which gets an employee ID and for that
-- employee calculates the salary based on the number of years the employee has been working
-- in the company. (Use a loop construct to calculate the salary).
-- The procedure calculates and prints the salary.

-- Q2 Solution –-

CREATE OR REPLACE PROCEDURE calculate_salary(employeeId IN NUMBER) AS
    new_salary NUMBER :=10000;
    years NUMBER :=0;
    firstname VARCHAR2(255);
    lastname VARCHAR2(255);        
    
BEGIN 
  SELECT first_name, last_name, TRUNC((months_between(CURRENT_DATE ,TO_DATE(hire_date)))/12)
        INTO firstname, lastname, years
        FROM employees 
        WHERE employee_id = employeeId;        
  FOR i IN 1..years LOOP  
        new_salary := new_salary * 1.05;
      END LOOP; 
      
      DBMS_OUTPUT.PUT_LINE ('First Name: ' || firstname);
      DBMS_OUTPUT.PUT_LINE ('Last Name: ' || lastname);
      DBMS_OUTPUT.PUT_LINE ('Salary: $' ||to_char(new_salary, '99,999'));
  
    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('ERROR: Wrong employee ID.');
END calculate_salary;
/
BEGIN
    calculate_salary(107);
END;
/

-- Question 3 –-
-- Write a stored procedure named warehouses_report to print the warehouse ID,
-- warehouse name, and the city where the warehouse is located in the following
-- format for all warehouses:
-- Warehouse ID:
-- Warehouse name:
-- City:
-- State:
-- If the value of state does not exist (null), display “no state”.
-- The value of warehouse ID ranges from 1 to 9.
-- You can use a loop to find and display the information of each warehouse
-- inside the loop. (Use a loop construct to answer this question. Do not use cursors.)

-- Q3 Solution –-

CREATE OR REPLACE PROCEDURE warehouses_report AS
    warehouseid INTEGER;
    warehousename varchar2(255);
    city varchar2(255); 
    state varchar2(255);
    i INTEGER;
    
BEGIN
    FOR i IN 1..9 LOOP
    SELECT w.warehouse_id, w.warehouse_name, l.city, COALESCE(l.state,'no state')
        INTO warehouseid, warehousename, city, state
        FROM warehouses w
        LEFT JOIN locations l
            ON w.location_id = l.location_id
        WHERE warehouse_id = i;
        DBMS_OUTPUT.PUT_LINE ('Warehouse ID: ' || warehouseid);
        DBMS_OUTPUT.PUT_LINE ('Warehouse name: ' || warehousename);
        DBMS_OUTPUT.PUT_LINE ('City: ' || city);
        DBMS_OUTPUT.PUT_LINE ('State: ' || state);
        DBMS_OUTPUT.PUT_LINE (' ');
    END LOOP;
END warehouses_report;
/
BEGIN
    warehouses_report();
END;
/