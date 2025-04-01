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
    ll n, dem = 0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(23, 0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll i = 0;
    for(ll j = 6; j < n; j++) {
        while(i + 5 < j) {
            cnt[a[i] % 23]++;
            i++;
        }
        dem += cnt[a[j] % 23];
    }
    cout << dem;
    return 0;
}