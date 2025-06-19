#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int new_data)
	{
		this->data = new_data;
		this->next = NULL;
	}
};

class sll
{
public:
	static node *top;

	void push_back(int new_data);
	void push_front(int new_data);
	void pop_front();
	void pop_back();
	void remove(int data);
	void display();
	void search(int data);
	void reverse();
	void sort();
};

node *sll::top = new node(1);

void sll::push_back(int new_data)
{
	node *new_node = new node(new_data);
	new_node->next = NULL;

	if (&(sll::top) == NULL)
	{
		sll::top = new_node;
	}

	node *i = sll::top;
	while (i->next != NULL)
	{
		i = i->next;
	}

	i->next = new_node;
}

void sll::push_front(int new_data)
{
	node *new_node = new node(new_data);
	new_node->next = sll::top;
	sll::top = new_node;
}

void sll::pop_front()
{
	if (sll::top == NULL)
	{
		cout << "List is already empty" << endl;
	}
	else
	{
		node *temp = sll::top;
		sll::top = sll::top->next;
		delete temp;
	}
}

void sll::pop_back()
{
	if (sll::top == NULL)
	{
		cout << "List is already empty" << endl;
	}
	else
	{
		node *i = sll::top;
		node *j = i;

		while (i->next != NULL)
		{
			j = i;
			i = i->next;
		}

		j->next = NULL;
		delete i;
	}
}

void sll::display()
{
	if (sll::top == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		node *i = sll::top;
		while (i->next != NULL)
		{
			cout << i->data << " ";
			i = i->next;
		}
		cout << endl;
	}
}

void sll::search(int data)
{
	node *i = sll::top;
	int index = 0;

	while (i->next != NULL)
	{
		if (i->data == data)
		{
			cout << "Element found at index: " << index << endl;
			return;
		}

		i = i->next;
		index++;
	}

	cout << "Element not found in the list" << endl;
}

void sll::remove(int data)
{
	if (sll::top == NULL)
	{
		cout << "List is already empty" << endl;
	}
	else
	{
		node *i = sll::top;
		node *j = i;

		while (i->next != NULL)
		{
			if (i->data == data)
			{
				j->next = i->next;
				delete i;
				return;
			}
			j = i;
			i = i->next;
		}
	}
}

void sll::reverse()
{
	if (sll::top == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		node *curr = sll::top;
		node *prev = NULL;
		node *next = NULL;

		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		sll::top = prev;
	}
}

int main()
{
	sll l;

	l.push_back(2);
	l.push_back(6);
	l.push_back(3);
	l.push_back(8);
	l.push_back(2);
	l.push_back(8);
	l.push_back(0);

	l.display();

	l.push_front(99);

	l.display();

	l.pop_back();

	l.display();

	l.pop_front();

	l.display();

	l.search(8);

	l.remove(8);

	l.display();

	l.reverse();

	l.display();

	return 0;
}