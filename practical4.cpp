//Stacks using arrays

#include <iostream>
using namespace std;
class Stack{
public:
    int stackA[100],n=100,top=-1;

    void push(int val){
        if(top >= n-1)
            cout<<"\nStack overflow";
        else{
            top++;
            stackA[top] = val;
        }
    }
    void pop(){
        if(top <=-1){
            cout<<"Stack Underflow";
        }else{
            cout<<"\nThe popped element is "<<stackA[top--]<<endl;
        }
    }
    void peek(){
        if(top <=-1){
            cout<<"Stack Underflow";
        }else{
            cout<<"\nThe top element is "<<stackA[top]<<endl;
        }
    }
    bool isEmpty(){
        if(top <= -1){
            cout<<"\nStack is empty ";
            return true;
        }
        cout<<"\nStack not empty";
        return false;
    }
    bool isFull(){
        if(top >= n-1){
            cout<<"\nStack is full ";
            return true;
        }
        cout<<"\nStack ain't full";
        return false;
    }
    void display(){
        if(top >= 0){
            cout<<"\nStack elements are: ";
            for(int i=top;i>=0;i--)
                cout<<stackA[i]<<" ";
            cout<<endl;
        }else
            cout<<"\nEmpty stack";
    }
};
int main(){
    Stack st;
    cout<<"\n1. Push in stack";
    cout<<"\n2. Pop from stack";
    cout<<"\n3. Peek in stack";
    cout<<"\n4. Check if stack is empty";
    cout<<"\n5. Check if stack is full";
    cout<<"\n6. Display stack ";
    cout<<"\n7. Exit "<<endl;
    int ch,val;
    bool x;
    do{
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\nEnter value to be pushed: ";
            cin>>val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            x = st.isEmpty();
            break;
        case 5:
            x = st.isFull();
            break;
        case 6:
            st.display();
            break;
        case 7:
            cout<<"\nExiting.."<<endl;
            break;
        default:
            cout<<"\nEnter correct choice ";
        }
    }while(ch != 7);
    return 0;
}
