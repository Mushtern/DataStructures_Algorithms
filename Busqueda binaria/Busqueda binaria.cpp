#include <iostream>
using namespace std;

const int y = 11;
int datos[y] = { 23,45,21,43,31,76,43,56,24,76,35 };

int busqueda(int datos[y], int n) {
	int x = y-1 / 2;
	if (n == datos[x]) {
		cout << "El número se encuentra en el arreglo, en la posicion " << x << endl;
	}
	else {
		x = busqueda(&datos[11], n);
	}
	return 0;
}


int main() {

}
