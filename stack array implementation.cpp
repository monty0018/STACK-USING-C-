/*stack array implementation*/

#include <iostream>
using namespace std;

#define MAX 1000  // Maximum size of the stack

class Stack {
	int arr[MAX];  // Array to store elements
	int top;       // Index of the top element

public:
	Stack() {
		top = -1;    // Constructor initializes stack as empty
	}
// Add element to the stack
	bool push(int x) {
		if (top >= MAX - 1) {
			cout << "Stack Overflow\n";
			return false;
		} else {
			arr[++top] = x;
			return true;
		}
	}
// Remove element from the stack
	int pop() {
		if (top < 0) {
			cout << "Stack Underflow\n";
			return -1;
		} else {
			return arr[top--];
		}
	}
// Return top element

	int peek() {
		if (top < 0) {
			cout << "Stack is Empty\n";
			return -1;
		} else {
			return arr[top];
		}
	}
// Check if stack is empty
	bool isEmpty() {
		return (top < 0);
	}
};



// Driver Code
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << "Top element is: " << s.peek() << endl;
	cout << "Elements popped from stack:\n";
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << "Is stack empty? " << s.isEmpty() << endl;

	return 0;
}
