/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "tepso"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll a,b,c;
    while(cin >> a >> b >> c){
        ll res=0;
        res+=a+b+c;
        cout << res << endl;
    }
    
    return 0;
}