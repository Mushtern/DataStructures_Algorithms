
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

void imprimeMatriz(vector<vector<int>> m) {
    cout << "Matriz generada:\n";
    for (int i = 1; i < m.size(); ++i)
        {
        for (int j = 1; j < m[i].size(); ++j)
        {
            cout << m[i][j] << " ";
        }
        cout <<endl;
    }
}

void knapsack(int N, vector<int> value, vector<int> weight, int W)
{

    vector<vector<int>> matriz;
    for (int k = 0; k <= N; k++)
    {
        vector<int> temporal (W+1);
        matriz.push_back(temporal);
    }
    for (int i = 0; i <= N; i++)
     {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                matriz[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                matriz[i][j] = max(value[i - 1] + matriz[i - 1][j - weight[i - 1]], matriz[i - 1][j]);
            }
            else
            {
                matriz[i][j] = matriz[i - 1][j];
            }
        }
    }
    cout<<"\nResultados\n";
    cout << "\nBeneficio optimo: " << matriz[N][W] << "\n\n";
    imprimeMatriz(matriz);
}

int main() {

    //Lectura de datos N, W, pesos y valores
    int N, W;
    vector<int> valor, peso;
    cout << "Numero de elementos:\n ";
    cin >> N;
    cout << "\nBeneficios: \n";
    for (int i = 0; i < N; i++)
        {
        int n;
        cin >> n;
        valor.push_back(n);
    }
    cout << "\nPesos: \n";
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        peso.push_back(n);
    }
    cout << "\nTamaño de la mochila: ";
    cin >> W;
    knapsack(N, valor, peso, W);
}
