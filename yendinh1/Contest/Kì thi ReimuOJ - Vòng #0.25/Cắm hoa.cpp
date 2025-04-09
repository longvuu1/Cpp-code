#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

struct S {
    int n;
    vector<vector<int>> t;
    S(int n_) : n(n_) {
        t.resize(4 * n);
    }
    void b(vector<int> &a, int i, int l, int r) {
        if(l == r) {
            if(a[l] != -1)
                t[i].push_back(a[l]);
            return;
        }
        int m = (l + r) / 2;
        b(a, i*2, l, m);
        b(a, i*2+1, m+1, r);
        t[i].resize(t[i*2].size() + t[i*2+1].size());
        merge(t[i*2].begin(), t[i*2].end(), t[i*2+1].begin(), t[i*2+1].end(), t[i].begin());
    }
    void u(int i, int l, int r, int p, int v, int o) {
        if(p < l || p > r) return;
        if(o == 1) {
            auto it = std::upper_bound(t[i].begin(), t[i].end(), v);
            t[i].insert(it, v);
        } else if(o == -1) {
            auto it = std::lower_bound(t[i].begin(), t[i].end(), v);
            if(it != t[i].end() && *it == v)
                t[i].erase(it);
        }
        if(l == r) return;
        int m = (l + r) / 2;
        if(p <= m) u(i*2, l, m, p, v, o);
        else       u(i*2+1, m+1, r, p, v, o);
    }
    int q(int i, int l, int r, int ql, int qr, int x, bool g) {
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) {
            if(g) {
                auto it = std::upper_bound(t[i].begin(), t[i].end(), x);
                return t[i].end() - it;
            } else {
                auto it = std::lower_bound(t[i].begin(), t[i].end(), x);
                return it - t[i].begin();
            }
        }
        int m = (l + r) / 2;
        return q(i*2, l, m, ql, qr, x, g) + q(i*2+1, m+1, r, ql, qr, x, g);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n), v;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    struct Q { int t, p, x; };
    vector<Q> qs(q);
    for (int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1) {
            int x; 
            cin >> x;
            qs[i] = {t, -1, x};
            v.push_back(x);
        } else if(t == 2) {
            int p; 
            cin >> p;
            qs[i] = {t, p, -1};
        } else if(t == 3) {
            int p, x; 
            cin >> p >> x;
            qs[i] = {t, p, x};
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto c = [&](int x) {
        return int(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
    };
    int m = n + q + 5;
    vector<int> A(m+1, -1);
    S s(m);
    T t;
    long long ti = 0;
    for (int i = 1; i <= n; i++){
        int cv = c(a[i-1]);
        A[i] = cv;
        t.insert(i);
        s.u(1, 1, m, i, cv, 1);
        int cnt = s.q(1, 1, m, 1, i-1, cv, true);
        ti += cnt;
    }
    int ni = n+1;
    for (int i = 0; i < q; i++){
        if(qs[i].t == 1) {
            int x = qs[i].x;
            int cv = c(x);
            int id = ni++;
            A[id] = cv;
            t.insert(id);
            s.u(1, 1, m, id, cv, 1);
            int ai = s.q(1, 1, m, 1, id-1, cv, true);
            ti += ai;
            cout << ti << "\n";
        } else if(qs[i].t == 2) {
            int p = qs[i].p;
            auto it = t.find_by_order(p-1);
            if(it == t.end()) continue;
            int id = *it;
            int cv = A[id];
            int li = s.q(1, 1, m, 1, id-1, cv, true);
            int ri = s.q(1, 1, m, id+1, m, cv, false);
            int rem = li + ri;
            ti -= rem;
            s.u(1, 1, m, id, cv, -1);
            t.erase(id);
            A[id] = -1;
        } else if(qs[i].t == 3) {
            int p = qs[i].p;
            int x = qs[i].x;
            int nv = c(x);
            auto it = t.find_by_order(p-1);
            if(it == t.end()) continue;
            int id = *it;
            int ov = A[id];
            int li = s.q(1, 1, m, 1, id-1, ov, true);
            int ri = s.q(1, 1, m, id+1, m, ov, false);
            int rem = li + ri;
            ti -= rem;
            s.u(1, 1, m, id, ov, -1);
            A[id] = nv;
            s.u(1, 1, m, id, nv, 1);
            int al = s.q(1, 1, m, 1, id-1, nv, true);
            int ar = s.q(1, 1, m, id+1, m, nv, false);
            ti += (al + ar);
            cout << ti << "\n";
        }
    }
    return 0;
}
