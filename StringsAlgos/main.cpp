#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;

void findString(string linea, string mcode_1,string file_1, string a, string b)
{
  ifstream mcode1,mcode2;
  ifstream file1,file2;

  mcode1.open(a);
  while(getline(mcode1, linea)) {
    mcode_1 = mcode_1 + linea;
  }

  file1.open(b);
  while(getline(file1, linea)) {
    file_1 = file_1 + linea;
    file_1 = file_1 + " ";
  }

  size_t found = file_1.find(mcode_1);
  if (found != string::npos) {
    std::cout <<"True "<<found<< '\n';
 }

  else
  {
    cout<<"False"<<endl;
  }
}



void findReverse(string linea, string mcode_1,string file_1, string a, string b)
{
  ifstream mcode1;
  ifstream file1;

  mcode1.open(a);
  while(getline(mcode1, linea)) {
    mcode_1 = mcode_1 + linea;
  }

  int tamanio = mcode_1.length();

  file1.open(b);
  while(getline(file1, linea)) {
    file_1 = file_1 + linea;
    file_1 = file_1 + " ";
  }

  reverse(mcode_1.begin(), mcode_1.end());

  size_t found = file_1.find(mcode_1);
  if (found != string::npos) {
    std::cout <<found<<' '<<found+tamanio<<'\n';
 }
}



void subString(string a,string b){
  int cont = 0;
  int posicion = 0;
  string coincidencia;
  
  for(int i = 0 ; i < a.length(); i++)
  {
      for(int j = i; j < a.length(); j++)
      {
          string x = a.substr(i,j-i+1);
          int n=0;
          for(int k=0;k<b.length();k++)
          {
              if(b[k] == x[n]){
                n++;
              }
              else if(n == x.length())
              {
                  posicion = a.find(coincidencia);
                  break;
              }
              else {
                  n = 0;
              }
          }
          if(n == x.length()) {
              cont = 1;
              if(coincidencia.length() < x.length()) 
              {
                coincidencia = x;
                posicion = a.find(coincidencia);
              }
          }
      }
  }
  if(cont)
    cout << posicion<<" "<<posicion+coincidencia.length()<< endl;
  else
    cout <<"No hay coincidencias\n";
  return;
}



int main() {
  string linea;
  string mcode_1;
  string file_1;
  string archivo_1,archivo_2;
  ifstream archivo1;
  ifstream archivo2;


  archivo1.open("transmission1.txt");
  while(getline(archivo1, linea)) {
    archivo_1 = archivo_1 + linea;
    archivo_1 = archivo_1 + " ";
  }

  archivo2.open("transmission2.txt");
  while(getline(archivo2, linea)) {
    archivo_2 = archivo_2 + linea;
    archivo_2 = archivo_2 + " ";
  }

  cout<<"----Parte 1----\n";
  
  string a = "mcode1.txt",b = "transmission1.txt";
  findString(linea, mcode_1, file_1,a,b);
  a = "mcode2.txt";
  findString(linea, mcode_1, file_1,a,b);
  a = "mcode3.txt";
  findString(linea, mcode_1, file_1,a,b);
  a = "mcode1.txt",b = "transmission2.txt";
  findString(linea, mcode_1, file_1,a,b);
  a = "mcode2.txt";
  findString(linea, mcode_1, file_1,a,b);
  a = "mcode3.txt";
  findString(linea, mcode_1, file_1,a,b);

  cout<<"----Parte 2----"<<endl;

  a = "mcode1.txt",b = "transmission1.txt";
  findReverse(linea, mcode_1, file_1,a,b);
  a = "mcode2.txt";
  findReverse(linea, mcode_1, file_1,a,b);
  a = "mcode3.txt";
  findReverse(linea, mcode_1, file_1,a,b);
  a = "mcode1.txt",b = "transmission2.txt";
  findReverse(linea, mcode_1, file_1,a,b);
  a = "mcode2.txt";
  findReverse(linea, mcode_1, file_1,a,b);
  a = "mcode3.txt";
  findReverse(linea, mcode_1, file_1,a,b);

  cout<<"----Parte 3----"<<endl;
  subString(archivo_1,archivo_2 );
}