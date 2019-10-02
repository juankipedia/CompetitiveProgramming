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

int n, k, ki;
unsigned long long int idi;
list<ulli> s;
set<ulli> memo;



int main() {
	io_boost;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> idi;
		if(memo.find(idi) == memo.end()){
			memo.insert(idi);
			if(ki == k){
				memo.erase(s.back());
				s.pop_back();
				s.push_front(idi);
			}
			else{
				ki++;
				s.push_front(idi);
			}
		}
	}
	cout << ki << endl;
	for(const ulli &e: s) cout << e << " ";
	cout << endl;
    return 0;
}