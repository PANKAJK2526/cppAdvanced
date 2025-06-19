#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;

	node(int new_data) : data(new_data), next(NULL), prev(NULL) {};
};

class dll
{
public:
	static node *top;
	static node *rear;

	void display_top_to_bottom();
	void display_bottom_to_top();
	void push_back(int new_data);
	void push_front(int new_data);
	void pop_back();
	void pop_front();
	void reverse();
	void sort();
	void remove(int data);
	void search(int data);
};

node *dll::top = NULL;
node *dll::rear = NULL;

void dll::display_top_to_bottom()
{
	if (top == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		node *i = top;

		while (i != NULL)
		{
			cout << i->data << " ";
			i = i->next;
		}
		cout << endl;
	}
}

void dll::display_bottom_to_top()
{
	if (top == NULL)
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		node *i = rear;

		while (i != NULL)
		{
			cout << i->data << " ";
			i = i->prev;
		}
		cout << endl;
	}
}

void dll::push_back(int new_data)
{
	node *new_node = new node(new_data);

	if (top == NULL)
	{
		top = new_node;
		rear = top;
	}
	else
	{
		node *i = top;
		node *j = NULL;

		while (i->next != NULL)
		{
			j = i;
			i = i->next;
		}

		i->next = new_node;
		new_node->prev = i;
		rear = new_node;
	}
}

int main()
{
	dll l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	l.display_top_to_bottom();
	l.display_bottom_to_top();

	return 0;
}