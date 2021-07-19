# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n;
string num;

int main(){
    cin >> n;
    cin >> num;
    vector<string> ans;
    for(int i = 0; i < 10; i++){
        vector<string> b;
        for(int j = 0; j < n; j++){
            string c = num;
            for(int k = 0; k < n; k++) c[k] = num[(j + k) % n];
            b.push_back(c);
        }
        sort(b.begin(), b.end());
        ans.push_back(b[0]);
        for(int j = 0; j < n; j++) num[j] = (((num[j] - '0') + 1) % 10) + '0';
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}

