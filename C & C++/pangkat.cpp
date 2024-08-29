#include <iostream>
using namespace std;

int main()
{
  int angka, pangkat;
  cout << "Masukan Nilai Yang Ingin Dipangkatkan : ";
  cin >> angka;
  cout << "Masukan Nilai Pangkat : ";
  cin >> pangkat;

  int hasil = 1;

  for (int i = 1; i <= pangkat; i++)
  {
    hasil *= angka;
  }

  cout << "Hasil Pemangkatan " << angka << " Pangkat " << pangkat << " Adalah : " << hasil << endl;
  cin >> angka;
  return 0;
}
