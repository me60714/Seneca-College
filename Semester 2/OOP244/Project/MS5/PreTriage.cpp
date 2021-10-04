///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.08.03            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;

namespace sdds {
    void PreTriage::reg()
    {
        if (m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
        }
        else
        {
            int selection = -1;
            m_pMenu >> selection;
            if (selection == 1)
            {
                m_lineup[m_lineupSize] = new CovidPatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                cin >> *m_lineup[m_lineupSize];
                cout << endl;
                cout << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
            }
            else if (selection == 2)
            {
                m_lineup[m_lineupSize] = new TriagePatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->fileIO(false);
                cin >> *m_lineup[m_lineupSize];
                cout << endl;
                cout << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl
                     << endl;
                m_lineupSize++;
            }
            else if (selection == 0)
            {
                ;
            }
        }
    }

    void PreTriage::admit()
    {
        int selection = -1;
        int index = -1;

        m_pMenu >> selection;
        if (selection == 1)
        {
            index = indexOfFirstInLine('C');
            if (index != -1)
            {
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[index]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[index];
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
            }
        }
        else if (selection == 2)
        {
            index = indexOfFirstInLine('T');
            if (index != -1)
            {
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[index]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[index];
                cout << "******************************************" << endl
                     << endl;
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
            }
        }
        else if (selection == 0)
        {
            ;
        }
    }

    const Time PreTriage::getWaitTime(const Patient &p) const
    {
        int timeWaiting = 0, count = 0;
        
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == p.type())
                count++;
        }

        if (p.type() == 'T')
        {
            timeWaiting = m_averTriageWait;
            timeWaiting *= count;
        }
        else if (p.type() == 'C')
        {
            timeWaiting = m_averCovidWait;
            timeWaiting *= count;
        }

        return timeWaiting;
    }

    void PreTriage::setAverageWaitTime(const Patient &p)
    {
        int CT = getTime();
        int PTT = p.operator sdds::Time();
        int PTN = p.number();
        int AWT;

        if (p.type() == 'T')
        {
            AWT = m_averTriageWait;
            m_averTriageWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        }
        else if (p.type() == 'C')
        {
            AWT = m_averCovidWait;
            m_averCovidWait = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        }
    }

    void PreTriage::removePatientFromLineup(int index){removeDynamicElement(m_lineup, index, m_lineupSize);}

    int PreTriage::indexOfFirstInLine(char type) const
    {
        int match = -1;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == type)
            {
                match = i;
                break;
            }
        }
        return match;
    }

    void PreTriage::load()
    {
        Patient* P = nullptr;
        string s;
        int lineNum = 0;

        cout << "Loading data..." << endl;
        std::fstream fin(m_dataFilename);
        if (fin.is_open())
        {
            fin >> m_averCovidWait;
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore(1000, '\n');

            for (int i = 0; i < maxNoOfPatients; i++)
            {
                P = nullptr;
                // while (m_lineupSize < maxNoOfPatients && !fin.eof())
                if (!fin.eof())
                {
                    string c;
                    c = 'x';
                    getline(fin, c, ',');
                    if (strCmp(c.c_str(), "C") == 0)
                    {
                        P = new CovidPatient();
                    }
                    else if (strCmp(c.c_str(), "T") == 0)
                    {
                        P = new TriagePatient();
                    }

                    if (P != nullptr && m_lineupSize < maxNoOfPatients)
                    {
                        P->fileIO(true);
                        fin >> *P;
                        P->fileIO(false);
                        m_lineup[i] = P;
                        m_lineupSize++;
                    }
                }
            }

            while (getline(fin, s))
                ++lineNum;
            
            if (lineNum > 0)
            {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            }

            if (m_lineupSize > 0)
            {
                cout << m_lineupSize << " Records imported..." << endl << endl;
            }
            else
            {
                cout << "No data or bad data file!" << endl << endl;
            }
            
            fin.close();
        }
    }

    PreTriage::PreTriage(const char *dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        delete[] m_dataFilename;
        
        m_dataFilename = new char[strLen(dataFilename) + 1];
        strCpy(m_dataFilename, dataFilename);
        
        load();
    }

    PreTriage::~PreTriage()
    {
        std::ofstream f(m_dataFilename);

        if (f.is_open())
        {
            cout << "Saving Average Wait Times," << endl;
            cout << "   COVID Test: " << m_averCovidWait << endl;
            cout << "   Triage: " << m_averTriageWait << endl;
            cout << "Saving m_lineup..." << endl;
            f << m_averCovidWait << "," << m_averTriageWait << endl;
            for (int i = 0; i < m_lineupSize; i++)
            {
                m_lineup[i]->csvWrite(f) << endl;
            }

            for (int i = 0; i < m_lineupSize; i++)
            {
                m_lineup[i]->fileIO(true);
                cout << (i + 1) << "- " << *m_lineup[i] << endl;

                if (m_lineup[i] != nullptr)
                {
                    delete m_lineup[i];
                    m_lineup[i] = nullptr;
                }
            }
            f.close();
        }

        delete [] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }

    void PreTriage::run(void)
    {
        int selection = -1;
        while (selection != 0)
        {
            m_appMenu >> selection;

            if (selection == 1)
                reg();
            else if (selection == 2)
                admit();
        }
    }

}