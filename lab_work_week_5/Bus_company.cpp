#include "Bus_company.h"
Bus_company::Bus::Bus(int number_of_bus, std::string name_of_driver, std::string surname_of_driver, int number_of_line, int place_in_bus) {
	this->number_of_bus = number_of_bus;
	this->name_of_driver = name_of_driver;
	this->surname_of_driver = surname_of_driver;
	this->number_of_line = number_of_line;
	this->place_in_bus = place_in_bus;
	this->biger_number = nullptr;
	this->less_number = nullptr;
	this->privious_bus = nullptr;
}
Bus_company::Bus_company() {
	this->first = nullptr;
}
bool Bus_company::Add_bus(int number_of_bus, std::string name_of_driver, std::string surname_of_driver, int number_of_line, int place_in_bus) {
	if (first == nullptr) {
		first = new Bus(number_of_bus, name_of_driver, surname_of_driver, number_of_line, place_in_bus);
		return true;
	}
	else
	{
		Bus* temp = this->first;
		while (temp!=nullptr||temp!=nullptr)
		{
			if (number_of_bus > temp->number_of_bus) {
				
				if (temp->biger_number == nullptr) {
					temp->biger_number = new Bus(number_of_bus, name_of_driver, surname_of_driver, number_of_line, place_in_bus);
					temp->biger_number->privious_bus = temp;
					return true;
				}
				temp = temp->biger_number;
			}
			else
			{
				
				if (temp->less_number == nullptr) {
				temp->less_number= new Bus(number_of_bus, name_of_driver, surname_of_driver, number_of_line, place_in_bus);
				temp->less_number->privious_bus = temp;
				return true;
				}
				temp = temp->less_number;
			}
		}

	}
}
bool Bus_company::Search(int number_of_bus) {
	Bus* temp = this->first;
	while (temp!=nullptr)
	{
		if (temp->number_of_bus > number_of_bus) {
			temp=temp->less_number;
		}
		else if (temp->number_of_bus==number_of_bus) {
			std::cout << "Number of Bus     : " << temp->number_of_bus << std::endl;
			std::cout << "Name of driver    : " << temp->name_of_driver << std::endl;
			std::cout << "Surname of Driver : " << temp->surname_of_driver << std::endl;
			std::cout << "Number of Line    : " << temp->number_of_line << std::endl;
			std::cout << "Place in Bus      : " << temp->place_in_bus << std::endl;
			return true;
		
		}
		else
		{
			temp=temp->biger_number;
		}
	}
	return false;
}
bool Save_info_to_file(Bus_company & first) {
	std::ofstream file_to_saving;
	int begin{ 0 };
	file_to_saving.open("info.txt");
	if (file_to_saving.is_open()) 
	{
		Bus_company * temp = &first;
		begin=temp->first->number_of_bus;
		while (temp->first->less_number !=nullptr)
		{
			if (temp->first->number_of_bus > temp->first->less_number->number_of_bus) {
				temp->first = temp->first->less_number;
			}

		}
		file_to_saving << "Number of Bus     : " << temp->first->number_of_bus << std::endl;
		file_to_saving << "Name of driver    : " << temp->first->name_of_driver << std::endl;
		file_to_saving << "Surname of Driver : " << temp->first->surname_of_driver << std::endl;
		file_to_saving << "Number of Line    : " << temp->first->number_of_line << std::endl;
		file_to_saving << "Place in Bus      : " << temp->first->place_in_bus << std::endl;
		while (temp->first->number_of_bus<=begin)
		{
			temp->first = temp->first->privious_bus;
			file_to_saving << "Number of Bus     : " << temp->first->number_of_bus << std::endl;
			file_to_saving << "Name of driver    : " << temp->first->name_of_driver << std::endl;
			file_to_saving << "Surname of Driver : " << temp->first->surname_of_driver << std::endl;
			file_to_saving << "Number of Line    : " << temp->first->number_of_line << std::endl;
			file_to_saving << "Place in Bus      : " << temp->first->place_in_bus << std::endl;
			file_to_saving << "Number of Bus     : " << temp->first->biger_number->number_of_bus << std::endl;
			file_to_saving << "Name of driver    : " << temp->first->biger_number->name_of_driver << std::endl;
			file_to_saving << "Surname of Driver : " << temp->first->biger_number->surname_of_driver << std::endl;
			file_to_saving << "Number of Line    : " << temp->first->biger_number->number_of_line << std::endl;
			file_to_saving << "Place in Bus      : " << temp->first->biger_number->place_in_bus << std::endl;
		}
		
	}
	else {
		std::cout << "file is not open or not exist\n";
		return false;
	}
	
}