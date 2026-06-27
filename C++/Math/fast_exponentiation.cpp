//O(log(b))
//retorna a^b % MOD

//recursivo
const ll MOD = 1000000007LL;

ll fexp(ll a, ll b){
	if(b == 0) return 1;

	ll half = fexp(a, b/2);
	half = (half * half) % MOD;

	if(b % 2 == 0) return half;
	return (half * a) % MOD;
}

//iterativo
const ll MOD = 1000000007LL;

ll fexp(ll a, ll b){
    ll result = 1;

    while(b > 0){
        if(b % 2 == 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }

    return result;
}