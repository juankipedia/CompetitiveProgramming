#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
lli hi;
priority_queue<pair<lli, int>> pq;
set<int> pos;

int main(){
    io_boost;
    while(cin >> n && n != 0){
        for(int i = 0; i < n; i++){
            cin >> hi;
            pq.push({hi, i});
            pos.insert(i);
        }

        lli maxi = 0;

        while(!pq.empty()){
            auto k = pq.top();
            pos.erase(k.second);
            auto it = pos.lower_bound(k.second);
            lli l, r;
            if(it != pos.end()) r = *it;
            else r = n;

            if(it == pos.begin()) l = -1;
            else{
                it--;
                l = *it;
            }
            maxi = max((r - l - 1) * k.first, maxi);
            pq.pop();
        }
        cout << maxi << endl;
    }
    return 0;
}