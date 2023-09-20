#include <stdio.h>

void printArr(int*, int);
void quickSort(int*, int, int);
void swap(int*, int*);

int main(){
	int arr[] = {7,5,1,0,5,9,11,4,3,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before Sorting :");
	printArr(arr, size);
	
	quickSort(arr, 0, size-1);
	
	printf("\nAfter Sorting :");
	printArr(arr, size);
	return 0;
}

//Function to sort array in a quick sort style
void quickSort(int arr[], int lowIndex, int highIndex){
	if(lowIndex >= highIndex){
		return;
	}
	int pivot = arr[highIndex];
	
	int leftPointer = lowIndex;
	int rightPointer = highIndex;
	
	while(leftPointer != rightPointer){
		while(arr[leftPointer] <= pivot && leftPointer != rightPointer){
			leftPointer++;
		}
		while(arr[rightPointer] >= pivot && leftPointer != rightPointer){
			rightPointer--;
		}
		swap(arr+leftPointer, arr+rightPointer);
	}
	swap(arr+leftPointer, arr+highIndex);
	
	quickSort(arr, lowIndex, rightPointer-1);
	quickSort(arr, leftPointer+1, highIndex);
}

//Function to print elements of an array
void printArr(int arr[], int size){
	int i=0;
	printf("\n[");
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\b]\n");
}

//Function to swap two numbers
void swap(int *fst, int *cnd){
	int temp = *fst;
	*fst = *cnd;
	*cnd = temp;
}
