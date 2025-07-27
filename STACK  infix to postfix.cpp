/*STACK : infix to postfix*/

class Solution {
public:
    int priority(char op) {
        switch(op) {
            case '^': return 3;
            case '*':
            case '/': return 2;
            case '+':
            case '-': return 1;
            default: return 0; // For '('
        }
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If operand, add to output
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                ans += c;
            }
            // If '(', push to stack
            else if (c == '(') {
                st.push(c);
            }
            // If ')', pop and output until '('
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Remove '(' from stack
            }
            // If operator, handle precedence
            else {
                while (!st.empty() && priority(c) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};