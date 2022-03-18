// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.12.03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds
{
    //three double-ended queues
    //Each queue is accessible outside this module's translation unit.
    extern std::deque<CustomerOrder> pending;
    extern std::deque<CustomerOrder> completed;
    extern std::deque<CustomerOrder> incomplete;

    //workstation class
    class Workstation : public Station
    {
        //double ended queue
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation{nullptr};
    
    public:
        Workstation(const std::string& str);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);

        //cannot be copied or moved
        Workstation(const Workstation&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(Workstation&&) = delete;
    };
}