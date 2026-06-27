//O(E * log(E))
//Retorna uma MST e seu custo
//Salvar grafo como lista de adjacencias {w, a, b}

vector<tuple<int, int, int>> adj;

pair<int, vector<tuple<int, int, int>>> kruskal(int n){
	DSU dsu(n);
	sort(all(adj));
	int cost = 0;

	vector<tuple<int, int, int>> mst;
	for(auto [w, a, b] : adj){
		if(dsu.find(a) != dsu.find(b)){
			mst.push_back({w, a, b});
			cost += w;
			dsu.join(a, b);
		}
	}

	return {cost, mst};
}
