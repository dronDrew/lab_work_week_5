#include "dependies.h"
#include "list_template.h"
#include "line_to_direction_template.h"
using namespace std;

int main() {
	list_two_direcktion<int> a;
	a.Add_to_tail(15);
	//a.Show();
	a.Add_to_tail(18);
	a.Add_to_tail(18);
	a.Add_to_position(3, 18);
	//a.Delete_from_position(3);
	a.Show();
	cout <<"___________________________________________"<< endl;
	a.Direction_swap();
	cout << "___________________________________________" << endl;
	a.Show();
	return 0;
}