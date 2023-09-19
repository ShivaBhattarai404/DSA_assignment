#include <stdio.h>

void insertion_sort(int*, int);
void printArr(int*, int);

int main(){
	int arr[] = {4,5,7,0,1,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before sorting\n");
	printArr(arr, size);
	
	insertion_sort(arr, size);
	
	printf("\n\nAfter sorting\n");
	printArr(arr, size);
	
	return 0;
}

//Function to sort array in a insertion sort style
void insertion_sort(int arr[], int n){
	int i;
	for(i=1; i<n; i++){
		int current = arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>current){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=current;
	}
}

//Function to print elements of Array
void printArr(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}
