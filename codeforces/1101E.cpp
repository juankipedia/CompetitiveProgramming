#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

pair<ui, ui> pi;
set<pair<ui,ui> > ps;

void in(){
	for(const auto &p : ps)
		if((pi.first <= p.first and pi.second <= p.second) or (pi.first <= p.second and pi.second <= p.first))
			return;
	ps.insert(move(pi));
	return;
}

void in_w(){
	for(const auto &p : ps){
		if((pi.first >= p.first and pi.second >= p.second) or (pi.first >= p.second and pi.second >= p.first))
			continue;
		else{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	io_boost
	int n;
	cin >> n;
	char q;
	ui x, y, x_m = 0, y_m = 0;
	while(n--){
		cin >> q >> pi.first >> pi.second;
		if(q == '+') in();
		else in_w();
	}
    return 0;
}