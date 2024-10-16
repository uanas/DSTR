#include <iostream>
using namespace std;

#define MAX 100

class StackArray {
private:
    string arr[MAX];
    int top;
    
public:
    StackArray() {
        top = -1;
    }
    
    void push(string item) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = item;
            cout << "Push " << item << " :\n";
            printStack();
        }
    }
    
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
        } else {
            cout << "Pop " << arr[top] << ": " << arr[top] << " is deleted!\n";
            top--;
            printStack();
        }
    }
    
    void printStack() {
        cout << "Current List: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
            if (i < top) cout << " , ";
        }
        cout << " , \n";
    }
    
    void printBaseToTop() {
        cout << "From base to Top:\nCurrent List: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
            if (i < top) cout << " , ";
        }
        cout << " , \n";
    }

    void printTopToBase() {
        cout << "From Top to base:\nCurrent List: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " , ";
        }
        cout << " , \n";
    }
};

int main() {
    StackArray stack;

    stack.push("TP01");
    stack.push("TP02");
    stack.push("TP03");
    stack.pop();
    stack.pop();
    stack.push("TP04");
    stack.push("TP05");
    stack.push("TP03");
    stack.pop();
    stack.pop();
    stack.push("TP02");
    
    stack.printBaseToTop();
    stack.printTopToBase();

    return 0;
}
