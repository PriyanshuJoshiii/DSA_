#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Queue
{
public:
    Node *start = NULL, *end = NULL;
    int size = 0;
    void push(int element)
    {
        Node *temp = new Node(element);
        if (start == NULL)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        size++;
    }
    void pop()
    {
        if (start == NULL)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            Node *temp = start;
            start = start->next;
            if (start == NULL)
                end = NULL;
            delete temp;
            size--;
        }
    }
    void peek()
    {
        if (start == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << start->data;
    }
    int sizee()
    {
        return size;
    }
};
int main()
{
    return 0;
}