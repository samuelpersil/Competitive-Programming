//O(n * W), em que n eh o numero de itens e W eh o peso maximo
//calcula a maior pontuacao possivel ao adicionar itens na mochila,
//em que a soma dos pesos escolhidos eh no maximo W
//dp[i][ainda_pode] = maior pontuacao utilizando itens do indice 0
//ao indice i, utilizando no maximo ainda_pode de peso

struct Item{
    int w, v;
};

//recursivo com backtracking
int n;
Item items[MAXN];
vector<vector<int>> dp(MAXN, vector<int>(MAXW, -1));

int rec(int i, int ainda_pode){
    if(i >= n){
        return 0;
    }

    if(dp[i][ainda_pode] != -1){
        return dp[i][ainda_pode];
    }

    int pega = 0;
    int npega = rec(i + 1, ainda_pode);

    if(ainda_pode - items[i].w >= 0) pega = items[i].v + rec(i + 1, ainda_pode - items[i].w);

    return dp[i][ainda_pode] = max(pega, npega);
}

cout << rec(0, w) << endl;

vector<Item> backtrack(int i, int ainda_pode){
    if(i >= n) return {};

    int npega = rec(i + 1, ainda_pode);
    int pega = 0;
    if(ainda_pode - items[i].w >= 0)
        pega = items[i].v + rec(i + 1, ainda_pode - items[i].w);

    if(pega > npega){
        vector<Item> result = backtrack(i + 1, ainda_pode - items[i].w);
        result.push_back(items[i]);
        return result;
    }
    return backtrack(i + 1, ainda_pode);
}

vector<Item> chosen = backtrack(0, W);

//iterativo 1D

int n;
Item items[MAXN];
vector<int> dp(W + 1, 0);
for(int i = 0; i < n; i++)
    for(int j = W; j >= items[i].w; j--)
        dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);


//iterativo com backtracking
int n;
Item items[MAXN];
vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

for(int i = 1; i <= n; i++)
    for(int j = 0; j <= W; j++){
        dp[i][j] = dp[i-1][j];
        if(j >= items[i-1].w)
            dp[i][j] = max(dp[i][j], dp[i-1][j - items[i-1].w] + items[i-1].v);
    }

vector<Item> chosen;
int j = W;
for(int i = n; i >= 1; i--){
    if(dp[i][j] != dp[i-1][j]){
        chosen.push_back(items[i-1]);
        j -= items[i-1].w;
    }
}