#include <iostream>
#include <stdlib.h>
#include <string>
#include "program.h"
#include "login.h"


int main();
#define max 20
using namespace std;
int main(){
    
    
    int pil;
    
    cout<<"WELCOME !!!"<<endl;
    cout<<endl;

    
    cout<<"1.Login"<<endl;
    cout<<"2.Sign Up"<<endl;
    cout<<"3.Forgot?"<<endl<<endl;

    cout<<"> ";
    cin>>pil;

    switch(pil){
        case 1:
        login();
        break;

        case 2:
        registr();
        break;

        case 3:
        forgot();
        break;

        case 4:
        default:
        cout<<"pilihan salah"<<endl;

    }



    menu_awal(); //memanggil fungsi menu_awal untuk memulai dari awal programnya
    system("cls");
    int pilihan, n, nobarang[max];
    string namabarang[max];
    int hargabarang[max];


    do
    {
    menu1:
    cout<<"==================================================="<<endl;
    cout<<"|           FINAL PROJECT STRUKTUR DATA           |"<<endl;
    cout<<"|                    KELOMPOK 7                   |"<<endl;
    cout<<"|                 WAREHOUSE TECHNO                |"<<endl;
    cout<<"==================================================="<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"        ==================================="<<endl;
    cout<<"        ||                               ||"<<endl;
    cout<<"        ||     1. Input Barang           ||"<<endl;
    cout<<"        ||     2. Hapus Barang           ||"<<endl;
    cout<<"        ||     3. Tampilkan Barang       ||"<<endl;
    cout<<"        ||     4. Urutkan Barang         ||"<<endl;
    cout<<"        ||     5. Cari Barang            ||"<<endl;
    cout<<"        ||     6. Edit Barang            ||"<<endl;
    cout<<"        ||     7. Bersihkan Barang       ||"<<endl;
    cout<<"        ||     8. Tentang                ||"<<endl;
    cout<<"        ||     9. Keluar                 ||"<<endl;
    cout<<"        ||                               ||"<<endl;
    cout<<"        ==================================="<<endl<<endl;
    cout<<"              > ";
    cin>>pilihan;

    switch(pilihan)
    {
        case 1:

        system("cls");

        cout << "=======================INPUT BARANG==============================="<< endl<<endl;
        cout << "Masukan banyak barang yang akan dimasukkan ke Rak (max 20) : ";
        cin >> n;
        cout<<endl;
        cout << "=================================================================="<< endl<<endl;
        for(int i = 0; i < n; i++)
        {
            cin.ignore();
            cout<<endl<<endl;
            cout << "       Masukkan barang ke-"<< i+1 <<endl;
            cout<<"---------------------------------"<<endl;
            cout<<endl;
            cout << "Nama Barang        : ";
            getline(cin, namabarang[i]);

            cout << "Harga barang       : ";
            cin >>hargabarang[i];
            cin.ignore();
            
            cout<< "Kode Barang        : ";
            cin >> nobarang[i];
          

            input_barang(namabarang[i], hargabarang[i], nobarang[i]);
        }
        break;

        case 2:

        system("cls");

        cout << "HAPUS BARANG"<<endl;
        hapus();
        break;

        case 3:

        system("cls");

        cout << ""<<endl;
        tampilkan_barang();
        break;

        case 4:

        system("cls");

        cout << "MENGURUTKAN BARANG"<<endl;
        menu_sorting();
        break;

        case 5:

        system("cls");

        cout << "MENCARI BARANG"<<endl;
        menu_search();
        break;

        case 6:

        system("cls");

        cout << "MENGEDIT BARANG"<<endl;
        edit();
        break;

        case 7:

        system("cls");
        bersih();
        cout << "RAK SUDAH BERSIH"<<endl;
        break;


        case 8:
        system("cls");

        cout<<"==================================================="<<endl;
        cout<<"|                   DEVELOPED by                  |"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"|    MAULANA RIZKY RAHMADHANI (21.11.4465)        |"<<endl;
        cout<<"|       MUHAMMAD QURAIS SIHAB (21.11.4407)        |"<<endl;
        cout<<"|           ALEX FREDY SUJITO (21.11.4403)        |"<<endl;
        cout<<"|          BAGUS ADHI LAKSANA (21.11.4439)        |"<<endl;
        cout<<"|            RAIHAN MAULUDANA (21.11.4453)        |"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"==================================================="<<endl;
        system("pause");
        system("cls");
        goto menu1;

        break;


        case 9:
        system("cls");
        main();
        

        cout<<"======================="<<endl;
        cout<<"===  TERIMA KASIH   ==="<<endl;
        cout<<"======================="<<endl;
        cout<<endl;    
    }
    cout << endl;
    system("pause");
    system("cls");
    }
    while (pilihan != 8);
}

