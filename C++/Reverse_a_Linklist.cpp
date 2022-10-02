#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prevptr=NULL;
    SinglyLinkedListNode* currptr=llist;
    SinglyLinkedListNode* nextptr;
    
    while(currptr!=NULL){
        nextptr=currptr->next;
        
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    
    return prevptr;

}

int main()
{

    SinglyLinkedList* llist = new SinglyLinkedList();
    llist->insert_node(4);
    llist->insert_node(3);
    llist->insert_node(6);
    llist->insert_node(1);
    llist->insert_node(8);
    llist->insert_node(9);
    llist->insert_node(0);
    llist->insert_node(12);
    llist->insert_node(11);
    SinglyLinkedListNode* llist1 = reverse(llist->head);
    
    SinglyLinkedListNode* temp=llist1;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    return 0;
}
