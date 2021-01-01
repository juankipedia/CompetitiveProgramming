#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 30000;
int len, n;
int s[MAXN], lis[MAXN];

void LIS(){
    len = 0;
    vector<int> l;
    int lis_len[MAXN], pos;
    for(int i = 0; i < n; i++){
        int j = lower_bound(l.begin(), l.end(), s[i]) - l.begin();
        if(j == l.size()) l.push_back(s[i]);
        else l[j] = s[i];
        lis_len[i] = j + 1;
        if(lis_len[i] > len){
            len = lis_len[i];
            pos = i;
        }
    }
    lis[len - 1] = s[pos];
    for(int i = pos - 1, j = len - 2; i >= 0; i--){
        if(s[i] < s[pos] && lis_len[i] == lis_len[pos] - 1){
            pos = i;
            lis[j] = s[i];
            j--;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    LIS();
    cout << len << endl;
    return 0;
}