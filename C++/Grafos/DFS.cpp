//O(V + E)
//Salvar o grafo como lista de adjacencias

vector<int> adj[n];
vector<bool> visited(n);

void dfs(int u){
	if(visited[u]) return;

	visited[u] = true;

	for(auto s : adj[u]){
		dfs(s);
	}
}
