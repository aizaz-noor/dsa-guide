#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = NULL;
};
Node* head = NULL;

void insert_at_start(int data){
    Node* p = new Node();
    p -> data = data;
    if(head == NULL){
    head = p;
}
else{
    p -> next = head;
    head = p;
}
}
void insertion_at_specific(int pos,int data){
    if (pos == 1){
        insert_at_start(data);
        return ;
    }
    else{
        Node* newnode = new Node();
        newnode->data = data;
        Node* curr = head;
        for(int i=1;i< pos-1 && curr != NULL;i++){
            curr=curr->next;
        }
        newnode->next= curr->next;
        curr->next=newnode;
        cout<<data<<"-data inserted at "<<pos;
    }
}
void insertion_at_end(int data){

    Node* p =new Node();
    p->data=data;
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;

    
}
void deletion_at_start(){
    if(head == NULL){
        cout<<"list is empty";
        return;
    }
    Node* p = head;
    head = head->next;
    delete p;
}
void deletion_at_specific_point(int pos){
    if (head == NULL){  
        return;
    }
    if (pos == 1){
        deletion_at_start();
    }
     Node* curr = head;
    for(int i=1; i < pos-1 && curr != NULL; i++){
        curr=curr->next;
    }
    if(curr->next!=NULL)
    cout<<"[position not found.]";
    else{
    Node* toDelete = curr->next;
        int val = toDelete->data;
        curr->next = toDelete->next; // Bypass the node
        delete toDelete;
    cout<<pos<<"-pos and deleted value:"<<val;
}
}
void delete_at_end(){
    if (head == NULL){
        cout<<"empty list.";
    }
    if (head->next == NULL) {
        delete head;
        return;
    }
    Node* temp = head;
    while (temp->next->next!= NULL){
        temp=temp->next;
    }
    int val= temp->next->data;
    delete temp->next;
    temp->next=NULL;
    cout<<"deleted value is:"<<val;
}

void display(){
    Node* temp = head;
    if (temp == NULL){
            cout<<"list is empty";
            return;
        }
    while (temp != NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<"->"; 
        }
        temp =temp->next;
    }
    cout<<endl;
}
int main(){
    int data;
    int choice;
    int pos;
    do
    {
    cout<<"chose the option: \n1.insert at start \n2. to display.\n3.at specific point.\n4.insertion at end.\n5.deletion_at_start.\n6.deletion_at_end.\n7. deletion at specific. \n";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"\nenter the value you wanted to enter?\n";
    cin>> data;
        insert_at_start(data);
        cout<<data<<"-inserted.\n";
    
    break;
    case 2:
    display();
    break;
    case 3 :
    cout<<"enter the pos where wanted to insert: "; 
    cin>>pos;
    cout<<"enter the value you wanted to enter?\n";
    cin>> data; 
    insertion_at_specific(pos,data);
    break;
    case 4:
      cout<<"\nenter the value you wanted to enter?\n";
    cin>> data;
    insertion_at_end(data);
    break;
    case 5:
    deletion_at_start();
    break;
    case 6:
    delete_at_end();
    break;
    case 7:
    cout<<"enter the pos where wanted to insert: "; 
    cin>>pos;
    deletion_at_specific_point(pos);
    break;
    default:
    cout<<"invalid value.";

    }
 } while (choice!=8);
    
}

