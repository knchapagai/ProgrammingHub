#include <iostream>
using namespace std;
class node
{
public:
    int dat;
    node *prev;
    node *next;

    node(int val)
    {
        dat = val;
        next = NULL;
        prev = NULL;
    };
    void insertAtHead(node *&head, int val)
    {
        node *n = new node(val);
        n->next = head;
        head = n;
    }
    void insertAtTail(node *&head, int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    };
    int search(node *head, int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->dat == key)
            {
                return key;
            }
            temp = temp->next;
        }
        return -1;
    }
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->dat << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deletenode(node *&head, int val)
    {

        node *temp = head;
        while (temp->next->dat != val)
        {
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
    void deletefirstnode(node *&head)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
    }
    node *revitll(node *&head)
    {
        node *currptr = head;
        node *prevptr = NULL;
        node *nextptr;
        while (currptr != NULL)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;

            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    node *revrecll(node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *newhead = revrecll(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    node *revkll(node *&head, int k)
    {
        int cunt = 0;
        node *prevptr = NULL;
        node *nextptr = NULL;
        node *currptr = head;
        while (currptr != NULL && cunt < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            cunt++;
        }
        if (nextptr != NULL)
        {
            head->next = revkll(nextptr, k);
        }
        return prevptr;
    }
    void makecycle(node *&head, int pos)
    {
        node *startnode;
        node *temp = head;
        int cont = 1;
        while (temp->next != NULL)
        {
            if (cont == pos)
            {
                startnode = temp;
            }
            temp = temp->next;
            cont++;
        }
        temp->next = startnode;
    }
    bool detectcycle(node *&head)
    {
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
    void deletecycle(node *&head)
    {
        node *slow = head;
        node *fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        fast = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
    }
    void insertDoublyAtHead(node *&head, int val)
    {
        node *n = new node(val);
        n->next = head;
        if (head != NULL)
        {
            head->prev = n;
        }
        head = n;
    }
    void insertDoublyAtTail(node *&head, int val)
    {
        node *n = new node(val);
        node *temp = head;

        if (head == NULL)
        {
            insertDoublyAtHead(head, val);
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
    void doublydeleteathead(node *&head)
    {
        node *todelete = head;
        head = head->next;
        head->prev = NULL;
        delete todelete;
    }
    void doublyminedelete(node *&head, int val)
    {
        if (val == 1)
        {
            doublydeleteathead(head);
            return;
        }
        node *temp = head;
        while (temp->next != NULL && temp->next->dat != val)
        {
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next->next != NULL)
        {
            temp->next->next->prev = temp;
        }

        delete todelete;
    }
    int length(node *head)
    {
        int l = 0;
        node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }
    node *kappend(node *&head, int k)
    {
        node *newhead;
        node *newtail;
        node *tail = head;
        int l = length(head);
        int count = 1;
        k = k % l;
        while (tail->next != NULL)
        {
            if (count == l - k)
            {
                newtail = tail;
            }
            if (count == l - k + 1)
            {
                newhead = tail;
            }
            tail = tail->next;
            count++;
        }
        newtail->next = NULL;
        tail->next = head;
        return newhead;
    }
    int checcintersection(node *&head1, node *&head2)
    {
        int l1 = length(head1);
        int l2 = length(head2);
        int d = 0;
        node *ptr1;
        node *ptr2;
        if (l1 > l2)
        {
            d = l1 - l2;
            ptr1 = head1;
            ptr2 = head2;
        }
        else
        {
            d = l2 - l1;
            ptr2 = head1;
            ptr1 = head2;
        }

        while (d)
        {
            ptr1 = ptr1->next;
            if (ptr1 == NULL)
            {
                return -1;
            }
            d--;
        }
        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1 == ptr2)
            {
                return ptr1->dat;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return -1;
    }
    void mekintersect(node *&head1, node *&head2, int pos)
    {
        node *temp1 = head1;
        while (--pos)
        {
            temp1 = temp1->next;
        }
        node *temp2 = head2;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    node *mergell(node *&head1, node *head2)
    {
        node *p1 = head1;
        node *p2 = head2;
        node *bakanode = new node(-1);
        node *p3 = bakanode;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->dat < p2->dat)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while (p1 != NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != NULL)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        return bakanode->next;
    }
    node *mergerecll(node *&head1, node *head2)
    {
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        node *result;
        if (head1->dat < head2->dat)
        {
            result = head1;
            result->next = mergerecll(head1->next, head2);
        }
        else
        {
            result = head2;
            result->next = mergerecll(head1, head2->next);
        }
        return result;
    }
    void insertcircularathead(node *&head, int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            n->next = n;
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }
    void insertcircularattail(node *&head, int val)
    {
        if (val == 1)
        {
            insertcircularathead(head, val);
            return;
        }
        node *n = new node(val);
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    void circulardisplay(node *head)
    {
        node *temp = head;
        do
        {
            cout << temp->dat << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void ciculardeleteathead(node *&head)
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node *todelete = head;
        temp->next = head->next;
        head = head->next;
        delete todelete;
    }
    void circulardeleteattail(node *&head, int pos)
    {
        if (pos == 1)
        {
            ciculardeleteathead(head);
            return;
        }
        node *temp = head;
        int cont = 1;
        while (cont != pos - 1)
        {
            temp = temp->next;
            cont++;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
    void evenafterodd(node *&head)
    {
        node *odd = head;
        node *even = head->next;
        node *evenstart = even;
        while (odd->next != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenstart;
        if (odd->next == NULL)
        {
            even->next = NULL;
        }
    }
};
int main()
{
    node a(7);
    node *head = NULL;
    // node *head2 = NULL;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    // int arr2[] = {2, 3, 6};
    for (int i = 0; i < 7; i++)
    {
        a.insertAtTail(head, arr1[i]);
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     a.insertAtTail(head2, arr2[i]);
    // }
    a.display(head);
    a.evenafterodd(head);
    a.display(head);
    // a.display(head2);
    // node *newhead = a.mergerecll(head1, head2);
    // a.display(newhead);
    // a.insertcircularattail(head, 1);
    // a.insertcircularattail(head, 2);
    // a.insertcircularattail(head, 3);
    // a.insertcircularattail(head, 4);
    // a.insertcircularattail(head, 5);
    // a.insertcircularattail(head, 6);
    // a.circulardisplay(head);
    // a.insertcircularathead(head, 69);
    // a.circulardisplay(head);
    // a.circulardeleteattail(head, 1);
    // a.circulardisplay(head);
    // cout << a.detectcycle(head) << endl;
    // a.insertDoublyAtTail(head2, 9);
    // a.insertDoublyAtTail(head2, 10);
    // a.mekintersect(head1, head2, 5);
    // a.display(head1);
    // a.display(head2);
    // cout << a.checcintersection(head1, head2) << endl;
    // node *newhead = a.kappend(head, 3);
    // a.display(newhead);
    // a.doublyminedelete(head, 6);
    // a.display(head);
    // a.makecycle(head, 4);
    // cout << a.detectcycle(head) << endl;
    // a.deletecycle(head);
    // cout << a.detectcycle(head) << endl;
    // a.display(head);
    // int k = 2;
    // node *newhead = a.revkll(head, k);
    // a.display(newhead);
    // node *newhead = a.revrecll(head);
    // a.display(newhead);
    // if (a.search(head, 2) != -1)
    // {
    //     cout << "element found at " << a.search(head, 2) << " ";
    // }
    // else
    // {
    //     cout << "not";
    // }
    // a.deletefirstnode(head);
    // a.display(head);
}