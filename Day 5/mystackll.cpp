#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* head;
    Node* tail;
    int maxSize;
    int currSize;
    
    Stack(int size){
        this->maxSize = size;
        currSize = 0;
        head = NULL;
        tail = NULL;
    }
    
    void push(int value){
        if(currSize == maxSize){ 
            cout<<"Stack is Full"<<endl;
            return;
        }
        
        Node* temp = new Node(value);
        if(currSize == 0){
            tail = temp;
            head = tail;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        currSize++;
    }
    
    void pop(){
        if(currSize == 0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        
        if(currSize == 1){
            delete head; // Free the memory
            head = tail = NULL; // Set pointers to NULL
            currSize = 0;
        }
        else{
            Node* temp = head;
            // Iterate to find the node BEFORE the tail
            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail; // Delete the current tail
            tail = temp; // Update tail to the previous node
            tail->next = NULL; // Remove link to deleted node
            currSize--;
        }
    }
    
    bool empty(){
        return currSize == 0;
    }
    
    int top(){
        if(currSize == 0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return tail->data;
    }
};

int main(){
    Stack s(100);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl; // 40
    
    s.pop(); // Removes 40
    cout<<s.top()<<endl; // 30
    
    s.pop(); // Removes 30
    cout<<s.top()<<endl; // 20
    
    s.pop(); // Removes 20
    cout<<s.top()<<endl; // 10
    
    s.pop(); // Removes 10 (Stack now empty)
    cout<<s.top()<<endl; // Stack is empty, -1
    
    s.pop(); // Stack is empty msg
    cout<<s.top()<<endl; // Stack is empty, -1
    
    cout<<s.empty()<<endl; // 1 (True)
    
    s.push(10); 
    cout<<s.top()<<endl; // 10
    
    return 0;
}