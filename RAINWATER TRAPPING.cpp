/*RAINWATER TRAPPING*/

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left=0;
        int right=arr.size()-1;
        
        int left_max=0;
        int right_max=0;
        
        int result=0;
        
        while(left<right){
            if(arr[left]<arr[right]){
                if(arr[left]>=left_max){
                    left_max=arr[left];
                }
                else{
                    result+=left_max-arr[left];
                }
                left++;
                
            }
            else{
                if(arr[right]>=right_max){
                    right_max=arr[right];
                }
                else{
                    result+=right_max-arr[right];
                }
                right--;
                
            }
            
            
        }
        return result;
        
    }
};