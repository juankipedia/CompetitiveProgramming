#include<bits/stdc++.h>
using namespace std;
int main()
{
      ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
      long long n, t;
      cin >> t;
      while(t--)
      {
            cin >> n;
            long long a[n], flag=1;
            for (long long i=0; i<n; i++)
            {
                  cin >>a[i];
                  a[i]+=i;
            }
            set<long long> ans;
            for (long long i=0; i<n; i++)
            {
                  long long temp= temp=(n+a[i]%n)%n;
                  if (ans.count(temp)==1)
                  {
                        flag=0;
                        break;
                  }
                  else ans.insert(temp);
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
      }
      return 0;
}