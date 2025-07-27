/*STACK IMPLIMENTATION USING LINKED LIST*/



#include<bits/stdc++.h>
using namespace std;

class Node{
 public:
 int data;
 Node* next;
 
 public:
 Node(int val) {
        data = val;
        next = NULL;
 }
    
};

//class
class Stack{
    
    private:     //ENCAPSULATION
    //members
    Node* top; 
    
    public:
    
    Stack(){
        top=NULL;
    }
    
    
    
  //methods or functions
    
    void push(int x){
       Node* newNode=new Node(x);
       newNode->next=top;
       top=newNode;
       
    }
    
    int pop(){
        if(top==NULL){
            return -1;
        }
        else{
            int popped=top->data;
            Node* temp=top;
            top=top->next;
            delete temp;
            return popped;
        }
        
    }
    
    int topIndex(){
        if(top==NULL){
            return -1;
        }
        else{
            return top->data;
        }
    }
    
    int isEmpty(){
        if(top==NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    
   

   
    
};


int main(){
    
    
    Stack st;
   st.push(2);
   st.push(3);
    st.push(4);
    st.push(7);
    st.push(8);
    st.push(9);
    cout<<st.topIndex()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.topIndex()<<endl;
    
    return 0;
    
}



