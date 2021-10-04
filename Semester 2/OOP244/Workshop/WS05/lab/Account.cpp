///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.23            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const { return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0)? true:false; }
   
   Account::operator int() const { return m_number; }

   Account::operator double() const { return m_balance; }
   
   bool Account::operator ~() const { return (m_number == 0)? true:false; }
   
   Account& Account::operator=(int newAccountNum)
   {
      if (m_number <= 0)
         (newAccountNum >= 10000 && newAccountNum <= 99999)? m_number = newAccountNum:m_number = -1;

      return *this;
   }
   Account& Account::operator=(Account& acc)
   {
      if (m_number == 0 && bool(acc))
      {
         m_number = int(acc);
         m_balance = double(acc);
         acc.m_number = 0;
         acc.m_balance = 0;
      }

      return *this;
   }
   Account& Account::operator+=(double money)
   {
      if (!bool(this) || money < 0)
      {
      }
      else
         m_balance += money;

      return *this;
   }
   Account& Account::operator-=(double money)
   {
      if (!bool(this) || money < 0 || m_balance - money < 0)
      {
      }
      else
         m_balance -= money;

      return *this;
   }
   Account& Account::operator<<(Account& acc)
   {
      if (m_number != int(acc) && bool(acc) && bool(this))
      {
         m_balance += acc;
         acc.m_balance = 0;
      }

      return *this;
   }
   Account& Account::operator>>(Account& acc)
   {
      if (m_number != int(acc) && bool(acc) && bool(this))
      {
         acc += m_balance;
         m_balance = 0;
      }
      return *this;
   }
   double operator+(const Account& acc1, const Account& acc2)
   {
      double sum = 0.0;
      if(bool(acc1) && bool(acc2))
      {
         sum = double(acc1) + double(acc2);
      }
      return sum;
   }
   double& operator+=(double& sum, const Account& acc)
   {
      if (bool(acc))
      {
         sum += double(acc);
      }

      return sum;
   }
}