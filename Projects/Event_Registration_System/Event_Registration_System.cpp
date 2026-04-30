#include <iostream>
#include <string>
using namespace std;

// defined a node for the linked list to store participant registration details.
struct Node {
    int participant_id;     // participant id
    string name;           // Participants full name
    string status;         // Registration status
    Node* next;            // Pointer to the next node in the list
};

Node* head = NULL;  // (head) start of the registration list


// Validate that the status entered by the user is allowed.
bool isValidStatus(const string& s) {
    return (s == "Confirmed" || s == "Pending" || s == "Canceled" || s == "c" || s == "C" || s == "p" || s == "P" || s == "x" || s == "X");
}

// Normalize the status input to the full string format.
string normalizeStatus(const string& s) {
    if (s == "c" || s == "C") return "Confirmed";
    if (s == "p" || s == "P") return "Pending";
    if (s == "x" || s == "X") return "Canceled";
    return s; // Return as-is if already full or invalid
}

// Search the list for an existing participant id.
bool idExists(int id) {
    Node* current = head; // start from the head of the list
    while (current != NULL) {      // traverse the list until the end
        if (current->participant_id == id) {   // if a matching id is found, return true
            return true;
        }
        current = current->next;   // move to the next node
    }
    return false;   // if the end of the list is reached without finding the id, return false
}

// registration of participants
// add a new participant to the registration list.
void registerParticipant() {
    int id;
    string name, status;
    
    cout << "\nEnter Participant ID: ";
    cin >> id;
    // Check if the entered ID already exists in the list to prevent duplicates.
    if (idExists(id)) {
        cout << "[Error: ID [" << id << "] already exists! Please choose a different id.\n";
        return;
    }
    
    cin.ignore();  // Clear the input buffer before reading the name.
    cout << "Enter Name: ";  
    getline(cin, name);   // Read the full name including spaces.
    
    cout << "Enter Status (C/c for Confirmed, P/p for Pending, X/x for Canceled): ";
    cin >> status;

    // Validate the status input before proceeding.
    if (!isValidStatus(status)) {
        cout << "[Error] Invalid status! Use C/c, P/p, or X/x.\n";
        return;
    }
    
    // Create a new node and insert it at the front of the list.
    Node* newNode = new Node;  
    newNode->participant_id = id;  
    newNode->name = name;  
    newNode->status = normalizeStatus(status);
    newNode->next = head;
    head = newNode;
    
    cout << "Success: [" << name << "] has been registered successfully.\n";
}

// update status
// Change the registration status for an existing participant.
void updateStatus() {
    int id;
    string newStatus;
    
    cout << "\nEnter ID to update: ";
    cin >> id;
    
    cout << "Enter New Status: ";
    cin >> newStatus;
    // validate the new status input before attempting to update.
    if (!isValidStatus(newStatus)) {
        cout << "[Error] Invalid status! Use C/c, P/p, or X/x.\n";
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        if (current->participant_id == id) {
            current->status = normalizeStatus(newStatus);
            cout << "[Updated] Participant id [" << id << "] status changed to [" << normalizeStatus(newStatus) << "].\n";
            return;
        }
        current = current->next;
    }
    cout << "[Error] Participant id [" << id << "] not found.\n";
}

// Remove Canceled
// delete all registrations that are marked as Canceled.
void removeCanceled() {
    int count = 0;
    
    // Remove canceled nodes from the start of the list.
    while (head != NULL && head->status == "Canceled") {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    
    // Remove canceled nodes from the rest of the list.
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->status == "Canceled") {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }
    
    cout << "[Removed] " << count << " canceled registration removed.\n";
}

// display Confirmed
// Print only the participants whose registration status is Confirmed.
void displayConfirmed() {
    cout << "\n--- CONFIRMED PARTICIPANTS ---\n";
    Node* current = head;
    bool found = false;
    
    while (current != NULL) {
        if (current->status == "Confirmed") {
            cout << "ID: " << current->participant_id << " | Name: " << current->name << "\n";
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "No confirmed participants found.\n";
    }
    cout << "------------------------------\n";
}

// display All
// Show every participant record in the list including their status.
void displayAll() {
    cout << "\n--- ALL PARTICIPANTS ---\n";
    Node* current = head;
    
    if (current == NULL) {
        cout << "The registration list is empty.\n";
    } else {
        while (current != NULL) {
            cout << "ID: " << current->participant_id << " | Name: " << current->name  << " | Status: " << current->status << "\n";
            current = current->next;
        }
    }
    cout << "------------------------\n";
}

// Cleanup memory
// Free all allocated nodes in the list before the program exits.
void cleanup() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "System Memory cleaned up.\n";
}

// Start the program and show the user menu until they choose to exit.
int main() {
    int choice;
    
    do {
        cout << "\n========== EVENT REGISTRATION SYSTEM ==========\n";
        cout << "1. Register Participant\n";
        cout << "2. Update Registration Status\n";
        cout << "3. Remove Canceled Registrations\n";
        cout << "4. Display Confirmed Participants\n";
        cout << "5. Display All Participants\n";
        cout << "0. Exit\n";
        cout << "=============================================\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: registerParticipant(); break;
            case 2: updateStatus(); break;
            case 3: removeCanceled(); break;
            case 4: displayConfirmed(); break;
            case 5: displayAll(); break;
            case 0: 
                cout << "\nexiting...\n";
                cleanup();
                break;
            default:
                cout << "Error Invalid choice!\n";
        }
    } while (choice != 0);
    
    return 0;
}