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

int n, m;

int main() {
	cin >> n >> m;
	int a[m];
	int b[m];
	for (int i = 0; i < m; ++i){
		cin >> a[i] >> b[i];
	}

	int x = a[0], y = b[0];

	for (int i = 1; i < m; ++i){
		if(a[i] != x and b[i] != x){
			y = a[i];
			for (int j = i + 1; j < m; ++j){
				if(a[j] != y and b[j] != y and a[j] != x and b[j] != x){
					y = b[i];
					for (int k = i + 1; k < m; ++k){
						if(a[k] != y and b[k] != y and a[k] != x and b[k] != x){
							
							x = b[0];
							for (int l = 1; l < m; ++l){
								if(a[l] != x and b[l] != x){
									y = a[l];
									for (int t = l + 1; t < m; ++t){
										if(a[t] != y and b[t] != y and a[t] != x and b[t] != x){
											y = b[l];
											for (int h = l + 1; h < m; ++h){
												if(a[h] != y and b[h] != y and a[h] != x and b[h] != x){

													cout << "NO" << endl;
													return 0;
												}
											}
											cout << "YES" << endl;
											return 0;
										}
									}
									cout << "YES" << endl;
									return 0;
								}
							}


						}
					}
					cout << "YES" << endl;
					return 0;
				}
			}
			cout << "YES" << endl;
			return 0;
		}
	}

	for (int i = 1; i < m; ++i){
		if(a[i] != y and b[i] != y and a[i] != x and b[i] != x){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;

}