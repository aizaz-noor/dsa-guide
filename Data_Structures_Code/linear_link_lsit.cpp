#include<iostream>
using namespace std;
class Node {
public:
    int data;    
    Node* next;
};
Node* list = NULL;
void insertion_at_start(Node* p,int data)
{
    if (list == NULL){
        p=new Node;
        p->data=data;
        p->next = NULL;
        list=p;
    }
    else{
        p=new Node;
        p->data=data;
        p->next=list;
        list=p;
    }
}
void insertion_at_end(Node* p,int data){
    if (list == NULL){
        p=new Node;
        p->data=data;
        p->next = NULL;
        list=p;
    }
    else{
        Node* q;
        q=list;
        while(q->next!=NULL){
            q=q->next;
        }
        p->next = new Node;
        p->next->data=data;
        q->next = p;
    }
}
void insertion_at_specifc_point(Node* p,int data,int pos){
    Node* q;
    p=list;
    while(p != NULL){
        if(p->data == pos){
            q=new Node;
            q->data=data;
            q->next=p->next;
            p->next=q;
        }
        p=p->next;
    }
}
void display(){
    Node* q = list;
    while (q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
}
}
int main(){
    char ch;
    int input,position;
    do{ 
   cout<<"\n1. Insertion at start"<<endl;
   cout<<"2. Insertion at end"<<endl;
   cout<<"3. Insertion at specific point"<<endl;
   cout<<"4. Display"<<endl;
   cout<<"5. Exit"<<endl;
        cout<<"Enter the Choice:";
        cin>>ch;
        switch (ch)
        {
        case '1':
            cout<<"Enter the data to insert at start: ";
            cin>>input;
            insertion_at_start(list,input);
            cout<<"inserted."<<endl;
            break;
        case '2':
            cout<<"Enter the data to insert at end: ";
            cin>>input;
            insertion_at_end(list,input);
            cout<<"inserted."<<endl;
            break;
        case '3':
            cout<<"Enter the data to insert: ";
            cin>>input;
            cout<<"Enter the position after which to insert: ";
            cin>>position;
            insertion_at_specifc_point(list,input,position);
            cout<<"inserted at position: "<<position<<endl;
            break;
        case '4':
            cout<<"The linked list is: ";
            display();
            break;
        case '5':
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
        }
}while(ch != '6');
}
