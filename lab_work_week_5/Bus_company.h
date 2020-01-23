#pragma once
#include "dependies.h"
class Bus_company
{
	class Bus {
	public:
		int number_of_bus;
		std::string name_of_driver;
		std::string surname_of_driver;
		int number_of_line;
		int place_in_bus;
		Bus* biger_number;
		Bus* less_number;
		Bus* privious_bus;
		Bus(int number_of_bus, std::string name_of_driver,std::string surname_of_driver,int number_of_line,int place_in_bus);
	};
public:
	Bus* first;
	Bus_company();
	bool Add_bus(int number_of_bus, std::string name_of_driver, std::string surname_of_driver, int number_of_line, int place_in_bus);
	bool Search(int number_of_bus);
	friend bool Save_info_to_file(Bus_company  &first);
};
bool Save_info_to_file(Bus_company &first );
