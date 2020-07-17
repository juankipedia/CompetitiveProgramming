#include <bits/stdc++.h>
using namespace std;
 
# define fast_io std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
 
int n, a[400001], m[400001], lcp[400001];
string s;
pair<pair<int, int>, int> v[400001], r[400001]; 
 
void rs(){
    int c[n] = {0}, p[n] = {0};
    for(int i = 0; i < n; i++)
        c[v[i].first.first]++;
    for(int i = 1; i < n; i++) p[i] = p[i - 1] + c[i - 1];
    for(int i = 0; i < n; i++)
        r[p[v[i].first.first]++] = v[i];
    for(int i = 0; i < n; i++) v[i] = r[i];
}
 
int main(){
    fast_io;
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
        for(int i = 0; i < n; i++)
            v[i] = {{m[(a[i] - (1ull << k)  + n) % n],  m[a[i]]}, (a[i] - (1ull << k)  + n) % n};
        rs();
        for(int i = 0; i < n; i++) a[i] = v[i].second;
        m[a[0]] = 0;
        for(int l = 1; l < n; l++){
            int i = v[l].first.first, j = v[l].first.second, ii = v[l - 1].first.first, jj = v[l - 1].first.second;
            if(i == ii && j == jj) m[a[l]] = m[a[l - 1]];
            else m[a[l]] = m[a[l - 1]] + 1;
        }
    }

    for(int i = 0; i < n; i++){
        m[a[i]] = i;
        cout << a[i] << " ";
    }
    cout << "\n";

    int K = 0;
    for(int i = 0; i < n - 1; i++){
        int pi = m[i]; int j = a[pi - 1];
        while(s[i + K] == s[j + K]) K++;
        lcp[pi] = K;
        K = max(K - 1, 0);
    }
    for(int i = 1; i < n; i++) cout << lcp[i] << " ";
    cout << "\n";
    return 0;
}