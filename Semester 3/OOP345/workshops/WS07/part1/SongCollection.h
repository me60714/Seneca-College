// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 10.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <vector>

namespace sdds
{
    struct Song
    {
        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price;
        size_t m_year;
        size_t m_length;
    };

    class SongCollection
    {
        std::vector<Song> m_songcollection;
    public:
        SongCollection(std::string name);
        void display(std::ostream& out) const;
    };

    std::ostream &operator<<(std::ostream& out, const Song& theSong);
}