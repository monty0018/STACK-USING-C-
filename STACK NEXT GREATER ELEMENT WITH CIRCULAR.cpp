/*STACK NEXT GREATER ELEMENT WITH CIRCULAR*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
     
        int n=arr.size();
        
        vector<int> nge(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=arr[i%n]){
                st.pop();
            }
            
            nge[i]=st.empty()?-1:st.top();
            
            st.push(arr[i%n]);
        }
        
        return nge;
        
        
    }
};