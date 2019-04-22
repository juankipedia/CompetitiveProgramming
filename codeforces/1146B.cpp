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

string solve(){
    for(int i = 0;i < s.size(); i++)
        if(s[i] != 'a')
            t += s[i];
    if(t.size() % 2 != 0)
        return ":(";

    int mid = t.size() / 2;

    string t1 = t.substr(0,mid), t2 = t.substr(mid,mid);
    if(t1 == t2 && t1 == s.substr(s.size()-mid,mid))
        return s.substr(0,s.size() - mid);
    return ":(";
}

int main(){
    cin >> s;
    cout<< solve()<<endl;
    return 0;
}