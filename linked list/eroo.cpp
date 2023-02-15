#include <iostream>
using namespace std;
struct node
{
    string name;
    int age;
    double salary;
    node *next;
    node *prev;
};
node *head = NULL;
// for singly linked list
void insert(string name, int age, double salary)
{
    node *newnode = new node;
    newnode->age = age;
    newnode->salary = salary;
    newnode->name = name;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        head->next = newnode;
        newnode->next = NULL;
    }
}
void display()
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << "name: " << temp->name << "Age: " << temp->age << "salary: " << temp->salary << "\n";
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    insert("Tole", 30, 1000.9);
    insert("Tole", 30, 1000.9);
    insert("Tole", 30, 1000.9);
    display();
    return 0;
}
