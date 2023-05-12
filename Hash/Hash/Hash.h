#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

struct Alumno{
    string matricula, nombre;
};

class Hash{
    int n;
    vector<struct Alumno> tabla;
public:
    void leeArchivo(int);
    Hash();
    Hash(int);
    ~Hash();
};

#endif // HASH_H_INCLUDED
