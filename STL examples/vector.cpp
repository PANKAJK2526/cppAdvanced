#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4 };

	v.push_back(5);
	cout<<v.size()<<endl;
	cout<<v.at(1)<<endl;

	vector<int>::iterator i = v.begin();
	advance(i, 2);
	
	v.erase(i);

	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << v.front()<<endl;
	cout << v.back() << endl;

	i = v.begin();
	advance(i, 2);

	v.insert(i, 3);
	v.pop_back();

	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	v.clear();
	cout << v.empty() << endl;

	return 0;
}