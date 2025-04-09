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
ll lower(const vector<ll>& a, ll m) {
    ll l = 0, r = a.size();
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (a[mid] < m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
vector<ll> khoitao() {
    vector<ll> a;
    ll N = 1e18;
    for (ll i = 1;i<=N;i*=2){
        for (ll j =1;j<=N/i;j*=3){
            for (ll k =1;k<=N/(i*j);k*= 5){
                a.pb(i*j*k);
            }
        }
    }
    sort(a.begin(), a.end());
    return a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    vector<ll> a = khoitao();
    int q;
    cin >> q;
    while (q--) {
        ll m;
        cin >> m;
        int k = lower(a, m);
        if (k<a.size()&&a[k]==m){
            cout << (k + 1) << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}