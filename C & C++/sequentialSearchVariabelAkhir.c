#include <stdio.h>

void sequentialSearchSorted(int A[], int n, int X) {
    int i = 0;
    int found = 0;
    int stop = 0;
    while (i < n && !stop) {
        if (A[i] == X) {
            found = 1;
            break;
        } else if (A[i] > X) {
            stop = 1;
        }
        i++;
    }
    if (found) {
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

    sequentialSearchSorted(A, n, X);

    return 0;
}
