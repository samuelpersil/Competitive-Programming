//O(V * E)
//Calcula as distancia dos menores caminhos do
//vertice x aos demais
//Salvar o grafo como lista de arestas (a, b, w)
//Lida com ciclos negativos, enquanto Dijkstra nao
//Handbook

int n;
vector<tuple<int, int, int>> edges;
vector<int> distance(n, oo);

distance[x] = 0;
for(int i = 0; i < n - 1; i++){
    for(auto [a, b, w] : edges){
        if(distance[a] != oo)
            distance[b] = min(distance[b], distance[a] + w);
    }
}

//Detectar ciclo negativo
bool has_negative_cycle = false;
for(auto [a, b, w] : edges){
    if(distance[a] != oo && distance[a] + w < distance[b]){
        has_negative_cycle = true;
        break;
    }
}