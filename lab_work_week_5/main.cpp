#include "dependies.h"
#include "list_template.h"
#include "line_to_direction_template.h"
#include "binary_tree.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	binary_tree a;
	a.InitDictionery();
	//a.Show();
	string aq = "apple";
	string ax = "торт";
	string az = "антоновка";
	string aa = "якорь";
	string ap = "pearch";
	string at = "dog";
	a.Search(aq);
	a.Search(ax);
	//a.Search(ax);
	a.Edit_translation(aq, az);
	a.Search(aq);
	a.Search(at);
	//a.Delete_translation(aq);
	a.Add_translation(aq, aa);
	a.Add_translation(aq, ap);
	a.Search(aq);
	a.Search(ax);
	cout << "________________________________\n";
	a.Thre_most_popular();
	return 0;
}