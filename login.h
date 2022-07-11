#include<iostream>
#include<istream>
#include<fstream>
#include<string>
void login();
void registr();
void forgot();

using namespace std;
int main();

void login(){
    int count;
    string user,pass,u,p;
    system("cls");
    cout<<"Login"<<endl;
    cout<<endl;
    cout<<"Username : ";
    cin>>user;
    cout<<"Password : ";
    cin>>pass;
    
    ifstream input("database.dat");
    while(input>>u>>p){
            if(u==user && p==pass){
                    count=1;
                    
            }
    }

    input.close();
    if(count==1){
            system("cls");

            
            
    }else if(count != 1){
            cout<<endl;
            cout<<"Login Gagal, pastikan Username dan Password Kamu benar!!"<<endl;
            system("pause");
            system("cls");
            main();
            
            
            
    }else{
        
    
    }
}

void registr(){
        string reguser, regpass, ru, rp;
        system("cls");
        cout<<"============REGISTER============"<<endl;
        cout<<"Username : ";
        cin>>reguser;
        cout<<"Password : ";
        cin>>regpass;

        ofstream reg("database.dat", ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"Registrasi Berhasil"<<endl;
        system("pause");
        system("cls");
        main();
        
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"1.Cari akun berdasarkan Username"<<endl;
        cout<<"2.Cari Akun berdasarkan Password Terakhir"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Pilihan :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nMasukkan Username Terakhir :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.dat");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nAkun ditemukan!!\n";
                                cout<<"\nPassword kamu adalah : "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                                
                        }
                        else
                        {
                                cout<<"\nMaaf, akun kamu tidak ditemukan!\n";
                                cout<<"\nHubungi CS di instagram @sihabcdefgh \n";
                                cin.get();
                                cin.get();
                                main();
                                
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nMasukkan Password terakhir :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.dat");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nAkun ditemukan!! \n";
                                cout<<"\nUsername kamu adalah : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();                                
                        }
                        else
                        {
                                cout<<"Maaf, akun kamu tidak ditemukan!\n";
                                cout<<"\nHubungi CS di instagram @sihabcdefgh \n";
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                                
                        }
                
                        break;
                }
                
                case 3:
                {       
                        system("cls");
                        cin.get();
                        main();
                       
                }
                default:
                        cout<<"Maaf, pilihan kamu salah!!"<<endl;
                        forgot();
        }
}