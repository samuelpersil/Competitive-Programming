#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

ll fexp(ll a, ll b, ll MOD){
    ll result = 1;

    while(b > 0){
        if(b % 2 == 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }

    return result;
}

int main(){fastio
    int t; cin >> t;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        cout << expo(a, expo(b, c, 1000000006LL))
    }

    return 0;
}