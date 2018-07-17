# include <iostream>
# include <vector>
using namespace std;
int main() {
 long long houses, tasks, last, next;
 cin >> houses >> tasks;
 long long total = 0;
 cin >> last;
 total += last - 1; 
 
 for(int i = 0; i < tasks - 1; i++){
  cin >> next;
  
  if(next > last){
   total += next - last;
  }
  
  if(next < last){
   total += houses - last + 1;
   total += next - 1;
  }
  last = next;
 }
 
 cout << total << '\n';
 return 0;
}