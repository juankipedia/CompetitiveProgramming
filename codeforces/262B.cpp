#include <iostream>
#include <vector>
using namespace std;

int main(){
 int n, k;
 cin >> n >> k;
 vector<int> array;
 int aux, minor = 100000, pos_minor = 0;
 int sum = 0;
 for(int i = 0; i < n; i++)
 {
  cin >> aux;
  if(aux < 0) {
   if(k != 0) {
    aux *= -1;
    k--;
   }
  }
  if(aux < minor) {
    minor = aux;
    pos_minor = i;
   };
  array.push_back(aux);
  sum += aux;
 }
 
 if(k > 0) {
  if((k % 2 != 0))
   sum -= 2*array[pos_minor];
 }

 cout << sum << '\n';
 return 0; 
}