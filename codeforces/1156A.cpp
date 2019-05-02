#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int vis[102] = {0};
	for(int i = 0; i < n; i++) {
		cin >> vis[i];
	}
	int sum = 0;
	for(int i = 1; i < n; i++) {
		if((vis[i-1] == 2 && vis[i] == 3) || (vis[i-1] == 3 && vis[i] == 2)) {
			cout << "Infinite" << endl;
			return 0;
		} else if (vis[i-1] == 2 || vis[i] == 2) {
			sum += 3;
		} else if(vis[i-1] == 3 || vis[i] == 3) {
			sum += 4;
		}
	}
	for(int i = 2; i < n; i++) {
		if(vis[i-2] == 3 && vis[i-1] == 1 && vis[i] == 2) 
			sum--;
	}
	cout << "Finite" << endl;
	cout << sum << endl;
	return 0;
}