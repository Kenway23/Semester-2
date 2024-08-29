#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> // untuk menggunakan fungsi exit()

struct {
    int NPM;
    char Nama[20];
    char Kelas[2];
    int Nilai;
} Rekaman;

FILE *Data_Nilai_MHS;

void InputData();
void OutputData();
void Splitting();
void Merging();
void KonsolidasiTanpaSeparator();
void KonsolidasiDenganSeparator();

int main() {
    int pilihan;

    // Input data ke dalam file tanpa separator
    InputData();

    // Output data dalam file tanpa separator
    OutputData();

    do {
        // Tampilkan menu pilihan
        printf("\nMenu Pilihan:\n");
        printf("1. Splitting Data\n");
        printf("2. Merging Data\n");
        printf("3. Konsolidasi Data Tanpa Separator\n");
        printf("4. Konsolidasi Data Dengan Separator\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        // Eksekusi fungsi berdasarkan pilihan
        switch (pilihan) {
            case 1:
                Splitting();
                break;
            case 2:
                Merging();
                break;
            case 3:
                KonsolidasiTanpaSeparator();
                break;
            case 4:
                KonsolidasiDenganSeparator();
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }

        // Tampilkan output data setelah eksekusi pilihan
        if (pilihan >= 1 && pilihan <= 4) {
            OutputData();
        }

    } while (pilihan != 5);

    getche();
    return 0;
}

void InputData() {
    // Isi dengan program untuk menulis data ke file
    int N;

    Data_Nilai_MHS = fopen("Data Nilai MHS.TXT", "at");

    printf("Input Data Mahasiswa\n");
    printf("Input Jumlah Mahasiswa: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        printf("NPM   : ");
        scanf("%d", &Rekaman.NPM);
        printf("Nama  : ");
        scanf("%s", Rekaman.Nama);
        printf("Kelas : ");
        scanf("%s", Rekaman.Kelas);
        printf("Nilai : ");
        scanf("%d", &Rekaman.Nilai);

        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    fclose(Data_Nilai_MHS);
}

void OutputData() {
    // Buka file untuk membaca
    Data_Nilai_MHS = fopen("Data Nilai MHS.TXT", "rt");
    if (Data_Nilai_MHS == NULL) {
        printf("Error: File tidak dapat dibuka\n");
        exit(1);
    }

    printf("Output Data Mahasiswa\n");
    printf("NPM\tNama\tKelas\tNilai\n");
    printf("--------------------------------\n");

    // Baca dan tampilkan data dari file
    while (fscanf(Data_Nilai_MHS, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        printf("%d\t%s\t%s\t%d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Tutup file
    fclose(Data_Nilai_MHS);
}

void Splitting() {
    FILE *fileKelasA, *fileKelasB, *fileKelasC;

    // Buka file utama untuk membaca
    Data_Nilai_MHS = fopen("Data Nilai MHS.TXT", "rt");
    if (Data_Nilai_MHS == NULL) {
        printf("Error: File tidak dapat dibuka\n");
        exit(1);
    }

    // Buka file untuk setiap kelas
    fileKelasA = fopen("Data Kelas A.TXT", "wt");
    fileKelasB = fopen("Data Kelas B.TXT", "wt");
    fileKelasC = fopen("Data Kelas C.TXT", "wt");

    if (fileKelasA == NULL || fileKelasB == NULL || fileKelasC == NULL) {
        printf("Error: Salah satu file kelas tidak dapat dibuka\n");
        exit(1);
    }

    // Baca data dari file utama dan tulis ke file masing-masing kelas
    while (fscanf(Data_Nilai_MHS, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        if (strcmp(Rekaman.Kelas, "A") == 0) {
            fprintf(fileKelasA, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
        } else if (strcmp(Rekaman.Kelas, "B") == 0) {
            fprintf(fileKelasB, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
        } else if (strcmp(Rekaman.Kelas, "C") == 0) {
            fprintf(fileKelasC, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
        }
    }

    // Tutup semua file
    fclose(Data_Nilai_MHS);
    fclose(fileKelasA);
    fclose(fileKelasB);
    fclose(fileKelasC);

    printf("Data telah dipisah berdasarkan kelas dan disimpan dalam file terpisah.\n");
}

void Merging() {
    FILE *fileKelasA, *fileKelasB, *fileKelasC;

    // Buka file utama untuk menulis
    Data_Nilai_MHS = fopen("Merged Data Nilai MHS.TXT", "wt");
    if (Data_Nilai_MHS == NULL) {
        printf("Error: File utama tidak dapat dibuka\n");
        exit(1);
    }

    // Buka file untuk setiap kelas
    fileKelasA = fopen("Data Kelas A.TXT", "rt");
    fileKelasB = fopen("Data Kelas B.TXT", "rt");
    fileKelasC = fopen("Data Kelas C.TXT", "rt");

    if (fileKelasA == NULL || fileKelasB == NULL || fileKelasC == NULL) {
        printf("Error: Salah satu file kelas tidak dapat dibuka\n");
        exit(1);
    }

    // Gabungkan data dari file kelas A
    while (fscanf(fileKelasA, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas B
    while (fscanf(fileKelasB, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas C
    while (fscanf(fileKelasC, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Tutup semua file
    fclose(Data_Nilai_MHS);
    fclose(fileKelasA);
    fclose(fileKelasB);
    fclose(fileKelasC);

    printf("Data telah digabungkan ke dalam file utama 'Merged Data Nilai MHS.TXT'.\n");
}

void KonsolidasiTanpaSeparator() {
    FILE *fileKelasA, *fileKelasB, *fileKelasC;

    // Buka file utama untuk menulis
    Data_Nilai_MHS = fopen("Konsolidasi Tanpa Separator.TXT", "wt");
    if (Data_Nilai_MHS == NULL) {
        printf("Error: File utama tidak dapat dibuka\n");
        exit(1);
    }

    // Buka file untuk setiap kelas
    fileKelasA = fopen("Data Kelas A.TXT", "rt");
    fileKelasB = fopen("Data Kelas B.TXT", "rt");
    fileKelasC = fopen("Data Kelas C.TXT", "rt");

    if (fileKelasA == NULL || fileKelasB == NULL || fileKelasC == NULL) {
        printf("Error: Salah satu file kelas tidak dapat dibuka\n");
        exit(1);
    }

    // Gabungkan data dari file kelas A
    while (fscanf(fileKelasA, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas B
    while (fscanf(fileKelasB, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas C
    while (fscanf(fileKelasC, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Tutup semua file
    fclose(Data_Nilai_MHS);
    fclose(fileKelasA);
    fclose(fileKelasB);
    fclose(fileKelasC);

    printf("Data telah dikonsolidasikan tanpa separator ke dalam file 'Konsolidasi Tanpa Separator.TXT'.\n");
}

void KonsolidasiDenganSeparator() {
    FILE *fileKelasA, *fileKelasB, *fileKelasC;

    // Buka file utama untuk menulis
    Data_Nilai_MHS = fopen("Konsolidasi Dengan Separator.TXT", "wt");
    if (Data_Nilai_MHS == NULL) {
        printf("Error: File utama tidak dapat dibuka\n");
        exit(1);
    }

    // Buka file untuk setiap kelas
    fileKelasA = fopen("Data Kelas A.TXT", "rt");
    fileKelasB = fopen("Data Kelas B.TXT", "rt");
    fileKelasC = fopen("Data Kelas C.TXT", "rt");

    if (fileKelasA == NULL || fileKelasB == NULL || fileKelasC == NULL) {
        printf("Error: Salah satu file kelas tidak dapat dibuka\n");
        exit(1);
    }

    // Gabungkan data dari file kelas A dengan separator
    fprintf(Data_Nilai_MHS, "---- Data Kelas A ----\n");
    while (fscanf(fileKelasA, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas B dengan separator
    fprintf(Data_Nilai_MHS, "---- Data Kelas B ----\n");
    while (fscanf(fileKelasB, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Gabungkan data dari file kelas C dengan separator
    fprintf(Data_Nilai_MHS, "---- Data Kelas C ----\n");
    while (fscanf(fileKelasC, "%d %s %s %d", &Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, &Rekaman.Nilai) != EOF) {
        fprintf(Data_Nilai_MHS, "%d %s %s %d\n", Rekaman.NPM, Rekaman.Nama, Rekaman.Kelas, Rekaman.Nilai);
    }

    // Tutup semua file
    fclose(Data_Nilai_MHS);
    fclose(fileKelasA);
    fclose(fileKelasB);
    fclose(fileKelasC);

    printf("Data telah dikonsolidasikan dengan separator ke dalam file 'Konsolidasi Dengan Separator.TXT'.\n");
}

