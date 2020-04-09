#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
int main(){
    io_boost;
    int t, n, m;
    char b[100][100];
    bool black;

    cin >> t;
    while (--t != -1)
    {
        cin >> n >> m;
        black = true;

        for (int i{0}; i < n; ++i)
            for (int j{0}; j < m; ++j)
            {
                if (i & 1)
                    b[i][j] = ((j & 1) ? 'B' : 'W');
                else
                    b[i][j] = ((j & 1) ? 'W' : 'B');
            }

        if (!((n * m) & 1))
        {
            bool fixed = false;
            for (int i{0}; i < n; ++i)
            {
                for (int j{0}; j < m; ++j)
                    if (b[i][j] == 'W')
                    {
                        b[i][j] = 'B';
                        fixed = true;
                        break;
                    }
                if (fixed)
                    break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << b[i][j];
            cout << "\n";
        }
    }
    return 0;
}