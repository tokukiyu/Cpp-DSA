#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = new node();
node *second = new node();
node *third = new node();
void insertfrst(int dt)
{
    node *n = new node();
    n->data = dt;
    n->next = head;
    head = n;
}
// hello
void insertEnd(int dt)
{
    node *n = new node();
    n->data = dt;
    n->next = NULL;
    node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
}

void insertAt(int val, int pos)
{
    node *n = new node();
    n->data = val;
    node *temp = head;
    int i = 1;
    for (; i <= pos;)
    {
        if (i == pos)
        {
            n->next = temp->next;
            temp->next = n;
            break;
        }
        else
            temp = temp->next;
        i++;
    }
}

void display(node *n)
{
    while (n != NULL)
    {
        cout << n->data << endl;
        n = n->next;
    }
}

int main(int argc, char const *argv[])
{
    cout<<"hello";
    int array[] = {1, 2, 3, 4, 2, 444, 4};
    int s = sizeof(array) / sizeof(array[1]);
    int i = 0;
    for (; i < s;)
    {
        insertfrst(array[i]);
        i++;
    }
    insertAt(10, 3);
    display(head);

    return 0;
}
