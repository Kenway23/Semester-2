#include <stdio.h>

#define SIZE 9

int main() {
    int A[SIZE] = {12, 20, 22, 30, 10, 8, 33, 7, 15};
    int X, index;

    printf("Masukkan nilai X yang ingin dicari: ");
    scanf("%d", &X);

    // Menambahkan sentinel di akhir array
    A[SIZE] = X;
	
    index = 0;
    while (A[index] != X) {
        index++;
    }

    // Mengembalikan indeks nilai X jika ditemukan
    if (index < SIZE) {
        printf("Nilai %d ditemukan pada indeks %d.\n", X, index);
    } else {
        printf("Nilai %d tidak ditemukan dalam array.\n", X);
    }

    return 0;
}
