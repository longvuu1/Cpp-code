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
    ll n,x,dem=0;
    cin >> n >> x;
    vector<ll> a(n+1);  
    vector<ll> s(n+1,0);
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        mp[s[i]]++;
        dem+=mp[s[i]-x];
        if(s[i]==x&&s[i]-x!=s[i]) dem++;
    }
    cout << dem;
    return 0;
}