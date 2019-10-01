#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;


ulli mod(ulli n, ulli m) { return (n % m + m) % m; }

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ulli h, w, empty{1};
    cin >> h >> w;

    vector<ulli> r(h), c(w);

    for (ulli &i : r)
        cin >> i;
    for (ulli &i : c)
        cin >> i;

    for (ulli i{0}; i < h; ++i)
    {
        for (ulli j{0}; j < w; ++j)
        {

        	if(j < r[i] and i == c[j]){
        		cout << 0 << endl;
        		return 0;
        	}
        	if(j == r[i] and i < c[j]){
        		//cout << i << " " << j << endl;
        		cout << 0 << endl;
        		return 0;
        	}
            if (i > c[j] && j > r[i])
            {
                empty = empty * 2;
                empty = empty % 1000000007;
            }
        }
    }

    cout << empty << endl;

    return 0;
}