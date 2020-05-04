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

string s, t;
int k, l, n;

int main() {
    cin >> s >> k;
    vector<string> S;
    n = s.size();
    for(int i = 0; i < n; i ++){
        t = "";
        l = min(k, n - i);
        for(int j = 0; j < l; j++){
            t += s[j + i];
            S.push_back(t);
        }
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    cout  << S[k - 1] << endl;

    return 0;
}