#include <iostream>

using namespace std;

class Complex
{
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		this->real = r;
		this->imag = i;
	}

	Complex operator+(const Complex &c)
	{
		Complex res;

		res.real = this->real + c.real;
		res.imag = this->imag + c.imag;

		return res;
	}

	void operator[](const string &s)
	{
		if (s == "real")
			cout << this->real << endl;
		else
			cout << this->imag << endl;
	}

	complex operator++()
	{
		complex res;

		res.real = this->real++;
		res.imag = this->imag;

		return res;
	}

	complex operator++(int i)
	{
		complex res;

		res.real = this->real;
		res.imag = this->imag++;

		return res;
	}

	friend ostream &operator<<(ostream &out, const Complex &c);
	friend istream &operator>>(istream &in, const Complex &c);
	friend void operator==(const Complex &c1, const Complex &c2);
};

ostream &operator<<(ostream &out, const Complex &c)
{
	out << c.real;
	out << " +i" << c.imag << endl;

	return out;
}

istream &operator>>(istream &in, const Complex &c)
{
	in >> c.real;
	in >> c.imag;

	return in;
}

void operator==(const Complex &c1, const Complex &c2)
{
	bool res;

	if (c1.real == c2.real && c1.imag == c2.imag)
		res = true;
	else
		res = false;

	if (res)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
}

int main()
{
	Complex c1(10, 5), c2(2, 4);
	cout << c1;
	cout << c2;
	Complex c3 = c1 + c2;
	cout << c3;
	c3++;
	cout << c3;
	++c3;
	cout << c3;
	Complex c4;
	c4["real"];
	c3["imag"];
	// cin >> c4;

	return 0;
}