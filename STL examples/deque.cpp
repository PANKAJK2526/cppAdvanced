#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque<int> q;

	q.push_back(4);
	q.push_front(3);
	q.push_back(1);
	q.push_front(7);

	cout << q.front() << " " << q.back() << endl;
	q.pop_back();
	q.pop_front();
	cout << q.front() << " " << q.back();

	return 0;
}