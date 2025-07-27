/*STACK : postfix to infix*/

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for(int i=0;i<exp.length();i++){
            char ch=exp[i];
            
            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
               st.push(string(1, ch));  // Convert char to string
            }
            
            else{
                
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                string new_exp = "(" + op2 + ch + op1 + ")";
                st.push(new_exp);
            }
            
        
        }
        return st.top();
        
        
    }
};