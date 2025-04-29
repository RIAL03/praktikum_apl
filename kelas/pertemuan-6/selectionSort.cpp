#include <iostream>
using namespace std;

void selectionSortAsc(int a[], int panjang)
{
    // Loop untuk mengatur posisi elemen dari depan
    for (int i = 0; i < panjang - 1; i++)
    {
        int min = i; // Anggap elemen ke-i adalah yang terkecil

        // Cari elemen terkecil di sisa array (dari i+1 sampai akhir)
        for (int j = i + 1; j < panjang; j++)
        {
            if (a[j] < a[min])
            {
                min = j; // Update indeks elemen terkecil
            }
        }

        // Tukar elemen terkecil dengan elemen di posisi i
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        // Tampilkan hasil array setelah tiap tahap penukaran
        cout << "Tahap ke-" << i + 1 << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

void selectionSortDesc(int a[], int panjang)
{
    // Loop untuk mengatur posisi elemen dari depan
    for (int i = 0; i < panjang - 1; i++)
    {
        int max = i; // Anggap elemen ke-i adalah yang terbesar

        // Cari elemen terbesar di sisa array (dari i+1 sampai akhir)
        for (int j = i + 1; j < panjang; j++)
        {
            if (a[j] > a[max])
            {
                max = j; // Update indeks elemen terbesar
            }
        }
        // Tukar elemen terbesar dengan elemen di posisi i
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;

        // Tampilkan hasil array setelah tiap tahap penukaran
        cout << "Tahap ke-" << i + 1 << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[6] = {8, 45, 6, 12, 81, 32};
    int panjang = sizeof(arr) / sizeof(arr[0]);

    cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < panjang; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Data setelah diurutkan (Selection Sort Ascending):" << endl;
    selectionSortAsc(arr, panjang);

    cout << "Data setelah diurutkan (Selection Sort Descending):" << endl;
    selectionSortDesc(arr, panjang);
    return 0;
}
