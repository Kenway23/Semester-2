#include <stdio.h>

int main() {
    int nilai_akhir;
    char grade;

    printf("Masukkan nilai akhir (0-100): ");
    scanf("%d", &nilai_akhir);

    if (nilai_akhir < 0 || nilai_akhir > 100) {
        printf("Nilai yang dimasukkan tidak valid.\n");
        return 1;
    }

    if (nilai_akhir >= 85 && nilai_akhir <= 100) {
        grade = 'A';
    } else if (nilai_akhir >= 70 && nilai_akhir <= 84) {
        grade = 'B';
    } else if (nilai_akhir >= 55 && nilai_akhir <= 69) {
        grade = 'C';
    } else if (nilai_akhir >= 40 && nilai_akhir <= 54) {
        grade = 'D';
    } else {
        grade = 'E';
    }

    printf("Grade nilai akhir Anda adalah: %c\n", grade);

    return 0;
}

