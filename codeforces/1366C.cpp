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
int matrix[30][30];
int t, n, m;

int main() {
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> matrix[i][j];
        vector<int> o, z;
        for(int i = 0; i < m; i++){
            int h = i, k = 0, oi = 0, zi = 0;
            while(k < n && h >= 0){
                if(matrix[k][h] == 0) zi++;
                else oi ++;
                k++; h--;
            }
            o.push_back(oi); z.push_back(zi);
        }

        for(int i = 1; i < n; i++){
            int h = i, k = m - 1, oi = 0, zi = 0;
            while(h < n && k >= 0){
                if(matrix[h][k] == 0) zi++;
                else oi ++;
                h++; k--;
            }
            o.push_back(oi); z.push_back(zi);
        }
        int l = 0, r = o.size() - 1, ans = 0;
        while(l < r){
            if((z[l] + z[r]) < (o[l] + o[r])) ans += z[l] + z[r];
            else ans += o[l] + o[r];
            l++; r--;
        }
        cout << ans << endl;
    }
    return 0;
}

