#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
node *head = NULL;
void insertAtFirst(int val)
{
	node *newnode = new node();
	newnode->data = val;
	if (head == NULL)
	{
		head = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		newnode->prev = NULL;
		head = newnode;
	}
}
void atTheEnd(int val)
{
	node *newnode = new node();
	node *pre = head;
	newnode->data = val;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else
	{
		while (pre->next != NULL)
		{
			pre = pre->next;
		}
		pre->next = newnode;
		newnode->prev = pre;
	}
}
void insertAt(int val, int loc)
{
	node *newnode = new node();
	newnode->data = val;
	int n = 1;
	node *temp = head;
	while (temp->next != NULL)
	{
		if (n == loc)
		{
			newnode->next = temp->next;
			newnode->prev = temp->next->prev;
			temp->next = newnode;
			temp->next->prev = newnode;
			break;
		}
		else
		{
			temp = temp->next;
			n++;
		}
	}
}
void deleteFirst()
{
	node *next = head->next;
	if (head == NULL)
	{
		cout << "we have no any value at first";
	}
	else
	{
		next->prev = head->prev;
		head->next = next->next;
		head = next;
	}
}
void deleteFromEnd()
{
	node *lst = head;

	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->prev->next = NULL;
	delete lst;
}
void display()
{
	node *temp = head;
	while (temp != NULL)
	{

		cout << temp->data << " ";
		temp = temp->next;
	}
}
void dislpayBackward()
{
	//	node *prev=head;
	node *lst = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	while (lst != NULL)
	{
		cout << lst->data << " ";
		lst = lst->prev;
	}
}
int main()
{
	//     	insertAtFirst(4); you can Uncomment here to chect it out
	insertAtFirst(5);
	atTheEnd(7);
	atTheEnd(6);
	atTheEnd(9);
	atTheEnd(23);
	atTheEnd(9);
	atTheEnd(50);
	display();
	cout << "\n";
	// deleteFirst(); you can Uncomment here to chect it out
	//	deleteFromEnd(); you can Uncomment here to chect it out
	dislpayBackward();
	insertAt(12, 6);
	display();
	cout << " \n";

	return 0;
}
