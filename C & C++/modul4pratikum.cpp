#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> //untuk menggunakan fungsi exit()

typedef struct { 
	char Nomor_Rekening[8];
	char Kode_Transaksi[2];
	double Jumlah;
} transaksi;

FILE *Data_Transaksi;

void InputData(transaksi proses[], int n) {
	printf("\nMasukkan data transaksi\n");
	for (int i = 0; i < n; i++) {
		printf("Masukan Nomor rekening: ");
		scanf("%7s", proses[i].Nomor_Rekening);
		while (getchar() != '\n'); 

		printf("Masukan Kode transaksi (D/K): ");
		scanf("%c", &proses[i].Kode_Transaksi);
		while (getchar() != '\n'); 

		printf("Masukan Jumlah Uang: ");
		scanf("%lf", &proses[i].Jumlah);
		while (getchar() != '\n'); 
	}

	FILE *Data_Transaksi = fopen("data_transaksi.txt", "ab");
	if (Data_Transaksi == NULL) {
		printf("Error: Tidak dapat membuka file untuk menulis.\n");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		fwrite(&proses[i], sizeof(transaksi), 1, Data_Transaksi);
	}

	fclose(Data_Transaksi);
	printf("Data transaksi berhasil disimpan ke dalam file.\n");	
}

void OutputData() {
	transaksi proses[13];
	FILE *Data_Transaksi = fopen("data_transaksi.txt", "rb");
	if (Data_Transaksi == NULL) {
		printf("Error: Tidak dapat membuka file untuk membaca.\n");
		return;
	}

	int i = 0;
	while (fread(&proses[i], sizeof(transaksi), 1, Data_Transaksi) && i < 13) {
		printf("Nomor Rekening: %s\nKode Transaksi: %c\nJumlah: Rp%.2f\n", 
			   proses[i].Nomor_Rekening, proses[i].Kode_Transaksi[0], proses[i].Jumlah);
		i++;
	}
	printf("\n");

	fclose(Data_Transaksi);
}

void menu_hitung_transaksi() {
	transaksi proses;
	FILE *Data_Transaksi = fopen("data_transaksi.txt", "rb");
	if (Data_Transaksi == NULL) {
		printf("Error: Tidak dapat membuka file untuk membaca.\n");
		return;
	}

	int jumlahDebit = 0;

	while (fread(&proses, sizeof(transaksi), 1, Data_Transaksi)) {
		if (proses.Kode_Transaksi[0] == 'D') {  
			jumlahDebit++;
		}
	}

	printf("Jumlah transaksi debit: %d\n", jumlahDebit);

	fclose(Data_Transaksi);
}

void menu_cari_maks_transaksi() {
	transaksi proses;
	FILE *Data_Transaksi = fopen("data_transaksi.txt", "rb");
	if (Data_Transaksi == NULL) {
		printf("Error: Tidak dapat membuka file untuk membaca.\n");
		return;
	}

	double maksDebit = 0.0;
	double maksKredit = 0.0;

	while (fread(&proses, sizeof(transaksi), 1, Data_Transaksi)) {
		if (proses.Kode_Transaksi[0] == 'D' && proses.Jumlah > maksDebit) {
			maksDebit = proses.Jumlah;
		} else if (proses.Kode_Transaksi[0] == 'K' && proses.Jumlah > maksKredit) {
			maksKredit = proses.Jumlah;
		}
	}

	printf("Nilai transaksi debit terbesar: Rp%.2f\n", maksDebit);
	printf("Nilai transaksi kredit terbesar: Rp%.2f\n", maksKredit);

	fclose(Data_Transaksi);
}

int main() {
	transaksi proses[13];
	int pilih_menu;
	int n;

	do {
		printf("Menu Utama\n");
		printf("1. Membuat File\n");
		printf("2. Membaca File\n");
		printf("3. Hitung Transaksi\n");
		printf("4. Cari transaksi\n");
		printf("0. Keluar\n");
		printf("Silahkan memilih menu 1-4: ");
		scanf("%d", &pilih_menu);
		printf("\n");
		while (getchar() != '\n'); 

		switch (pilih_menu) {
			case 1:
				printf("Berapa banyak transaksi yang akan dilakukan: ");
				scanf("%d", &n);
				while (getchar() != '\n'); 
				InputData(proses, n);
				break;
			case 2:
				OutputData();
				break;
			case 3:
				menu_hitung_transaksi(); 
				break;
			case 4:
				menu_cari_maks_transaksi();
				break;
			case 0:
				printf("Keluar dari program.\n");
				break;
			default:
				printf("Pilihan tidak ada\n");
				break;
		}
	} while (pilih_menu != 0);

	return 0;
}

