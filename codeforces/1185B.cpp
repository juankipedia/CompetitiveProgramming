#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


int t;
string s1, s2;
int main() {
	cin >> t;
	while(t --){
		cin >> s1;
		cin >> s2;
		vector<pair<char, int>> v1;
		vector<pair<char, int>> v2;
		v1.push_back(make_pair(s1[0], 1));
		for (int i = 1; i < s1.length(); ++i){
			if(s1[i] == v1[v1.size() - 1].first) v1[v1.size() - 1].second++;
			else
			v1.push_back(make_pair(s1[i], 1));	
		}

		v2.push_back(make_pair(s2[0], 1));
		for(int i = 1; i < s2.length(); ++i){
			if(s2[i] == v2[v2.size() - 1].first) v2[v2.size() - 1].second++;
			else v2.push_back(make_pair(s2[i], 1));	
		}

		if(v1.size() != v2.size()){
			cout << "NO" << endl;
		}
		else{
			bool f = true;
			for (int i = 0; i < v1.size(); ++i){
				if(v1[i].first != v2[i].first or v1[i].second > v2[i].second){
					cout << "NO" << endl;
					f = false;
					break;
				}
			}
			if(f) cout << "YES" << endl;	
		}
	}
    return 0;
}