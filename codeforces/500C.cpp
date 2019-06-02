#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
typedef std::numeric_limits< double > dbl;


int mod;


double eps = .0000000001;

int main (){
  int n, m;
  cin >> n >> m;
  int weights[500];
  for (int i=0; i<n; i++){
    cin >> weights[i];
  }

  int lastocc[500];
  for (int i=0; i<500; i++){
    lastocc[i] = -1;
  }
  long long sum = 0;
  int arr[1000];
  for (int i=0; i<m; i++){
    cin >> arr[i];
  }
  for (int i=0; i<m; i++){
    if (i == 0){
      lastocc[arr[i]-1] = i;
      continue;
    }
    if (lastocc[arr[i]-1] == -1){
      set<int> neww;
      for (int j=0; j<i; j++){
        if (!neww.count(arr[j])){
         
          sum += weights[arr[j]-1];
          neww.insert(arr[j]);
        }
      }

    }else{
      set<int> neww;
      for (int j=lastocc[arr[i]-1]+1; j<i; j++){
        if (!neww.count(arr[j])){
          sum += weights[arr[j]-1];
          neww.insert(arr[j]);
        }
      }
    }
    //cout << sum << " " << i << endl;
    lastocc[arr[i]-1] = i;
  }
  cout << sum;
  return 0;
}