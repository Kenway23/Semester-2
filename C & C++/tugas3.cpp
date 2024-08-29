#include <iostream>
using namespace std;

    int main() {
        int nilai1,nilai2,jumlah=0;

        cout<<"Masukam Nilai integer pertama:";
         cin >>nilai1;
         cout<<"Masukam Nilai integer kedua:";
         cin >>nilai2;

         if(nilai2<nilai1){
            cout << "Eror : Nilai kedua harus lebih besar dari nilai pertama : "<<endl;
            return 1;
         }

         for(int i = nilai1 + 1;i<nilai2;i++){
            jumlah +=i;
         }

         cout << "Total Penjumlahan di antara "<<nilai1<<" Dan "<<nilai2<<" adalah: "<<jumlah<<endl;

         return 0;
    }