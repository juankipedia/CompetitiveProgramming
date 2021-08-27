# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int main(){
    string s;
    int k;
    cin >> s >> k;
    vector<string> v;
    sort(s.begin(), s.end());
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << v[k - 1] << endl;
    return 0;
}