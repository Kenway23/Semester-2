#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char npm[12];
    char nama[255];
    char nilai;
};

int main() {
    int pilihan;
    int i, n;
    struct Mahasiswa mhs[255], mhs_baru[6];

    // Menulis file data mahasiswa baru
    printf("Menu Penambahan Data Mahasiswa\n");
    printf("1. Tambah Data\n");
    printf("2. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        printf("Masukkan jumlah data mahasiswa baru (maksimum 6): ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            printf("Data mahasiswa ke-%d\n", i + 1);
            printf("Masukkan NPM: ");
            scanf("%s", mhs_baru[i].npm);
            printf("Masukkan Nama: ");
            scanf("%s", mhs_baru[i].nama);
            printf("Masukkan Nilai (A/B/C/D/E): ");
            scanf(" %c", &mhs_baru[i].nilai);
        }

        // Simpan data mahasiswa baru ke file
        FILE *fp = fopen("data_mahasiswa.txt", "a");
        if (fp == NULL) {
            printf("Error: Tidak bisa membuka file\n");
            exit(1);
        }

        for (i = 0; i < n; i++) {
            fprintf(fp, "%s %s %c\n", mhs_baru[i].npm, mhs_baru[i].nama, mhs_baru[i].nilai);
        }

        fclose(fp);
        printf("Data mahasiswa baru berhasil ditambahkan\n");
    }

    // Membaca file data mahasiswa yang sudah terbentuk sebelumnya
    printf("\nMenu Tampilan Data Mahasiswa\n");
    printf("1. Tampilkan Data\n");
    printf("2. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        FILE *fp = fopen("data_mahasiswa.txt", "r");
        if (fp == NULL) {
            printf("Error: Tidak bisa membuka file\n");
            exit(1);
        }

        i = 0;
        printf("\nData Mahasiswa:\n");
        printf("NPM  Nama  Nilai\n");
        printf("----  -----  -----\n");
        while (fscanf(fp, "%s %s %c", mhs[i].npm, mhs[i].nama, &mhs[i].nilai) != EOF) {
            printf("%s %s %c\n", mhs[i].npm, mhs[i].nama, mhs[i].nilai);
            i++;
        }

        fclose(fp);
    }

    // Pencarian data mahasiswa berdasarkan NIM
    printf("\nMenu Pencarian Data Mahasiswa\n");
    printf("1. Cari Data\n");
    printf("2. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        char npm_cari[12];
        int found = 0;

        printf("Masukkan NPM yang dicari: ");
        scanf("%s", npm_cari);

        FILE *fp = fopen("data_mahasiswa.txt", "r");
        if (fp == NULL) {
            printf("Error: Tidak bisa membuka file\n");
            exit(1);
        }

        while (fscanf(fp, "%s %s %c", mhs[i].npm, mhs[i].nama, &mhs[i].nilai) != EOF) {
            if (strcmp(npm_cari, mhs[i].npm) == 0) {
                found = 1;
                printf("\nData Mahasiswa Ditemukan:\n");
                printf("NPM: %s\n", mhs[i].npm);
                printf("Nama: %s\n", mhs[i].nama);
                printf("Nilai: %c\n", mhs[i].nilai);
                break;
            }
            i++;
        }

        if (!found) {
            printf("\nData Mahasiswa tidak ditemukan.\n");
        }

        fclose(fp);
    }

    return 0;
}
