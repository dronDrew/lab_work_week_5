#include "dependies.h"
#include "list_template.h"
#include "line_to_direction_template.h"
#include "binary_tree.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	binary_tree a;
	a.InitDictionery();
	string one="apple";
	string two="cat";
	string three="dog";
	string four="нога";
	string five="рука";
	string six="торт";
	a.Search(one);
	a.Search(one);
	a.Search(one);
	a.Search(one);
	a.Search(one);
	a.Search(one);
	a.Search(two);
	a.Search(two);
	a.Search(two);
	a.Search(two);
	a.Search(two);
	a.Search(three);
	a.Search(three);
	a.Search(three);
	a.Search(three);
	a.Search(four);
	a.Search(four);
	a.Search(four);
	a.Search(five);
	a.Search(five);
	a.Search(six);
	cout << "________________________________\n";
	a.Thre_most_popular();
	a.Thre_most_unpopular();
	return 0;
}