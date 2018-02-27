#include <iostream>

struct node
{
	int data;
	node *next;
};
class list
{
	node * head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(int);
	void display();
	void delete_last();
	void insert_start(int);
	void insert_position(int, int);
	void delete_first();
	void delete_position(int pos);

};
void list::createnode(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
void list::insert_start(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}
void list::insert_position(int pos, int value)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;

}
void list::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}void list::delete_last()
{
	node *current = new node;
	node *previous = new node;
	current = head;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
}
void list::delete_position(int pos)
{
	node *current = new node;
	node *previous = new node;
	current = head;
	for (int i = 1; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}
void list::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
}
int main(int argc, char * argv[]) {
	list list;
	for (int i = 0; i < 25; i++)
	{
		list.insert_start(i);
	}
	list.display();
	std::cin.get();
	for (int i = 25; i > 0; --i) {
		list.delete_position(i);
	} std::cout << "deleted list\n"; list.display();	std::cin.get();

	return 0;
}