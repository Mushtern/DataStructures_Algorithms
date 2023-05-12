#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int main()
{
    int n;
    int renglones;
    int mod;
    int caracteres;
    string linea;
    string datos;
    string tabla[0][n] = {};
    ifstream archivo;
    archivo.open("datos.txt", ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo, linea);
        datos = datos+linea+"\n";
    }

    archivo.close();

    caracteres = datos.size();

    cout<<"Introduce un numero que sea múltiplo de 4 y que cumpla con 16<=n<=64: \n";
    cin>>n;


    while(n%4 != 0 || n<16 || n>64){
        cout<<"El numero tiene que ser multiplo de 4 y debe cumplir con 16<=n<=64. Intente de nuevo: \n";
        cin>>n;
    }

    if(caracteres%n!=0){
        if(caracteres<n){
            renglones = 1;
            for(int i = 0;i<n;i++){
                tabla[0][i] = to_string(n);
            }
        }
        for(int i = 0;i<n;i++){
            cout<<tabla[0][i];
        }
        renglones = caracteres/n+1;
    }
    else{
        renglones = caracteres/n;

        /*for(int i = 0 ; i<renglones<i++){
            for(int j = 0; j<n;j++){

            }
        }*/
    }



}
