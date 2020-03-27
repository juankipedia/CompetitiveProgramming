#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

lli t, n, k, ki;
string s;

int main() {
    cin >> t;
    while(t--){
        cin >> n >> k;
        s = string(n, 'a');
        ki = 1;
        lli j = n - 1, i = n - 2;
        for(; i >= 0; i--){
            //cout << i << " " << j  << " " << ki << endl;
            if(ki == k) break;
            else if((j - i - 1) + ki > k){
                for(; j > i; j--){
                    if(ki == k) break;
                    ki ++;
                }
                break;
            } 
            ki += (j - i - 1);
            if(ki == k){
                j = i + 1;
                break;
            }
            ki ++;
        }
        s[j] = s[i] = 'b';
        cout << s << endl;
    }
    return 0;
}