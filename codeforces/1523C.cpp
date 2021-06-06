# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int T, N, nums[1005];

int main(){
    io_boost;
    cin >> T;
    while(T--){
        cin >> N;
        vector<int> list[N];
        for(int i = 0; i < N; i++) cin >> nums[i];
        list[0].push_back(nums[0]);
        for(int i = 1; i < N; i++){
            list[i] = list[i - 1];
            if(nums[i] == 1) list[i].push_back(nums[i]);
            else{
                while(list[i][list[i].size() - 1] + 1 != nums[i]){
                    list[i].pop_back();
                }
                list[i][list[i].size() - 1] = nums[i];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < list[i].size() - 1; j++){
                cout << list[i][j] << ".";
            }
            cout << list[i][list[i].size() - 1] << endl;
        }
    }
    return 0;
}