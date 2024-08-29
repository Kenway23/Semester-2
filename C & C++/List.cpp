#include <iostream>
#include <conio.h>

using namespace std;

struct Simpul {
   int Info;
   struct Simpul *Next;
};
Simpul *Head = NULL;
void InsertFirst(Simpul **AwalList);
void InsertLast(Simpul **AwalList);
void InsertAfter(Simpul **AwalList);
void DisplayList(Simpul **AwalList);
Simpul* SearchData(Simpul **AwalList);
void DeleteFirst(Simpul **AwalList);
void DeleteAfter(Simpul **AwalList);
void EditData(Simpul **Head);

int main()
{
    Simpul *AwalList = NULL;
    bool loop = true;
    
    do {
    cout <<endl;
    cout << "PRAKTIKUM LIST" << endl;
    cout << "==============" << endl;
    cout << "esc. Exit "<< endl;
    cout << "1. Insert First " << endl;
    cout << "2. Insert Last " << endl;
    cout << "3. Insert After " << endl;
    cout << "4. Insert List " << endl;
    cout << "5. Search Data " << endl;
    cout << "6. Delete First " << endl;
    cout << "7. Delete After " << endl;
    cout << "8. Edit Data " << endl;
    cout << endl;
    cout << "Masukan Pilihan : ";
    
    switch(_getch())
    {
        case 23 : {
        loop = false;
        cout << "exit..by";
        break;
        }
        case '1': { InsertFirst(&AwalList); break;}
        case '2': { InsertLast(&AwalList); break;}
        case '3': { InsertAfter(&AwalList); break;}
        case '4': { DisplayList(&AwalList); break;}
        case '5': {
        	int FindData;
        	cout << "Inp Data Yang Akan Dicari : ";
        	cin >> FindData;
        	
        	Simpul *p;
    		for (p = Head; p != NULL && p->Info != FindData; p = p->Next);

        	//if (p==NULL) cout << "Data yang di cari tidak ada";	
			return p;
			
			
//        if (SearchData(&AwalList)==NULL)
//            cout << "Data tdk ada";
//            else cout << "Data ditemukan";
            break;
	     }
        case '6': { DeleteFirst(&AwalList); break;}
        case '7': { DeleteAfter(&AwalList); break;}
        case '8': { //EditData(&AwalList); 
			Simpul *p = SearchData(&Head);
			if (p!=NULL){
				int NewData;
				cout << "Inp Data Baru : ";
				cin >> NewData;
				p->Info = NewData;
				cout << "Data Sudah Diubah";
			}
			
		break;
		
	}
        break;
    }
    cout <<endl;
    system("PAUSE");
    }
    while (loop);
    return 0;
    
}
