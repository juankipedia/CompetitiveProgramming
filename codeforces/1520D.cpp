# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int T;

int main(){
    io_boost;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n + 5];
        map<lli, lli> freq;
        vector<lli> av;
        lli val = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i <= n; i++){
            if(freq.count(arr[i] - i))
                val += freq[arr[i] - i];
            else val += 0;
            freq[arr[i] - i]++;
        }
        cout << val << endl;
    }
    return 0;
}