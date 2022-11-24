//Queue using arrays
#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue{
int arr[SIZE],head,tail;
public:
    Queue(){
        head = tail = 0;
    }

    //Check if queue is empty
    bool isEmpty(){
        return head==tail;
    }

    //Check if queue is full
    bool isFull(){
        return tail == SIZE;
    }

    //Peek the head of queue
    void peek(){
        if(isEmpty())
            cout<<"\n\tQueue is empty";
        else
            cout<<"\n\tElement at head = "<<arr[head];
    }
    //Adding element
    void enqueue(int elem){
        if(isFull()){
            cout<<"\n\tQueue is Full -- Overflow";
        }else{
            arr[tail] = elem;
            tail++;
        }
    }
    //Deleting element
    int dequeue(){
        int popped;
        if(isEmpty()){
            cout<<"\n\tQueue is empty -- UNDERFLOW\n";
            //returning some random -ve no.
            return -193201;
        }else{
            popped = arr[head];
            for(int i=head;i<tail-1;i++)
                arr[i]= arr[i+1];
            tail--;
            return popped;
        }
    }
    //Display queue
    void display(){
        int i;
        if(isEmpty()){
            cout<<"\n\tEmpty Queue";
        }else{
            cout<<"\n\tElements: \n\t";
            for(i=head ; i<tail; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Queue q;
    int ch,num,x;
    do{
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isFull?\n5.isEmpty?.\n6.display\n7.exit";
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
            if(x != -193201)
                cout<<"\n\tDeleted element :"<<x;
            break;
        case 3:
            q.peek();
            break;
        case 4:
            if(q.isFull()) cout<<"\n\tQueue is full\n";
            else cout<<"\n\tQueue is not full\n";
            break;
        case 5:
            if(q.isEmpty()) cout<<"\n\tQueue is empty\n";
            else cout<<"\n\tQueue is not empty\n";
            break;
        case 6:
            q.display();
            break;
        case 7:
            cout<<"\n\tExiting...\n";
            break;
        default:
            cout<<"\n\tEnter correct input\n";
        }
    }while(ch != 7);

    return 0;
}
