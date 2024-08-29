#include <iostream>
#include <conio.h> // For _getch()

using namespace std;

struct Simpul {
    int Info;
    Simpul* next;
};

void InsertFirst(Simpul** AwalList) {
    // Implementation for inserting at the beginning
}

void InsertLast(Simpul** AwalList) {
    // Implementation for inserting at the end
}

void InsertAfter(Simpul** AwalList) {
    // Implementation for inserting after a node
}

void DisplayList(Simpul** AwalList) {
    // Implementation for displaying the list
}

void DeleteFirst(Simpul** AwalList) {
    // Implementation for deleting the first node
}

void DeleteAfter(Simpul** AwalList) {
    // Implementation for deleting a node after a given node
}

Simpul* SearchData(Simpul** Head) {
    int FindData;
    cout << "Masukkan data yang akan dicari: ";
    cin >> FindData;

    Simpul* p;
    for (p = *Head; p != NULL && p->Info != FindData; p = p->next);

    return p;
}

void EditData(Simpul** Head) {
    Simpul* p = SearchData(Head);

    if (p != NULL) {
        int NewData;
        cout << "Masukkan data baru: ";
        cin >> NewData;

        p->Info = NewData;
        cout << "Data sudah diubah";
    } else {
        cout << "Data tidak ditemukan";
    }
}

int main() {
    Simpul* AwalList = NULL;
    bool loop = true;

    do {
        cout << endl;
        cout << "PRAKTIKUM LIST" << endl;
        cout << "==============" << endl;
        cout << "esc. Exit " << endl;
        cout << "1. Insert First " << endl;
        cout << "2. Insert Last " << endl;
        cout << "3. Insert After " << endl;
        cout << "4. Display List " << endl;
        cout << "5. Search Data " << endl;
        cout << "6. Delete First " << endl;
        cout << "7. Delete After " << endl;
        cout << "8. Edit Data " << endl;
        cout << endl;
        cout << "Masukan Pilihan : ";

        switch (_getch()) {
            case 23: {
                loop = false;
                cout << "Keluar dari program";
                break;
            }
            case '1': { InsertFirst(&AwalList); break; }
            case '2': { InsertLast(&AwalList); break; }
            case '3': { InsertAfter(&AwalList); break; }
            case '4': { DisplayList(&AwalList); break; }
            case '5': {
                if (SearchData(&AwalList) == NULL)
                    cout << "Data tidak ditemukan";
                else
                    cout << "Data ditemukan";
                break;
            }
            case '6': { DeleteFirst(&AwalList); break; }
            case '7': { DeleteAfter(&AwalList); break; }
            case '8': { EditData(&AwalList); break; }
            break;
        }
        cout << endl;
        system("PAUSE");
    } while (loop);

    return 0;
}
