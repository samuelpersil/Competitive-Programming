//O((V + E) * log(V))
//Gera um array com as distancias minimas dos vertices ao no inicial
//Salvar grafo como lista de adjacencias
//Os pesos devem ser colocados na fila de prioridade como -w, pra serem ordenados da maior para a menor distancia
//As arestas sao salvas como {b, -w}, de forma que existe um caminho de a para b com peso w
//Eh necessario colocar o elemento {b, -w} em adj[a], e {a, -w} em adj[b]

const int oo = 1e9;
int n;
vector<pair<int, int>> adj[MAXN];
vector<int> distance(MAXN, oo);

void dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	//para salvar diretamente os pesos como w, eh preciso mudar a pq para uma min-heap
	//priority_queue<pii, vector<pii>, greater<pii>> pq;
	distance[start] = 0;
	pq.push({0, start});

	while(!pq.empty()){
		auto [dist, u] = pq.top(); pq.pop();

		if(-dist > distance[u]) continue;
		
		for(auto [b, w] : adj[u]){
			if(distance[u] + w < distance[b]){
				distance[b] = distance[u] + w;
				pq.push({-distance[b], b});
			}
		}
	}
}
