#include <iostream>
#include <string>
using namespace std;

class ParkingLotQueue {
private:
    int rear;
    int front;
    int size = 4; 
    string que[4];

public:
    ParkingLotQueue() {
        rear = -1;
        front = -1;
    }

    void insertion(string gate) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "The queue is Overflowed\n";
            return;
        } else if (rear == -1 && front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        que[rear] = gate;
    }

    string deletion() {
        if (front == -1 && rear == -1) {
            cout << "The queue is Underflowed\n";
            return "";
        }
        
        string gate = que[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return gate;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty";
            return;
        }
        int i = front;
        while (i != rear) {
            cout << que[i] << " ";
            i = (i + 1) % size;
        }
        cout << que[rear] << endl;
    }
};

int main() {
    ParkingLotQueue pl;
    pl.insertion("North");
    pl.insertion("East");
    pl.insertion("South");
    pl.insertion("West");

    int cycles;
    cout << "--- Parking Lot Management System ---\n";
    cout << "Enter number of cycles to simulate: "; 
    cin >> cycles;

    for (int i = 1; i <= cycles; i++) {
        cout << "\nCycle " << i << ":" << endl;

        string currentGate = pl.deletion();

        cout << "Vehicle entering from gate: " << currentGate << endl;
        pl.insertion(currentGate);
        
        cout << "Current Queue Order: ";
        pl.display();
    }

    return 0;
}