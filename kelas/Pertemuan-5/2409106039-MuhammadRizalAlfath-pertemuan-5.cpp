// passByValue.cpp
# include <iostream>
using namespace std;

struct orang{
    string nama;
    int umur;
};
int main(){

    // orang Orang;
    // Orang.nama = "Kalingga";
    // Orang.umur = 20;

    // orang* orang2 = &Orang;
    // cout << orang2->nama << endl;

    //-------------------------------------------------------

    int primeNumber[6] = {
        2,3,5,7,11,13
    };

    int (*ptrprimeNumber)[6] = &primeNumber;

    for (int i = 0; i < 6; i++){
        cout << (*ptrprimeNumber)[i] << endl;
    }

    cout << "pointer yang menunjuk ke suatu array"<< endl;
    int a[5] = {1,2,3,4,5};
    int (*aPtr)[5] = &a;
    for (int i =0; i <5; i++){
    cout << *aPtr <<endl;
    }

    cout << "Pointer yang menunjuk ke arah elemen array" <<endl;
    int b[5] = {1,2,3,4,5,};
    int *bPtr = b;
    for (int i = 0; i < 5; i++){
    cout << bPtr <<endl;
    // cout << *bPtr <<endl;
    bPtr++;
    }

    



    //------------------------------------------------------
    
    // int stack = 64;
    // int stacksnowball = 16;

    // cout << "stack : " << stack << endl; 
    // cout << "&stack : " << &stack << endl;

    // cout << "stacksnowball : " << stacksnowball << endl; 
    // cout << "&stacksnowball : " << &stacksnowball << endl;

    // int isi = stack;
    // cout << stack << endl;
    // cout << isi << endl;

    // stack = 69;
    // int* Isi = &stack;

    // cout << stack << endl;
    // cout << isi << endl;

    // stack = 16;
    // cout << "---------- setelah stack diubah -------------" << endl;
    // cout << isi << endl;

    // *Isi = isi + 10;
    // cout << "---setelah isi diubah----" << endl;

    // cout << stack << endl;
    // cout << *Isi << endl;

}