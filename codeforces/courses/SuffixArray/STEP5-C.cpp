#include <bits/stdc++.h>
using namespace std;
 
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
 
int n, a[400001], m[20][400001], lcp[400001], pn;
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
    io_boost;
    cin >> s;
    s += '$';
    n = s.size();
    for(int i = 0; i < n; i++) a[i] = i;
    sort(a, a + n, [](int i, int j){
        return s[i] < s[j];
    });
 
    m[0][a[0]] = 0;
    for(int i = 1; i < n; i++)
        if(s[a[i]] == s[a[i - 1]])  m[0][a[i]] = m[0][a[i - 1]];
        else m[0][a[i]] = m[0][a[i - 1]] + 1;
 
    ulli k = 0;
    for(; (1 << k) < n; k ++){
        for(int i = 0; i < n; i++)
            v[i] = {{m[k][(a[i] - (1 << k)  + n) % n],  m[k][a[i]]}, (a[i] - (1 << k)  + n) % n};
        rs();
        for(int i = 0; i < n; i++) a[i] = v[i].second;
        m[k + 1][a[0]] = 0;
        for(int l = 1; l < n; l++){
            int i = v[l].first.first, j = v[l].first.second, ii = v[l - 1].first.first, jj = v[l - 1].first.second;
            if(i == ii && j == jj) m[k + 1][a[l]] = m[k + 1][a[l - 1]];
            else m[k + 1][a[l]] = m[k + 1][a[l - 1]] + 1;
        }
    }

    cin >> pn;

    vector<pair<int, int>> ss(pn);

    for(int i = 0; i < pn; i++){
        cin >> ss[i].first >> ss[i].second;
        ss[i].first--; ss[i].second--;
    }
    sort(ss.begin(), ss.end(), [](auto A, auto B){
        int la = A.second - A.first + 1, lb = B.second - B.first + 1;
        int i = A.first, j = B.first, l = min(la, lb);
        int k = log2(l);
        pair<int, int> a = {m[k][i], m[k][(i + l - (1 << k)) % n]};
        pair<int, int> b = {m[k][j], m[k][(j + l - (1 << k)) % n]};
        if(a == b){
            if(la == lb) return A < B;
            else if(la < lb) return true;
            else return false;
        }
        return a < b;

    });


    for(int i = 0; i < pn; i++)
        cout << ss[i].first + 1 << " " << ss[i].second + 1 << endl;
    return 0;
}