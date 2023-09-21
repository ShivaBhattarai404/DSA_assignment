#include <stdio.h>

void printArr(int*, int);
void bucketSort(int*, int);
int getMax(int*, int);

int main(){
	int arr[] = {4,0,1,9,9,12,7,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before Sorting :");
	printArr(arr, size);
	
	bucketSort(arr, size);
	
	printf("\nAfter Sorting :");
	printArr(arr, size);
	return 0;
}

//Function to sort array in a bucket sort style
void bucketSort(int arr[], int size){
	int max = getMax(arr, size);
	int tempArr[max+1], i, j;
	
	for(i=0; i<=max; i++){
		tempArr[i] = 0;
	}
	for(i=0; i<size; i++){
		tempArr[arr[i]]++;
	}
	for(i=0,j=0; i<=max; i++){
		while(tempArr[i] > 0){
			arr[j++] = i;
			tempArr[i]--;
		}
	}
}

//Function to get maximum value from an array
int getMax(int arr[], int size){
	int max = arr[0];
	int i;
	for(i=1; i<size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

//Function to print elements of array
void printArr(int arr[], int size){
	int i=0;
	printf("\n[");
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\b]\n");
}
