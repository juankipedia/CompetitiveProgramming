# include <iostream>
# include <string>
using namespace std;

int main(){
  string s;
  char aux;
  int array[26] = {0};
  
  while((aux=getchar()) != '\n'){
   array[static_cast<int>(aux) - 97 ] = 1;
   
  }
  
  int counter = 0;
  for(int e : array) {
   if(e == 1) counter++;
  }
  
  if(counter % 2 == 0) cout << "CHAT WITH HER!";
  else cout << "IGNORE HIM!";

  return 0;
 }