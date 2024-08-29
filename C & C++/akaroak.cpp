#include <iostream>

using namespace std;

int main(){
	float bilangan;
	double tebakan, presisi, hasil;
	presisi = 0.00001;
	cout << "Bilangan : "; cin >> bilangan;
	tebakan = bilangan / 2;
	while (tebakan + tebakan - bilangan > presisi ) {
		tebakan  = (tebakan + (bilangan/tebakan))/2;
	}
	hasil = sqrt(bilangan);
	cout << "Akar kuadrat dari"<< bilangan << ":" << tebakan
	cout << "Akar kuadrat dari " <<bilangan << ":" << hasil <<
	
	return 0;
}
