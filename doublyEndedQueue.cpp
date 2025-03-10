#include<iostream>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool pushFront(int data){
        if((front == 0 && rear == size-1 || rear == (front-1) % (size-1))){
            cout<<"Queue is Full"<<endl;
            return false;
        }else if(front == -1){
            front = rear = 0;
        }else if(front == 0 && rear != size-1){
            front = size-1;
        }else{
            front--;
        }
        arr[front] = data;
        return true;
    }

    bool pushRear(int data){
        if((front == 0 && rear == size-1 || rear == (front-1) % (size-1))){
            cout<<"Queue is Full"<<endl;
            return false;
        }else if(front == -1){//Single element
            front = rear = 0;
        }else if(rear == size-1 && front != 0){//Maintaining cyclic nature
            rear = 0;
        }else{ //Normal flow
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    int popFront (){
        if(front == -1){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ //Single element
            front = rear = -1;
        }else if(front == size-1){ //Front is at the end of queue
            front = 0;
        }else{   //Front is in between
            front++;
        }
        return ans;
     }

     int popRear (){
        if(front == -1){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){ //Single element
            front = rear = -1;
        }else if(rear == 0){ //Front is at the end of queue
            rear = size-1;
        }else{   //Front is in between
            rear--;
        }
        return ans;
     }

    int Qfront(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }
    int Qback(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[rear];
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Deque q(10);
    q.pushRear(12);
    q.pushRear(24);
    q.pushRear(36);
    q.pushRear(48);
    cout<<q.Qfront()<<endl;
    cout<<q.Qback()<<endl;

    q.popRear();
    q.popRear();
    
    cout<<q.Qfront()<<endl;
    cout<<q.Qback()<<endl;
}