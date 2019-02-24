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

int main() {
  io_boost;
  int n;
  cin >> n;
  int r = 0;
  vector<pair<int,int> > v;
  v.push_back(make_pair(0, 0));
  
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i < (int) v.size(); i++) {
    r += max(0, min(v[i].first, v[i].second) + 1 - (max(v[i - 1].first, v[i - 1].second)));
    if (i > 1 && v[i - 1].first == v[i - 1].second) r--;
  }
  if ((int) v.size() == 1) {
    cout << min(v[0].first, v[0].second) + 1 << '\n';
  } else {
    cout << r << '\n';
  }
  return 0;
}