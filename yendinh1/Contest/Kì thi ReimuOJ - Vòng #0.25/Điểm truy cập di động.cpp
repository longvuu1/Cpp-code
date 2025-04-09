#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    set<int> ss;
    for (int i = 1; i <= n; ++i) p[i] = i;
    auto update = [&](int i) {
        if (p[i] == i) ss.erase(i);
        else ss.insert(i);
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        swap(p[u], p[v]);
        update(u);
        update(v);

        if (ss.empty()) {
            cout << 1LL * n * (n - 1) / 2 << '\n';
        } else {
            int s1 = *ss.begin();
            int s2 = *ss.rbegin();
            int last_a = s1 - 1;
            int first_s = s2 + 1;

            if (last_a < first_s)
                cout << 1LL * last_a * (n - first_s + 1) << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}
