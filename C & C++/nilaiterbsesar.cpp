#include <iostream>
using namespace std;

    int main() {
        int jumlah,angka,maksimum = 0;
         cout<<"Masukam jumlah angka yang angka diinput:";
         cin >>jumlah;
         
         for (int i = 0; i < jumlah; i++)
         {
            cout<<"Masukan Angka ke-"<<i+1<<":";
            cin>>angka;

            if (angka>maksimum)
            {
                maksimum = angka;
            }
            
         }

         cout << "Nilai Terbesar dari angka yang diinput adalah: "<< maksimum << endl;

         return 0 ;
         
    }