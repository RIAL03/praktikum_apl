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
    AttackStrength att_str;
};

// Struct untuk menyimpan data user
struct User {
    string username;
    string password;
    bool is_admin;
};

// Const
const int maks_karakter = 10;
const int maks_user = 10;
const int maks_attempt = 3;

// Global variables
Karakter karakter[maks_karakter];
User users[maks_user];
int jumlahKarakter = 0;
int jumlahUser = 0;
bool is_login = false;
bool is_admin = false;
string userSekarang;

// Fungsi dengan parameter dereference
void printKarakterDetail(const Karakter *karakterPtr) {
    cout << "\nDetail Karakter (dereference):" << endl;
    cout << "Nama: " << karakterPtr->nama << endl;
    cout << "Health: " << karakterPtr->health << endl;
    cout << "Defense: " << karakterPtr->defense << endl;
    cout << "Attack: " << karakterPtr->att_str.attack << endl;
    cout << "Strength: " << karakterPtr->att_str.strength << endl;
}

// Fungsi dengan parameter address-of
void updateHealth(Karakter &karakterRef, int newHealth) {
    karakterRef.health = newHealth;
    cout << "Health karakter " << karakterRef.nama << " berhasil diupdate menjadi " << newHealth << endl;
}

void enter(bool tampilkan_enter = true) {
    if (tampilkan_enter) {
        cout << "\nTekan Enter untuk kembali ke menu...";
    }
    cin.ignore(1000, '\n');
    cin.get();
}

void login(int maks_percobaan = maks_attempt) {
    int attempt = 0;
    while (attempt < maks_percobaan) {
        string username, password;
        cout << "\n=== LOGIN ===" << endl;
        cout << "Percobaan ke-" << attempt + 1 << " dari " << maks_percobaan << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        bool found = false;
        for (int i = 0; i < jumlahUser; i++) {
            if (users[i].username == username && users[i].password == password) {
                found = true;
                is_login = true;
                userSekarang = username;
                is_admin = users[i].is_admin;
                cout << "Login berhasil!" << endl;
                cout << "Anda login sebagai " << (is_admin ? "Admin" : "User") << endl;
                return;
            }
        }

        if (!found) {
            attempt++;
            cout << "Username atau password salah!" << endl;
            if (attempt < maks_percobaan) {
                cout << "Anda memiliki " << maks_percobaan - attempt << " percobaan lagi.\n";
            }
        }
    }

    cout << "\nAnda telah gagal login sebanyak " << maks_percobaan << " kali.\n";
    cout << "Program akan berhenti. Silakan jalankan kembali program untuk mencoba lagi.\n";
    exit(0);
}

void registrasi(int maxUsers = maks_user) {
    if (jumlahUser >= maxUsers) {
        cout << "Kapasitas user penuh! Tidak bisa mendaftar." << endl;
        return;
    }

    string username, password;
    cout << "\n=== REGISTER ===" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].username == username) {
            cout << "Username sudah digunakan!" << endl;
            return;
        }
    }

    users[jumlahUser].username = username;
    users[jumlahUser].password = password;
    users[jumlahUser].is_admin = false;
    jumlahUser++;

    cout << "Registrasi berhasil! Silakan login." << endl;
}

void tambahKarakter(int maxCharacters = maks_karakter) {
    if (jumlahKarakter < maxCharacters) {
        string namaBaru;
        bool namaUnik = false; 
        
        cout << "Masukkan Nama Karakter: ";
        cin >> namaBaru;
        
        while (!namaUnik) { 
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

        // penggunaan fungsi dengan parameter dereference
        printKarakterDetail(&karakter[jumlahKarakter-1]);
        
        // penggunaan fungsi dengan parameter address-of
        updateHealth(karakter[jumlahKarakter-1], karakter[jumlahKarakter-1].health);

    } else {
        cout << "Data penuh! Tidak bisa menambahkan karakter baru.\n";
    }
}

void tampilkanKarakter(bool detailed = false) {
    if (jumlahKarakter == 0) {
        cout << endl << "Tidak ada karakter yang tersimpan.\n";
        return;
    }

    if (!detailed) {
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
    } else {
        cout << "\n==================== Daftar Karakter (Detailed) ====================\n"<< endl;
        cout << left << setw(5) << "No" 
             << setw(20) << "Nama"
             << setw(15) << "Attack"
             << setw(15) << "Strength"
             << setw(15) << "Defense"
             << setw(15) << "Health"
             << setw(15) << "Power Score" << endl;
        cout << "----------------------------------------------------------------------------\n";

        for (int i = 0; i < jumlahKarakter; i++) {
            int powerScore = (karakter[i].att_str.attack + karakter[i].att_str.strength) * (karakter[i].health / 10);
            cout << left << setw(5) << i+1
                 << setw(20) << karakter[i].nama
                 << setw(15) << karakter[i].att_str.attack 
                 << setw(15) << karakter[i].att_str.strength  
                 << setw(15) << karakter[i].defense
                 << setw(15) << karakter[i].health
                 << setw(15) << powerScore << endl;
        }
        cout << "----------------------------------------------------------------------------\n";
    }
}

void ubahKarakter(int startIndex = 0) {
    if (jumlahKarakter == 0) {
        cout << "Tidak ada karakter yang tersimpan.\n";
        return;
    } 
    
    tampilkanKarakter();
    
    int index;
    cout << "Masukkan nomor karakter yang ingin diubah: ";
    cin >> index;
    index--; 

    if (index >= startIndex && index < jumlahKarakter) {
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

        // penggunaan fungsi dengan parameter dereference
        printKarakterDetail(&karakter[index]);
        
        // penggunaan fungsi dengan parameter address-of
        updateHealth(karakter[index], karakter[index].health);

    } else {
        cout << "Nomor karakter tidak valid!\n";
    }
}

void hapusKarakter(bool confirm = false, int index = -1) {
    if (jumlahKarakter == 0) {
        cout << "Tidak ada karakter yang tersimpan.\n";
        return;
    }
    
    if (!confirm) {
        tampilkanKarakter();
        cout << "Masukkan nomor karakter yang ingin dihapus: ";
        cin >> index;
        index--;
        
        if (index >= 0 && index < jumlahKarakter) {
            cout << "Apakah Anda yakin ingin menghapus " << karakter[index].nama << "? (y/n): ";
            char choice;
            cin >> choice;
            
            if (choice == 'y' || choice == 'Y') {
                hapusKarakter(true, index);
            } else {
                cout << "Penghapusan dibatalkan.\n";
                enter();
            }
        } else {
            cout << "Nomor tidak valid!\n";
        }
        return;
    }
    
    for (int i = index; i < jumlahKarakter - 1; i++) {
        karakter[i] = karakter[i + 1];
    }
    jumlahKarakter--;
    cout << "Karakter berhasil dihapus!\n";
}

void adminMenu(bool adminsmenu = true) {
    int pilihan;
    while (true) { 
        if (adminsmenu) {
            cout << "\n=== MENU ADMIN (" << userSekarang << ") ===" << endl;
        }
        cout << "1. Tambah Karakter\n";
        cout << "2. Tampilkan Karakter\n";
        cout << "3. Ubah Karakter\n";
        cout << "4. Hapus Karakter\n";
        cout << "5. Logout\n" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        if (pilihan == 5) {
            is_login = false;
            is_admin = false;
            cout << "Logout berhasil.\n";
            break;
        }
        
        switch (pilihan) {
            case 1: tambahKarakter(); enter(); break;
            case 2: tampilkanKarakter(); enter(); break;
            case 3: ubahKarakter(); enter(); break;
            case 4: hapusKarakter(); enter(); break;
            default:
                cout << endl << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    }
}

void userMenu(bool adminsmenu = true) {
    int pilihan;
    if (adminsmenu) {
        cout << "\n=== MENU USER (" << userSekarang << ") ===" << endl;
    }
    cout << "1. Lihat Karakter" << endl;
    cout << "2. Lihat Karakter (Detailed)" << endl;
    cout << "3. Logout" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: 
            tampilkanKarakter();
            enter(); 
            break;
        case 2:
            tampilkanKarakter(true);
            enter();
            break;
        case 3:
            is_login = false;
            cout << "Logout berhasil." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }
}

int main(int argc, char* argv[]) {
    users[jumlahUser++] = {"rizal", "039", true};

    int menu_utama;

    while (true) {
        if (!is_login) {
            cout << "\n=== MENU UTAMA ===" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> menu_utama;

            switch (menu_utama) {
                case 1: login(); break;
                case 2: registrasi(); break;
                case 3: 
                    cout << "Keluar dari program." << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid!" << endl;
            }
        }
        else {
            if (is_admin) {
                adminMenu();
            }
            else {
                userMenu();
            }
        }
    }

    return 0;
}