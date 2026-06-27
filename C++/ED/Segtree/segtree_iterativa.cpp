//Realiza consultas e atualizacoes em um indice em O(log(n))
//0-Indexed
//Valores iniciais sao salvos em (seg[n], ..., seg[2*n - 1])
//Query: retorna a operacao f aplicada no intervalo [l, r]
//Update: substitui o valor em k para x

const int oo = INT_MAX;

struct Segtree {
    int n;
    vector<int> tree;

    Segtree(int n) : n(n), tree(2*n, oo) {}

    int f(int a, int b){
        return min(a, b);
    }

    void build(){
        for(int i = n - 1; i >= 1; i--){
            tree[i] = f(tree[2*i], tree[2*i+1]);
        }
    }

    int query(int l, int r){
        l += n; r += n;
        int s = oo;
        while(l <= r){
            if(l%2 == 1) s = f(s, tree[l++]);
            if(r%2 == 0) s = f(s, tree[r--]);
            l /= 2; r /= 2;
        }
        return s;
    }

    void update(int k, int x){
        k += n;
        tree[k] = x;
        for(k /= 2; k >= 1; k /= 2){
            tree[k] = f(tree[2*k], tree[2*k+1]);
        }
    }
};

//Para ler os dados iniciais da arvore, usar:
for(int i = 0; i < n; i++){
    cin >> tree[i + n];
}