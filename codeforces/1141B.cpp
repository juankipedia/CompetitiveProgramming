#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main() {
	size_t n;
	cin >> n;
	bool a[n];
	size_t r = 0;
	for (size_t i = 0; i < n; ++i)
		cin >> a[i];
	if(a[n - 1] == 1){
		size_t c = 0;
		size_t i = 0;
		for (; i < n; ++i){
			if(a[i])
				c++;
			else if(c >= r){
				r = c;
				c = 0;
			}
			else
				c = 0;
		}
		i = 0;
		while(a[i]){
			c++;
			i++;
		}
		
		if(c > r)
			cout << c << endl;
		else
			cout << r << endl;
	}
	else{
		size_t c = 0;
		for (size_t i = 0; i < n; ++i){
			if(a[i])
				c++;
			else if(c >= r){
				r = c;
				c = 0;
			}
			else
				c = 0;
		}
		cout << r << endl;
	}
    return 0;
}