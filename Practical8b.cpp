//Fibonacci Series using recursion

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}
int main(){
    int n,m;
    cout<<"\nEnter the number of terms:";
    cin>>n;
    cout<<"\nFibonacci Series:";
    for(int i=0;i<n;i++){
        cout<<" "<<fibonacci(m++);
    }
    return 0;
}
