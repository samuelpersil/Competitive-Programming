//O(n * log(log(n)))
//se sieve[n] == n, entao n eh primo
//para encontrar os divisores primos de n, basta fazer n /= sieve[n] até n == 1

vector<int> sieve(N + 1, 0);
sieve[0] = 1, sieve[1] = 1;

for(int i = 2; i <= N; i++){
	if(!sieve[i]){
		sieve[i] = i;
		for(int j = i * i; j <= N; j += i){
			if(!sieve[j]) sieve[j] = i;
		}
	}		
}
