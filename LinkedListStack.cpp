#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>




using namespace std;






class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class StackLinkedList {
private:
    Node* head;  // Head points to the first element
    Node* tail;  // Tail points to the last element

public:
    StackLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string item) {
        Node* newNode = new Node(item);
        if (!head) {
            // If the list is empty, head and tail point to the new node
            head = tail = newNode;
        } else {
            // If the list is not empty, add new node to the end
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Push " << item << " :\n";
        printStack();
    }

    void pop() {
        if (!head) {
            // If the stack is empty
            cout << "Stack Underflow\n";
            return;
        } 
        
        if (head == tail) {
            // If there's only one element in the stack
            cout << "Pop " << tail->data << ": " << tail->data << " is deleted!\n";
            delete tail;
            head = tail = nullptr;  // Now the stack is empty
        } else {
            // More than one element
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;  // Traverse to the second last node
            }
            cout << "Pop " << tail->data << ": " << tail->data << " is deleted!\n";
            delete tail;  // Delete the last node
            tail = temp;  // Update the tail to the second last node
            tail->next = nullptr;  // Set the new tail's next to null
        }
        printStack();
    }

    void printStack() {
        cout << "Current List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " , ";
            temp = temp->next;
        }
        cout << " , \n";
    }

    void printBaseToTop() {
        cout << "From base to Top:\nCurrent List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " , ";
            temp = temp->next;
        }
        cout << " , \n";
    }

    void printTopToBase() {
        cout << "From Top to base:\nCurrent List: ";
        printReverse(head);
        cout << " , \n";
    }

    void printReverse(Node* node) {
        if (!node) return;
        printReverse(node->next);
        cout << node->data;
        if (node != head) cout << " , ";
    }
};

int main() {
    StackLinkedList stack;

    stack.push("TP01");
    stack.push("TP02");
    stack.push("TP03");
    stack.pop();  // Pop TP03
    stack.pop();  // Pop TP02
    stack.push("TP04");
    stack.push("TP05");
    stack.push("TP03");
    stack.pop();  // Pop TP03
    stack.pop();  // Pop TP05
    stack.push("TP02");

    stack.printBaseToTop();  // From base to top
    stack.printTopToBase();  // From top to base

    return 0;
}




