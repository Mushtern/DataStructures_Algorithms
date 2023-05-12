#include<iostream>
#include<vector>
#include<limits.h>
#include <queue>
#include <string.h>
#include <cmath>
 
using namespace std;
const int INF = 999; 
int ary[999][999],completed[999],n,cost=0;
vector<vector<int>> grafoDijkstra;
char abc[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int distanciaMinima(vector<int> dist, vector<bool> visitado) {
    int min = INT_MAX; 
    int pos;
    for (int i = 0; i < dist.size(); i++) 
    {
        if (visitado[i] == false && dist [i] <= min) 
        {
            min = dist[i];
            pos = i;
        }
    }
    return pos;
}

//O(N)
void imprimirDijkstra(vector<int> dist, int nodoInicial) {
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != 0)cout<<"Km de colonia "<< abc[nodoInicial]<<" a colonia "<< abc[i]<<": "<< dist[i] << endl;
    }
}


//Dijkstra 
//O(N^2)
void dijkstra(vector<vector<int>> grafo, int nodoInicial)
 {
    vector<int> dist(grafo.size(), INT_MAX);
    vector<bool> visitado(grafo.size(), false);
    dist[nodoInicial] = 0;

    for (int i = 0; i < grafo.size() - 1; i++) 
    {
        int pos = distanciaMinima(dist, visitado);
        visitado[pos] = true;
        for (int j = 0; j < grafo.size(); j++)
         {
            if (!visitado[j] && grafo[pos][j] && dist[pos] != INT_MAX) {
                dist[j] = min(dist[j], dist[pos] + grafo[pos][j]);
            }
        }
    }
    imprimirDijkstra(dist, nodoInicial);
}

 
void input()
{
  int i,j;
  
  cout<<"Ingrese el numero de colonias: ";
  cin>>n;
  
  cout<<"Ingrese los km: "<<endl;
  
  for(i=0;i < n;i++)
  {
    vector<int> row;
    for( j=0;j < n;j++)
    {
      int valor;
      cin>>valor;
      ary[i][j] = valor;
      if (valor == -1)
      {
        row.push_back(0);
      } else 
      { 
        row.push_back(valor);
      }
    }
    completed[i]=0;
    grafoDijkstra.push_back(row);
  }

    cout << " "<<endl;
    for (int i = 0; i < n; i++) 
    {
        dijkstra(grafoDijkstra, i);
        cout << "\n";
    }

}
 
int menor(int c)
{
  int i,nc=999;
  int min=999,kmin;
  
  for(i=0;i < n;i++)
  {
    if((ary[c][i]!=0)&&(completed[i]==0))
    if(ary[c][i]+ary[i][c] < min)
    {
      min=ary[i][0]+ary[c][i];
      kmin=ary[c][i];
      nc=i;
    }
  }
  
  if(min!=999)
  cost+=kmin;
  
  return nc;
}



void mincost(int city)
{
  int i,ncity;
  
  completed[city]=1;
  
  cout<<abc[city]<<"--->";
  ncity=menor(city);
 
  if(ncity==999)
  {
    ncity=0;
    cout<<'A';
    cost+=ary[city][ncity];
    
    return;
  }
 
mincost(ncity);
}


bool bfs(int rGraph[INF][INF], int s, int t, int parent[]) {
  bool visited[INF];
  memset(visited, 0, sizeof(visited));

  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < INF; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  return (visited[t] == true);
}

//Fordfulkerson 
int fordFulkerson(int graph[INF][INF], int s, int t) {
  int u, v;

  int rGraph[INF][INF];
  for (u = 0; u < INF; u++)
    for (v = 0; v < INF; v++)
      rGraph[u][v] = graph[u][v];

  int parent[INF];
  int max_flow = 0;



  while (bfs(rGraph, s, t, parent)) {
    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }

  return max_flow;
}



int main()
{
input();
cout<<"El camino mas corto es: ";
mincost(0); 

int n2;
cout << "\nNúmero de nodos: ";
cin >> n2;

cout<<"Ingrese las capacidades máximas de flujo de datos entre colonias\n";
int graph[INF][INF];
for(int i=0;i < n2;i++)
{
  vector<int> row;
  for( int j=0;j < n2;j++)
  {
    int valor;
    cin>>valor;
    graph[i][j] = valor;
  }
}

cout << "Flujo Maximo: " << fordFulkerson(graph, 0, 3) << endl;

//Distancia entre dos puntos 

int centralesExistentes;
cout<<"\nCuantas centrales hay?: \n ";
cin>>centralesExistentes;
vector<vector<int>> grafoPuntos;

cout<<"Introduce las ubicaciones de las centrales:\n";
for(int i = 0; i < centralesExistentes; i++){
  vector<int> renglon;
  for(int j = 0; j<2; j++){
    int punto;
    cin>>punto;
    renglon.push_back(punto);
  }
  grafoPuntos.push_back(renglon);
}

vector<int> nuevaCentral;
cout<<"Introduce las coordenadas de la nueva central: ";
for(int i = 0; i < 2; i++){
  int p;
  cin>>p;
  nuevaCentral.push_back(p);
}

int x2 = nuevaCentral[0];
int y2 = nuevaCentral[1];
vector<int>distancias;

for(int i = 0; i<centralesExistentes; i++){
  int x1 = grafoPuntos[i][0];
  int y1 = grafoPuntos[i][1];
  int distancia = sqrt(pow(x2-x1,2)+pow(y2-y1, 2));
  distancias.push_back(distancia);
}

//Identificar el menor

int menor = distancias[0];
for(int i = 0; i < centralesExistentes; i++){
  if(menor > distancias[i]){
    menor = distancias[i];
  }
}
cout<<"La menor distancia es: "<<menor;
return 0;
}











