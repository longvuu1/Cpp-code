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

bool check(ll n) {
    if (n < 1000000) {
        ll x = round(cbrt(n));
        return x * x * x == n;
    }
    ll l = 0, r = 1000000;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll k = mid * mid * mid;
        if (k == n) return true;
        if (k < n)
            l = mid + 1;
        else
            r = mid - 1;
        if (k / mid / mid != mid) break;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (check(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}