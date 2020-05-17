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

int main(){
    int t, n, k, aarr[30], b[30], s{0};

    cin >> t;
    while (--t != -1)
    {
        cin >> n >> k;

        for (int i{0}; i < n; ++i)
            cin >> aarr[i];
        for (int i{0}; i < n; ++i)
            cin >> b[i];

        sort(aarr, aarr + n, std::greater<int>());
        sort(b, b + n, std::greater<int>());

        s = 0;
        for (int i{0}, ai{0}, bi{0}; i < n; ++i)
            if (b[bi] > aarr[ai] && bi < k)
                s += b[bi++];
            else
                s += aarr[ai++];

        cout << s << "\n";
    }return 0;
}
    