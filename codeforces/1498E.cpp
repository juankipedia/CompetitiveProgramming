# include <bits/stdc++.h>
using namespace std;
 
 
int N, a[505];
 
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    vector<pair<int, pair<int, int>>> v;
    for(int i = 1; i <= N; i++){
        if(a[i] == 0 || a[i] == N - 1) continue;
        for(int j = i + 1; j <= N; j++){
            if(a[j] == 0 || a[j] == N - 1) continue;
            if(a[i] >= a[j])
                v.push_back({abs(a[i] - a[j]), {i, j}});
            else
                v.push_back({abs(a[i] - a[j]), {j, i}});
        }
    }
 
    if(v.size() == 1){
        cout << "! 0 0" << endl;
        return 0;
    }
 
    sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
    
    for(auto &p : v){
        cout << "? " <<  p.second.first << " " << p.second.second << endl;  
        string ans;
        cin >> ans;
        cout.flush();
        if(ans[0] == 'Y'){
            cout << "! " << p.second.first << " " << p.second.second << endl;
            return 0;
        }
    }
    cout << "! 0 0"<< endl;
    return 0;
}