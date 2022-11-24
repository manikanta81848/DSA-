//Tower of Hanoi

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char startS, char auxS, char endS){
    if(n==1){
        cout<<startS<<" --> "<<endS<<endl;
    }else{
        towerOfHanoi(n-1,startS,endS,auxS);
        towerOfHanoi(1,startS,auxS,endS);
        towerOfHanoi(n-1,auxS,startS,endS);
    }
}

int main(){
    //For number of disks
    int numOfDisks;
    //Variables for the 3 pegs
    char st,aux,en;

    //Variable for continuing with the code
    char choice;
    while(true){
        cout<<"--------------------------------------------";
        cout<<"\nWelcome to the TOWER OF HANOI "<<endl;
        cout<<"\nEnter the number of disks to move: ";
        cin>>numOfDisks;
        cout<<"\nEnter the Starting Auxiliary and Ending peg with spaces (eg: A B C) : ";
        cin>>st>>aux>>en;
        cout<<"\n\nThe solution for the given conditions for Tower of Hanoi is: "<<endl;
        towerOfHanoi(numOfDisks,st,aux,en);

        cout<<"\nDo you want to continue?(y/n)";
        cin>>choice;
        if(choice == 'n' || choice == 'N')
            break;
    }
    return 0;
}
