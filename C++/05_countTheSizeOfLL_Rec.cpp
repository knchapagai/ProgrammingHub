#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    void display(node *p)
    {
        cout << "linked list : " << endl;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

    int rcount(node *p)
    {
        if (p == 0)
            return 0;
        else
        {
            return rcount(p->next) + 1;
        }
    }
};
int main()
{
    cout << "enter the no of elements in the linked list : " << endl;
    int n, x;
    cin >> n;
    cout << "enter the " << n << " elements " << endl;
    cin >> x;
    node *first = new node;
    node *p, *temp;
    first->data = x;
    first->next = NULL;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = new node;
        p->data = x;
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
    node().display(first);
    ;
    cout << endl;
    cout << "Size of linked list:\n"
         << node().rcount(first) << endl;

    return 0;
}