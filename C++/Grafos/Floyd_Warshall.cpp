//O(V^3)
//Calcula as menores distancias entre quaisquer dois
//vertices do grafo
//Inicializa com uma matriz de adjacencias adj[][],
//em que adj[a][b] guarda o peso da aresta entre a e b
//e constroi a matriz de adjacencias dist[][]

int n;
int dist[MAXN][MAXN];
int adj[MAXN][MAXN];

for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        if(i == j) dist[i][j] = 0;
        else if(adj[i][j]) dist[i][j] = adj[i][j];
        else dist[i][j] = oo;

for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

//ciclos negativos
bool negative_cycle(){
    for(int i = 0; i < n; i++){
        if(dist[i][i] < 0) return true;
    }
    return false;
}
