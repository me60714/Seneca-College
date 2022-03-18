// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 13.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
    SpellChecker::SpellChecker() {}

    SpellChecker::SpellChecker(const char* filename)
    {
        ifstream file(filename);
        if (file)
        {
            for (size_t i = 0; i < SIZE; ++i)
            {
                file >> m_badWords[i];
                file >> m_goodWords[i];
                m_replace[i] = 0;
            }
            file.close();
        }
        else {throw "Bad file name!";}
    }

    void SpellChecker::operator()(string& text)
    {
        size_t found = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            while ((found = text.find(m_badWords[i])) != string::npos)
            {
                text.replace(found, m_badWords[i].length(), m_goodWords[i]);
                m_replace[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(ostream& out) const
    {
        out << "Spellchecker Statistics" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            out.width(15);
            out.setf(ios::right);
            out << m_badWords[i] << ": " << m_replace[i] << " replacements" << endl;
        }
    }
}