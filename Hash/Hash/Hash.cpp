#include "Hash.h"
#include <iostream>
#include <fstream>

using namespace std;

Hash::Hash(){
    n = 0;
}

Hash::Hash(int _n){
    tabla.reserve(_n);
    for(int i = 0; i<_n; i++){
        tabla[i].matricula = "hola";
    }
    cout<<tabla[0].matricula;
}

Hash::~Hash(){
}

void Hash::leeArchivo(int _n){
    ifstream alumnos;
    string texto;
    alumnos.open("alumnos.txt", ios::in);

    if(alumnos.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }

    for(int i = 0; i<_n; i++){
        getline(alumnos, texto);

    }
}
