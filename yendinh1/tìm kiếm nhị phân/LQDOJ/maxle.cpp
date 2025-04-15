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
    ll n,k;
    cin >> n >>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    while(k--){
        ll x;
        cin >> x;
        ll l = 0, r = n - 1,res=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[mid]<=x){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout << res+1 << endl;
    }
    return 0;
}