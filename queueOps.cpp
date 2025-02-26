#include <iostream>
#include <vector>

using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    Queue(){
        size = 10000;
        arr  = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Overflow!"<<endl;
        }else{
            arr[rear] = data;
            rear++;
        }    
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }else{
            int ans = arr[front];
            arr[front] = -1;
            front++;

            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int Qfront(){
        if(front == rear){
            return -1;
        }else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Queue q;
    q.enqueue(12);
    cout<<q.Qfront()<<endl;

    q.enqueue(24);
    cout<<q.Qfront()<<endl;

    q.enqueue(36);
    cout<<q.Qfront()<<endl;

    q.enqueue(48);
    cout<<q.Qfront()<<endl;

    q.dequeue();
    cout<<q.Qfront()<<endl;

    q.dequeue();
    cout<<q.Qfront()<<endl;

    q.dequeue();
    cout<<q.Qfront()<<endl;

    q.dequeue();
    cout<<q.Qfront()<<endl;

    if(q.isEmpty()){
        cout<<"Queue is empty!"<<endl;
    }else{
        cout<<"Queue is not empty!"<<endl;
    }
}