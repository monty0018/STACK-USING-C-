/**STACK IMPLEMENTATION USING QUEUE**/

class Stack {
	// Define the data members.
        queue<int>q;

   public:
    Stack() {
        // Implement the Constructor.

    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
    return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element) {
        // Implement the push() function.
    

         q.push(element);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }

    }

    int pop() {
        // Implement the pop() function.
       if(q.empty()){
           return -1;
       }
       
        int x=q.front();
        q.pop();
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q.empty()){
            return -1;
        }

        return q.front();
    }
};