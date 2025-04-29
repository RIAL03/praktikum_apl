#include <iostream>
using namespace std;

void insertionSortAsc(int a[], int panjang)
{
    // Mulai dari elemen kedua, karena elemen pertama dianggap sudah terurut
    for (int i = 1; i < panjang; i++)
    {
        int key = a[i]; // Simpan elemen yang mau disisipkan
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j]; // Geser elemen ke kanan
            j--;             // Geser indeks ke kiri
        }

        // Tempatkan key di posisi yang tepat
        a[j + 1] = key;

        // Tampilkan array setelah setiap penyisipan
        cout << "Tahap ke-" << i << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

void insertionSortDesc(int a[], int panjang)
{
    // Mulai dari elemen kedua, karena elemen pertama dianggap sudah terurut
    for (int i = 1; i < panjang; i++)
    {
        int key = a[i]; // Simpan elemen yang mau disisipkan
        int j = i - 1;

        // Geser elemen yang lebih kecil dari key ke kanan
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j]; // Geser elemen ke kanan
            j--;             // Geser indeks ke kiri
        }

        // Tempatkan key di posisi yang tepat
        a[j + 1] = key;

        // Tampilkan array setelah setiap penyisipan
        cout << "Tahap ke-" << i << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[6] = {7, 5, 10, 8, 32, 24};
    int panjang = sizeof(arr) / sizeof(arr[0]);

    cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < panjang; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSortAsc(arr, panjang);
    cout << "Data setelah diurutkan (Ascending): ";
    for (int i = 0; i < panjang; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    insertionSortDesc(arr, panjang);
    cout << "Data setelah diurutkan (Descending): ";
    for (int i = 0; i < panjang; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
