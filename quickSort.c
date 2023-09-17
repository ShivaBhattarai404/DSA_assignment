#include <stdio.h>
#include <stdlib.h>

int* createArr();
void quick_sort(int*, int, int);
void printArr(int*, int);

int main() {
	int *arr = createArr();
    int size = sizeof(arr) / sizeof(arr[0]) + 1;

    printf("Original Array: ");
	printArr(arr, size);

    quick_sort(arr, 0, size-1);

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

//Function for sorting array in a quick sort style
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int left = low;
        int right = high - 1;

        while (1) {
            while (left <= right && arr[left] < pivot) {
                left++;
            }
            while (left <= right && arr[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            } else {
                break;
            }
        }

        int temp = arr[left];
        arr[left] = arr[high];
        arr[high] = temp;

        quick_sort(arr, low, left - 1);
        quick_sort(arr, left + 1, high);
    }
}

//Function to print elements of array
void printArr(int arr[], int size){
	int i;
	for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}