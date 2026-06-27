//O(n * log(n))
//Calcula o tamanho da maior subsequencia crescente em um array
//lower_bound() calcula uma LIS estritamente crescente
//para uma LIS nao-decrescente, trocar por upper_bound()

int lis(vector<int> &arr){
    vector<int> dp;
 
    for(int i = 0; i < n; i++){
        int l = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
 
        if(l == dp.size()){
            dp.push_back(arr[i]);
        }
        else{
            dp[l] = arr[i];
        }
    }
 
    return dp.size();
}

//LIS com backtracking

vector<int> lis_backtrack(vector<int> &arr){
    int n = arr.size();
    vector<int> dp;
    vector<int> pos(n);
    vector<int> prev(n, -1);
    vector<int> last(n, -1); // last[l] = índice mais recente com pos = l

    for(int i = 0; i < n; i++){
        int l = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(l == dp.size()) dp.push_back(arr[i]);
        else dp[l] = arr[i];

        pos[i] = l;
        if(l > 0) prev[i] = last[l - 1];
        last[l] = i;
    }

    // reconstrói seguindo os prev
    vector<int> result;
    for(int i = last[dp.size() - 1]; i != -1; i = prev[i])
        result.push_back(arr[i]);

    reverse(result.begin(), result.end());
    return result;
}