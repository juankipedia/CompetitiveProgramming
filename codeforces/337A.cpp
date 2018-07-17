# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
 int n, m, aux;
 cin >> n >> m;
 vector<int> array;
 
 for(int i = 0; i < m; i++){
  cin >> aux;
  array.push_back(aux);
 }

 sort(array.begin(), array.end());
 
 int a, b, menor = 10001;
 
 for(int i = 0; i  + n - 1 < array.size(); i++){
  a= array[i];
  b = array[i + n - 1];
  
  if(b - a < menor){
   menor = b-a;
  }
 }
  
 cout << menor << '\n';

 return 0;
}