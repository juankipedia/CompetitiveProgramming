# include <bits/stdc++.h>
using namespace std;





int main(){
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n;
    while(l < r){
        int mid = (r + l) / 2;
        cout << "? " << l << " " << mid << endl;
        int sum;
        cin >> sum;
        sum = (mid - l + 1) - sum;
        if(sum >= k){
            r = mid;
        }
        else{
            l = mid + 1;
            k -= sum;
        }
    }
    cout << "! " <<  l << endl;
    return 0;
}