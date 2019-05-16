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

int a1 = 4, a2 = 8, a3 = 15, a4 = 16, a5 = 23, a6 = 42;
unordered_map<int, pair<int, int> >m;


pair<int, int> p[4];
unordered_map<int, bool> include;

int q(const int &i, const int &j){
	int r;
	cout << "? " << i << " " << j <<endl;
	fflush(stdout);
	cin >> r;
	return r;
}


int main() {

	m[32] = make_pair(a1, a2); m[60] = make_pair(a1, a3); m[64] = make_pair(a1, a4); m[92] = make_pair(a1, a5); m[168] = make_pair(a1, a6); 
m[120] = make_pair(a2, a3); m[128] = make_pair(a2, a4); m[184] = make_pair(a2, a5); m[336] = make_pair(a2, a6); m[240] = make_pair(a3, a4); 
m[345] = make_pair(a3, a5); m[630] = make_pair(a3, a6); m[368] = make_pair(a4, a5); m[672] = make_pair(a4, a6); m[966] = make_pair(a5, a6); 

include[a1] = false; include[a2] = false; include[a3] = false; include[a4] = false; include[a5] = false;
include[a6] = false;


	
	p[0] = m[q(1, 2)]; include[p[0].first] = true; include[p[0].second] = true;
	p[1] = m[q(3, 4)]; include[p[1].first] = true; include[p[1].second] = true;
	auto w = m[q(5, 1)];
	if(not include[w.first])
		p[2].first = w.first;
	else
		p[2].first = w.second;
	include[p[2].first] = true;
	if(p[2].first == w.first){
		if(p[0].first != w.second) swap(p[0].first, p[0].second);
	}
	else if(p[0].first != w.first) swap(p[0].first, p[0].second);
	w = m[q(5, 3)];

	if(p[2].first == w.first){
		if(p[1].first != w.second) swap(p[1].first, p[1].second);
	}
	else if(p[1].first != w.first) swap(p[1].first, p[1].second);
	
	for(const auto &e: include) if(e.second == false) p[3].first = e.first;

	cout << "! ";
	for (int i = 0; i < 4; ++i){
		cout << p[i].first << " ";
		if(p[i].second != 0)
			cout << p[i].second << " ";
	}
	cout << endl;
    return 0;
}