#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Dynamic Memory Allocation (Linked List)
class DynamicMemoryAllocation
{
private:
    Node *head;

public:
    // Constructor
    DynamicMemoryAllocation()
    {
        head = NULL;
    }

    // Insert at Beginning
    void insert_at_beginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;

        cout << "\nNode inserted at beginning successfully.\n\n";
    }

    // Append at End
    void append(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            cout << "\nNode appended successfully.\n\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nNode appended successfully.\n\n";
    }

    // Display Linked List
    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << " -> NULL\n\n";
    }

    // Search Node
    void Search(int key)
    {
        Node *temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "\nElement " << key << " found at position "
                     << position << ".\n\n";
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "\nElement not found.\n\n";
    }

    // Delete Node
    void Delete_node(int key)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is Empty.\n\n";
            return;
        }

        // Delete first node
        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << "\nNode deleted successfully.\n\n";
            return;
        }

        Node *current = head;

        while (current->next != NULL && current->next->data != key)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            cout << "\nElement not found.\n\n";
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "\nNode deleted successfully.\n\n";
    }

    // Reverse Linked List
    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;

        cout << "\nLinked List reversed successfully.\n\n";
    }

    // Destructor
    ~DynamicMemoryAllocation()
    {
        Node *temp;

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DynamicMemoryAllocation list;

    int choice, value;

    do
    {
        cout << "======================================" << endl;
        cout << "   DYNAMIC MEMORY ALLOCATION PROJECT  " << endl;
        cout << "======================================" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Append at End" << endl;
        cout << "3. Display Linked List" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Delete Node" << endl;
        cout << "6. Reverse Linked List" << endl;
        cout << "7. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter value : ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 2:
            cout << "\nEnter value : ";
            cin >> value;
            list.append(value);
            break;

        case 3:
            list.display();
            break;

        case 4:
            cout << "\nEnter value to search : ";
            cin >> value;
            list.Search(value);
            break;

        case 5:
            cout << "\nEnter value to delete : ";
            cin >> value;
            list.Delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            cout << "\nThank You! Program Ended Successfully.\n\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n\n";
        }

    } while (choice != 7);

    return 0;
}