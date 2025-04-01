/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    ll l = 0, r = n - 1;
    sort(a.begin(), a.end());
    while(l < r) {
        if(a[l].fi + a[r].fi == x) {
            cout << a[l].se << " " << a[r].se;
            return 0;
        }
        if(a[l].fi + a[r].fi < x) l++;
        else r--;
    }
    cout << "IMPOSSIBLE";
    return 0;
}