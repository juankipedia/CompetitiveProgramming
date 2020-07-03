#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int64_t t, n, l, r, o, acc;
string s;

int main(){
   io_boost;
    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> n;
        cin >> s;

        l = r = o = acc = 0;

        for (int i{0}; i < n; ++i)
        {
            if (s[i] == '(')
                ++o;
            else
                --o;

            if (o == -1)
            {
                ++acc;
                ++o;
            }
        }

        cout << acc << "\n";
    }

    return 0;
}
