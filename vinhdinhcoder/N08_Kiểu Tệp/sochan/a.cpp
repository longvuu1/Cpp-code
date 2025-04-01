/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "sochan"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    ll dem=0;
    vector<ll> a(n);
    vector<ll> b;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(a[i]%2==0) {
            dem++;
            b.pb(a[i]);
        }
    }
    cout << dem << endl; 
    for(ll i=0; i<b.size(); i++) {
        cout << b[i] << " ";
    }
    return 0;
}