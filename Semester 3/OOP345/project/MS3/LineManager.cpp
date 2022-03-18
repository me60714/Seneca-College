// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.12.03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace sdds
{
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
    {
        std::ifstream f(file);
        Utilities u;

        bool more = false;
        size_t pos = 0;
        std::string str;
        std::string item;
        std::string nextItem;
        std::string error = "Error: fail to open the file!";

        if(!f)
        {
            throw error;
        }
        else
        {
            Workstation* curStation{};
            Workstation* nextStation{};
            Workstation* firstStation{};
            while (getline(f, str))
            {
                item = u.extractToken(str, pos, more);
                curStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s){
                    return s->getItemName() == item;
                });

                activeLine.push_back(curStation);

                if (more != false)
                {
                    nextItem = u.extractToken(str, pos, more);
                    nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s){
                         return s->getItemName() == nextItem;
                    });

                    curStation->setNextStation(nextStation);
                }
            }
            
            for_each(stations.begin(), stations.end(), [&](Workstation* s){
                firstStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s){
                    return s->getNextStation() == firstStation;
                });
            });

            m_firstStation = firstStation;
        }
        
        f.close();
        m_cntCustomerOrder = pending.size();
    }
    void LineManager::linkStations()
    {
        Workstation* station = m_firstStation;
        std::vector<Workstation*> reOrdered;
        while (station)
        {
            reOrdered.push_back(station);
            station = station->getNextStation();
        }
        activeLine = reOrdered;
    }
    bool LineManager::run(std::ostream& os)
    {
        static size_t count = 0;
        bool full = false;

        os << "Line Manager Iteration: " << ++count << std::endl;
        if (!pending.empty())
        {
            *activeLine.front() += std::move(pending.front());
            pending.pop_front();
        }
        for (auto &i : activeLine)
            i->fill(os);

        for (auto &i : activeLine)
            i->attemptToMoveOrder();

        if (completed.size() + incomplete.size() == m_cntCustomerOrder)
        {
            full = true;
        };

        return full;
    }
    void LineManager::display(std::ostream& os) const
    {
        for (auto &i : activeLine)
        {
            i->display(os);
        };
    }
}