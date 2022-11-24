#include <iostream>
using namespace std;
//Queue using linked list
struct QNode{
    int data;
    QNode* next;
    QNode(int x){
        data = x;
        next = NULL;
    }
};
class Queue{
    QNode *head , *tail;
public:
    Queue(){
        head = tail = NULL;
    }
    void enqueue(int elem){
        QNode *temp = new QNode(elem);
        cout<<"\n\tAdded element in queue\n";
        if(isEmpty()){
            head = tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"\n\tEmpty queue -- UNDERFLOW";
            return;
        }
        QNode *temp = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        delete(temp);
        cout<<"\n\tDeleted element from head";
    }
    void peek(){
        if(isEmpty()){
            cout<<"\n\tEmpty Queue";
            return;
        }
        cout<<"\n\tElement at head: "<<head->data;
    }
    bool isEmpty(){
        return tail == NULL;
    }
    void display(){
        QNode *temp = head;
        if(isEmpty()){
            cout<<"\n\tEmpty Queue";
            return;
        }
        cout<<"\n\tElements are: ";
        while(temp->next != NULL){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }cout<<temp->data<<endl;
    }
};
int main(){
    Queue q;
    int ch,num,x;
    do{
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty?.\n5.display\n6.exit";
        cout<<"\nEnter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nEnter element to be pushed: ";
            cin>>num;
            q.enqueue(num);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            if(q.isEmpty()) cout<<"\n\tQueue is empty\n";
            else cout<<"\n\tQueue is not empty\n";
            break;
        case 5:
            q.display();
            break;
        case 6:
            cout<<"\n\tExiting...\n";
            break;
        default:
            cout<<"\n\tEnter correct input\n";
        }
    }while(ch != 6);

    return 0;
}
