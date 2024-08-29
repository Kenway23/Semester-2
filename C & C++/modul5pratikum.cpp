#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int kode_buku;
    int jenis;
    int harga_sewa;
    int stok;
} databuku;

FILE *buku, *buku2, *buku3;

void InputData();
void OutputData();
void InputData2();
void OutputData2();
void MergeIntersect();
void MergeUnion();
void ShowResult(const char* filename);

int main() {
    InputData();
    OutputData();
    InputData2();
    OutputData2();
    MergeIntersect();
    ShowResult("gabungbukuAND.txt");
    MergeUnion();
    ShowResult("gabungbukuOR.txt");
    return 0;
}

void InputData() {
    int N;
    databuku data;

    buku = fopen("buku.txt", "at");

    printf("Input Data Buku\n");
    printf("Input Jumlah Buku: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        printf("Kode Buku   : ");
        scanf("%d", &data.kode_buku);
        printf("Jenis  : ");
        scanf("%d", &data.jenis);
        printf("Harga Sewa : ");
        scanf("%d", &data.harga_sewa);
        printf("Stok : ");
        scanf("%d", &data.stok);

        fprintf(buku, "%d %d %d %d\n", data.kode_buku, data.jenis, data.harga_sewa, data.stok);
    }

    fclose(buku);
}

void OutputData() {
    databuku data;
    buku = fopen("buku.txt", "rt");

    if (buku == NULL) {
        printf("Error: File buku.txt tidak dapat dibuka\n");
        exit(1);
    }

    printf("Output Data Buku dari File Buku 1\n");
    printf("Kode Buku\tJenis\tHarga Sewa\tStok\n");
    printf("--------------------------------\n");

    while (fscanf(buku, "%d %d %d %d\n", &data.kode_buku, &data.jenis, &data.harga_sewa, &data.stok) != EOF) {
        printf("%d\t%d\t%d\t%d\n", data.kode_buku, data.jenis, data.harga_sewa, data.stok);
    }

    fclose(buku);
}

void InputData2() {
    int N;
    databuku data;

    buku2 = fopen("buku2.txt", "at");

    printf("Input Data Buku 2\n");
    printf("Input Jumlah Buku: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        printf("Kode Buku   : ");
        scanf("%d", &data.kode_buku);
        printf("Jenis  : ");
        scanf("%d", &data.jenis);
        printf("Harga Sewa : ");
        scanf("%d", &data.harga_sewa);
        printf("Stok : ");
        scanf("%d", &data.stok);

        fprintf(buku2, "%d %d %d %d\n", data.kode_buku, data.jenis, data.harga_sewa, data.stok);
    }

    fclose(buku2);
}

void OutputData2() {
    databuku data;
    buku2 = fopen("buku2.txt", "rt");

    if (buku2 == NULL) {
        printf("Error: File buku2.txt tidak dapat dibuka\n");
        exit(1);
    }

    printf("Output Data Buku dari File Buku 2\n");
    printf("Kode Buku\tJenis\tHarga Sewa\tStok\n");
    printf("--------------------------------\n");

    while (fscanf(buku2, "%d %d %d %d\n", &data.kode_buku, &data.jenis, &data.harga_sewa, &data.stok) != EOF) {
        printf("%d\t%d\t%d\t%d\n", data.kode_buku, data.jenis, data.harga_sewa, data.stok);
    }

    fclose(buku2);
}

void MergeIntersect() {
    databuku data1, data2;
    buku = fopen("buku.txt", "rt");
    buku2 = fopen("buku2.txt", "rt");
    buku3 = fopen("gabungbukuAND.txt", "wt");

    if (buku == NULL || buku2 == NULL || buku3 == NULL) { 
        printf("Error: Salah satu atau kedua file tidak dapat dibuka\n");
        exit(1);
    }

    int endOfFile1 = fscanf(buku, "%d %d %d %d\n", &data1.kode_buku, &data1.jenis, &data1.harga_sewa, &data1.stok);
    int endOfFile2 = fscanf(buku2, "%d %d %d %d\n", &data2.kode_buku, &data2.jenis, &data2.harga_sewa, &data2.stok);

    while (endOfFile1 != EOF && endOfFile2 != EOF) {
        if (data1.kode_buku < data2.kode_buku) {
            endOfFile1 = fscanf(buku, "%d %d %d %d\n", &data1.kode_buku, &data1.jenis, &data1.harga_sewa, &data1.stok);
        } else if (data1.kode_buku > data2.kode_buku) {
            endOfFile2 = fscanf(buku2, "%d %d %d %d\n", &data2.kode_buku, &data2.jenis, &data2.harga_sewa, &data2.stok);
        } else {
            fprintf(buku3, "%d %d %d %d\n", data1.kode_buku, data1.jenis, data1.harga_sewa, data1.stok);
            endOfFile1 = fscanf(buku, "%d %d %d %d\n", &data1.kode_buku, &data1.jenis, &data1.harga_sewa, &data1.stok);
            endOfFile2 = fscanf(buku2, "%d %d %d %d\n", &data2.kode_buku, &data2.jenis, &data2.harga_sewa, &data2.stok);
        }
    }

    fclose(buku);
    fclose(buku2);
    fclose(buku3);
}

void MergeUnion() {
    databuku data1, data2;
    buku = fopen("buku.txt", "rt");
    buku2 = fopen("buku2.txt", "rt");
    buku3 = fopen("gabungbukuOR.txt", "wt");

    if (buku == NULL || buku2 == NULL || buku3 == NULL) {
        printf("Error: Salah satu atau kedua file tidak dapat dibuka\n");
        exit(1);
    }

    while (fscanf(buku, "%d %d %d %d\n", &data1.kode_buku, &data1.jenis, &data1.harga_sewa, &data1.stok) != EOF) {
        fprintf(buku3, "%d %d %d %d\n", data1.kode_buku, data1.jenis, data1.harga_sewa, data1.stok);
    }

    while (fscanf(buku2, "%d %d %d %d\n", &data2.kode_buku, &data2.jenis, &data2.harga_sewa, &data2.stok) != EOF) {
        // Check if the current book from buku2 already exists in buku1 to avoid duplicates
        int duplicate = 0;
        rewind(buku);
        while (fscanf(buku, "%d %d %d %d\n", &data1.kode_buku, &data1.jenis, &data1.harga_sewa, &data1.stok) != EOF) {
            if (data2.kode_buku == data1.kode_buku) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            fprintf(buku3, "%d %d %d %d\n", data2.kode_buku, data2.jenis, data2.harga_sewa, data2.stok);
        }
    }

    fclose(buku);
    fclose(buku2);
    fclose(buku3);
}

void ShowResult(const char *filename) {
    databuku data;
    FILE *file = fopen(filename, "rt");

    if (file == NULL) {
        printf("Error: File %s tidak dapat dibuka\n", filename);
        exit(1);
    }

    printf("Hasil Gabungan dari File %s\n", filename);
    printf("Kode Buku\tJenis\tHarga Sewa\tStok\n");
    printf("--------------------------------\n");

    while (fscanf(file, "%d %d %d %d\n", &data.kode_buku, &data.jenis, &data.harga_sewa, &data.stok) != EOF) {
        printf("%d\t%d\t%d\t%d\n", data.kode_buku, data.jenis, data.harga_sewa, data.stok);
    }

    fclose(file);
}

