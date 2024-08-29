#include <stdio.h>

void SelectionSort(int A[], int N) {
    int i, j, minIndex;
    for (i = 0; i < N - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < N; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}

int main() {
    int N, i;
    
    printf("Masukkan ukuran array: ");
    scanf("%d", &N);
    
    int A[N];
    
    printf("Masukkan elemen array:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Panggil prosedur SelectionSort
    SelectionSort(A, N);
    
    printf("Hasil setelah Selection Sort:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
