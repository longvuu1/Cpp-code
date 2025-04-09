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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> b;
    for(ll i =0;i<n;i++){
        if (a[i]!=a[i+1]){
            b.pb(a[i]);
        }
    }
    ll res=0;
    for(ll i = 0; i < b.size(); i++) {
        res = max(res,upper_bound(b.begin(),b.end(),b[i]+n-1)-b.begin()-i);
    }
    cout << n - res;
    return 0;
}