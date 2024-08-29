#include <stdio.h>

int main() {
    int A[] = {7, 8, 10, 12, 15, 20, 22, 30, 33};
    int n = sizeof(A) / sizeof(A[0]);
    int X, index;

    printf("Masukkan nilai X yang ingin dicari: ");
    scanf("%d", &X);

    int low = 0;
    int high = n - 1;
    index = -1; 
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == X) {
            index = mid;
            break;
        } else if (A[mid] < X) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    if (index != -1) {
        printf("Nilai %d ditemukan pada indeks %d.\n", X, index);
    } else {
        printf("Nilai %d tidak ditemukan dalam array.\n", X);
    }

    return 0;
}

