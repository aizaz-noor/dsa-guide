#include <iostream>
using namespace std;

class CircularQueue{
    private:
        int rear;
        int front;
        int size = 5;
        int que[5];
    public:
        CircularQueue(){
            rear = -1;
            front = -1; 
        }
        void insertion(int x){
            if(front == 0 && rear == size - 1 || front == rear + 1){
                cout<<"the que is Overflowed";
                return;
            }
            else if (rear == -1 && front == -1){
                front = 0;
                rear = 0;    
            }
            else if(rear == size - 1 && front != 0){
                rear = 0;
            }
            else{
                rear++;
        }
        que[rear] = x;
    }
        void deletion(){
            if (front == -1 && rear == -1){
                cout<<"the que is Underflowed";
                return;
            }
            cout<<"the deleted element is: "<<que[front]<<endl;
            if (front == rear){
                int temp = que[front];
                que[front] = 0;
                front = -1;
                rear = -1;
            }
            else if (front == size - 1){
                int temp = que[front];
                que[front] = 0;
                front = 0;
            }
            else{
                int temp = que[front];
                que[front] = 0;
                front++;
               
            }
        }
        void display(){
            if (front == -1 || rear == -1){
                cout<<"the que is empty";
                return;
            }
            int i = front;
            while (i != rear){
                cout<<que[i]<<" ";
                ++i;
            }
            cout<<que[rear]<<endl; 
        }
};
int main(){
    CircularQueue cq;
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
        cq.insertion(value);
        cout<<value<<" --inserted\n";
        break;
        case 2 :
        cq.deletion();
        break;
        case 3 :
        cout<<"Display:";
        cq.display();
        break;
        case 4:
        break;
        default:
        cout<<"invalid choice.";
    }
} while(ch != 4);
    return 0;
}


