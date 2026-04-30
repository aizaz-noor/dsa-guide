#include<iostream>
using namespace std;

void maxHeap(int arr[], int root, int i){
    int largest = i;
    int left    = ( i * 2 ) + 1;
    int right    = ( i * 2 ) + 2;
    if ( left < root  && arr[left] > arr[largest] )
        largest = left;
    if ( right < root && arr[right] > arr[largest] )
        largest = right;
    if ( largest != i ) {
        swap(arr[i], arr[largest]);
        maxHeap(arr, root, largest);
    }
}

void insert(int arr[], int &size, int key, int capacity) {
    if (size >= capacity) {
        cout << "Overflow: Heap is full!" << endl;
        return;
    }
    arr[size] = key;   
    size++;            
    maxHeapifyUp(arr, size - 1); 
}
void maxHeapifyUp(int arr[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}
int deleteRoot(int arr[], int &size) {
    if (size == 0)
        return -1;

    int deleted = arr[0];
    arr[0] = arr[size - 1];
    size--;
    maxHeap(arr, size, 0);
    return deleted;
}


int main() {
    int arr[] = {5,3,9,7,8,3,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);
    
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
   int currentSize = n;
    int removed = deleteRoot(arr, currentSize);
    cout << "Deleted root: " << removed << endl;

    cout << "Heap after deletion: ";
    for (int i = 0; i < currentSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}