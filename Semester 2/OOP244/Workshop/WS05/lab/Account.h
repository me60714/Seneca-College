///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.23            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(int newAccountNum);
      Account& operator=(Account& acc);
      Account& operator+=(double money);
      Account& operator-=(double money);
      Account& operator<<(Account& acc);
      Account& operator>>(Account& acc);
   };
   double operator+(const Account& acc1, const Account& acc2);
   double& operator+=(double& sum, const Account& acc);
   
   
}
#endif // SDDS_ACCOUNT_H_