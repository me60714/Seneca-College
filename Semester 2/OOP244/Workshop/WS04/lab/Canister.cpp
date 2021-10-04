///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.16            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"
using namespace std;
namespace sdds
{
    const double PI = 3.14159265;

    void Canister::setToDefault()
    {
        this->m_contentName = nullptr;
        this->m_height = 13.0;
        this->m_diameter = 10.0;
        this->m_contentVolume = 0.0;
        this->m_usable = true;
    }

    bool Canister::isEmpty() const
    {
        return (m_contentVolume < 0.00001);
    }

    bool Canister::hasSameContent(const Canister &C) const
    {
        bool b;

        if (m_contentName != nullptr && C.m_contentName != nullptr && strCmp(m_contentName, C.m_contentName) == 0)
            b = true;
        else
            b = false;

        return b;
    }

    void Canister::setName(const char *Cstr)
    {
        if (Cstr != nullptr && this->m_usable == true)
        {
            this->m_contentName = nullptr;
            this->m_contentName = new char[strLen(Cstr) + 1];
            strCpy(this->m_contentName, Cstr);
        }
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char *contentName)
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char *contentName)
    {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
        {
            this->m_height = height;
            this->m_diameter = diameter;
            this->m_contentVolume = 0;
            setName(contentName);
        }
        else
            this->m_usable = false;
    }

    void Canister::clear()
    {
        delete this->m_contentName;
        this->m_contentName = nullptr;
        this->m_contentVolume = 0;
        this->m_usable = true;
    }

    Canister::~Canister()
    {
        clear();
    }

    double Canister::capacity() const
    {
        return PI * (this->m_height - 0.267) * (this->m_diameter / 2) * (this->m_diameter / 2);
    }

    double Canister::volume() const
    {
        return this->m_contentVolume;
    }

    Canister &Canister::setContent(const char *contentName)
    {
        if (contentName == nullptr)
            this->m_usable = false;
        else if (this->isEmpty())
            this->setName(contentName);
        else if (strCmp(this->m_contentName, contentName) != 0)
            this->m_usable = false;

        return *this;
    }

    Canister &Canister::pour(double quantity)
    {
        if (this->m_usable == true && quantity > 0 && (quantity + this->volume()) <= this->capacity())
            this->m_contentVolume += quantity;
        else
            this->m_usable = false;

        return *this;
    }

    Canister &Canister::pour(Canister &C)
    {
        setContent(C.m_contentName);

        if (C.volume() > (this->capacity() - this->volume()))
        {
            C.m_contentVolume = C.volume() - (this->capacity() - this->volume());
            this->m_contentVolume = this->capacity();
        }
        else
        {
            pour(C.volume());
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    std::ostream &Canister::display() const
    {
        cout.width(7);
        cout.setf(ios::right);
        cout.precision(1);
        cout << fixed;
        cout << this->capacity() << "cc (" << this->m_height << "x" << this->m_diameter << ") Canister";

        if (this->m_usable == false)
            cout << " of Unusable content, discard!";
        else if (this->m_contentName != nullptr)
        {
            cout << " of ";
            cout.width(7);
            cout.setf(ios::right);
            cout.precision(1);
            cout << fixed;
            cout << this->volume() << "cc   " << m_contentName;
        }
        return cout;
    }
}