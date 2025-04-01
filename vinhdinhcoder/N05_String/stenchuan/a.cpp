/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define simp main
#define pb push_back
using namespace std;

char toupper(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char tolower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int simp() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    string st;
    getline(cin, st);
    cout << toupper(st[0]);
    for(int i = 1; i < st.length(); i++) {
        if(st[i-1] == ' ') {
            cout << toupper(st[i]);
        } else {
            cout << tolower(st[i]);
        }
    }
    
    return 0;
}