#include <stdio.h>

void shell_sort(int*, int);
void printArr(int*, int);

int main(){
	int arr[] = {4,5,7,0,1,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before sorting\n");
	printArr(arr, size);
	
	shell_sort(arr, size);
	
	printf("\n\nAfter sorting\n");
	printArr(arr, size);
	
	return 0;
	return 0;
}

//Function to sort array in a insertion sort style
void shell_sort(int arr[], int n){
	int gap;
	for(gap=n/2; gap>0; gap/=2){
		int i;
		for(i=gap; i<n; i++){
			int current = arr[i];
			int j=i-gap;
			while(j>=0 && arr[j]>current){
				arr[j+gap] = arr[j];
				j-=gap;
			}
			arr[j+gap]=current;
		}
	}
}

//Function to print elements of Array
void printArr(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}
