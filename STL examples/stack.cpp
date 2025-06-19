#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s;

	s.push(4);
	s.push(3);
	s.push(1);
	s.push(7);
	s.push(2);

	cout << s.top();
	s.pop();
	cout << s.top();

	return 0;
}