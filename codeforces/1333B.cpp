#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int main(){
    io_boost;
    int t, n, a[(int)(1e5)], b[(int)(1e5)], av[2];
    bool valid;
    cin >> t;
    while (--t != -1)
    {
        cin >> n;
        valid = true;

        av[0] = av[1] = 0;

        for (int i{0}; i < n; ++i)
            cin >> a[i];

        for (int i{0}; i < n; ++i)
            cin >> b[i];

        valid = a[0] == b[0];

        for (int i{0}; i < n; ++i)
        {
            if ((a[i] < b[i] && !av[1]) || (a[i] > b[i] && !av[0]))
            {
                valid = false;
                break;
            }

            if (a[i] == 1)
                av[1] = 1;
            else if (a[i] == -1)
                av[0] = 1;
        }

        cout << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}