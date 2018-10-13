# include <bits/stdc++.h>

using namespace std;

unsigned int n_activities(pair<unsigned int, unsigned int> *a, unsigned int & n){
	sort(a, a + n, [](const pair<unsigned int, unsigned int> &A, const pair<unsigned int, unsigned int> &B){ return (A.second == B.second)?(A.first < B.first):(A.second < B.second); });
	
	unsigned int count = 1;
	pair<unsigned int, unsigned int> actual = a[0];

	for (unsigned int i = 1; i < n; ++i){
		if(a[i].first >= actual.second){
			count ++;
			actual = a[i];
		}
	}
	return count;
}

int main(){
	unsigned int t, a, s, e;
	cin >> t;

	while(t--){
		cin >> a;
		pair<unsigned int, unsigned int> activities[a];
		for (unsigned int i = 0; i < a; ++i){
			cin >> s >> e;
			activities[i] = make_pair(s, e);
		}
		cout << n_activities(activities, a) << endl;
	}
	return 0;
}