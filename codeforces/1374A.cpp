#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int64_t t, x, y, n, k;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> x >> y >> n;

        k = (n / x) * x + y;

        while (k > n)
            k -= x;

        cout << k << "\n";
    }

    return 0;
}
