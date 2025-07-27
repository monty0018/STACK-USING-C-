/**STACK MINIMUM STACK**/

/*Intuition Behind the Approach
The goal is to track the minimum element in the stack at all times without using extra space (like a separate stack for minimums). Instead, we modify the way we push elements to encode information about the minimum.

Key Idea:
When pushing a new element x that is smaller than the current minimum (mini):

Instead of pushing x directly, we push 2 * x - mini (an encoded value).

We then update mini = x.

When popping an element, if the popped value is smaller than mini, it means it was an encoded value, so we decode it to recover the previous minimum.

Step-by-Step Explanation
1. Initialization (Solution())
mini is initialized to INT_MAX (a very large value) to handle the first push correctly.

2. push(int x) Operation
If the stack is empty:

mini = x (since x is the only element, it's the minimum).

Push x onto the stack.

If x >= mini:

Push x directly (no encoding needed).

If x < mini:

Push 2 * x - mini (this encodes information about the previous minimum).

Update mini = x (since x is the new minimum).

Why 2 * x - mini?

This formula ensures that when we later pop this value, we can recover the previous minimum using mini = 2 * mini - x.

3. pop() Operation
If the stack is empty: Do nothing.

Otherwise:

Pop the top element x.

If x < mini: This means x was an encoded value, so we decode it to get the previous minimum:

mini = 2 * mini - x (reverses the encoding).

If x >= mini: No special action is needed (just pop).

4. peek() Operation
If the stack is empty: Return -1.

Otherwise:

Get the top element x.

If x >= mini: Return x (it's a normal value).

If x < mini: Return mini (since x was an encoded value representing the minimum).

5. getMin() Operation
If the stack is empty: Return -1.

Otherwise: Return mini (which always holds the current minimum).*/

#include <stack>
#include <climits>  // For INT_MAX
using namespace std;

class Solution {
public:
    stack<int> st;
    int mini;

    Solution() {
        mini = INT_MAX;  // Initialize to a large value
    }

    void push(int x) {
        if (st.empty()) {
            mini = x;
            st.push(x);
        } else {
            if (x >= mini) {
                st.push(x);
            } else {
                st.push(2 * x - mini);  // Encode the value
                mini = x;  // Update mini
            }
        }
    }

    void pop() {
        if (st.empty()) return;  // Handle empty stack

        int x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;  // Decode to get previous mini
        }
    }

    int peek() {
        if (st.empty()) return -1;  // Handle empty stack

        int x = st.top();
        return (x >= mini) ? x : mini;  // Return decoded value if needed
    }

    int getMin() {
        if (st.empty()) return -1;  // Handle empty stack
        return mini;
    }
};