//Circular queue using array
#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue{
int arr[SIZE],head,tail;
public:
    Queue(){
        head = tail = -1;
    }

    //Check if queue is empty
    bool isEmpty(){
        return head == -1;
    }

    //Check if queue is full
    bool isFull(){
        if(head == 0 && tail == SIZE - 1)
            return true;
        if(head == tail + 1)
            return true;
        return false;
    }
    //Adding element
    void enqueue(int elem){
        if(isFull()){
            cout<<"\n\tQueue is Full";
        }else{
            if(head == -1) head = 0;
            tail = (tail + 1)%SIZE;
            arr[tail] = elem;
        }
        display();
    }
    //Deleting element
    int dequeue(){
        int popped;
        if(isEmpty()){
            cout<<"\n\tQueue is empty -- UNDERFLOW\n";
            return -1232311;
        }else{
            popped = arr[head];
            if(head == tail)
                head = tail = -1;
            else
                head = (head + 1)%SIZE;
            return popped;
        }
    }
    //Display queue
    void display(){
        int i;
        if(isEmpty()){
            cout<<"\n\tEmpty Queue";
        }else{
            cout<<"\n\tHead: "<<head<<"\n\tTail: "<<tail<<"\n\tElements: \n\t";
            for(i=head ; i!=tail ; i=(i+1)%SIZE)
                cout<<arr[i]<<" ";
            cout<<arr[i]<<" "<<endl;
        }
    }
};

int main(){
    Queue q;
    int ch,num,x;
    do{
        cout<<"\n1.Enqueue\n2.Dequeue\n3.isFull?\n4.isEmpty?.\n5.display\n6.exit";
        cout<<"\nEnter choice:";
        cin>>ch;
        switch(ch){
        case 1:
            if(!q.isFull()){
                cout<<"\nEnter element to be pushed: ";
                cin>>num;
            }
            q.enqueue(num);
            break;
        case 2:
            x = q.dequeue();
            if(x != -1232311)
                cout<<"\n\tDeleted element :"<<x;
            break;
        case 3:
            if(q.isFull()) cout<<"\n\tQueue is full\n";
            else cout<<"\n\tQueue is not full\n";
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
