// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 10.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "SongCollection.h"

namespace sdds
{
    SongCollection::SongCollection(std::string name)
    {
        std::ifstream file(name);
        if (!file){throw "ERROR: CANNOT OPEN THE FILE!\n";}
        else
        {
            std::string str, title, artist, album, year, length, price;
            Song song;
            while(file)
            {
                std::getline(file, str, '\n');
                if (!str.empty())
                {
                    //title
                    title = str.substr(0, 25);
                    title.erase(0, title.find_first_not_of(' '));
                    title.erase(title.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    song.m_title = title;

                    //artist
                    artist = str.substr(0, 25);
                    artist.erase(0, artist.find_first_not_of(' '));
                    artist.erase(artist.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    song.m_artist = artist;

                    //album
                    album = str.substr(0, 25);
                    album.erase(0, album.find_first_not_of(' '));
                    album.erase(album.find_last_not_of(' ') + 1);
                    str.erase(0, 25);
                    song.m_album = album;

                    //year
                    year = str.substr(0, 5);
                    year.erase(0, year.find_first_not_of(' '));
                    year.erase(year.find_last_not_of(' ') + 1);
                    str.erase(0, 5);

                    if(!year.empty()){song.m_year = std::stoi(year);}
                    else{song.m_year = 0;}

                    //length
                    length = str.substr(0, 5);
                    length.erase(0, length.find_first_not_of(' '));
                    length.erase(length.find_last_not_of(' ') + 1);
                    str.erase(0, 5);
                    song.m_length = stoi(length);

                    //price
                    price = str.substr(0, 5);
                    price.erase(0, price.find_first_not_of(' '));
                    price.erase(price.find_last_not_of(' ') + 1);
                    str.erase(0, 5);
                    song.m_price = stod(price);

                    m_songcollection.push_back(song);
                }
            }
            file.close();
        }

    }

    void SongCollection::display(std::ostream& out) const //for_each accumulate
    {
        std::for_each(m_songcollection.begin(), m_songcollection.end(), [&](const Song oneSong){
            out << oneSong << std::endl;
        });

        size_t total = std::accumulate(m_songcollection.begin(), m_songcollection.end(), 0, [](size_t sum, const Song song){
            return sum + song.m_length;
        });

        out << std::setw(89) << std::setfill('-') << '\n'<< std::setfill(' ');
        out << "| " << std::setw(77) << std::right << "Total Listening Time: ";
        out << total / 3600 << ":" << (total % 3600) / 60 << ":";
        out << (total % 3600) % 60 << " |" << std::endl;
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong)
    {
        out << "| " << std::left << std::setw(20) << theSong.m_title
            << " | " << std::left << std::setw(15) << theSong.m_artist
            << " | " << std::left << std::setw(20) << theSong.m_album;
        
        if (theSong.m_year != 0)
        {
            out << " | " << std::right << std::setw(6) << theSong.m_year;
        }
        else
        {
            out << " | " << std::right << std::setw(6) << ' ';
        }

        out << " | " << theSong.m_length / 60 << ":"
            << std::right << std::setw(2) << std::setfill('0')
            << theSong.m_length % 60 << std::setfill(' ');
        
        out << " | " << theSong.m_price << " |";
        
        return out;
    }

    void SongCollection::sort(std::string sortBy) //sort
    {
        if (sortBy == "title")
        {
            std::sort(m_songcollection.begin(), m_songcollection.end(), [](Song s1, Song s2){
                return s1.m_title < s2.m_title;
            });
        }
        else if (sortBy == "album")
        {
            std::sort(m_songcollection.begin(), m_songcollection.end(), [](Song s1, Song s2){
                return s1.m_album < s2.m_album;
            });
        }
        else if (sortBy == "length")
        {
            std::sort(m_songcollection.begin(), m_songcollection.end(), [](Song s1, Song s2){
                return s1.m_length < s2.m_length;
            });
        }
        else{throw "ERROR: INVALID VALUE.\n";}
    }

    void SongCollection::cleanAlbum() //transform
    {
        std::transform(m_songcollection.begin(), m_songcollection.end(), m_songcollection.begin(), [=](Song song){
            if (song.m_album == "[None]")
            {
                song.m_album = "";
            }
            return song;
        });
    }

    bool SongCollection::inCollection(std::string artist) const //any_of
    {
        return std::any_of(m_songcollection.begin(), m_songcollection.end(), [artist](Song song){
            return song.m_artist == artist;
        });
    }

    std::list<Song> SongCollection::getSongsForArtist(std::string artist) const //count_if copy_if
    {
        auto count = std::count_if(m_songcollection.begin(), m_songcollection.end(), [artist](const Song song){
            return artist == song.m_artist;
        });

        std::list<Song> collection(count);
        
        copy_if(m_songcollection.begin(), m_songcollection.end(), collection.begin(), [artist](const Song song){
            return artist == song.m_artist;
        });

        return collection;
    }
}