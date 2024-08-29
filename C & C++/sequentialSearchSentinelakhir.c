#include <stdio.h>

void sequentialSearchSentinel(int A[], int n, int X) {
    int i = 0;
    int found = 0;
    A[n] = X; // Tambahkan sentinel
    while (A[i] != X) {
        i++;
    }
    if (i < n) {
        printf("Nilai ditemukan pada indeks %d\n", i);
    } else {
        printf("Nilai tidak ditemukan\n");
    }
}

int main() {
    int A[] = {50, 45, 55, 30, 35, 48, 39, 25, 15, 18};
    int n = sizeof(A) / sizeof(A[0]);
    int X;

    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &X);

    sequentialSearchSentinel(A, n, X);

    return 0;
}
