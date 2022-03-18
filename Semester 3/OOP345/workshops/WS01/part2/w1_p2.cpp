// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14

#include <iostream>
#include <iomanip>
#include <fstream>
#include "event.h"
#include "event.h"

/* input file format: a comma separated set of fields; some fields have a single parameter
T175,SComputer Starting,P,

codes
	T - time (parameter: a number representing the time--measured in seconds--when the following codes apply)
	S - start event (parameter: a string representing the description for the event that starts)
	E - end the event
	P - print to screen
	A - archive
*/

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char *argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	// TODO: print the command line here, in the format
	//   1: first argument
	//   2: second argument
	//   3: third argument
	//   ...
	for (int i = 0; i < argc; i++)
	{
		std::cout << std::setw(3) << i + 1 << ": ";
		std::cout << argv[i] << std::endl;
	}

	std::cout << "--------------------------\n\n";


	// the archive can store maximum 10 events
	sdds::Event archive[10];
	// the index of the next available position in the archive
	size_t idxArchive = 0;

	sdds::Event currentEvent;

	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

	for (auto day = 1; day < argc; ++day)
	{
		// each parameter for an application contains the events from one day
		// process each one
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << argv[day] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}
		char opcode = '\0';
		size_t time = secInDay + 1;
		in >> opcode >> time;

		// starting at midnight, until the end of the day
		for (::g_sysClock = 0u; ::g_sysClock < secInDay; ++::g_sysClock)
		{
			// what should happen this second
			while (time == ::g_sysClock)
			{
				// skip the delimiter
				in.ignore();
				// read the next opcode
				in >> opcode;

				// end of the file
				if (in.fail())
					break;

				// handle the operation code
				switch (opcode)
				{
				case 'T': // a new time code, this is the exit from the while loop (back to for loop)
					in >> time;
					break;
				case 'S': // start a new event, the old event is automatically finished
					char buffer[1024];
					in.get(buffer, 1024, ',');
					currentEvent.set(buffer);
					break;
				case 'E': // end the current event
					currentEvent.set();
					break;
				case 'P': // print to scren the information about the current event
					currentEvent.display();
					break;
				case 'A': // add a copy of the current event to the archive
					sdds::Event copy(currentEvent);
					archive[idxArchive++] = copy;
					break;
				}
			}
		}
	}

	// print the archive
	std::cout << "--------------------\n";
	std::cout << "    Archive\n";
	std::cout << "--------------------\n";
	for (auto i = 0u; i < idxArchive; ++i)
		archive[i].display();
	std::cout << "--------------------\n";
}
