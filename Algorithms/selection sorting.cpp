#include <iostream>
using namespace std;


void display(int arr[],int size){
    cout<<"sorted array: ";
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
void selection_Sort(int arr[],int size){
    for (int i=0;i<size-1;i++){
        int minJ=i;
        int minX = arr[i];
        for (int j=i+1;j<size;j++){
            if (arr[j]<minX){
                minJ=j;
                minX=arr[j];
            }
        }
        arr[minJ]=arr[i];
        arr[i]=minX;
    }
    display(arr,size);
    
}

void insertion_Sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    display(arr,size);
}

int main(){
    int size;
    cout<<"enter the size of the array: ";
    cin>>size;
    int list[size]={};
    int i;
    for (i=0;i<size;i++){
        cout<<"Enter the ["<<i+1<<"] element in the array: ";
        cin>>list[i];
    }
    cout<<"Selection ";
    selection_Sort(list,size);
    cout<<"\nInsertion ";
    insertion_Sort(list,size);
    return 0;
}