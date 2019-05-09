#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);



unordered_map<int, int> m_m;
bool check(){
	if(m_m.size() == 1)
		return true;
	auto i = m_m.begin();
	while(i->second == 0)
		i++;

	int f = i->second;
	for (const auto & e: m_m)
		if(e.second != f and e.second != 0)
			return false;

	return true;
}

void find(int &min, int &max, int &min_i, int &max_i){
	max = 0; min = numeric_limits<int>::max(); min_i; max_i;
	int i = 0;
	for (const auto & e: m_m){
		if(e.second > max){
			max = e.second;
			max_i = e.first;
		}
		if(e.second < min and e.second != 0){
			min = e.second;
			min_i = e.first;
		}
		i ++;
	}
}

int main() {
	int n;
	cin >> n;
	int u[n];
	int max, min, min_i, max_i;
	for (int i = 0; i < n; ++i){
		cin >> u[i];
		++m_m[u[i]];
	}

	find(min, max, min_i, max_i);
	m_m[min_i]--;
	if(check()){
		cout << n << endl;
		return 0;
	}
	m_m[min_i] ++;
	m_m[max_i]--;
	if(check()){
		cout << n << endl;
		return 0;
	}

	m_m[max_i]++;

	for(int x = n - 1; x >= 0; x--){
		m_m[u[x]]--;

		find(min, max, min_i, max_i);

		m_m[min_i]--;
		if(check()){
			cout << x << endl;
			return 0;
		}
		m_m[min_i] ++;
		m_m[max_i]--;
		if(check()){
			cout << x << endl;
			return 0;
		}

		m_m[max_i]++;

	}
    return 0;
}