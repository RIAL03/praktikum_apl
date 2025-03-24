#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk menyimpan attack dan strength
struct AttackStrength {
    int attack;
    int strength;
};

// Struct untuk menyimpan data karakter
struct Karakter {
    string nama;
    int health;
    int defense;
    AttackStrength att_str; // Nested struct untuk attack dan strength
};

// Struct untuk menyimpan data user
struct User {
    string username;
    string password;
};

int main() {
    const int maks_karakter = 10;
    const int maks_user = 10;
    Karakter karakter[maks_karakter];

    User users[maks_user];
    int jumlahKarakter = 0;
    int jumlahUser = 0;

    // Admin
    users[jumlahUser++] = {"rizal", "039"};

    int menu_utama;
    bool logged_in = false;
    bool is_admin = false;
    string current_user;

    while (true) {
        if (!logged_in) {
            cout << "\n=== MENU UTAMA ===" << endl;
            cout << "1. Login User" << endl;
            cout << "2. Login Admin" << endl;
            cout << "3. Register User" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> menu_utama;

            if (menu_utama == 1) { // Login User
                string username, password;
                cout << "\n=== LOGIN USER ===" << endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                bool found = false;
                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        found = true;
                        logged_in = true;
                        current_user = username;
                        is_admin = false;
                        cout << "Login berhasil!" << endl;
                        break;
                    }
                }

                if (!found) {
                    cout << "Username atau password salah!" << endl;
                }
            }
            else if (menu_utama == 2) { // Login Admin
                int percobaan = 3;
                bool login_admin = false;
                
                while (percobaan > 0 && !login_admin) {
                    string username, password;
                    cout << "\n=== LOGIN ADMIN ===" << endl;
                    cout << "Percobaan tersisa: " << percobaan << endl;
                    cout << "Username: ";
                    cin >> username;
                    cout << "Password: ";
                    cin >> password;

                    bool found = false;
                    for (int i = 0; i < jumlahUser; i++) {
                        if (users[i].username == username && users[i].password == password) {
                            if (username == "rizal") { 
                                found = true;
                                login_admin = true;
                                logged_in = true;
                                current_user = username;
                                is_admin = true;
                                cout << "Login admin berhasil!" << endl;
                                break;
                            }
                        }
                    }

                    if (!found) {
                        percobaan--;
                        cout << "Username atau password salah!" << endl;
                        if (percobaan == 0) {
                            cout << "Maaf Anda telah salah login 3 kali." << endl;
                            return 0;
                        }
                    }
                }
            }
            else if (menu_utama == 3) { // Register User
                if (jumlahUser >= maks_user) {
                    cout << "Kapasitas user penuh! Tidak bisa mendaftar." << endl;
                    continue;
                }

                string username, password;
                cout << "\n=== REGISTER USER ===" << endl;
                cout << "Username: ";
                cin >> username;

                
                bool username_exists = false;
                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].username == username) {
                        username_exists = true;
                        break;
                    }
                }

                if (username_exists) {
                    cout << "Username sudah digunakan!" << endl;
                } else {
                    cout << "Password: ";
                    cin >> password;

                    users[jumlahUser].username = username;
                    users[jumlahUser].password = password;
                    jumlahUser++;

                    cout << "Registrasi berhasil! Silakan login." << endl;
                }
            }
            else if (menu_utama == 4) {
                cout << "Keluar dari program." << endl;
                return 0;
            }
            else {
                cout << "Pilihan tidak valid!" << endl;
            }
        }
        else {
            if (is_admin) { // Menu Admin
                int pilihan;
                while (pilihan != 5) { 
                    cout << "\n=== CRUD Statistik Karakter ===\n";
                    cout << "1. Tambah Karakter\n";
                    cout << "2. Tampilkan Karakter\n";
                    cout << "3. Ubah Karakter\n";
                    cout << "4. Hapus Karakter\n";
                    cout << "5. Logout\n" << endl;
                    cout << "Pilih menu: ";
                    cin >> pilihan;
            
                    if (pilihan == 1) { // CREATE (Tambah Karakter)
                        if (jumlahKarakter < maks_karakter) {
                            string namaBaru;
                            bool namaUnik = false; 
                    
                            cout << "Masukkan Nama Karakter: ";
                            cin >> namaBaru;
                    
                            while (namaUnik == false) { 
                                namaUnik = true; 
                    
                                for (int i = 0; i < jumlahKarakter; i++) {
                                    if (karakter[i].nama == namaBaru) {
                                        namaUnik = false; 
                                        cout << "Nama sudah digunakan! Pilih nama lain: ";
                                        cin >> namaBaru;
                                        break; 
                                    }
                                }
                            }
                    
                            karakter[jumlahKarakter].nama = namaBaru;
                            cout << "Masukkan Attack: ";
                            cin >> karakter[jumlahKarakter].att_str.attack; 
                            cout << "Masukkan Strength: ";
                            cin >> karakter[jumlahKarakter].att_str.strength; 
                            cout << "Masukkan Defense: ";
                            cin >> karakter[jumlahKarakter].defense;
                            cout << "Masukkan Health: ";
                            cin >> karakter[jumlahKarakter].health;
                    
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
                                     << setw(15) << karakter[i].nama
                                     << setw(10) << karakter[i].att_str.attack 
                                     << setw(10) << karakter[i].att_str.strength  
                                     << setw(10) << karakter[i].defense
                                     << setw(10) << karakter[i].health << endl;
                            }
                            cout << "------------------------------------------------------------\n";
                        }
                        cout << "\nTekan Enter untuk kembali ke menu...";
                        cin.ignore(1000, '\n');
                        cin.get();
                    } 
                    
                    else if (pilihan == 3) { // UPDATE (Ubah Karakter)
                        if (jumlahKarakter == 0) {
                            cout << "Tidak ada karakter yang tersimpan.\n";
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
                                     << setw(15) << karakter[i].nama
                                     << setw(10) << karakter[i].att_str.attack 
                                     << setw(10) << karakter[i].att_str.strength  
                                     << setw(10) << karakter[i].defense
                                     << setw(10) << karakter[i].health << endl;
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

                            if (karakter[index].nama != namaBaru) { 
                                bool namaUnik = false;
                                while (!namaUnik) { 
                                    namaUnik = true;

                                    for (int i = 0; i < jumlahKarakter; i++) {
                                        if (i != index && karakter[i].nama == namaBaru) {
                                            namaUnik = false;
                                            cout << "Nama sudah digunakan oleh karakter lain! Pilih nama lain: ";
                                            cin >> namaBaru;
                                            break;
                                        }
                                    }
                                }
                            }

                            karakter[index].nama = namaBaru;
                            cout << "Masukkan Attack Baru: ";
                            cin >> karakter[index].att_str.attack;
                            cout << "Masukkan Strength Baru: ";
                            cin >> karakter[index].att_str.strength;
                            cout << "Masukkan Defense Baru: ";
                            cin >> karakter[index].defense;
                            cout << "Masukkan Health Baru: ";
                            cin >> karakter[index].health;

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
                            cout << "Tidak ada karakter yang tersimpan.\n";
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
                                     << setw(15) << karakter[i].nama
                                     << setw(10) << karakter[i].att_str.attack 
                                     << setw(10) << karakter[i].att_str.strength  
                                     << setw(10) << karakter[i].defense
                                     << setw(10) << karakter[i].health << endl;
                            }
                            cout << "------------------------------------------------------------\n";
                        }
                        int index;
                        cout << "Masukkan nomor karakter yang ingin dihapus: ";
                        cin >> index;
                        index--;
            
                        if (index >= 0 && index < jumlahKarakter) {           
                            for (int i = index; i < jumlahKarakter - 1; i++) {
                                karakter[i] = karakter[i + 1];
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
                        logged_in = false;
                        is_admin = false;
                        cout << "Logout berhasil.\n";
                    } 
                    
                    else {
                        cout << endl << "Pilihan tidak valid! Silakan coba lagi.\n";
                    }
                }
            }
            else { // Menu User
                int pilihan;
                cout << "\n=== MENU USER (" << current_user << ") ===" << endl;
                cout << "1. Lihat Karakter" << endl;
                cout << "2. Logout" << endl;
                cout << "Pilihan: ";
                cin >> pilihan;

                if (pilihan == 1) { // Lihat Karakter
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
                                 << setw(15) << karakter[i].nama
                                 << setw(10) << karakter[i].att_str.attack 
                                 << setw(10) << karakter[i].att_str.strength  
                                 << setw(10) << karakter[i].defense
                                 << setw(10) << karakter[i].health << endl;
                        }
                        cout << "------------------------------------------------------------\n";
                    }
                    cout << "\nTekan Enter untuk kembali ke menu...";
                    cin.ignore(1000, '\n');
                    cin.get();
                }
                else if (pilihan == 2) { // Logout
                    logged_in = false;
                    cout << "Logout berhasil." << endl;
                }
                else {
                    cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }

    return 0;
}