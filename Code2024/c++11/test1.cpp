#include <iostream>
#include <map>
using namespace std;


int main() 
{
	int i = 10; 
	auto p = &i;
	auto pf = strcpy;
	cout << typeid(p).name() << endl; 
	cout << typeid(pf).name() << endl;
	map<string, string> dict = { {"sort", "≈≈–Ú"}, {"insert", "≤Â»Î"} }; 
	//map<string, string>::iterator it = dict.begin(); auto it = dict.begin();
	return 0;
}