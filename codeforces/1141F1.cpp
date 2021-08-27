# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int N, a[55];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    int p, k = 0, sp;
    for(int i = 0; i < N; i++)
        for(int s = 1; s <= N; s++){
            int sum = 0, kp = 1;
            if((i + s) > N) continue;
            int l = i, r = i + s - 1;
            for(int j = i; j < i + s; j++) sum += a[j];
            for(int j = i + s; j < N; j++){
                int sumj = 0, w = j;
                for(; w < N; w++){
                    sumj += a[w];
                    if(sumj == sum){ w++; break; }
                }
                w--;
                if(sumj == sum){
                    if(w <= r) l = j, r = w;
                    else if(j > r) kp++, l = j, r = w;
                }
            }
            if(k < kp){
                k = kp;
                p = i;
                sp = s;
            }
        }

    
    vector<pair<int, int>> ans;
    ans.push_back({p, p + sp - 1});
    int sum = 0;
    int l = p, r = p + sp - 1;
    for(int j = p; j < p + sp; j++) sum += a[j];
    for(int j = p + sp; j < N; j++){
        int sumj = 0, w = j;
        for(; w < N; w++){
            sumj += a[w];
            if(sumj == sum){ w++; break; }
        }
        w--;
        if(sumj == sum){
            if(w <= r){
                //cout << j << " " << w << endl;
                l = j; 
                r = w;
                ans.pop_back();
                ans.push_back({l, r});
            }
            else if(j > r){
                l = j;
                r = w;
                ans.push_back({l, r});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto [i, j] : ans) cout << i + 1 << " " << j + 1 << endl;
    return 0;
}