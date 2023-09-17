#include <stdio.h>
#include <stdlib.h>

int* createArr();
void selection_sort(int*, int);
void printArr(int*, int);

int main() {
//    int arr[] = {9, 5, 2, 8, 3, 7, 1, 6, 4};
	int *arr = createArr();
    int size = sizeof(arr) / sizeof(arr[0]) + 1;

    printf("Original Array: ");
	printArr(arr, size);

    selection_sort(arr, size);

    printf("\nSorted Array: ");
	printArr(arr, size);

    printf("\n");

    return 0;
}

//Function to create a new array
int* createArr(){
	int n, i;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n);
	
	int *arr = (int*)malloc(sizeof(n*sizeof(int)));
	for(i=0; i<n; i++){
		printf("Enter %d element : ", i+1);
		scanf("%d", arr+i);
	}
	return arr;
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
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

//Function to print elements of array
void printArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}