#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int i = 0, j = n - 1, l = 0; 
	string r = "";
	while(i <= j){
		if(a[i] < a[j] and a[i] > l){
			l = a[i];
			r += 'L';
			i++;
		}
		else if(a[i] > a[j] and a[j] > l){
			l = a[j];
			r += 'R';
			j--;
		}
		else if(a[i] > l){
			l = a[i];
			r += 'L';
			i++;
		}
		else if(a[j] > l){
			l = a[j];
			r += 'R';
			j--;
		}
		else
			break;
	}	
	cout << r.length() << endl;
	cout << r << endl;
    return 0;
}