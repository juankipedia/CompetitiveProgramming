#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int n, m;
bool nm[100];
string sa[100];
vector<string> l, r;
string middle;

bool palindrome(const string &s){
    int l = 0, h = s.size() - 1; 

    while (h > l) 
        if (s[l++] != s[h--]) 
            return false; 
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> sa[i];
    for(int i = 0; i < n; i++){
        if(nm[i]) continue;
        for(int j = i + 1; j < n; j++){
            if(nm[j]) continue;
            if(palindrome(sa[i] + sa[j])){
                l.push_back(sa[i]); r.push_back(sa[j]);
                nm[i] = nm[j] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!nm[i] && palindrome(sa[i])) { middle = sa[i]; break;}
    }
    cout << l.size() * m + middle.size() + r.size() * m << endl;
    for(const string &ss: l) cout << ss;
    cout << middle;

    for(int i = r.size() - 1; i >=0 ;i--) cout << r[i];
    cout << endl;
    return 0;
}