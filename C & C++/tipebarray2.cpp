#include <stdio.h>

int A[10] = {24,34,21,65,22,12,24};
int i;
int x;
int found;
int count;

int main() {
    printf("[24,34,21,65,22,12,24]\n");
    printf("Pilih angka berapapun di atas...\n\n");
    
    printf("Pilihan anda : "); scanf("%d", &x);
    
    found = 0;
    count = 0;

    for (i = 0; i < 10; i++) {
        if (A[i] == x) {
            if (found == 0) {
                printf("Ditemukan di elemen ke %d ", i);
                found = 1;
            } else {
                printf("dan ke %d ", i);
            }
            count++;
        }
    }
    if (found == 0) {
        printf("Tidak ditemukan\n");
    } 
    return 0;
}
