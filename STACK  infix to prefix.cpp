/*STACK : infix to prefix*/

class Solution {
public:
   int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
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
    
    
    
    string infixToPrefix(string s) {
    // Step 1: Reverse the infix expression
    reverse(s.begin(), s.end());
    
    // Step 2: Swap '(' and ')' in the reversed string
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    
    // Step 3: Convert to postfix (which is actually reverse prefix)
    string result = infixToPostfix(s);
    
    // Step 4: Reverse the result to get prefix
    reverse(result.begin(), result.end());
    
    return result;
}
    
    
};