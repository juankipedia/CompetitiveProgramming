#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;



int main() {
int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  if (k > 0)
  {
    if (s.size() == 1)
    {
      s[0] = '0';
      --k;
    }

    if (s[0] > '1')
    {
      s[0] = '1';
      --k;
    }

    for (size_t i{1}; i < n && k > 0; ++i)
    {
      if (s[i] > '0')
      {
        s[i] = '0';
        --k;
      }
    }
  }

  cout << s << endl;
}