#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l = { 1,2,3,4,5 };

	cout << l.front() << endl;
	cout << l.back() << endl;

	l.push_back(6);
	l.pop_front();
	l.push_front(0);
	l.pop_back();

	list<int>::iterator i = l.begin();
	l.insert(i, 9);
	advance(i, 3);
	l.erase(i);

	for (auto j : l)
	{
		cout << j << ' ';
	}
	cout << endl;

	l.sort();
	l.reverse();

	for (auto j : l)
	{
		cout << j << ' ';
	}
	cout << endl;

	return 0;
}

