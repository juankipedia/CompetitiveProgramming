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

int t, a, b;
string s, sp;
int main() {
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> s;
        sp = string(s[0] - '0', '(') + s[0];
        for(int i = 1; i < s.size(); i++){
            a = s[i] - '0';
            b = s[i - 1] - '0';
            if(s[i] < s[i - 1]) sp += string(b - a, ')') + s[i];
            else if(s[i] > s[i - 1]) sp += string(a - b, '(') + s[i];
            else sp += s[i];
        }
        sp += string(s[s.size()-1] - '0', ')');
        cout << "Case #" << ti << ": " << sp << endl;
    }
    return 0;
}