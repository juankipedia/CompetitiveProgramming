#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
 
int n, a[100001], m[100001], nm[100001];
string s;
 
 
int main(){
    io_boost;
    cin >> s;
    s += '$';
    n = s.size();
    for(int i = 0; i < n; i++) a[i] = i;
    sort(a, a + n, [](int i, int j){
        return s[i] < s[j];
    });
 
    m[a[0]] = 0;
    for(int i = 1; i < n; i++)
        if(s[a[i]] == s[a[i - 1]])  m[a[i]] = m[a[i - 1]];
        else m[a[i]] = m[a[i - 1]] + 1;
 
    ulli k = 0;
    for(; (1ull << k) < n; k ++){
        sort(a, a + n, [k](int i, int j){
            if(m[i] < m[j]) return true;
            if(m[i] == m[j]) return m[(i + (1ull << k)) % n] < m[(j + (1ull << k)) % n];
            return false;
        });
        nm[a[0]] = 0;
        for(int l = 1; l < n; l++){
            int i = a[l], j = a[l - 1];
            if(m[i] == m[j] && m[(i + (1ull << k)) % n] == m[(j + (1ull << k)) % n]) nm[a[l]] = nm[a[l - 1]];
            else nm[a[l]] = nm[a[l]] = nm[a[l - 1]] + 1;
        }
        for(int i = 0; i < n; i++) m[i] = nm[i];
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}