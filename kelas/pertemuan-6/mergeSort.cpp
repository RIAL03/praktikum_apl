#include <iostream>
using namespace std;

int arr[] = {38, 27, 43, 3, 9, 82, 10, 55};
int n = sizeof(arr) / sizeof(arr[0]);

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void mergeAsc(int arr[], int l, int m, int r)
{
    int temp[8];   // array sementara untuk hasil penggabungan
    int i = l;     // pointer untuk bagian kiri
    int j = m + 1; // pointer untuk bagian kanan
    int k = 0;     // pointer untuk temp

    // Bandingkan elemen dari kedua bagian, dan ambil yang lebih kecil
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari bagian kiri (kalau masih ada)
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari bagian kanan (kalau masih ada)
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Salin kembali dari temp ke array asli di posisi yang benar
    for (int x = 0; x < k; x++)
    {
        arr[l + x] = temp[x];
    }
}

// Fungsi utama merge sort (rekursif)
void mergeSortAsc(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;         // Cari titik tengah
        mergeSortAsc(arr, l, m);     // Urutkan bagian kiri
        mergeSortAsc(arr, m + 1, r); // Urutkan bagian kanan
        mergeAsc(arr, l, m, r);      // Gabungkan dua bagian yang sudah terurut
    }
}

void mergeDesc(int arr[], int l, int m, int r)
{
    int temp[8];   // array sementara untuk hasil penggabungan
    int i = l;     // pointer untuk bagian kiri
    int j = m + 1; // pointer untuk bagian kanan
    int k = 0;     // pointer untuk temp

    // Bandingkan elemen dari kedua bagian, dan ambil yang lebih besar
    while (i <= m && j <= r)
    {
        if (arr[i] > arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari bagian kiri (kalau masih ada)
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari bagian kanan (kalau masih ada)
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Salin kembali dari temp ke array asli di posisi yang benar
    for (int x = 0; x < k; x++)
    {
        arr[l + x] = temp[x];
    }
}

void mergeSortDesc(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;          // Cari titik tengah
        mergeSortDesc(arr, l, m);     // Urutkan bagian kiri
        mergeSortDesc(arr, m + 1, r); // Urutkan bagian kanan
        mergeDesc(arr, l, m, r);      // Gabungkan dua bagian yang sudah terurut
    }
}

int main()
{
    cout << "Sebelum sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSortAsc(arr, 0, n - 1); // Panggil merge sort dari awal sampai akhir array

    cout << "Sesudah sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Mengurutkan secara descending
    mergeSortDesc(arr, 0, n - 1); // Panggil merge sort dari awal sampai akhir array
    cout << "Sesudah sorting descending: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
