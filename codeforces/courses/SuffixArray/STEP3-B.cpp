#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
 
int n, a[400001], m[400001], t;
string s, si;
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


bool compare(int p, string &str){
    for(int i = 0; i < str.length(); i++){
        if(s[(p + i) % n] < str[i]) return true;
        else if(s[(p + i) % n] > str[i]) return false;
    }
    return false;
}

bool bs(string &str, int &p){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(compare(a[mid], str)) l = mid + 1;
        else r = mid;
    }
    for(int i = 0; i < str.length(); i++)
        if(s[(a[l] + i) % n] != str[i]) return false;
        p = l;
    return true;
}

bool compare2(int p, string &str){
    for(int i = 0; i < str.length(); i++)
        if(s[(p + i) % n] < str[i]) return true;
        else if(s[(p + i) % n] > str[i]) return false;
    return true;
}

bool bs2(string &str, int &p){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + (r - l + 1) / 2;
        if(compare2(a[mid], str)) l = mid;
        else r = mid - 1;
    }
    for(int i = 0; i < str.length(); i++)
        if(s[(a[r] + i) % n] != str[i]) return false;
        p = r;
    return true;
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
            else m[a[l]] = m[a[l]] = m[a[l - 1]] + 1;
        }
    }

    cin >> t;
    while(t--){
        cin >> si;
        int p1 = -1, p2 = -1;
        bs(si, p1); 
        bs2(si, p2);
        if(p1 != -1 && p2 != -1) cout << p2 - p1 + 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}