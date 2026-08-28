//O(V + E)
//Salvar o grafo como lista de adjacencias

vector<int> adj[n];
vector<int> visited(n);
vector<int> distance(n);

queue<int> q;

visited[start] = true;
distance[start] = 0;

q.push(start);

while(!q.empty()){
	int u = q.front(); q.pop();

	for(auto s : adj[u]){
		if(visited[s]) continue;
		visited[s] = true;
		distance[s] = distance[u] + 1;
		q.push(s);
	}
}
