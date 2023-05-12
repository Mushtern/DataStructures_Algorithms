#include <iostream>
#include <list>

using namespace std;

class Grafo {

    private:
        int N;
        list<int> *m;
    public:
        Grafo(int n) {
            this->N = n;
            m = new list<int>[N];
        }
        void coloreaGrafo();
        void agregaVertice(int row, int column);
};

void Grafo::coloreaGrafo() {

    bool libre[N];
    int color;
	int resultado[N];
	resultado[0] = 0;

	for (int k = 1; k< N; k++)
        {
		resultado[k] = -1;
    }

	for (int color = 0; color < N; color++)
        {
		libre[color] = false;
	}

	for (int i = 1; i < N; i++)
        {
		list<int>::iterator j;
		for (j = m[i].begin(); j != m[i].end(); ++j){
			if (resultado[*j] != -1){
				libre[resultado[*j]] = true;
			}
		}
		for (color = 0; color < N; color++){
			if (libre[color] == false){
				break;
			}
		}
		resultado[i] = color;
		for (j = m[i].begin(); j != m[i].end(); ++j)
            {
			if (resultado[*j] != -1)
			{
				libre[resultado[*j]] = false;
            }
        }
	}
  cout<<"\t\n Resultados \n";
	for (int i = 0; i < N; i++) {
		cout << "Vertice: " << i << ", Color: " << resultado[i] << endl<<endl;
    }
}

void Grafo::agregaVertice(int row, int column) {
	m[row].push_back(column);
	m[column].push_back(row);
}

int main() {
    bool node;
    int n;
    cout << "Introduce el numero de nodos: ";
    cin >> n;
    Grafo g(n);

    cout<<"Introduce la matriz de adyacencia representando el grafo: \n";

    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
         {
            cin >> node;
            if (node == 1)
             {
                g.agregaVertice(i, j);
             }
        }
    }
	g.coloreaGrafo();

	return 0;
}
