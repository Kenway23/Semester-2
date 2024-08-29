#include <stdio.h>

void binarySearch(int A[], int low, int high, int X) {
    int found = 0;
    while (low <= high && !found) {
        int mid = (low + high) / 2;
        if (A[mid] == X) {
            found = 1;
            printf("Nilai ditemukan pada indeks %d\n", mid);
        } else if (A[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Nilai tidak ditemukan\n");
    }
}

int main() {
    int A[] = {15, 18, 25, 30, 35, 39, 45, 48, 50, 55}; // Array harus terurut untuk binary search
    int n = sizeof(A) / sizeof(A[0]);
    int X;

    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &X);

    binarySearch(A, 0, n - 1, X);

    return 0;
}
