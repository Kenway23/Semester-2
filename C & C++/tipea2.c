#include <stdio.h>
#include <string.h>

#define MAX_PEMESAN 100
#define MAX_JENIS_TRANSPORTASI 4

typedef struct {
  char nama_pemesan[50];
  char asal_jurusan;
  int jumlah_tiket;
  double total_penjualan;
} DataPenjualan;

typedef struct {
  char data_tiket[100];
  double harga;
} DataTiket;

void inputDataPenjualan(DataPenjualan penjualan[], int *n);
void hitungTotalPenjualan(DataPenjualan penjualan[], int n);
void tampilkanRekapPenjualan(DataPenjualan penjualan[], int n, double batas, DataTiket data_tiket[]);

int main() {
  DataPenjualan penjualan[MAX_PEMESAN];
  int n = 0;
  double batas;
  DataTiket data_tiket[] = {
  {"Bandung-Jakarta", 100000},
  {"Jakarta-Bandung", 100000},
  {"Bandung-Surabaya", 300000},
  {"Surabaya-Bandung", 300000},
  };

  inputDataPenjualan(penjualan, &n);
  hitungTotalPenjualan(penjualan, n);

  printf("Cari data yang total penjualannya lebih besar dari (X): ");
  scanf("%lf", &batas);

  tampilkanRekapPenjualan(penjualan, n, batas, data_tiket);

  return 0;
}

void inputDataPenjualan(DataPenjualan penjualan[], int *n) {
  char lagi;

  do {
    printf("Nama Pemesan: ");
    scanf("%s", penjualan[*n].nama_pemesan);

    printf("Kode Jurusan(1.Bandung-Jakarta,2.Jakarta-Bandung,3.Bandung-Surabaya,4.Surabaya-Bandung): ");
    scanf("%d", &penjualan[*n].asal_jurusan);

    printf("Jumlah Tiket: ");
    scanf("%d", &penjualan[*n].jumlah_tiket);

    hitungTotalPenjualan(&penjualan[*n], 1);

    (*n)++;

    printf("Data Berhasil Input! Tambah lagi? (Y/T): ");
    scanf(" %c", &lagi);
  } while (lagi == 'Y' || lagi == 'y');
}

void hitungTotalPenjualan(DataPenjualan penjualan[], int n) {
  int i;
  DataTiket data_tiket[] = {
  {"Bandung-Jakarta", 100000},
  {"Jakarta-Bandung", 100000},
  {"Bandung-Surabaya", 300000},
  {"Surabaya-Bandung", 300000},
  };

  for (i = 0; i < n; i++) {
    penjualan[i].total_penjualan = penjualan[i].jumlah_tiket * data_tiket[penjualan[i].asal_jurusan - 1].harga;

    if (penjualan[i].jumlah_tiket > 2) {
      penjualan[i].total_penjualan *= 0.95; //diskon 5%
    }
  }
}
void tampilkanRekapPenjualan(DataPenjualan penjualan[], int n, double batas, DataTiket data_tiket[]) {
  int i;

  printf("\nRekap Penjualan Tiket:\n");
  for (i = 0; i < n; i++) {
    if (penjualan[i].total_penjualan > batas) {
      printf("%d.\n", i + 1);
      printf("Nama Pemesan: %s\n", penjualan[i].nama_pemesan);
      printf("Jenis Transportasi: %s\n", data_tiket[penjualan[i].asal_jurusan - 1].data_tiket);
      printf("Total Penjualan: %.0lf\n\n", penjualan[i].total_penjualan);
      printf("-------------------------\n");
    }
  }
}
