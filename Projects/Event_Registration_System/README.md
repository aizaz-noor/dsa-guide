# Event Registration System

A command-line tool built in C++ that manages event participants using a singly linked list. This project shows how to use basic data structures and memory management in C++.

## Features

* **Register Participants:** Add new users to the list. The system checks for duplicate IDs and formats the status (Confirmed, Pending, Canceled).
* **Update Status:** Change the registration status of any existing participant.
* **Remove Canceled:** Walk through the linked list to find and delete all canceled registrations.
* **View Lists:** Show all registered participants or filter to see only confirmed ones.
* **Memory Management:** Clears all allocated nodes from memory before the program exits.

## Technical Details

* **Language:** C++
* **Data Structure:** Singly Linked List (`struct Node`)
* **Concepts Used:** Pointers, dynamic memory allocation (`new` / `delete`), list traversal, and input validation.

## How to Run

1. Compile the code using a C++ compiler:
   ```bash
   g++ Event_Registration_System.cpp -o event_system
   ```
2. Run the executable:
   * **Windows:** `.\event_system.exe`
   * **Linux/macOS:** `./event_system`
```
