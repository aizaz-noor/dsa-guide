#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* start;

public:
    LinkedList() {
        start = NULL;
    }

    // list ke end pe add karna
    void add(int val) {
        Node* temp = new Node;
        temp->value = val;
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            Node* t = start;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = temp;
        }
    }

    // adjacent sum check
    void findPair(int target) {
        Node* first = start;

        while (first && first->next) {
            Node* second = first->next;

            if ((first->value + second->value) == target) {
                cout << "Match mil gaya: "
                     << first->value << " & "
                     << second->value << endl;
                return;
            }

            first = first->next;
        }

        cout << "Koi matching pair nahi mila." << endl;
    }
};

int main() {
    LinkedList l;

    l.add(10);
    l.add(13);
    l.add(15);
    l.add(3);
    l.add(7);

    int target = 17;

    l.findPair(target);

    return 0;
}