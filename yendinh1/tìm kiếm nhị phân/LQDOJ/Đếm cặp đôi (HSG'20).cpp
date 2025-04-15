/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,x;
    cin >> n >> x;  
    vector<ll> a(n);
    map<ll, ll> s;
    ll res=0;
    for(ll i =0;i<n;i++){
        cin>>a[i];
        res+=s[x-a[i]];
        s[a[i]]++;
    }
    cout << res;
    return 0;
}