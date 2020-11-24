#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
void primeFactors(ulli n){
    vector<ulli> factors;
    while(n % 2 == 0){  
        factors.push_back(2);  
        n = n/2;  
    }
    for(ulli i = 3; i * i <= n; i = i + 2){
        while(n % i == 0){  
            factors.push_back(i);  
            n = n/i;  
        }  
    }
    if(n > 2) factors.push_back(n);
    
    if(factors.size() == 1){
        cout << 1 << endl << factors[0] << endl;
        return;
    }

    map<ulli, ulli> fm;
    for(ulli f: factors) ++fm[f];
    vector<pair<ulli, ulli>> fp;
    for(auto &p: fm) fp.push_back(p);
    sort(fp.begin(), fp.end(), [](auto &A, auto &B){
        return A.second > B.second;
    });
    factors.clear();
    for(auto &p: fp)
        for(ulli i = 0; i < p.second; i++) factors.push_back(p.first);


    vector<ulli> ans;
    ulli pos =  factors.size() - 1;
    for(ulli i = 1; i < factors.size(); i++){
        //cout << factors[i] << " " << factors[i - 1] << endl;
        if(factors[i] == factors[i - 1]) ans.push_back(factors[i - 1]);
        else{
            pos = i - 1;
            break;
        }
    }
    //cout << "---" << pos << endl;
    cout << ans.size() + 1 << endl;
    for(ulli f: ans) cout << f << " ";
    ulli lf = factors[pos];
    for(ulli i = pos + 1; i < factors.size(); i++) lf *= factors[i];
    cout << lf << " " << endl;
}  


int t;
ulli N;

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        primeFactors(N);
    }
    
    return 0;
}