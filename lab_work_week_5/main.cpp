#include "dependies.h"
#include "list_template.h"
#include "line_to_direction_template.h"
#include "binary_tree.h"
#include "Bus_company.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	Bus_company fon;
	int iter{ 6 };
	int number_of_bus{0};
	std::string name_of_driver;
	std::string surname_of_driver;
	int number_of_line{0};
	int place_in_bus{0};
	while (iter>0)
	{
		cout << "Number of bus\n";
		cin >> number_of_bus;
		cout << "Name of driver\n";
		cin >> name_of_driver;
		cout << "Surname of driver\n";
		cin >> surname_of_driver;
		cout << "Number of line\n";
		cin >> number_of_line;
		cout << "place in bus\n";
		cin >> place_in_bus;
		fon.Add_bus(number_of_bus, name_of_driver, surname_of_driver, number_of_line, place_in_bus);
		iter--;
	}
	cout << "Number of bus for Serching\n";
	cin >> number_of_bus;
	fon.Search(number_of_bus);
	Save_info_to_file(fon);
	return 0;
}