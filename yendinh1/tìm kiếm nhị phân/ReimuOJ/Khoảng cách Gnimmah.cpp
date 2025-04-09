/*
    @author longvuuu
*/
#include <bits/stdc++.h>
#define taskname "GNIMMAH"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> s[26];
int tknp(vector<int> v, int k) {
    int l = 0, r = v.size() - 1;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(v[mid] >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int tknp1(vector<int> &v, int k) {
    int l = 0, r = v.size() - 1;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(v[mid] <= k) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.length(),m=b.length();
    for(int i = 0; i < n; i++) {
        s[a[i]-'a'].pb(i);
    }
    ll res = 0;
    for(int i = 0; i <= n - m; i++) {
        int dem = 0;
        for(int j = 0; j < m; j++) {
            if(a[i + j] == b[j]) {
                dem++;
            }
        }
        res += dem;
    }
    cout << res << "\n";
    return 0;
}