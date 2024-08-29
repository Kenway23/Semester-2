#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk menampilkan array
void displayArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fungsi Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Fungsi Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Fungsi untuk mendapatkan nilai maksimum dalam array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Fungsi Counting Sort untuk Radix Sort
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Fungsi Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// Fungsi Counting Sort
void countingSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    vector<int> count(maxVal + 1, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    char repeat;
    do {
        int n;
        cout << "Masukkan jumlah elemen array: ";
        cin >> n;
        vector<int> arr(n);
        
        cout << "Masukkan elemen array:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << "Array sebelum diurutkan: ";
        displayArray(arr);
        
        int choice;
        cout << "Pilih metode sorting:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Radix Sort\n";
        cout << "4. Counting Sort\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                insertionSort(arr);
                break;
            case 2:
                bubbleSort(arr);
                break;
            case 3:
                radixSort(arr);
                break;
            case 4:
                countingSort(arr);
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                continue;
        }
        
        cout << "Array setelah diurutkan: ";
        displayArray(arr);
        
        cout << "Apakah Anda ingin mengulang? (y/t): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
    
    return 0;
}

