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
    ll S;
    cin >> n >> S;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Calculate prefix sum
    vector<ll> pref(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
        int left = 0, right = n - i;
        while(left <= right) {
            int mid = (left + right) / 2;
            ll sum = pref[i + mid] - pref[i];
            if(sum <= S) {
                ans = max(ans, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}ư