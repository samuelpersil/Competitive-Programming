//O(n * m)
//Calcula o tamanho da maior subsequencia comum entre dois arrays

int a[1001], b[1001];
int dp[1001][1001];

//recursiva
int lcs(int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }
 
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i - 1] == b[j - 1]){
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else{
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
}

//iterativa
for(int i = 0; i <= n; i++){
    dp[i][0] = 0;
}
for(int i = 0; i <= m; i++){
    dp[0][i] = 0;
}

for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

cout << dp[n][m] << endl;

//backtracking
vector<int> lcs_result;
int i = n, j = m;

while(i > 0 && j > 0){
    if(a[i-1] == b[j-1]){
        lcs_result.push_back(a[i-1]);
        i--; 
        j--;
    }
    else if(dp[i-1][j] >= dp[i][j-1]){
        i--;
    }
    else{
        j--;
    }
}
reverse(lcs_result.begin(), lcs_result.end());