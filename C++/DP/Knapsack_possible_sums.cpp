//O(n * W), em que n eh o numero de itens e W eh o peso maximo
//calcula todas as possiveis somas utilizando um dado conjunto de pesos/moedas
//total = soma de todos os pesos

int n;
vector<bool> possible(MAXSUM);
vector<int> from(MAXSUM);
vector<int> arr[MAXN];

for(int i = 0; i < n; i++){
    for(int x = total; x >= 0; x--){
        if(possible[x] && !possible[x + arr[i]]){
            possible[x + arr[i]] = true;
            from[x + arr[i]] = i;
        }
    }
}

//reconstruindo a solucao

int now = target;
while(now > 0){
    cout << from[now] << " ";
    now -= (arr[from[now]]);
}
cout << endl;