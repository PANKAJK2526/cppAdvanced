#include<iostream>

using namespace std;

int main()
{
	pair<int, int> p1, p4;
	pair<int, string> p2;
	pair<char, char> p3;

	p1 = make_pair(1, 1);
	p2 = make_pair(1, '2');
	p3 = make_pair('2', '2');
	p4 = make_pair(1, 1);

	cout << p1.first << " " << p2.second << endl;

	if (p1 == p4)
		cout << "Same" << endl;
	else
		cout << "Different";
	return 0;
}