#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t, n;
    long long int a, b;
    std::cin >> t;
    while(t--){
        std::cin >> a >> b >> n;
        pair<long long int, long long int> arr[n];
        for(int i = 0; i < n; i++){
            std::cin >> arr[i].first;
        }
        for(int i = 0; i < n; i++) std::cin >> arr[i].second;
        sort(arr, arr + n);
        bool flag = true;
        for(int i = 0; i < n; i++){
            bool could_kill = true;
            if(arr[i].second <= a) b -= arr[i].first;
            else{
                unsigned long long int k = (arr[i].second + a - 1) / a;
                unsigned long long int k1 = (b + arr[i].first - 1) / arr[i].first;
                if(k1 < k) could_kill = false;
                b -= arr[i].first * k;
            }
            if((b <= 0 && i != n - 1) || !could_kill){ flag = false; break; }
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    
    }
    return 0;
}