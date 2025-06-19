#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> v)
{
	for (auto p = v.begin(); p != v.end(); p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}

void findFirst(vector<int> v)
{
	vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
									  { return (i > 4); });

	cout << "First number greater than 4 is: " << *p << endl;
}

void sortDecreasing(vector<int> &v)
{
	sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
		 { return (a > b); });
}

void countIfFun(vector<int> v)
{
	int count = count_if(v.begin(), v.end(), [](int a)
						 { return (a >= 5); });

	cout << "The number of elements greater than or equal to 5 is: " << count << endl;
}

void uniqueElements(vector<int> &v)
{
	vector<int>::iterator p = unique(v.begin(), v.end(), [](int a, int b)
									 { return a == b; });

	v.resize(distance(v.begin(), p));
}

void squareOfNum(int i)
{
	auto square = [](int i)
	{
		return i * i;
	};

	cout << "Square of 6 is: " << square(6) << endl;
}

void multiplication(vector<int> v)
{
	int f = accumulate(v.begin(), v.end(), 1, [](int i, int j)
					   { return i * j; });

	cout << "Multiplication of vector v is: " << f << endl;
}

int main()
{
	vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};

	printVector(v);

	findFirst(v);

	sortDecreasing(v);

	printVector(v);

	countIfFun(v);

	uniqueElements(v);

	printVector(v);

	squareOfNum(6);

	multiplication(v);
}