#include <iostream>
using namespace std;

const int MAKS = 100;
string mahasiswa[MAKS];
int jumlahData = 0;

// CREATE - pakai reference di parameter (address-of param)
void tambahMahasiswa(string *data, int &jumlah, string namaBaru) {
  if (jumlah < MAKS) {
    *(data + jumlah) = namaBaru; // dereference pointer
    jumlah++;                    // langsung pakai reference (tanpa dereference)
    cout << "Mahasiswa ditambahkan.\n";
  } else {
    cout << "Data penuh!\n";
  }
}

// READ
void tampilMahasiswa(string *data, const int &jumlah) {
  cout << "\nDaftar Mahasiswa:\n";
  for (int i = 0; i < jumlah; i++) {
    cout << i + 1 << ". " << *(data + i) << endl;
  }
}

// UPDATE
void ubahMahasiswa(string *data, const int &jumlah, int index,
                   string namaBaru) {
  if (index >= 0 && index < jumlah) {
    *(data + index) = namaBaru;
    cout << "Data berhasil diubah.\n";
  } else {
    cout << "Index tidak valid!\n";
  }
}

// DELETE
void hapusMahasiswa(string *data, int &jumlah, int index) {
  if (index >= 0 && index < jumlah) {
    for (int i = index; i < jumlah - 1; i++) {
      *(data + i) = *(data + i + 1);
    }
    jumlah--;
    cout << "Data berhasil dihapus.\n";
  } else {
    cout << "Index tidak valid!\n";
  }
}

int main() {
  int pilihan;
  string nama;
  int index;

  do {
    cout << "\n===== MENU CRUD MAHASISWA (Param Reference + Pointer) =====\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Tampilkan Mahasiswa\n";
    cout << "3. Ubah Mahasiswa\n";
    cout << "4. Hapus Mahasiswa\n";
    cout << "5. Keluar\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
    case 1:
      cout << "Masukkan nama: ";
      getline(cin, nama);
      tambahMahasiswa(mahasiswa, jumlahData,
                      nama); // tidak perlu & lagi karena param sudah reference
      break;
    case 2:
      tampilMahasiswa(mahasiswa, jumlahData);
      break;
    case 3:
      tampilMahasiswa(mahasiswa, jumlahData);
      cout << "Masukkan nomor yang ingin diubah: ";
      cin >> index;
      cin.ignore();
      cout << "Masukkan nama baru: ";
      getline(cin, nama);
      ubahMahasiswa(mahasiswa, jumlahData, index - 1, nama);
      break;
    case 4:
      tampilMahasiswa(mahasiswa, jumlahData);
      cout << "Masukkan nomor yang ingin dihapus: ";
      cin >> index;
      hapusMahasiswa(mahasiswa, jumlahData, index - 1);
      break;
    case 5:
      cout << "Keluar dari program.\n";
      break;
    default:
      cout << "Pilihan tidak valid!\n";
    }

  } while (pilihan != 5);

  return 0;
}
