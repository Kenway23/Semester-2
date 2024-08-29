#include <stdio.h>


void bubbleSortAsc(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void bubbleSortDesc(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void quickSortAsc(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortAsc(arr, low, pivot - 1);
        quickSortAsc(arr, pivot + 1, high);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}


void quickSortDesc(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortDesc(arr, low, pivot - 1);
        quickSortDesc(arr, pivot + 1, high);
    }
}

int main() {
    int A[100], n, i;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &n);

    printf("Masukkan elemen array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    
    bubbleSortAsc(A, n);
    printf("\nHasil pengurutan ascending (Bubble Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

   
    bubbleSortDesc(A, n);
    printf("\nHasil pengurutan descending (Bubble Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }


    quickSortAsc(A, 0, n - 1);
    printf("\nHasil pengurutan ascending (Quick Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

   
    quickSortDesc(A, 0, n - 1);
    printf("\nHasil pengurutan descending (Quick Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}

