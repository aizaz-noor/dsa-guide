#include <iostream>
using namespace std;

//global variables for stack
int stack[7];
int top = -1;
int stackSize = 7;

int parent(int i) {
        return (i - 1) / 2;
    }

int getLeftChild(int i) {
        return 2 * i + 1;
    }
int getRightChild(int i) {
        return 2 * i + 2;
    }

void swapValues(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

void shiftDown(int arr[], int Maxheapsize, int index) {
    int largest = index;
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);


    if (leftChild < Maxheapsize && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < Maxheapsize && arr[rightChild] > arr[largest])
        largest = rightChild;
    if (largest != index) {
        swapValues(arr[index], arr[largest]);
        shiftDown(arr, Maxheapsize, largest);
    }
}

void shiftUp(int arr[], int index) {
    int parentIndex = parent(index);
    
    while (parentIndex >= 0 && arr[parentIndex] < arr[index]) {
        swapValues(arr[index], arr[parentIndex]);
        index = parent(index);
        parentIndex = parent(index);
    }
}
void insertNode(int arr[], int& n, int val) {
    n = n + 1;           
    arr[n - 1] = val;   
    shiftUp(arr, n - 1); 
}

void deleteRoot(int arr[], int& n) {
   if (n <= 0) {
        cout << "Heap is empty!" << endl;
        return;
    }
    

    arr[0] = arr[n - 1];
    n = n - 1;          
    shiftDown(arr, n, 0);
} 
void push(int x){
    if (top == stackSize - 1){
        cout<<"overflow";
    }
    top++;
    stack[top]=x;
}
void printstack(){
    if (top == -1){
        cout<<"stack is empty";
    }
    cout<<"ascending: ";
    for(int i=top;i>-1;i--){
        cout<<stack[i]<<" ";
    }
}
void heapsorting(int arr[],int &n){
if (n <= 0) {
        cout << "heap is empty!" << endl;
    }
    for(int i=0;i<stackSize;i++){
    int temp = arr[0];
    arr[0] = arr[n - 1];
    n = n - 1;          
    shiftDown(arr, n, 0);
    push(temp);
    }
    printstack();

}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        shiftDown(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[7] = { 5, 3, 9, 7, 8, 3, 10 };
    int n = 7; 

    cout << "original Array: ";
    printArray(arr, n);
    buildMaxHeap(arr, n);
    cout << "max Heap built: ";
    printArray(arr, n);
    cout << "\ninserting 15" << endl;
    insertNode(arr, n, 15);
    cout << "after Insertion:  ";
    printArray(arr, n);
    cout << "\ndeleting root " << endl;
    deleteRoot(arr, n);
    cout << "after Deletion:   ";
    printArray(arr, n);
    cout<<"===heap-Sort==="<<endl;
    heapsorting(arr,n);
    return 0;
}