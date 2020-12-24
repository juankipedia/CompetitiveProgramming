#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *  KMP.
 *  Find all occurrences of p in txt (pattern searching).
 *  Time complexity: O(n)
 **/

int t;
string txt, p;
int lps[1000000];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

int main(){
    io_boost;
    cin >> txt >> p;
    LPS();
    vector<int> ans;
    int i = 0, j = 0;
    while(i < txt.size()){
        if(txt[i] == p[j]){j++; i++;}
        if(j == p.size()){
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        }
        else if(i < txt.size() && p[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    if(ans.size() == 0) cout << "Not Found" << endl;
    else{
        cout << ans.size() << endl;
        for(int pos : ans) cout << pos << " ";
    }
    return 0;
}