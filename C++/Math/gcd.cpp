//O(log(min(a, b)))
//lcm(a, b) = a / gcd(a, b) * b
//c++ ja tem __gcd(a, b) implementado

ll gcd(ll a, ll b){
	if(b == 0) return a;

	return gcd(b, a % b);
}
