#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;


const int maxn = 2*1e5;
int n;
int a[maxn];
vector<int> l, r;
int main() {
	cin >> n;
	int maxval = 0, maxp = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] > maxval){
			maxval = a[i];
			maxp = i;
		}
	}

	for (int i = 0; i < n; ++i){
		if(i != maxp){
			if(i < maxp)
				l.push_back(a[i]);
			else
				r.push_back(a[i]);
		}
	}

	int lp = l.size() - 1, rp = 0;

	for (int i = 0; i < n - 1; ++i){
		if(lp >= 0 and rp < r.size()){
			int nextval = max(l[lp], r[rp]);
			if(maxval > nextval){
				maxval = nextval;
				if (nextval == l[lp]) lp--;
				else rp++;
			}
			else{
				cout << "no" << endl;
				return 0;
			}
		}
		else if(lp >= 0){
			int nextval = l[lp];
			if(maxval > nextval){
				maxval = nextval;
				lp--;
			}
			else{
				cout << "no" << endl;
				return 0;
			}
		}
		else{

			int nextval = r[rp];
			if(maxval > nextval){
				maxval = nextval;
				rp++;
			}
			else{
				cout << "no" << endl;
				return 0;
			}

		}
	}
	cout << "yes" << endl;
    return 0;
}