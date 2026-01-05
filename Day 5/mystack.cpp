#include<iostream>
using namespace std;
class Stack{
    //properties;
    private:
    int* arr;
    int index =-1;
    int size;
    public:
    Stack(int size){
        this->size = size;
        arr = new int(size);
    }
    void push(int value){
        if(index ==size-1){
            cout<<"Stack is full"<<endl;
            return;
        }
        index++;
        arr[index] = value;
    }
    void pop(){
        if(index==-1){
            cout<<"Stack is empty "<<endl;
            return;
        }
        index--;
    }
    void isEmpty(){
        if(index==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }
    int top(){
        if(index==-1){
            cout<<" - Stack is empty"<<endl;
            return INT_MIN;
        }
        return arr[index];
    }
};
int main(){
    Stack s(100);
    s.push(10);
    s.push(20);
    cout<< s.top()<<endl;//20
    s.pop();
    s.pop();
    cout<<s.top()<<endl;//  Returns INT MIN and tells stack is empty
    s.isEmpty();
    return 0;
}