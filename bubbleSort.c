#include <stdio.h>

void bubble_sort(int*, int);
void printArr(int*, int);
void swap(int*, int*);

int main() {
	int arr[] = {5,7,5,0,1,88,12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nOriginal Array: ");
	printArr(arr, size);

    bubble_sort(arr, size);

    printf("\nSorted Array: ");
	printArr(arr, size);

    printf("\n");

    return 0;
}

//Function for sorting array in a bubble sort style
void bubble_sort(int arr[], int n) {
    int i, j;
    for(i=0; i<n-1; i++){
    	for(j=0; j<n-i-1; j++){
    		if(arr[j] > arr[j+1]){
    			swap(arr+j, arr+j+1);
			}
		}
	}
}

//Function to print elements of array
void printArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

//Function for swapping two elements
void swap(int* fst, int* cnd){
	int temp = *fst;
	*fst = *cnd;
	*cnd = temp;
}
