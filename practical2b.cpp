//Linear Search in linked list
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class List{
    Node* head;
public:
    List() { head = NULL;}

    void insertNode(int);
    void printList();
    void listLinearSearch(int);
};

void List::insertNode(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void List::listLinearSearch(int key){
    if(head == NULL){
        cout<<"\nGiven list is empty!";
    }else{
        Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(temp->data == key){
                cout<<"\nThe element was found at index "<<i;
                return;
            }
            temp = temp->next;
            i++;
        }
        cout<<"\nThe element was not found in the list"<<endl;
    }
}

int main(){
    List listA;
    int n;
    cout<<"\nHow many elements do you want to enter: ";
    cin>>n;
    cout<<"\nEnter the elements of the list with a space: "<<endl;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        listA.insertNode(num);
    }
    cout<<"\nEnter the key to be searched in the list: "<<endl;
    int key;
    cin>>key;

    listA.listLinearSearch(key);
    return 0;
}
