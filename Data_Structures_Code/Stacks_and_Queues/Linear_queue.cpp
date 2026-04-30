#include <iostream>
using namespace std;
class qeue{
    private:
    int rear;
    int front;
    int size = 100;
    int que[100];
    public:
    qeue(){
        rear = -1;
        front = -1; 
    }
    void insertion(int x){
        if(rear == size -1){

            cout<<"the que is Overflowed";
            return;
        }
        if (rear == -1 && front == -1){
            front = 0;
            rear = 0; 
        }
        else{
            rear++;
        }
        que[rear] = x;
}
    void deletion(){
        if (front == -1 || rear == -1){
            cout<<"the que is Underflowed";
            return;
        }
        int temp = que[front];
        que[front] = 0;
        front++;
    }
    void display(){
        if (front == -1 || rear == -1){
            cout<<"the que is empty";
            return;
        }
        for (int i = front; i <= rear; i++){
            cout<<que[i]<<" ";
        }
        cout<<endl;
}
};
int main(){
    qeue q;
    int ch;
    do{
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            int val;
            cout<<"Enter value to insert: ";
            cin>>val;
            q.insertion(val);
            break;
            case 2:
            cout<<"Deleting front element..."<<endl;
            q.deletion();
            break;
            case 3:
            q.display();
            break;
            case 4:
            cout<<"Exiting..."<<endl;
            break;
            default:
            cout<<"Invalid choice, try again."<<endl;
    }
}while (ch != 4);
    return 0;
}   
