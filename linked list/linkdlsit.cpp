#include <iostream>
using namespace std;
struct node
{
    int salary;
    string name;
    int age;
    node *next;
    node *pre;
};
node *head = NULL;
void insertEnd(int salary)
{
    node *newnode = new node;
    newnode->salary = salary;
    if (head == NULL)
    {
        head = newnode;
        // newnode->next = NULL;
    }
    else
    {
        node *lst = head;
        while (lst->next != NULL)
            lst = lst->next;
        lst->next = newnode;
        newnode->next = NULL;
    }
}
void insertAtbeggin(int salary)
{
    node *newnode = new node;
    newnode->salary = salary;
    if (head == NULL)
    {
        head = newnode;
        // newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insertAt(int salary, int pos)
{
    node *newnode = new node;
    newnode->salary = salary;
    node *val = head;
    node *pre = head;
    for (int i = 1; i < pos && val->next != NULL; i++)
    {
        val = val->next;
    }
    newnode->next = val->next;
    val->next = newnode;
}
void dirocod()
{
    node *cur = head;
    node *pre;
    node *temp;
    int pos = 9;
    for (int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur != NULL)
    {
        pre->next = temp;
        temp->next = cur;
    }
    delete temp;
    cur->next = NULL;
}
void mine()
{
    node *temp;
    node *cur = head;
    node *pre = head;
    int n = 1;
    while (n < 9)
    {
        pre = cur;
        cur = cur->next;
        n++;
    }
    temp = cur;
    pre->next = cur->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = NULL;
}
void display()
{
    node *current = head;
    while (current != NULL)
    {
        cout << "salary: " << current->salary << "\n";
        current = current->next;
    }
}
int main(int argc, char const *argv[])
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);
    insertEnd(7);
    insertEnd(8);
    insertEnd(9);
    insertEnd(10);
    insertEnd(11);
    insertEnd(12);
    mine();
    display();
    return 0;
}
