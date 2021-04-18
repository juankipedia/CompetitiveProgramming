# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, K;
    set<int> ss;
    cin >> t;
    while(t--){
        cin >> n >> K;
        int j = n, i = 1;
        vector<int> res, res3;
        for(int l = 0; l < K && i < j; l++){
            res.emplace_back(i); res.emplace_back(j);
            i++; j--;
        }
        for(; i <= j; i++){
            res.emplace_back(i);
        }
        for(int l = 1; l < res.size() - 1; l++)
            if(res[l] > res[l - 1] && res[l] > res[l  + 1]) K--;
        if(K != 0){
            cout << -1 << endl;
            continue;
        }
        for(int nn: res) cout << nn << " ";
        cout << endl;
    }
    return 0;
}