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

ulli n[25821], N;
int t;
int main() {
    io_boost;
    cin >> t;
    int i = 2;
    n[1] = 2;
    while(n[i - 1] <= 1000000000){
        n[i] = n[i - 1] + 3 * i - 1;
        i++;
    }

    while(t--){
        cin >> N;
        int j = 1;
        while(N > 1){
            auto pp  = lower_bound(n, n + i, N);
            int p = pp - n;
            if(n[p] > N) p--;
            N -= n[p];
            j ++;
        }
        cout << j - 1 << endl;
    }


    return 0;
}