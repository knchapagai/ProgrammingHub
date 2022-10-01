#include <iostream>

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

using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//----------------------------------------
Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL)
        return head;
    int length = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    Node *tail = temp;
    tail->next = head;
    int k = length - n;

    temp = head;
    for (int i = 1; i < k; i++)
    {
        temp = temp->next;
    }
    Node *a = temp->next;
    head = a;
    temp->next = NULL;
    return head;
}
