# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  char aux;
  vector <int> array;
  while((aux = getchar()) != '\n'){
    if(aux == '1') {
     array.push_back(1);
    }
    else if(aux == '2')
     array.push_back(2);
    else if (aux == '3')
     array.push_back(3);
  }
  sort(array.begin(), array.end());
  
  for(int i = 0; i < array.size() - 1; i++)
   cout << array[i] << '+';
  cout << array[array.size() - 1];
  return 0;
 }