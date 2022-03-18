// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <sstream>
#include "Utilities.h"
#include "Racecar.h"

using namespace std;
namespace sdds
{
    std::string trim(std::string& str)
    {
        const char* space = " \n\r\v\f\t";
        string temp;
        temp = str.substr(0, str.find(","));
        temp.erase(0, temp.find_first_not_of(space));
        temp.erase(temp.find_last_not_of(space) + 1);
        str.erase(0, str.find(",") + 1);

        return temp;
    }

    Vehicle *createInstance(std::istream &in)
    {
        Vehicle* vehicle{nullptr};
        string temp;
        getline(in, temp, '\n');

        string temp2 = trim(temp);

        stringstream str;
        str << temp;

        if (str && !temp.empty())
        {

            if (temp2[0] == 'c' || temp2[0] == 'C')
            {
                vehicle = new Car(str);
            }
            else if (temp2[0] == 'r' || temp2[0] == 'R')
            {
                vehicle = new Racecar(str);
            }
            else
            {
                if (temp2[0] != 'u' && temp2[0] != 'n' && temp2[0] != 'b')
                {
                    throw "Unrecognized record type: [" + temp2 + "]";
                }
            }
        }
        return vehicle;
    }
}