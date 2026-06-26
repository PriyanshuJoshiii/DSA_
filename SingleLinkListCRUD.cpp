#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *create(Node *head, int s)
{
    if (s == 0)
        return NULL;
    else
    {
        cout << "Enter the elements: ";
        int arr[s];
        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
        }
        head = new Node(arr[0], nullptr);
        Node *temp = head;
        for (int i = 1; i < s; i++)
        {
            temp->next = new Node(arr[i], nullptr);
            temp = temp->next;
        }
        return head;
    }
}
void traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL(The end Of LL)" << endl;
}
int ListSize(Node *head)
{
    if (head == NULL)
        return 0;
    if (head->next == NULL)
        return 1;
    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
Node *convertarrtoll(vector<int> &arr, Node *head)
{
    if (head == NULL)
    {
        head = new Node(arr[0], nullptr);
    }
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i], nullptr);
        temp = temp->next;
    }
    return head;
}
void Findlen(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << " Length Of The Link List is: 0" << endl;
        return;
    }
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << " Length Of The Link List is: " << count << endl;
}
void FindElem(int x, Node *head)
{
    if (head == NULL)
    {
        cout << "No Element in Link List" << endl;
    }
    else
    {
        if (head->data == x)
        {
            cout << "Found The Number at Position 1";
            return;
        }
        Node *temp = head->next;
        int i = 2;
        while (temp != NULL)
        {
            if (temp->data == x)
            {

                cout << "Found The Number At position " << i << endl;
                return;
            }
            else
            {
                temp = temp->next;
                i++;
            }
        }
        cout << "Not Found The Number At any position " << endl;
    }
    return;
}
Node *DeleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head->next;
    delete (head);
    return temp;
}
Node *DeleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete (head);
        cout << "Deleted SucessFully" << endl;
        return NULL;
    }
    else
    {
        Node *temp = head;
        Node *prev;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete (temp);
    }
    cout << "Deleted SucessFully" << endl;
    return head;
}
Node *DeleteKth(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        if (k == 1)
        {
            delete (head);
            return head;
        }
        return head;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        Node *prev;
        while (temp != NULL)
        {
            if (count == k)
            {
                prev->next = prev->next->next;
                delete (temp);
                break;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
    return head;
}
Node *DeleteElement(Node *head, int elem)
{
    Node *temp = head;
    Node *prev;
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == elem)
    {
        temp = temp->next;
        delete (head);
        return temp;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == elem)
            {
                prev->next = prev->next->next;
                delete (temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
}
Node *InsertHead(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val, nullptr);
    }
    Node *temp = new Node(val, head);
    return temp;
}
Node *InsertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val, nullptr);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(val, nullptr);
    return head;
}
Node *InsertKthPos(Node *head, int item, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    Node *prev;
    if (k == 1)
    {
        return new Node(item, head);
    }
    int count = 1;
    while (temp != NULL)
    {
        if (count == k)
        {
            prev->next = new Node(item, temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (k == ListSize(head) + 1)
        prev->next = new Node(item, temp);
    return head;
}
Node *InserBeforeElem(Node *head, int elem, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == elem)
    {
        return new Node(key, head);
    }
    else
    {
        Node *temp = head;
        Node *prev;
        while (temp != NULL)
        {
            if (temp->data == elem)
            {
                prev->next = new Node(key, temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    /*int size;
    cout << "Hey Please Enter The Size Of The Link List: ";
    cin >> size;
    Node *head = NULL;
    head = create(head, size);
    traversal(head);
    */
    // Array To Link List.
    Node *head = NULL;
    vector<int> v = {23, 5, 7, 54, 3};
    head = convertarrtoll(v, head);
    int size_of_LL = ListSize(head);
    cout << "Size of Link List is: " << size_of_LL << endl;
    traversal(head); // Traverse The Whole Link List
    // Findlen(head);            Find The Length Of The Link List.
    FindElem(3, head); // Find The Element is it Found Gives The Positon.
    // head = DeleteHead(head);  Deletes The Head Of The Link List and returns the new head.
    // traversal(head);
    // head = DeleteTail(head); Deletes The Tail Of The Link List and returns the new head.
    // traversal(head);
    // head = DeleteKth(head, 4);  Deletes The Kth element(starting from 1) Of The Link List and returns the new head.
    // head = DeleteElement(head, 3); Deletes The Element With Value K Of The Link List and returns the new head.
    // head = InsertHead(head, 89);   Insert a New element at The Postion of head and head shifts next.
    // head = InsertTail(head, 2); Inserts a New Element at the End Of The Link List.
    // head = InsertKthPos(head, 82, 7);
    // head = InserBeforeElem(head, 5, 4);Inserts an key Element Just Before a value present in Link List.
    traversal(head);
    return 0;
}
