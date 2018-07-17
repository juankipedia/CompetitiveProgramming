# include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned int t;
	scanf("%u", &t);
	for (unsigned int i = 0; i < t; ++i){
		unsigned int r;
		scanf("%u", &r);
		cout << setprecision(2) << fixed << 3.0 * r * r * 1.73205080756887729352744634  / 2.0 << "\n";
	}
	return 0;
}