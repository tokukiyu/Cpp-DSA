// Include header file
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *head = NULL;
//this insert at end
void insert(int val)
{
    node *newnode = new node();
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        node *last = head->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
        //  last = newnode;
    }
}
void insertAtBeginning(int val)
{
    node *newnode = new node();
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        node *last = head->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insertAtPosition(int data, int position)
{
    node *newNode = new node;
    newNode->data = data;

    // If the linked list is empty, make the new node the head and link it to itself
    if (head == NULL)
    {
        head = newNode;
        newNode->prev = head;
        newNode->next = head;
    }
    else
    {
        // Find the node at the given position
        node *current = head;
        int n = 1;
        for (int i = 1; i < position && current->next != head; i++)
        {
            current = current->next;
            n++;
        }
        if (current->next == head)
        {
            if (position == (n + 1))
            {
                newNode->prev = current;
                newNode->next = head;
                head->prev = newNode;
                current->next = newNode;
            }
            cout << "Invalid position!" << endl;
        }
        else if (position == 0)
        {
            cout << "\n Invalid position! \n " << endl;
        }
        else if (position == 1)
        {
            head = newNode;
        }
        // Link the new node to the current node and the current node's previous node
        else
        {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }

        // If the new node was inserted at the beginning of the list, make it the head
    }
}
// Function to delete the first node of the doubly circular linked list
void deleteFormBeginning()
{
    // Find the second node in the linked list
    node *sknd = head->next;
    if (head == NULL)
    {
        cout << "you have no any data here: ";
    }

    else
    {
        // If the linked list has only one node, delete it and set the head to NULL
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            // Unlink the first node from the linked list
            sknd->prev = head->prev;
            head->prev->next = sknd;
            // Delete the first node and make the second node the head
            delete head;
            head = sknd;
        }
    }
}
void deleteFromEnd()
{
    // Find the last node in the linked list
    node *last = head->prev;
    // Fs a                                                                                                                                                                                                                                                                    dc   c vx1111111111111111111111111n the linked list
    node *skndLast = last->prev;
    // If the linked list is empty, there is nothing to delete
    if (head == NULL)
    {
        cout << "you have no any data here: ";
    }
    else
    {
        // If the linked list has only one node, delete it and set the head to NULL
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            skndLast->next = head;
            head->prev = skndLast;
            delete last;
        }
    }
}
void deleteFrom(int position)
{
    // Find the node at the given position
    node *current = head;

    if (head == NULL)
    {
        cout << "you have no any data here: ";
    }
    else
    {
        if (position == 1)
        {
            // delete head;
            head->prev->next = head->next;
            head = head->next;
        }
        else
        {
            int n = 1;
            while (current->next != head)
            {
                if (n == position)
                {
                    // If the node was found, unlink it from the linked list and delete it
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    break; // done loop;
                }
                else
                {
                    current = current->next;
                    n++;
                }
            }
            // search till end and position was not valid
            if (current->next == head)
            {
                if (n == position)
                {
                    current->prev->next = head;
                    current->next->prev = current->prev;
                    delete current;
                }
                else
                {
                    cout << "Invalid position!" << endl;
                }
            }
        }
    }
}
// Function to print the doubly circular linked list
void display()
{
    int counter = 0;
    node *current = head;
    do
    {
        cout << current->data << " ";
        counter++;
        current = current->next;
    } while (current != head);
    cout<< "\nNow you have "<<counter<< " nodes \n";
}
int main()
{
    cout << " it is working \n";
    cout << "Insert by defualt |at end \n";
    insert(10);
    insert(20);
    insert(20);
    insert(20);
    insert(30);
    display();
    cout << "\n Enter data at end | pls Enter data: ";
    int first;
    cin >> first;
    insert(first);
    display();
    cout << "\nInsert at beginning \n";
   cin >> first;
   insertAtBeginning(first);
    display();
    cout << endl;
    cout << endl;
    system("pause");
    int n, data;
    cout << "Insert at specific position \n"
         << "Enter position to enter new data: ";
    cin >> n;
    cout << "\nEnter data at: " << n << ": ";
    cin >> data;
    insertAtPosition(data, n);
    cout << "\n After Enter data " << data << " at " << n << endl;
    display();
    cout << endl;
    cout << endl;
    system("pause");
    cout<<"Deleting at the benginning and end\n";
    cout << "After delete from Beginning \n";
    deleteFormBeginning();
    display();
    cout << endl;
    cout << endl;
    system("pause");
    cout << "After delete from End \n";
    deleteFromEnd();
    display();
    cout << endl;
    cout << endl;
    system("pause");
    int b;
    cout << "enter position to delete data from: ";
    cin >> b;
    cout << "After delete from specic point | " << b << " \n";
    deleteFrom(b);
    display();
    return 0;
}