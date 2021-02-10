#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n, k;
string num[8];
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];
    vector<int> pos;
    for(int i = 0; i < k; i++) pos.push_back(i);
    int ans = 1e9;
    do{
        vector<int> nums;
        for(int i = 0; i < n; i++){
            string s = "";
            for(int p: pos) s += num[i][p];
            nums.push_back(stoi(s));
        }
        sort(nums.begin(), nums.end());
        ans = min(ans, nums[n - 1] - nums[0]);
 
    }while(next_permutation(pos.begin(), pos.end()));
    cout << ans << endl;
    return 0;
}