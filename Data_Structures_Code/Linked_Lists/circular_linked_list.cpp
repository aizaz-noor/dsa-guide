#include <iostream>
using namespace std;

class Node {
public:
    int data;    
    Node* next=NULL;
};

Node* head = NULL; 

void insertion_at_start(int X) {
    Node* p ;
    if (head == NULL) {
        p = new Node;
        p->data = X;
        p->next = head;
        head = p;
    } else {
        Node* q = head;
        while (q->next != head) {
            q = q->next;
        }
        p = new Node;
        p->data = X;
        p->next = head;
        q->next = p;
        head = p; 
    }
}

void insertion_at_end(int X) {
    if (head == NULL) {
        Node* p = new Node;
        p->data = X;
        head = p;
        p->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        Node* p = new Node;
        p->data = X;
        p->next = head;
        tail->next = p;
    }
}

void deletion_at_start() {
    if (head == NULL) {
        cout << "the list is empty" << endl;
        return;
    }
    
    Node* temp = head;
    if (temp->next == head) {
        delete temp; 
        head = NULL;
    } else {
        Node* q = head;
        while (q->next != head) {
            q = q->next;
        }
        head = head->next; 
        q->next = head;    
        delete q;       
    }
}

void deletion_at_last() {
    if (head == NULL) {
        cout << "the list is empty" << endl;
        return;
    }

    if (head->next == head) {
        delete head; 
        head = NULL;
    } else {
        Node* p = head;
        Node* q = NULL;
        while (p->next != head) {
            q = p;
            p = p->next;
        }
        q->next = head; 
        delete p;       
    }
}


void display() {
    if (list == NULL) {
        cout << "the list is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
}
int main(){
    int choice, data;
    do {
    cout << "\n1. Insertion at start" << endl;
    cout << "2. Insertion at end" << endl;
    cout << "3. Deletion at start" << endl;
    cout << "4. Deletion at end" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at start: ";
                cin >> data;
                insertion_at_start(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                insertion_at_end(data);
                break;
            case 3:
                deletion_at_start();
                break;
            case 4:
                deletion_at_last();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}