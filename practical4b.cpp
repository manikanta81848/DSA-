//Stacks using Linked List

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top;
void push(int data){

    Node* temp = new Node();

    if(!temp){
        cout<<"\nStack Overflow";
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(){
    Node* temp;

    if(top == NULL){
        cout<<"Stack Underflow";
        return;
    }
    temp = top;
    cout<<"\nThe popped element is "<<temp->data<<endl;
    top = top->next;
    delete(temp);
}

bool isEmpty(){
    return top == NULL;
}

void peek(){
    if(!isEmpty()){
        cout<<"\nThe top element is "<<top->data<<endl;
        return;
    }else{
        cout<<"\nEmpty stack";
    }
}

void display(){
    Node* temp;
    if(top == NULL){
        cout<<"\nEmpty stack";
        return;
    }
    temp = top;
    cout<<"\nStack elements are: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    cout<<"\n1. Push in stack";
    cout<<"\n2. Pop from stack";
    cout<<"\n3. Peek in stack";
    cout<<"\n4. Check if stack is empty";
    cout<<"\n5. Display stack ";
    cout<<"\n6. Exit "<<endl;
    int ch,val;
    bool x;
    do{
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nEnter value to be pushed: ";
            cin>>val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            x = isEmpty();
            if(x)
                cout<<"\nEmpty stack";
            else
                cout<<"\nStack is not empty";
            break;
        case 5:
            display();
            break;
        case 6:
            cout<<"\nExiting.."<<endl;
            break;
        default:
            cout<<"\nEnter correct choice ";
        }
    }while(ch != 6);
    return 0;
}
