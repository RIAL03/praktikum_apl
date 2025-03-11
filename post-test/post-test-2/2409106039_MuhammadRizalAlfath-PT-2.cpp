#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int maks = 10; 
    string nama[maks];
    int health[maks], defense[maks]; // Array 1 dimensi
    int att_str[maks][2]; // Array 2D / multidimensi
    int jumlahKarakter = 0;
    

    string cek_username, cek_password;
    int percobaan = 3;
    bool login;


    while (percobaan > 0){
        cout << endl << "Masukan Username :";
        cin >> cek_username; 
        cout << "Masukan Password :";
        cin >> cek_password;
        if (cek_username == "rizal" && cek_password == "039"){
            login = true;
            break;
        }
        else {
            percobaan--;
            cout << endl << "Maaf Username atau Password salah, coba lagi" << endl;
            cout << "percobaan : " << percobaan << endl;
        }
    }

    if (login == true){
        int pilihan;
        while (pilihan != 5) { 
            cout << "\n=== CRUD Statistik Karakter ===\n";
            cout << "1. Tambah Karakter\n";
            cout << "2. Tampilkan Karakter\n";
            cout << "3. Ubah Karakter\n";
            cout << "4. Hapus Karakter\n";
            cout << "5. Keluar\n" << endl;
            cout << "Pilih menu: ";
            cin >> pilihan;
    
            if (pilihan == 1) { // CREATE (Tambah Karakter)
                if (jumlahKarakter < maks) {
                    string namaBaru;
                    bool namaUnik = false; 
            
                    cout << "Masukkan Nama Karakter: ";
                    cin >> namaBaru;
            
                    while (namaUnik == false) { 
                        namaUnik = true; 
            
                        for (int i = 0; i < jumlahKarakter; i++) {
                            if (nama[i] == namaBaru) {
                                namaUnik = false; 
                                cout << "Nama sudah digunakan! Pilih nama lain: ";
                                cin >> namaBaru;
                                break; 
                            }
                        }
                    }
            
                    nama[jumlahKarakter] = namaBaru;
                    cout << "Masukkan Attack: ";
                    cin >> att_str[jumlahKarakter][0]; 
                    cout << "Masukkan Strength: ";
                    cin >> att_str[jumlahKarakter][1]; 
                    cout << "Masukkan Defense: ";
                    cin >> defense[jumlahKarakter];
                    cout << "Masukkan Health: ";
                    cin >> health[jumlahKarakter];
            
                    jumlahKarakter++;
                    cout << endl << "Karakter berhasil ditambahkan!\n";
                    cout << "\nTekan Enter untuk kembali ke menu...";
                    cin.ignore(1000, '\n');
                    cin.get();
                } else {
                    cout << "Data penuh! Tidak bisa menambahkan karakter baru.\n";
                }
            } 
            
            else if (pilihan == 2) { // READ (Tampilkan Karakter)
                if (jumlahKarakter == 0) {
                    cout << endl << "Tidak ada karakter yang tersimpan.\n";
                } else {
                    cout << "\n==================== Daftar Karakter ====================\n"<< endl;
                    cout << left << setw(5) << "No" 
                         << setw(15) << "Nama"
                         << setw(10) << "Attack"
                         << setw(10) << "Strength"
                         << setw(10) << "Defense"
                         << setw(10) << "Health" << endl;
                    cout << "------------------------------------------------------------\n";
    
                    for (int i = 0; i < jumlahKarakter; i++) {
                        cout << left << setw(5) << i+1
                             << setw(15) << nama[i]
                             << setw(10) << att_str[i][0] 
                             << setw(10) << att_str[i][1]  
                             << setw(10) << defense[i]
                             << setw(10) << health[i] << endl;
                    }
                    cout << "------------------------------------------------------------\n";
                }
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.ignore(1000, '\n');
                cin.get();
            } 
            
            else if (pilihan == 3) { // UPDATE (Ubah Karakter)
                if (jumlahKarakter == 0) {
                    
                } 
                
                else {
                    cout << "\n==================== Daftar Karakter ====================\n"<< endl;
                    cout << left << setw(5) << "No" 
                         << setw(15) << "Nama"
                         << setw(10) << "Attack"
                         << setw(10) << "Strength"
                         << setw(10) << "Defense"
                         << setw(10) << "Health" << endl;
                    cout << "------------------------------------------------------------\n";
    
                    for (int i = 0; i < jumlahKarakter; i++) {
                        cout << left << setw(5) << i+1
                             << setw(15) << nama[i]
                             << setw(10) << att_str[i][0] 
                             << setw(10) << att_str[i][1]  
                             << setw(10) << defense[i]
                             << setw(10) << health[i] << endl;
                    }
                    cout << "------------------------------------------------------------\n";
                }
            
                int index;
                cout << "Masukkan nomor karakter yang ingin diubah: ";
                cin >> index;
                index--; 

                if (index >= 0 && index < jumlahKarakter) {
                    string namaBaru;
                    cout << "Masukkan Nama Baru: ";
                    cin >> namaBaru;

                    if (nama[index] != namaBaru) { 
                        bool namaUnik = false;
                        while (!namaUnik) { 
                            namaUnik = true;

                            for (int i = 0; i < jumlahKarakter; i++) {
                                if (i != index && nama[i] == namaBaru) {
                                    namaUnik = false;
                                    cout << "Nama sudah digunakan oleh karakter lain! Pilih nama lain: ";
                                    cin >> namaBaru;
                                    break;
                                }
                            }
                        }
                    }

                    nama[index] = namaBaru;
                    cout << "Masukkan Attack Baru: ";
                    cin >> att_str[index][0];
                    cout << "Masukkan Strength Baru: ";
                    cin >> att_str[index][1];
                    cout << "Masukkan Defense Baru: ";
                    cin >> defense[index];
                    cout << "Masukkan Health Baru: ";
                    cin >> health[index];

                    cout << endl << "Data karakter berhasil diperbarui!\n";
                    cout << "\nTekan Enter untuk kembali ke menu...";
                    cin.ignore(1000, '\n');
                    cin.get();
                } else {
                    cout << "Nomor karakter tidak valid!\n";
                }
            } 
            
            else if (pilihan == 4) { // DELETE (Hapus Karakter)
                if (jumlahKarakter == 0) {
                    
                } 
                
                else {
                    cout << "\n==================== Daftar Karakter ====================\n"<< endl;
                    cout << left << setw(5) << "No" 
                         << setw(15) << "Nama"
                         << setw(10) << "Attack"
                         << setw(10) << "Strength"
                         << setw(10) << "Defense"
                         << setw(10) << "Health" << endl;
                    cout << "------------------------------------------------------------\n";
    
                    for (int i = 0; i < jumlahKarakter; i++) {
                        cout << left << setw(5) << i+1
                             << setw(15) << nama[i]
                             << setw(10) << att_str[i][0] 
                             << setw(10) << att_str[i][1]  
                             << setw(10) << defense[i]
                             << setw(10) << health[i] << endl;
                    }
                    cout << "------------------------------------------------------------\n";
                }
                int index;
                cout << "Masukkan nomor karakter yang ingin dihapus: ";
                cin >> index;
                index--;
    
                if (index >= 0 && index < jumlahKarakter) {           
                    for (int i = index; i < jumlahKarakter - 1; i++) {
                        nama[i] = nama[i + 1];
                        att_str[i][0] = att_str[i + 1][0]; 
                        att_str[i][1] = att_str[i + 1][1];  
                        defense[i] = defense[i + 1];
                        health[i] = health[i + 1];
                    }
                    jumlahKarakter--;
                    cout << endl << "Karakter berhasil dihapus!\n";
                    cout << "\nTekan Enter untuk kembali ke menu...";
                    cin.ignore(1000, '\n');
                    cin.get();
                } else {
                    cout << endl << "Nomor karakter tidak valid!\n";
                }
            } 
            
            else if (pilihan == 5) { 
                cout << "Keluar dari program.\n";
            } 
            
            else {
                cout << endl << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        }
    }
    else {
        cout << endl << "maaf anda sudah tidak dapat login, percobaan habis" << endl;
    }
    return 0;
}