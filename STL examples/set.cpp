#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<char> s = { 'C', 'B', 'V', 'O', 'E' };

	s.insert('M');

	s.erase('B');

	for (auto i : s)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << s.size();

	return 0;
}