// lab 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;

class CList
{
private:
    struct node
    {
        int data;
        node* next;
        node* pre;
    } *head;

public:
    CList()
    {
        head = NULL;
    }

    bool emptyList()
    {
        return head == NULL;
    }

    void insert_begin(int value)
    {
        node* temp = new node;
        temp->data = value;
        if (head == NULL)
        {
            temp->next = temp;
            temp->pre = temp;
            head = temp;
        }
        else
        {
            temp->next = head;
            temp->pre = head->pre;
            head->pre->next = temp;
            head->pre = temp;
            head = temp;
        }
    }

    void insert_end(int value)
    {
        node* temp = new node;
        temp->data = value;
        if (head == NULL)
        {
            temp->next = temp;
            temp->pre = temp;
            head = temp;
        }
        else
        {
            node* last = head->pre;
            temp->next = head;
            temp->pre = last;
            head->pre = temp;
            last->next = temp;
        }
    }

    void delete_begin()
    {
        if (emptyList())
        {
            cout << "List is empty, cannot delete from the beginning" << endl;
        }
        else
        {
            node* temp = head;
            head->next->pre = head->pre;
            head->pre->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    void delete_end()
    {
        if (emptyList())
        {
            cout << "List is empty, cannot delete from the end" << endl;
        }
        else
        {
            node* temp = head->pre;
            temp->pre->next = head;
            head->pre = temp->pre;
            delete temp;
        }
    }

    void delete_v(int value)
    {
        if (emptyList())
        {
            cout << "List is empty, cannot delete" << endl;
        }
        else
        {
            node* current = head;
            while (current->data != value && current->next != head)
            {
                current = current->next;
            }

            if (current->data == value)
            {
                current->pre->next = current->next;
                current->next->pre = current->pre;
                if (current == head)
                {
                    head = current->next;
                }
                delete current;
            }
            else
            {
                cout << "Value not found in the list" << endl;
            }
        }
    }

    int max()
    {
        if (emptyList())
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            int maxValue = head->data;
            node* temp = head->next;
            while (temp != head)
            {
                if (temp->data > maxValue)
                {
                    maxValue = temp->data;
                }
                temp = temp->next;
            }
            return maxValue;
        }
    }

    void two_node_list()
    {
        if (emptyList() || head->next == head)
        {
            cout << "List already has One node or two nodes or is empty" << endl;
        }
        else
        {
            node* first = head;
            node* last = head->pre;
            head = first;
            head->next = head->pre = last;
            delete first;
        }
    }

    void traverse2()
    {
        if (emptyList())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node* temp = head->pre;
            cout << temp->data << endl;
            while (temp != head)
            {
                cout << temp->data << endl;
                temp = temp->pre;
            }
        }
    }

    void traverse()
    {
        if (emptyList())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node* temp = head->next;
            cout << head->data << endl;
            while (temp != head)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    CList C;


    cout << "Insertion from the beginning..." << endl;
    C.insert_begin(22);
    C.insert_begin(18);
    C.traverse();
    cout << "Insertion from the end..." << endl;
    C.insert_end(55);
    C.traverse();

    cout << "Deleting from the beginning..." << endl;
    C.delete_begin();
    C.traverse();

    cout << "Deleting from the end..." << endl;
    C.delete_end();
    C.traverse();

    int valueToDelete = 18;
    cout << "Deleting value " << valueToDelete << "..." << endl;
    C.delete_v(valueToDelete);
    C.traverse();

    cout << "Max value in the list: " << C.max() << endl;

    cout << "Creating a two-node list..." << endl;
    C.two_node_list();
    C.traverse();

    cout << "Displaying list in reverse order..." << endl;
    C.traverse2();

    system("pause");
    return 0;
}
