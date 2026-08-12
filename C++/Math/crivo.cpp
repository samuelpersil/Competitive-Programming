//O(n * log(log(n)))
//se sieve[n] == n, entao n eh primo
//para encontrar os divisores primos de n, basta fazer n /= sieve[n] até n == 1

//crivo em que sieve[i] = menor primo que divide i
vector<int> sieve(N + 1, 1);
for(int i = 2; i <= N; i++){
	if(sieve[i] == 1){
		sieve[i] = i;
		for(int j = i * i; j <= N; j += i){
			if(sieve[j] == 1) sieve[j] = i;
		}
	}		
}

//crivo de numero de divisores, sieve[i] = numero de divisores de i
vector<int> sieve(N + 1, 0);
for(int i = 1; i <= N; i++){
	for(int j = i; j <= N; j += i){
		sieve[j]++;
	}
}

//testar se n eh primo iterando ate sqrt(n)
bool primo(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}