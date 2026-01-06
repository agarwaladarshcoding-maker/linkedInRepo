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

class Queue{
    public:
    Node* head;
    Node* tail;
    int maxSize;
    int currSize;
    
    Queue(int size){
        this->maxSize = size;
        currSize = 0;
        head = NULL;
        tail = NULL;
    }
    
    void push(int value){
        if(currSize == maxSize){ 
            cout<<"Queue is Full"<<endl;
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
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        if(currSize == 1){
            delete head; // Free the memory
            head = tail = NULL; // Set pointers to NULL
            currSize = 0;
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            
            currSize--;
        }
    }
    
    bool empty(){
        return currSize == 0;
    }
    int front(){ 
        if(currSize == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data; // 
    }
};

int main(){
    Queue q(100);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.front()<<endl; // 40
    
    q.pop(); // Removes 10
    cout<<q.front()<<endl; // 40
    
    q.pop(); // Removes 20
    cout<<q.front()<<endl; // 40
    
    q.pop(); // Removes 30
    cout<<q.front()<<endl; // 40
    
    q.pop(); // Removes 40
    cout<<q.front()<<endl; // Queue is empty, -1
    
    q.pop(); // Queue is empty msg
    cout<<q.front()<<endl; // Queue is empty, -1
    
    cout<<q.empty()<<endl; // 1 (True)
    
    q.push(10); 
    cout<<q.front()<<endl; // 10
    
    return 0;
}