# include <bits/stdc++.h>
using namespace std;


int main(){
	unsigned int b, n, sum = 0, s = 1;
	cin >> b >> n;
	unsigned int e[n];
	for (unsigned int i = 0; i < n; ++i){cin >> e[i]; sum += e[i];}
	if(sum < b){
		cout << 1 << endl;
		return 0;
	}
	sort(e, e + n, [](const unsigned int & A, const unsigned int &B){return A > B;});
	for (unsigned int i = 0; i < n; ++i){
		sum -= e[i];
		b += e[i];
		s++;
		if (sum < b){
			cout << s << endl;
			return 0;
		}
	}

	return 0;
}