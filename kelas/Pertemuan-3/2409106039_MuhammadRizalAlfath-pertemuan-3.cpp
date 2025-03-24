#include <iostream>
using namespace std;

struct tanggal{
    int hari, bulan, tahun;
};

struct mahasiswa{
    string nama;
    int nim;
    string gender;
    tanggal tanggal_lahir;
};

int main(){

    mahasiswa mhsbaru;
    mahasiswa mhslama;

    mhsbaru.nama = "rangga";
    mhsbaru.nim = 43;
    mhsbaru.gender = "lakik";
    mhsbaru.tanggal_lahir.hari = 3;
    mhsbaru.tanggal_lahir.bulan = 3;
    mhsbaru.tanggal_lahir.tahun = 2006;

    cout << mhsbaru.nama << endl;
    cout << mhsbaru.nim << endl;
    cout << mhsbaru.gender << endl;

    cout << "Tanggal lahir : " << mhsbaru.tanggal_lahir.hari << "/" << mhsbaru.tanggal_lahir.bulan << "/" << mhsbaru.tanggal_lahir.tahun << endl << endl; 

    mahasiswa mhsabadi [5];
    mhsabadi[0].nama = "ifnu";
    mhsabadi[1].nama = "ahmad";
    mhsabadi[2].nama = "nashrul";
    mhsabadi[3].nama = "rava";

    for(int i = 0; i < size(mhsabadi); i++){
        cout << mhsabadi[i].nama << endl;
    }

    return 0;
}