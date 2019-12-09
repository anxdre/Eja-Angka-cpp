//
//  main.cpp
//  Eja-Angka
//
//  Created by Andre Setiawan A on 09/12/19.
//  Copyright © 2019 Andre Setiawan A. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string satuan[]={"" , " satu " ," dua " , " tiga " , " empat " , " lima " , " enam " , " tujuh " , " delapan " , " sembilan "};

string konvertAngka(int n)
{
    if (n < 0)
    {
        return "Negatif" + konvertAngka(-n);
    }
    else if (n < 10)
    {
        return satuan[n];
    }
    else if (n == 10)
    {
        return "sepuluh ";
    }
    else if (n == 11)
    {
        return "sebelas ";
    }
    else if (n < 20)
    {
        return satuan [n-10] + " belas ";
    }
    else if (n < 100)
    {
        return satuan [(n-(n%10))/10] +  " puluh " + konvertAngka(n % 10);
    }
    else if (n < 1000)
    {
        return (n < 200 ? " seratus " : satuan[(n-(n% 100))/100] + " ratus") + konvertAngka(n % 100);
    }
    else if (n < 10000)
    {
        return (n < 2000 ? " seribu " : satuan[(n-(n%1000))/1000] + " ribu ") + konvertAngka(n % 1000);
    }
    else
    {
        return "Angka lebih dari 4 digit";
    }
}

string jadiFile(string nama){
    return nama + ".txt";
}

int main (){
    int angka;
    char cetak;
    char ulang;
    string namaFile;
    
awal:
    cout<<"masukkan nama file yang anda mau = ";
    cin>>namaFile;
validInput:
    cout<<"masukkan angka = ";
    cin>>angka;
    
    if(cin.good()) {
        cout<<konvertAngka(angka)<<endl;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"inputnya tidak valid"<<endl;
        goto validInput;
    }
    
validCetak:
    cout<<"ingin mencetak file? (y/n) = ";
    cin>>cetak;
    
    if(cetak == 'y')
    {
        ofstream myFile;
        myFile.open(jadiFile(namaFile),ios::out);
        myFile<<angka<<" = "<<konvertAngka(angka);
        myFile.close();
    }
    else if (cetak == 'n')
    {
        goto validPengulangan;
    }
    else
    {
        cout<<"Hanya (y/n)";
        goto validCetak;
    }
    
validPengulangan:
    cout<<"programnya diulang ?? (y/n)= ";
    cin>>ulang;
    
    if (ulang=='y')
    {
        goto awal;
    }
    else if(ulang=='n')
    {
        cout<<"makasih!"<<endl;
    }
    else
    {
        cout<<"hanya (y/n)";
        goto validPengulangan;
    }
}
