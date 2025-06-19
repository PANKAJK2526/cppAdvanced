#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q;

	q.push(4);
	q.push(3);
	q.push(1);
	q.push(7);
	q.push(2);

	cout << q.front() << " " << q.back() << endl;
	q.pop();
	cout << q.front() << " " << q.back();

	return 0;

	return 0;
}