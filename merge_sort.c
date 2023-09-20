#include <stdio.h>

void printArr(int*, int);
void merge_sort(int*, int);
void merge(int*, int, int*, int, int*, int);

int main(){
	int arr[] = {4,5,2,7,0,14,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before Sorting : ");
	printArr(arr, size);
	
	merge_sort(arr, size);
	
	printf("\nAfter Sorting : ");
	printArr(arr, size);	
	
	return 0;
}

//Function to perform sorting in a merge sort style
void merge_sort(int arr[], int size){
	if(size < 2){
		return;
	}
	int midIndex = size/2;
	int leftArr[midIndex], rightArr[size-midIndex];
	
	int i;
	for(i=0; i<midIndex; i++){
		leftArr[i] = arr[i];
	}
	for(i=midIndex; i<size; i++){
		rightArr[i-midIndex] = arr[i];
	}
	
	merge_sort(leftArr, midIndex);
	merge_sort(rightArr, size-midIndex);
	
	merge(arr, size, leftArr, midIndex, rightArr, size-midIndex);
}

//Function to merge Array
void merge(int arr[], int arrSize, int leftArr[], int leftArrSize, int rightArr[], int rightArrSize){
	int i=0, j=0, k=0;
	
	while(i < leftArrSize && j < rightArrSize){
		if(leftArr[i] < rightArr[j]){
			arr[k] = leftArr[i];
			i++;
		}else if(rightArr[j] < leftArr[i]){
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while(i < leftArrSize){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(j < rightArrSize){
		arr[k] = rightArr[j];
		j++;
		k++;
	}
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

