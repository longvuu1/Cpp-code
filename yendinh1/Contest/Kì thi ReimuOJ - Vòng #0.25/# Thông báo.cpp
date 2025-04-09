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
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    bool isPermabanned = false;
    // Check if the matrix contains the word "discord" in any direction
    string target = "discord";
    int len = target.length();
    
    // Check horizontal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - len; ++j) {
            string s = a[i].substr(j, len);
            if (s == target) {
                isPermabanned = true;
                break;
            }
        }
        if (isPermabanned) break;
    }
    
    // Check vertical
    if (!isPermabanned) {
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= n - len; ++i) {
                string s;
                for (int k = 0; k < len; ++k) {
                    s += a[i + k][j];
                }
                if (s == target) {
                    isPermabanned = true;
                    break;
                }
            }
            if (isPermabanned) break;
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    if (!isPermabanned) {
        for (int i = 0; i <= n - len; ++i) {
            for (int j = 0; j <= n - len; ++j) {
                string s;
                for (int k = 0; k < len; ++k) {
                    s += a[i + k][j + k];
                }
                if (s == target) {
                    isPermabanned = true;
                    break;
                }
            }
            if (isPermabanned) break;
        }
    }
    
    // Check diagonal (top-right to bottom-left)
    if (!isPermabanned) {
        for (int i = 0; i <= n - len; ++i) {
            for (int j = len - 1; j < n; ++j) {
                string s;
                for (int k = 0; k < len; ++k) {
                    s += a[i + k][j - k];
                }
                if (s == target) {
                    isPermabanned = true;
                    break;
                }
            }
            if (isPermabanned) break;
        }
    }
    
    cout << (isPermabanned ? "PERMABANNED" : "WELCOME TO GENSOKYO");
    
    return 0;
}