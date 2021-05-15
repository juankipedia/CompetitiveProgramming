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
 
int n;
const int MAX = 100;
string s;
int a[MAX];
int b[MAX];
 
int main() {
    cin >> n;
    cin >> s;
    int t = 6;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        t = min(t, b[i]);
    }
    int r = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '1') r++;
 
    string s1 = s;
    while(true){
        int ri = 0;
        for(int i = 0; i < n; i++){
            if(t >= b[i] && ((t - b[i]) % a[i] == 0))
                if(s1[i] == '1') s1[i] = '0';
                else s1[i] = '1';
 
            if(s1[i] == '1') ri ++;
        }
        //cout << s1 << " " << t << endl;
        r = max(r, ri);
        if(t == 1000000) break;
        t++;
 
    }
 
    cout << r << endl;
    return 0;
}