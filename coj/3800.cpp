# include <bits/stdc++.h>

using namespace std;

size_t m = size_t(1e9+7);

size_t fast_exp(size_t b, size_t p)
{
  size_t r = size_t(1);
  for(size_t i = (size_t(1) << 60); i; i >>= 1)
    {
      r *= r;
      r %= m;
      if(p & i){
      	r *= b;
      	r %= m;
      }
    }
  return r;
}

size_t sol(size_t b, size_t p)
{
  if(p == 0)
  	return size_t(1);
  if(p & 1){
    size_t v = sol(b, p / 2);
    return (( v * fast_exp(b, p / 2 + 1)) % m + v) % m;
  }
  return ((sol(b, p - 1) * b) % m + 1) % m;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  size_t n,k;
  cin>> n >> k;
  size_t r = 0, c = 0;

  for(int i = 1; i <= k; ++i){
      size_t l;
      cin >> l;
      if(i & 1)
      	c += l;
      else 
      	r = (r + (l * sol(n, c - 1)) % m) % m;
  }
  cout << r << endl;

  return 0;
}
