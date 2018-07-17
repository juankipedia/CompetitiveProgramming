# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(){

 size_t  d1, d2, d3;
 cin >> d1 >> d3 >> d2;
 vector<size_t> cases;
 
 cases.push_back(d1 + d2 + d3);
 cases.push_back(d1 + (2*d2) + d1);
 cases.push_back(d2 + d3 + d3 + d2);
 cases.push_back(d1 + d1 + d3 + d3);
 
 sort(cases.begin(), cases.end());
 cout << cases[0] << '\n';
 
 return 0;
}