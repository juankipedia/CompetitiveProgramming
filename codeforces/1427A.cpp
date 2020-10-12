#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[50], b[51], s[51];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> neg, po, ze;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < 0) neg.push_back(a[i]);
            else if(a[i] > 0) po.push_back(a[i]);
            else ze.push_back(a[i]);
        }
        if(po.size() == 0 && neg.size() == 0){
            cout << "NO" << endl;
            continue;
        }
        int k = 0, spo = 0, sneg = 0;
        for(int j = 0; j < po.size(); j++) spo += po[j];
        for(int j = 0; j < neg.size(); j++) sneg += neg[j];
        
        if(spo > abs(sneg)){
            for(int j = 0; j < po.size(); j++, k++) b[k] = po[j];
            for(int j = 0; j < neg.size(); j++, k++) b[k] = neg[j];
        }
        else if(spo < abs(sneg)){
            for(int j = 0; j < neg.size(); j++, k++) b[k] = neg[j];
            for(int j = 0; j < po.size(); j++, k++) b[k] = po[j];
        }
        else{
            cout << "NO" << endl;
            continue;
        }

        for(int j = 0; j < ze.size(); j++, k++) b[k] = ze[j];
        
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;



    }
    return 0;
}