//O(|a| * |b|)
//Calcula quantas operacoes sao necessarias para transformar a string A na string B
//Operacoes permitidas:
//  *Insercao
//  *Remocao
//  *Substituicao

//iterativa
int dp[MAXN][MAXN];
 
int dist(string a, string b){
    int n = a.size();
    int m = b.size();
    
    for (int i=0;i<=n;i++) {
        dp[i][0] = i;
    }
    for (int j=0;j<=m;j++) {
        dp[0][j] = j;
    }
 
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int cost = a[i-1] != b[j-1];
            dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost});
        }
    }
    return dp[n][m];
}
 
cout << dist(a,b) << endl;

//recursiva
vector<vector<int>> dp(MAXN, vector<int>(MAXN, -1));
 
string a, b;
 
int dist(int i, int j){
    if(i == -1) return j + 1;
    else if(j == -1) return i + 1;
    if(dp[i][j] != -1) return dp[i][j];
 
    int cost = (a[i] == b[j] ? 0 : 1);
 
    return dp[i][j] = min({dist(i - 1, j) + 1, dist(i, j - 1) + 1, dist(i - 1, j - 1) + cost});
}

cout << dist(a.length() - 1, b.length() - 1) << endl;
