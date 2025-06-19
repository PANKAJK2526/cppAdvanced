#include<iostream>
#include<tuple>

using namespace std;

int main()
{
	tuple<int, string, char> t1 = { 1,"111",'2' };
	tuple<int, string, char> t2, t3;
	int a; string b; char c;

	t3 = make_tuple(2, "222", '3');

	tie(t2) = t1;
	tie(a, b, c) = t2;

	if (t1 == t2)
		cout << "Same" << endl;
	else
		cout << "Different"<<endl;

	tie(a, b, c) = t3;
	cout << a << " " << b << " " << c << endl;

	return 0;
}