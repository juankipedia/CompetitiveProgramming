# include <iostream>
using namespace std;

unsigned int get_i(unsigned int n, unsigned int p, bool even){
	unsigned int count = 0;
	for (unsigned int i = 1; i <= n; ++i){
		if(even and i % 2 != 0)
			count ++;
		else if(!even and i % 2 == 0)
			count ++;

		if(count == p)
			return i;

	}
}

int main(){
	unsigned int t, n, p;
	string s;
	cin >> t;
	while(t--){
		cin >> n >> s >> p;
		cout << get_i(n, p, s == "even") << endl;
	}
	return 0;
}