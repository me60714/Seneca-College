///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.08            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const
   {
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineValue)
   {
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   Line::Line()
   {
      m_value = nullptr;
   }

   Line::~Line()
   {
      delete[] m_value;
      m_value = nullptr;
   }

   void TextFile::setEmpty()
   {
      m_filename = nullptr;
      m_textLines = nullptr;
      m_noOfLines = 0;
   }

   void TextFile::setFilename(const char *fname, bool isCopy)
   {
      if (!isCopy)
      {
         delete[] m_filename;
         m_filename = new char[strLen(fname)+1];
         strCpy(m_filename, fname);
      }
      else if (isCopy)
      {
         delete[] m_filename;
         char copy[20] = "C_";
         m_filename = new char[strLen(fname)+3];
         strCat(copy, fname);
         strCpy(m_filename, copy);
      }
   }

   void TextFile::setNoOfLines()
   {
      ifstream fobj(m_filename);
      if (!fobj.is_open())
      {
         ;
      }
      else
      {
         char ch;
         while (fobj.get(ch))
         {
            if (ch == '\n')
               m_noOfLines++;
         }

         if (m_noOfLines == 0)
         {
            delete[] m_filename;
            m_filename = nullptr;
         }
         m_noOfLines += 1;
      }
      fobj.close();
   }

   void TextFile::loadText()
   {
      if (m_filename == nullptr)
         ;
      else
      {
         delete [] m_textLines;
         m_textLines = nullptr;
         m_textLines = new Line[m_noOfLines];

         ifstream fobj(m_filename);
         if (fobj.is_open())
         {
            int i = 0;
            while (!fobj.eof())
            {
               string line;
               getline(fobj, line);
               this->m_textLines[i] = line.c_str();
               i++;
            }
            fobj.close();
            m_noOfLines = i;
         }
      }
   }

   void TextFile::saveAs(const char *fileName) const
   {
      ofstream fobj;
      fobj.open(fileName);
      
      for (int i = 0; i < (int)m_noOfLines; i++)
      {
         fobj << m_textLines[i].m_value << endl;
      }
      fobj.close();
   }

   TextFile::TextFile(unsigned pageSize)
   {
      setEmpty();
      m_pageSize = pageSize;
      if (m_filename)
      {
         setFilename(m_filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile::TextFile(const char *filename, unsigned pageSize)
   {
      m_pageSize = pageSize;
      setEmpty();
      if (filename)
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile::TextFile(const TextFile& src)
   {
      m_pageSize = src.m_pageSize;
      setEmpty();
      if (src)
      {
         setFilename(src.m_filename, true);
         src.saveAs(m_filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile& TextFile::operator=(const TextFile& src)
   {
      if (m_filename != nullptr && src.m_filename != nullptr && this != &src)
      {
         delete[] m_textLines;
         m_textLines = nullptr;
         src.saveAs(m_filename);
         setNoOfLines();
         loadText();
         m_noOfLines -= 1;
      }
      return *this;
   }

   TextFile::~TextFile()
   {
      delete[] m_filename;
      m_filename = nullptr;
      delete[] m_textLines;
      m_textLines = nullptr;
   }

   unsigned TextFile::lines() const
   {
      return m_noOfLines;
   }

   std::ostream& TextFile::view(std::ostream &ostr) const
   {
      if (m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0)
      {
         int page = 1;
         ostr << m_filename << endl;
         ostr << "==========" << endl;
         
         for (int i = 0; i < (int)this->lines(); i++)
         {
            while (i < (int)m_noOfLines)
            {
               ostr << this->m_textLines[i].m_value << endl;

               if ((i + 1) % m_pageSize == 0)
               {
                  ostr << "Hit ENTER to continue...";
                  cin.ignore(100, '\n');
                  page++;
               }
               i++;
            }
         }
      }
      return ostr;
   }

   std::istream& TextFile::getFile(std::istream &istr)
   {
      char temp[20];
      istr >> temp;
      istr.ignore(100, '\n');
      setFilename(temp);
      setNoOfLines();
      loadText();
      return istr;
   }

   TextFile::operator bool() const
   {
      bool Empty = (m_filename == nullptr && m_noOfLines == 0 && m_textLines == nullptr);

      return (!Empty)? true : false;
   }

   const char* TextFile::name() const
   {
      return m_filename;
   }

   const char* TextFile::operator[](unsigned index) const
   {     
      if (index >= (m_noOfLines-1))
      {
         index -= (m_noOfLines-1);
      }
      index = index % (m_noOfLines-1);

      return (this->m_filename == nullptr) ? NULL : this->m_textLines[index].m_value;
   }
   std::ostream &operator<<(std::ostream &ostr, const TextFile& text) { return text.view(ostr);}
   std::istream &operator>>(std::istream &istr, TextFile& text) { return text.getFile(istr); }
}