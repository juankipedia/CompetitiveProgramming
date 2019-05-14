#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	string r = "";
	int dr = 0;
	for (int i = 0; i < n - 1; ){
		if(s[i] != s[i + 1]){
			r += s[i];
			r += s[i + 1];
			i +=2;
			
		}
		else{
			dr += 1;
			n -= 1;
			s.erase(i, 1);
		}
	}

	if(n % 2 != 0) dr ++;
	cout << dr << endl;
	if(s == "")
		r = s;
	cout << r << endl;
    return 0;
}