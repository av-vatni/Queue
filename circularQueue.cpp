#include <iostream>

using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    Queue(){
        size = 100001;
        arr  = new int[size];
        front = rear = -1;
    }
    bool enqueue(int data){
        if((front == 0 && rear == size-1) || (rear == (front-1) % (size-1))){//List is full
            cout<<"Queue is full!"<<endl;
            return false;
        }else if(front == -1){
            front = rear = 0;  
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = data;
        return true;
    }
     int dequeue (){
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
    int Qfront(){
        if(front == rear){
            return -1;
        }else{
            return arr[front];
        }
    }
};

int main(){
    Queue q;
    q.enqueue(12);
    q.enqueue(24);
    q.enqueue(36);
    q.enqueue(48);
    cout<<q.Qfront()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.Qfront()<<endl;

}