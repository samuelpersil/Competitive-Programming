//Realiza consultas e atualizações em um índice em O(log(n))
//0-Indexed
//Valores iniciais sao salvos em (seg[n], ..., seg[2*n - 1])
//Query: retorna a operacao f aplicada no intervalo [l, r]
//Update: substitui o valor em k para x

const int oo = INT_MAX;

struct Segtree {
    int n;
    vector<int> tree, lazy;

    Segtree(int n) : n(n), tree(4*n, oo), lazy(4*n, 0) {}

    int f(int a, int b) {
        return min(a, b);
    }

    void push(int node) {
        if (lazy[node]) {
            tree[2*node]   += lazy[node]; lazy[2*node]   += lazy[node];
            tree[2*node+1] += lazy[node]; lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return oo;
        if (ql <= l && r <= qr) return tree[node];
        push(node);
        int mid = (l + r) / 2;
        return f(query(2*node, l, mid, ql, qr),
                 query(2*node+1, mid+1, r, ql, qr));
    }

    void update(int node, int l, int r, int ul, int ur, int val) {
        if (ul > r || ur < l) return;
        if (ul <= l && r <= ur) { tree[node] += val; lazy[node] += val; return; }
        push(node);
        int mid = (l + r) / 2;
        update(2*node, l, mid, ul, ur, val);
        update(2*node+1, mid+1, r, ul, ur, val);
        tree[node] = f(tree[2*node], tree[2*node+1]);
    }

    int  query(int l, int r)           { return query(1, 0, n-1, l, r); }
    void update(int l, int r, int val) { update(1, 0, n-1, l, r, val); }
};

// Para ler os dados iniciais, usar:
for(int i = 0; i < n; i++) seg.update(i, i, valor);
