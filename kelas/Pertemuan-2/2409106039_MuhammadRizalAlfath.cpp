#include <iostream>
using namespace std;
int main() {
// Deklarasi array dan inisialisasi elemen array
string nama[4] = {"Haqi", "Dzaki", "Musang"};
// Deklarasi array tanpa inisialisasi elemen array
int angka[6] = {1,2,4,8,9};
string buah[8] = {"semangka","jeruk","apel","salak"};
angka[1] = 10;

for (int i = 1; i < 7; i++)
{
    angka[i] = angka[i+1];
}

// angka[0] = 10;
// angka[1] = 19;
// angka[2] = 30;
// angka[3] = 40;
// angka[4] = 50;
// cout << angka[2];
int totalByte = sizeof(angka);
int singleByte = sizeof(angka[0]);
int panjangArray  = sizeof(angka) / sizeof(angka[0]);

for (int i = 0; i < panjangArray; i++)
{
    cout << "nilai array :" << angka[i] << endl;
}

// for (int i : angka)
// {
//     cout << "Nilai Arrai :" << i << endl;
// }

// cin : command input
// cout : command output
// cerr : command error
// endl : endline
// using std::cout;
// int panjangArray2 = size(angka);

// cout << totalByte << "\n"
//      << singleByte << "\n"
//      << panjangArray << "\n"
//      << panjangArray2;
// cout << __cplusplus << endl;

return 0;
}