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
	string ax = "����";
	string az = "���������";
	string aa = "�����";
	string ap = "pearch";
	a.Search(aq);
	a.Edit_translation(aq, az);
	a.Search(aq);
	//a.Delete_translation(aq);
	a.Add_translation(aq, aa);
	a.Add_translation(aq, ap);
	a.Search(aq);
	a.Search(ax);
	return 0;
}