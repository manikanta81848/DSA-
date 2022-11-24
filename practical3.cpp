// Binary search in a sorted array

#include <iostream>
using namespace std;

int binarySearch(int *arr,int s,int e,int key){
    if(e>=s){
        int mid = s + (e - s) / 2;
        if(arr[mid] == key)
            return mid;

        if(arr[mid]<key)
            return binarySearch(arr,mid+1,e,key);

        return binarySearch(arr,s,mid-1,key);

    }
    return -1;

}

int main(){
    int n;
    cout<<"\nEnter the size of array: ";
    cin>>n;
    // Creating array of size n using user input
    int arr[n];
    cout<<"\nEnter the elements of the sorted array with a space: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the key to be searched in the array: "<<endl;

    int key;
    cin>>key;
    int pos = binarySearch(arr,0,n-1,key);

    if(pos == -1){
            cout<<"\nThe element was not found in the array!";
    }else{
        cout<<"\nThe element was found at index "<<pos;
    }
    return 0;
}
