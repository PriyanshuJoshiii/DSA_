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
        this->next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    int size;
    Stack()
    {
        top = NULL;
        size = 0;
    }
    void push(int element)
    {
        Node *temp = new Node(element);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        return top->data;
    }

    bool isempty()
    {
        return top == NULL;
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek() << endl; // 30
    st.pop();
    cout << st.peek() << endl; // 20
    return 0;
}