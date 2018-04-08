# include <bits/stdc++.h>
using namespace std;

int main(){
	char num_c[1002];
	unsigned int t;
	int n, num;
	scanf("%u",&t);
	getchar();
	for (unsigned int i = 0; i < t; ++i){
		scanf("%s", num_c);
	    n = strlen(num_c);
	    num = (static_cast<int>(num_c[n - 2] - 48) * 10) + 
	    static_cast<int>(num_c[n - 1]) - 48;
		if (num % 4)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}