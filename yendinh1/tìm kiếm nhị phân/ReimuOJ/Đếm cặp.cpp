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

    int n;
    ll l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int low = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
        int high = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
        res = res + (high - low);
    }
    cout << res << "\n";
    return 0;
}