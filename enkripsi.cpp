#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

main(int argc, char *argv[]){

    FILE *Fin, *Fout;
    char p,c;
    string k;
    int i;

    // Membuka file
    Fin = fopen("halo.txt", "r");
    if(Fin == NULL) {
        cout << "Berkas " << argv[1] << " tidak ada " << endl;
        exit(0);
    }

    // membuka file
    Fout = fopen("enkripsi.txt", "w");
    cout << "Kata kunci : "; cin >> k;
    cout << "Enkripsi " << argv[2] << " menjadi " << "....";

    i = 0;
    while(!feof(Fin)) {
        p = getc(Fin);
        c = p ^ k[i];
        putc(c, Fout);
        i = (i + 1) % k.length();
    }

    // Menutup File
    fclose(Fin);
    fclose(Fout);
    
}