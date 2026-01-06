#include<iostream>
using namespace std;
class Queue{
    private:
    int size;
    int* arr;
    int frot;
    int rear;
    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        frot = -1;
        rear = -1;
    }
    void push(int value){
        if(rear == size-1){
            cout<<"Queue is Full"<<endl;
            return ;
        }
        rear++;
        arr[rear] = value;
        
    }
    void pop(){
        if(frot==rear){
            cout<<"Queue is empty"<<endl;
            frot = rear = -1;
            return ;
        }
        frot++;
    }
    int front(){
        if(frot==rear){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return arr[frot+1];
    }
    int back(){
        if(frot==rear){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return arr[rear];
    }
    bool empty(){
        if(frot==rear){
            return true;
        }
        return false;
    }
};
int main(){
    return 0;
}