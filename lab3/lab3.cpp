#include <iostream>
#include <new>
#include <queue>
using namespace std;

class Node {
public:
    Node(int x,Node *next){
        data=x;
        next=next;
    }
    Node *next;
    int data;
};


class Queue{
public:
    Node *front;
    Node *rear;
    int size=0;

    Queue(){front=rear=NULL;}

    void enqueue(int item) {
        Node *temp=new Node(item,NULL);
        if (rear==NULL){
            front=rear=temp;
            size++;
            return;

        }
        rear->next=temp;
        rear=temp;
        size++;

    }
    void dequeue() {
        if (front==NULL){
            return;
        }

        Node *temp= front;
        front=front->next;
        delete(temp);
        size--;

    }
    bool isEmpty() {
        if (size==0)
            return true;
        else
            return false;

    }

    int Size() {
        return size;
    }

    int top() {
        return front->data;
    }
};

int main() {
    Queue *myQueue =new Queue();
    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->enqueue(3);
    myQueue->enqueue(4);
    myQueue->enqueue(5);
    myQueue->enqueue(6);

    myQueue->dequeue();
    myQueue->dequeue();

    if (myQueue->isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    cout<<"Size: "<< myQueue->size<<endl;
    cout<<"Top item: "<< myQueue->top()<<endl;


    return 0;
}
