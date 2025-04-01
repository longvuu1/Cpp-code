/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
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
    ll n;
    cin >> n;
    n=n*n;
    vector<ll> a(n);
    ll s = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    map<ll, ll> k;
    for (ll i = 0; i < n; i++) {
        k[a[i]] += a[i];
    }
    ll res = 0;
    for (auto& i : k) {
        res = max(res, s - i.se);
    }
    cout << res;
    return 0;
}