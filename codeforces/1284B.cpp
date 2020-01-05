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

const int INF = std::numeric_limits<int>::max();
lli n;
int mini[100000], li, sj;
bool a[100000];
vector<int> maxi;

int main() {
	io_boost;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> li;
		int minii = INF, maxii = -1, p = INF;
		bool f = false;
		for (int j = 0; j < li; ++j){
			cin >> sj;
			if(p < sj) f = true; 
			minii = min(sj, minii);
			maxii = max(sj, maxii);
			p = sj;
		}

		if(!f){
			a[i] = true;
			maxi.push_back(maxii);
		}
		mini[i] = minii;

	}
	lli sum = 0, d;
	sort(maxi.begin(),maxi.end());
	for (int i = 0; i < n; ++i){
		if(a[i]){
			sum += upper_bound(maxi.begin(),maxi.end(), mini[i]) - maxi.begin(); 
		}
	}

	cout << n * n - sum << endl;
    return 0;
}