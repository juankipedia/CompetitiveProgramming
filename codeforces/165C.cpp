# include <bits/stdc++.h>
using namespace std;

int main(){
    long long k; 
    string s; 
    cin >> k >> s;
    long long n = s.size();
    vector<long long> f(n + 1,0); 
    f[0] = 1;

    long long sum = 0, r = 0;
    for(long long i = 0; i < n; i++){
        if(s[i] == '1')
        	sum++;
        if(sum >= k)
        	r += f[sum - k];
        ++f[sum];
    }

    cout << r << "\n";
    return 0;
}