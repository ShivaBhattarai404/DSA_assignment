#include <stdio.h>

void selection_sort(int*, int);
void printArr(int*, int);
void swap(int*, int*);

int main() {
    int arr[] = {9, 5, 2, 8, 3, 7, 1, 6, 4};
    
    int size = sizeof(arr) / sizeof(arr[0]) + 1;

    printf("Original Array: \n");
	printArr(arr, size);

    selection_sort(arr, size);

    printf("\n\nSorted Array: \n");
	printArr(arr, size);

    return 0;
}

//Function for sorting array in a selection sort style
void selection_sort(int arr[], int n) {
    int i, j;
	for (i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr+minIdx, arr+i);
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
