/**STACK POSTFIX TO PREFIX**/


class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        
        for(int i=0;i<post_exp.length();i++){
            
            char ch=post_exp[i];
            
            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
               st.push(string(1, ch));  // Convert char to string
            }
            
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string expr=ch+t2+t1;
                
                st.push(expr);
            
            }
            
            
            
            
        }
        
        return st.top();
    }
};