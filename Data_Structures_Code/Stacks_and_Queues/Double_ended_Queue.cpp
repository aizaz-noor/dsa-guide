#include <iostream>
using namespace std;
class Double_Ended_Queue{
    public:
        int rear;
        int front;
        int size = 100;
        int que[100];
Double_Ended_Queue(){
    front = -1;
    rear = -1;
}
void insertion(int value){
    if (front==0 && rear == size-1|| front==rear+1){
        cout<<"Overflow";
        return;
    }

        else if(front==-1 && rear == -1){
            front++;
            rear++;
            
        }
        else if(front == 0){
            front=size -1;
            
        } 
        else {
            front--;
            
        }
        que[front]=value;
        cout<<que[front]<<"--inserted.";
    }
void deletion(){
    if(front==-1 && rear==-1){
        cout<<"Underflow";
        return;
    }
    cout<<"the deleted value:"<<que[rear];
    if(rear == front){
        rear = -1;
        front =-1;
    }
    else if(rear == 0){
        rear= size -1;
    }
    else {
        rear--;
    }

}
void display(){
   if (front == -1) {
            cout << "The queue is empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << que[i] << " ";
            if (i == rear) break; 
            
            if (i == size - 1) i = 0; 
            else i++;
        }
        cout << endl;
    }
};
int main(){
    Double_Ended_Queue deq;
    int ch;
    int value;
    do{
        cout<<"\n1. Insertion\n2. Deletion\n3. Display";
        cout<<"\nEnter the Choice:";
        cin>>ch;
    switch(ch){
        case 1 :
        cout<<"Enter the value you wnated to insert:";
        cin>>value;
        deq.insertion(value);
        break;
        case 2 :
        deq.deletion();
        break;
        case 3 :
        cout<<"Display:";
        deq.display();
        break;
        case 4:
        break;
        default:
        cout<<"invalid choice.";
    }
} while(ch != 4);
    return 0;
}
