/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    unordered_map<ll, vector<ll>> s;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].pb(i);
    }

    while (q--) {
        ll x, l, r;
        cin >> x >> l >> r;
        if (s.find(x) == s.end()) {
            cout << 0 << '\n';
            continue;
        }
        vector<ll>& ss = s[x];
        ll l1 = -1, r1 = -1;
        ll l2 = 0, r2 = ss.size() - 1;
        while (l2 <= r2) {
            ll mid = (l2 + r2) / 2;
            if (ss[mid] >= l) {
                l1 = mid;
                r2 = mid - 1;
            } else {
                l2 = mid + 1;
            }
        }

        l2 = 0, r2 = ss.size() - 1;
        while (l2 <= r2) {
            ll mid = (l2 + r2) / 2;
            if (ss[mid] <= r) {
                r1 = mid;
                l2 = mid + 1;
            } else {
                r2 = mid - 1;
            }
        }
        if (l1 == -1 || r1 == -1 || l1 > r1) {
            cout << 0 << '\n';
        } else {
            cout << (r1 - l1 + 1) << '\n';
        }
    }

    return 0;
}