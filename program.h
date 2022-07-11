#include <iostream>
#define max 20 //inisialisasi variable max bisa menampung stack sebanyak 20 data
#include <string>
using namespace std;

struct tumpukan{   //struktur = membuat struct tumpukan yang dipakai untuk menyimpan data pada tumpukan, data dibuat dengan array
    int atas; //variable atas berfungsi untuk menandai data paling atas
    int nobarang[max]; //max mampu menampung 20 data sesuai yang di inisialisasikan pada #define max 20 di atas
    string namabarang[max];
    int hargabarang[max];

}T; //mendeklarasikan stack ke T (typedeff)

void menu_awal() //init/inisialisasi = set awal program, set nilai tumpukannya ke -1 haya sebagai nilai awal program
{
    T.atas = -1;
}

int kosong() //isEmpty, mengecek apakah tumpukan atas masih -1 atau tidak, kalau -1 maka mengembalikan nilai 1 atau true, jika masih -1 berarti tumpukkannya masih kosong
{
    if(T.atas == -1)
    return 1;
    else
    return 0;
}

int penuh() //isFull. digunakan mengecek tumpukan penuh atau belum
{
     if(T.atas == max-1)
     return 1;
     else
     return 0;
}

void input_barang(string namabarang, int hargabarang, int nobarang) //push
{
    if(kosong() == 1)
    {
        T.atas++; //atasnya di naikkan
        T.nobarang[T.atas] = nobarang;
        T.namabarang[T.atas] = namabarang;
        T.hargabarang[T.atas] = hargabarang;
        cout<<"\n"<<T.namabarang[T.atas]<<" Sudah masuk ke rak no "<< T.atas+1<<endl;
        cout<<"================================="<<endl;
    }
    else if(penuh() == 0)
    {
        T.atas++;
        T.nobarang[T.atas] = nobarang;
        T.namabarang[T.atas] = namabarang;
        T.hargabarang[T.atas] = hargabarang;
        cout<<"\n"<<T.namabarang[T.atas]<<" Sudah masuk ke rak no "<< T.atas+1<<endl;
        cout<<"================================="<<endl;
    }
    else
        cout<<"\nMaaf rak sudah penuh";
}

void tampilkan_barang()
{
    if(kosong() == 0)
    {
        for(int i = 0; i <= T.atas; i++)
        {
            
            cout<<"---------------------------------"<<endl;
            cout<<"\nBarang terletak di rak no "<< i+1 <<endl;
            cout<<"Nama barang  : "<<T.namabarang[i] <<endl;
            cout<<"Harga        : Rp. "<<T.hargabarang[i]<<endl;
            cout<<"Kode Barang  : "<<T.nobarang[i]<<endl;
            cout<<"---------------------------------"<<endl;
        }
    }
    else
        cout<<"\nRak masih kosong\n";
}

void edit()
{
    if(kosong() == 0)
    {
        int ganti, i;
        tampilkan_barang();

        cout<<"\n\nMasukkan kode barang yang akan diubah = ";
        cin>>ganti;
        cin.ignore();

        for (i = 0; i <= T.atas + 1; i++)
        {
            if(ganti == T.nobarang[i])
            {
                cout<<"Masukkan nama barang baru = ";
                getline(cin, T.namabarang[i]);
                cout<<"Masukkan harga barang baru = ";
                cin>>T.hargabarang[i];
                cout<<"Masukkan kode barang baru = ";
                cin>>T.nobarang[i];
                cout<<"\n\nData berhasil diubah\n";
            }else if(i > T.atas)
                cout<<"\nBarang tidak ditemukan"<<endl;   
        }
    }else
    cout<<"\nRak masih kosong\n";
}

void hapus()
{
    if(kosong() == 0)
    {
        tampilkan_barang();

        string tempnama;
        int temp, tempno, kode;
        int berhasil = 0;
        int i, j;
        int tempharga;
        cout<<"\nMasukan kode barang yang akan dihapus : ";
        cin>>kode;
        for(i = 0; i < T.atas + 1; i++)
        {
            for(j = 0; j < T.atas + 1; j++)
            {
                if(kode == T.nobarang[j])
                {
                    tempno = T.nobarang[j];
                    T.nobarang[j] = T.nobarang[j+1];
                    T.nobarang[j+1] = temp;

                    tempnama = T.namabarang[j];
                    T.namabarang[j] = T.namabarang[j+1];
                    T.namabarang[j+1] = temp;

                    tempharga = T.hargabarang[j];
                    T.hargabarang[j] = T.hargabarang[j+1];
                    T.hargabarang[j+1] = temp;

                    berhasil = 1;
                }
            }
        }
        if(berhasil == 1)
        {
             cout<<"\nBarang berhasil dihapus\n";
             T.atas--;
        }else if(berhasil == 0)
        {
            cout<<"\nMaaf barang tidak ditemukan"<<endl;
        }
    }else
    {
        cout<<"\nRak masih kosong\n";
    }
}

void bersih()
{
    T.atas = -1;
    cout<<" ";
}


void sorting_nama()
{
    int i,j, tempno;
    string tempnama;
    int tempharga;

    for(i = 0; i < T.atas; i++)
    {
        for(j = 0; j < (T.atas-i); j++)
        {
            if(T.namabarang[j] > T.namabarang[j+1])
            {
                tempnama = T.namabarang[j];
                T.namabarang[j] = T.namabarang[j+1];
                T.namabarang[j+1] = tempnama;

                tempno = T.nobarang[j];
                T.nobarang[j] = T.nobarang[j+1];
                T.nobarang[j+1] = tempno;

                tempharga = T.hargabarang[j];
                T.hargabarang[j] = T.hargabarang[j+1];
                T.hargabarang[j+1] = tempharga;
            }
        }
    }
    system("cls");
    cout<<"\nBarang setelah diurutkan menurut Nama Barang "<<endl;
    tampilkan_barang();
}

void sorting_kode()
{
	int i, j, tempno;
	string tempnama;
	int tempharga;
	
	for (i = 0; i < T.atas; i++)
	{
		for (j = 0; j < (T.atas-i); j++)
		{
			if(T.nobarang[j] > T.nobarang[j+1])
			{
				tempno = T.nobarang[j];
				T.nobarang[j] = T.nobarang[j+1];
				T.nobarang[j+1] = tempno;
				
				tempnama = T.namabarang[j];
				T.namabarang[j] = T.namabarang[j+1];
				T.namabarang[j+1] = tempnama;
				
				tempharga = T.hargabarang[j];
				T.hargabarang[j] = T.hargabarang[j+1];
				T.hargabarang[j+1] = tempharga;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Kode Barang" << endl;
	tampilkan_barang();
}

void sorting_harga()
{
	int i,j, tempno;
	string tempnama;
	int tempharga;
	for(i = 0; i < T.atas; i++)
	{
		for(j = 0; j < (T.atas-i); j++)
		{
			if(T.hargabarang[j] > T.hargabarang[j+1])
			{
				tempharga = T.hargabarang[j];
				T.hargabarang[j] = T.hargabarang[j+1];
				T.hargabarang[j+1] = tempharga;
				
				tempno = T.nobarang[j];
				T.nobarang[j] = T.nobarang[j+1];
				T.nobarang[j+1] = tempno;
				
				tempnama = T.namabarang[j];
				T.namabarang[j] = T.namabarang[j+1];
				T.namabarang[j+1] = tempharga;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Harga" << endl;
	tampilkan_barang();
}

void search_nama()
{
	if(kosong() == 0)
	{
		string cari;
		
		cout << "Masukkan Nama Barang yang dicari : ";
		getline(cin,cari);
		
		for(int i = 0; i <= T.atas+i; i++)
		{
			if(cari == T.namabarang[i])
			{
				cout<< "\nBarang ada pada rak no "<<i+1<<endl;
				cout<< "Nama barang  : "<<T.namabarang[i]<<endl;
				cout<< "Harga        : "<<T.hargabarang[i]<<endl;
				cout<< "Kode barang  : "<<T.nobarang[i]<<endl;
			}else if(i > T.atas)
			{
				cout<<"\nPencarian selesai"<<endl;
				break;
			}
		}
	}else
		cout<<"\nRak masih kosong\n";
}

void search_kode()
{
	if(kosong() == 0)
	{
		int cari;
		
		cout<<"Masukan Kode barang yang dicari : ";
		cin>>cari;
		
		for(int i = 0; i <= T.atas+1; i++)
		{
			if(cari == T.nobarang[i])
			{
				cout<<"\nBarang ada pada rak no "<<i+1<<endl;
				cout<<"Kode barang  : "<<T.nobarang[i]<<endl;
				cout<<"Nama barang  : "<<T.namabarang[i]<<endl;
				cout<<"Harga        : "<<T.hargabarang[i]<<endl;
			}else if(i > T.atas)
			{
				cout<<"\nPencarian selesai"<<endl;
				break;	
			}
		}
	}else
		cout<<"\nRak masih kosong\n";
}


void search_harga()
{
    if(kosong()==0)
    {
        int cari;

        cout<<"Masukkan Harga Barang yang Dicari : ";
        cin>>cari;

        for(int i=0;i<=T.atas+1;i++)
        {
            if(cari == T.hargabarang[i])
            {
                cout<<"\nBarang ada pada rak no "<<i+1<<endl;
                cout<<"Nama barang  : "<<T.namabarang[i]<<endl;
                cout<<"Harga        : "<<T.hargabarang[i]<<endl;
                cout<<"Kode barang  : "<<T.nobarang[i]<<endl;
            }else if(i>T.atas)
            {
                cout<<"\nPencarian selesai"<<endl;
                break;
            }
        }
    }else
        cout<<"\nEtalase kosong\n";
}

void menu_sorting()
{
    int pilihan;

    cout<<"1. Mengurutkan Menurut Nama Barang\n";
    cout<<"2. Mengurutkan Menurut Kode Barang\n";
    cout<<"3. Mengurutkan Menurut Harga Barang\n";
    cout<<"4. Kembali ke Menu Awal\n";
    cout<<"Masukkan pilihan : ";
    cin>>pilihan;

    switch (pilihan)
    {
        case 1:
            sorting_nama();
            break;
        
        case 2:
            sorting_kode();
            break;
        
        case 3:
            sorting_harga();
            break;
        
        case 4:
            int main();
            break;
    }
}

void menu_search()
{
    int pilihan;
    
    cout<<"1. Mencari Menurut Nama Barang\n";
    cout<<"2. Mencari Menurut Kode Barang\n";
    cout<<"3. Mencari Menurut Harga Barang\n";
    cout<<"4. Mencari ke Menu Awal\n";
    cout<<"Masukkan pilihan : ";
    cin>>pilihan;
    cin.ignore();

    switch (pilihan)
    {
        case 1:
            search_nama();
            break;
        
        case 2:
            search_kode();
            break;
        
        case 3:
            search_harga();
            break;
        
        case 4:
            menu_awal();
            break;
    }
}