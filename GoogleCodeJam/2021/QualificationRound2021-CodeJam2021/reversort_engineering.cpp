# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, c, a[105];

int main(){
    int t;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n >> c;
       
        cout << "Case #" << ti << ": ";
        if(c < n - 1 || c > (n * (n + 1) / 2 - 1)){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int r = n, off = n - 2, cnt = 0;
        vector<int> ans;
        while(r >= 2){
            if(cnt  + r + off > c){
                int ri = r;
                while(cnt + ri + off > c) ri--;
                ans.push_back(ri);
                break;
            }
            else if(cnt + r + off == c){
                ans.push_back(r);
                break;
            }
            ans.push_back(r);
            cnt += r;
            r--;
            off--;
        }
        
        for(int i = 1; i <= n; i++) a[i - 1] = i;
        bool rd = true;
        int L = 0, R = n - 1;
        for(int e: ans){
            for(int j = R, k = R - e + 1; k < j; j--, k++) swap(a[j], a[k]);
            if(rd) R--;
            else L++;
            rd = !rd;
        }

        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}