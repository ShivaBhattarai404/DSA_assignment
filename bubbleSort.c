#include <stdio.h>
#include <stdlib.h>

int* createArr();
void bubble_sort(int*, int);
void printArr(int*, int);

int main() {
	int *arr = createArr();
    int size = sizeof(arr) / sizeof(arr[0]) + 1;

    printf("Original Array: ");
	printArr(arr, size);

    bubble_sort(arr, size);

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

//Function for sorting array in a bubble sort style
void bubble_sort(int arr[], int n) {
    int swapped, i;
    do {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            int temp = arr[i];
            if (arr[i] > arr[i + 1]) {
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

//Function to print elements of array
void printArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}