#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long c0 = 0;
    const int B = 32; 
    vector<vector<int>> g(B);
    for (int x : a) {
        if(x == 0) c0++;
        else {
            int b = 31 - __builtin_clz(x); 
            g[b].push_back(x);
        }
    }
    
    long long r = 0;
    r += c0 * n;
    vector<vector<int>> cb(B, vector<int>(B, 0));
    for (int c = 0; c < B; c++){
        for (int x : g[c]){
            for (int b = 0; b < c; b++){
                if(x & (1 << b))
                    cb[c][b]++;
            }
        }
    }
    for (int b = 0; b < B; b++){
        int cg = g[b].size();
        if(cg == 0) continue;
        long long vy = 0;
        for (int c = b+1; c < B; c++){
            vy += cb[c][b];
        }
        r += (long long) cg * vy;
    }
    
    cout << r << "\n";
    return 0;
}
