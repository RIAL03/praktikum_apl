#include <iostream>
#include <string>
using namespace std;

//Username : rizal
//Password : 039

int login(string username, string password){
    string cek_username;
    string cek_password;
    int percobaan = 3;

    while (percobaan > 0){
        cout << endl << "Masukan Username :";
        cin >> cek_username; 
        cout << "Masukan Password :";
        cin >> cek_password;
        if (cek_username == username && cek_password == password){
            return 1;
        }
        else {
            percobaan--;
            cout << endl << "Maaf Username atau Password salah, coba lagi" << endl;
            cout << "percobaan : " << percobaan << endl;
        }
    }
    cout << "maaf anda sudah tidak dapat login, percobaan habis";
    return 0;
}

void konversi_celcius(){
    float celcius;
    while (true) { 
        cout << endl << "Masukkan suhu dalam Celcius: ";
        cin >> celcius;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Input tidak valid! Masukkan angka.\n";
        } else {
            break;
        }
    }

    cout << "Suhu dalam Fahrenheit: " << (celcius * 9/5) + 32 << endl;
    cout << "Suhu dalam Reamur: " << celcius * 4/5 << endl;
    cout << "Suhu dalam Kelvin: " << celcius + 273.15 << endl; 
}

void konversi_fahrenheit(){
    float fahrenheit;
    while (true) { 
        cout << endl << "Masukkan suhu dalam Fahrenheit: ";
        cin >> fahrenheit;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Input tidak valid! Masukkan angka.\n";
        } else {
            break;
        }
    }

    cout << "Suhu dalam Celcius: " << (fahrenheit - 32) * 5/9 << endl;
    cout << "Suhu dalam Reamur: " << (fahrenheit - 32) * 4/9 << endl;
    cout << "Suhu dalam Kelvin: " << (fahrenheit - 32) * 5/9 + 273.15 << endl;   
}

void konversi_reamur(){
    float reamur;
    while (true) { 
        cout << endl << "Masukkan suhu dalam Reamur: ";
        cin >> reamur;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Input tidak valid! Masukkan angka.\n";
        } else {
            break;
        }
    }

    cout << "Suhu dalam Celcius: " << reamur * 5/4 << endl;
    cout << "Suhu dalam Fahrenheit: " << (reamur * 9/4) + 32 << endl;
    cout << "Suhu dalam Kelvin: " << (reamur * 5/4) + 273.15 << endl;   
}

void konversi_kelvin(){
    float kelvin;
    while (true) { 
        cout << endl << "Masukkan suhu dalam Kelvin: ";
        cin >> kelvin;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Input tidak valid! Masukkan angka.\n";
        } else {
            break;
        }
    }

    cout << "Suhu dalam Celcius: " << kelvin - 273.15 << endl;
    cout << "Suhu dalam Fahrenheit: " << (kelvin - 273.15) * 9/5 + 32 << endl;
    cout << "Suhu dalam Reamur: " << (kelvin - 273.15) * 4/5 << endl;
}

int main(){
    int result = login("rizal","039");
    int pilihan;

    while(result == 1){
        cout << "\nMenu Utama Konversi Suhu:\n";
        cout << "1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin\n";
        cout << "2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin\n";
        cout << "3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin\n";
        cout << "4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur\n";
        cout << "5. Keluar\n";
        
        while (true) { 
            cout << endl << "Pilih menu (1-5): ";
            cin >> pilihan;
    
            if (cin.fail()) { 
                cin.clear();
                cin.ignore(1000, '\n'); 
                cout << "Input tidak valid! Masukkan angka.\n";
            } else {
                break;
            }
        }
        

        if (pilihan == 1){
            konversi_celcius();
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
           
        }
        else if (pilihan == 2){
            konversi_fahrenheit();
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        }
        else if (pilihan == 3){
            konversi_reamur();
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        }
        else if (pilihan == 4){
            konversi_kelvin();
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get(); 
        }
        else if (pilihan == 5){
            cout << "Terima Kasih" << endl;
            break;   
        }
        else{
            cout << "Pilihan tidak valid! Silakan pilih menu yang benar." << endl;   
        }
    }  
    return 0; 
}