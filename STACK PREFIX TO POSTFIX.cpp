/**STACK PREFIX TO POSTFIX **/


class Solution {
  public:
    string preToPost(string pre_exp) {
         stack<string>st;
        
        for(int i=pre_exp.length()-1;i>=0;i--){
            
            char ch=pre_exp[i];
            
            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
               st.push(string(1, ch));  // Convert char to string
            }
            
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string expr=t1+t2+ch;
                
                st.push(expr);
            
            }
            
            
            
            
        }
        
        return st.top();
        
        
        
    }
};