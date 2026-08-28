#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int count;
    int start;
    int end;
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        count = 0;
        start = -1;
        end = -1;
    }
    void enqueue(int element)
    {
        if (count == size)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (count == 0)
        {
            start = 0;
        }
        end = (end + 1) % size;
        arr[end] = element;
        count++;
    }
    int pop()
    {
        if (count == 0)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int element = arr[start];

        if (count == 1)
        {
            start = -1;
            end = -1;
            count = 0;
        }
        else
        {
            start = (start + 1) % size;
            count--;
        }

        return element;
    }
    int top()
    {
        if (start != -1)
        {
            return arr[start];
        }
        return -1;
    }
};
int main()
{
    Queue q(5);
    q.enqueue(3);
    cout << q.pop();
    cout << q.top();
    return 0;
}