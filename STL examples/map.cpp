#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<char, string> m = { {'1',"pankaj"},{'2', "neeraj"},{'3',"saroj"},{'4', "sonam"} };

	cout << m['4'] << endl;
	cout << m.at('2') << endl;
	cout << m.size() << endl;
	cout << m.max_size() << endl;

	m.insert(make_pair('5',"akshay"));

	for (auto j : m)
	{
		cout << j.first << ' ' << j.second << endl;
	}
	cout << endl;

	m.insert(make_pair('5', "gautham"));

	for (auto j : m)
	{
		cout << j.first << ' ' << j.second << endl;
	}
	cout << endl;

	m.insert_or_assign('5', "gautham");

	for (auto j : m)
	{
		cout << j.first << ' ' << j.second << endl;
	}
	cout << endl;

	if( m.find('3') != m.end());
	cout << m['3'] << endl << endl;;

	map<char, string>::iterator i = m.begin();
	advance(i, 3);
	m.erase(i);

	for (auto j : m)
	{
		cout << j.first << ' ' << j.second << endl;
	}
	cout << endl;

	return 0;
}