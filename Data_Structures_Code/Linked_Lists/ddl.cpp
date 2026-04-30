#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = NULL;
    Node* prev = NULL;
};
Node* head = NULL;
void insertion_at_start(int data){
      Node *p =new Node();
        p->data=data;
    if(head == NULL){
        head = p;
    }
    else{
      p->next=head;
        head->prev=p;
        head=p;
}
}
void insertion_at_end(int data){
     Node*z = new Node();
        z->data=data;
    if (head == NULL){
        head=z;
        return;

    }
    else{
    Node *q = head;
        while (q->next!=NULL){
            q=q->next;
        }
        z->prev=q;
        q->next=z;
        z->next=NULL:
}
}


