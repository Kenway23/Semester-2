#include <stdio.h>
#include <string.h>

#define MAX_PEMESAN 100
#define MAX_JENIS_TRANSPORTASI 4

typedef struct {
  char nama_pemesan[50];
  int kode_transportasi;
  int jumlah_tiket;
  double total_penjualan;
} DataPenjualan;

typedef struct {
  char jenis_transportasi[20];
  double harga;
} DataTransportasi;

void inputDataPenjualan(DataPenjualan penjualan[], int *n);
void hitungTotalPenjualan(DataPenjualan penjualan[], int n);
void tampilkanRekapPenjualan(DataPenjualan penjualan[], int n, double batas, DataTransportasi transportasi[]);

int main() {
  DataPenjualan penjualan[MAX_PEMESAN];
  int n = 0;
  double batas;
  DataTransportasi transportasi[] = {
    {"Bus", 50000},
    {"Kereta Api", 100000},
    {"Ferry", 75000},
    {"Pesawat", 200000},
  };

  inputDataPenjualan(penjualan, &n);
  hitungTotalPenjualan(penjualan, n);

  printf("Cari data yang total penjualannya lebih kecil dari (X): ");
  scanf("%lf", &batas);

  tampilkanRekapPenjualan(penjualan, n, batas, transportasi);

  return 0;
}

void inputDataPenjualan(DataPenjualan penjualan[], int *n) {
  char lagi;

  do {
    printf("Nama Pemesan: ");
    scanf("%s", penjualan[*n].nama_pemesan);

    printf("Kode Transportasi(1.Bus,2.Kereta Api,3.Ferry,4.Pesawat): ");
    scanf("%d", &penjualan[*n].kode_transportasi);

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
  DataTransportasi transportasi[] = {
    {"Bus", 50000},
    {"Kereta Api", 100000},
    {"Ferry", 75000},
    {"Pesawat", 200000},
  };

  for (i = 0; i < n; i++) {
    penjualan[i].total_penjualan = penjualan[i].jumlah_tiket * transportasi[penjualan[i].kode_transportasi - 1].harga;

    if (penjualan[i].jumlah_tiket > 3) {
      penjualan[i].total_penjualan *= 0.9;
    }
  }
}
void tampilkanRekapPenjualan(DataPenjualan penjualan[], int n, double batas, DataTransportasi transportasi[]) {
  int i;

  printf("\nRekap Penjualan Tiket:\n");
  for (i = 0; i < n; i++) {
    if (penjualan[i].total_penjualan < batas) {
      printf("%d.\n", i + 1);
      printf("Nama Pemesan: %s\n", penjualan[i].nama_pemesan);
      printf("Jenis Transportasi: %s\n", transportasi[penjualan[i].kode_transportasi - 1].jenis_transportasi);
      printf("Total Penjualan: %.0lf\n\n", penjualan[i].total_penjualan);
    }
  }
}
