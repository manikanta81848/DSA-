#include <iostream>
using namespace std;

void printArr(int*arr,int n){
	cout<<"\n[";
for (int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}cout<<"]";
}
void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubblesort(int*arr,int n){
	for (int i=0;i<n-1;i++){
	int flag=0;
		for (int j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1]){
				swap (&arr[j],&arr[j+1]);
				flag=1;
		}
		if (flag==0)
			break;
	}
}

void insertionsort(int*arr,int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while (j>=0 && key<arr[j]){
			if (key<arr[j]){
				arr[j+1]=arr[j];
				--j;
			}
		}
		arr[j+1]=key;
	}	
}

void selectionsort(int*arr,int n){
	for(int i=0;i<n-1;i++){
	int min_index=i;
	for (int j=i+1;j<n;j++){
		if(arr[j]<arr[min_index])
			min_index=j;
		}
	swap (&arr[i],&arr[min_index]);	
	}	
}

void merge(int*arr,int s,int e){

	int mid=s+(e-s)/2;
	int len1 =mid-s+1;
	int len2=e-mid;
	
	int first[len1],second[len2];
	int k=s;
	for (int i=0;i<len1;i++){
		first[i]=arr[k++];
	}
	k=mid+1;
	for(int i=0;i<len2;i++){
		second[i]=arr[k++];
	}
	
	int index1=0;int index2=0;
	k=s;
		while(index1<len1 && index2<len2){
			if (first[index1]<second[index2]){
				arr[k++]=first[index1++];
			}
			else{
				arr[k++]=second[index2++];
			}
		}
		
	while(index1< len1){
		arr[k++]=first[index1++];
	}
	while(index2<len2){
		arr[k++]=second[index2++];
	}
}

void mergesort(int*arr,int s,int e){
	if (s<e){
		int mid=s+(e-s)/2;
	mergesort (arr,s,mid);
	mergesort(arr,mid+1,e);
	
	merge(arr,s,e);
	}
}

int partition(int*arr,int low,int high){
	int pivot= arr[high];
	int i=low-1;
	for (int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap (&arr[i+1],&arr[high]);
	return i+1;
}

void quicksort(int*arr,int low,int high){
	if (low<high){
		int pi= partition(arr,low,high);
		
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int main(){
	int n,arr[n];
	cout<<"\nEnter the size of the array: ";
	cin>>n;
	cout<<"\nEnter all the elements of array with spaces: ";
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
		
int sort_choice;
	cout<<"\nHow do you want to sort the array? \n1.bubblesort\n2.Insertionsort\n3.Selectionsort\n4.Mergesort\n5.Quicksort\n-->";
	cin>>sort_choice;
	cout<<"\nUnsorted array: ";
	printArr(arr,n);
	
switch(sort_choice){
	case 1:
		bubblesort(arr,n);
		break;
	case 2:
		insertionsort(arr,n);
		break;
	case 3:
		selectionsort(arr,n);
		break;
	case 4:
		mergesort(arr,0,n-1);
		break;
	case 5:
		quicksort(arr,0,n-1);
		break;
}
	cout<<"\nSorted Array: ";
	printArr(arr,n);

	return 0;
}





























