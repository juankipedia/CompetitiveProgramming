# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int m;
	size_t s;
	scanf("%u", &m);
	while(m --){
		scanf("%lu", &s);
		printf("%lu\n",2 * (s - 1) * (s) + 1);
	}
	return 0;
}