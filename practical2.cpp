#include <iostream>
using namespace std;

int linearsearch(int*arr,int n,int x){
	for( int i=0;i<n;i++)
		if (arr[i]==x)
			return i;
		return -1;
}
int main(){
	int num,size,arr[size];
	cout<<"\n Enter the size: ";
	cin>>size;
	
	cout<<"\nEnter all the elements of array with a space: ";
	for(int i=0;i<size;i++)
		cin>>arr[i];

	cout<<"\nEnter the element to be searched: ";
	cin>>num;
	
	int indexofnum;
	indexofnum=linearsearch(arr,size,num);
	
	if(indexofnum>0)
		cout<<"\n The element was found at index: "<<indexofnum;
	else
		cout<<"\n No element is found... ";
	return 0;	
}
