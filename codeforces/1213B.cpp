#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


const int MAXN = 150000;
int n, t;
int a[MAXN];

int main() {
	cin >> t;
	while(t--){
		cin >> n;
		priority_queue<int> pq;
		int r = 0;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
		
		for (int i = 0; i < n; ++i){
			if(pq.empty()) pq.push(a[i]);
			else{
				while(not pq.empty()){
					if(pq.top() <= a[i]){
						pq.push(a[i]);
						break;
					}
					else{
						pq.pop();
						r++;
					}
				}

				if(pq.empty()) pq.push(a[i]);
			}
		}

		cout << r << endl;
	}
    return 0;
}