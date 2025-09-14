#include<iostream>
#define QUEUE_UNDERFLOW 1;
using namespace std;
struct node
{
    int item;
    node* next;
};

class Queue{
    private:
        node* front;
        node* rear;
        int size;
    public:
        Queue();
        void insertion(int);
        int getRear();
        int getFront();
        bool isEmpty();
        bool isFull();
        void deleteFront();
        ~Queue();
        int count();
        int getCount();


};
Queue::Queue(){
    front=nullptr;
    rear=nullptr;
    size=0;
}
void Queue::insertion(int data){
    node* temp=new node;
    temp->item=data;
    if(front==nullptr&&rear==nullptr){
        front=temp;
        rear=temp;
        temp->next=nullptr;
    }
    else{
        rear->next=temp;
        temp->item=data;
        temp->next=nullptr;
        rear=temp;
    }
    size++;
}
bool Queue::isEmpty(){
    return rear==nullptr;
}
int Queue::getFront(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    return front->item;
}
int Queue::getRear(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    return rear->item;
}
void Queue::deleteFront(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    node* temp=front;
    front=temp->next;
    if(front->next==nullptr)
        rear=nullptr;
    delete temp;
    size--;
}
Queue::~Queue(){
    while (rear!=nullptr)
    {
        deleteFront();
    }
    
}
int Queue::count(){
    int count=0;
    node *temp=front;
    if(rear==nullptr)
    return 0;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count+1;

}
int Queue::getCount(){
    return size;
}