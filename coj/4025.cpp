# include <bits/stdc++.h>
using namespace std;

int main(){
	long long unsigned int n, t, count;
	scanf("%llu" ,&t);
	while(t--){
		char c;
		scanf("%llu" ,&n);
		count = n;
		getchar();
		map<map<char, unsigned int>, unsigned int >  l;
		while(n--){
			map<char, unsigned int> s;
			while(scanf("%c", &c) and c != '\n') {
				if(s.find(c) == s.end()) s[c] = 1;
				else s[c] ++;
			}

			if(l.find(move(s)) == l.end()){
				l[move(s)] = 1;
			}
			else{
				count += 2 * l[move(s)];
				l[move(s)] ++;
			}
		}
		printf("%llu\n", count);
	}
	return 0;
}