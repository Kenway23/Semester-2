#include <stdio.h>

void InsertionSort(int A[], int N) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
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
    
    // Panggil prosedur InsertionSort
    InsertionSort(A, N);
    
    printf("Hasil setelah Insertion Sort:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
