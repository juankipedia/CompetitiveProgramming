#include <bits/stdc++.h>

using namespace std;


int main() {
  
unsigned long long n, aux, lastPow;

  cin >> n;
  aux = n;

  lastPow = (n & 1) ? 1 : 2;
  
  while(!(aux & 1))
   aux >>= 1;

  if(aux == 1 && lastPow == 2)
  {
    cout << 2 << endl;
    return 0;
  }


  for(unsigned long long i = 3; i * i <= n; i += 2) {
  if(aux%i ==0 && lastPow != 1) {
    cout << 1 << endl;
    return 0;
}
  while(aux % i == 0) {
    aux /= i;
    lastPow = i;
}
    
}

if(lastPow == 1)
    cout << aux << endl;
else if(aux == 1)
    cout << lastPow << endl;
    else cout << 1 << endl;

return 0;
}