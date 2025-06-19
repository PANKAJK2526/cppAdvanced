#include <iostream>

using namespace std;

int main()
{
	char choice;
	int x, y;

	while (1)
	{
		cout << "Enter the Operator (+,-,*,/)\n Enter x to exit\n";
		cin >> choice;

		if (choice == 'x')
		{
			return 0;
		}

		cout << "Enter the two numbers: ";
		cin >> x >> y;

		switch (choice)
		{
		case '+':
			cout << x << " + " << y << " = " << x + y << endl;
			break;
		case '-':
			cout << x << " - " << y << " = " << x - y << endl;
			break;
		case '*':
			cout << x << " * " << y << " = " << x * y << endl;
			break;
		case '/':
			cout << x << " / " << y << " = " << x / y << endl;
			break;
		default:
			cout << "Invalid Operator Input";
		}
	}

	return 0;
}