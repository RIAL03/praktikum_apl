#include <iostream>
using namespace std;

int main() {
    double angka1, angka2;
    char pilihan;

    while (true) {
        cout << "Masukkan angka pertama: ";
        cin >> angka1;

        cout << "Masukkan angka kedua: ";
        cin >> angka2;

        cout << "\nHasil Operasi Aritmatika:\n";
        cout << "Penjumlahan: " << angka1 + angka2 << endl;
        cout << "Pengurangan: " << angka1 - angka2 << endl;
        cout << "Perkalian  : " << angka1 * angka2 << endl;

        if (angka2 != 0) {
            cout << "Pembagian  : " << angka1 / angka2 << endl;
        } else {
            cout << "Pembagian  : Tidak dapat dibagi dengan nol!" << endl;
        }

        cout << "\nIngin melakukan perhitungan lagi? (y/n): ";
        cin >> pilihan;

        if (pilihan == 'n' || pilihan == 'N') {
            break;
        }
    }

    cout << "Program selesai." << endl;
    return 0;
}
