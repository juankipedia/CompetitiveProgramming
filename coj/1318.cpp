# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n[3];
	char abc[3];
	scanf("%u", &n[0]);
	scanf("%u", &n[1]);
	scanf("%u\n", &n[2]);
	scanf("%s", abc);
	sort(n, n + 3);
	printf("%u %u %u\n", n[static_cast<int>(abc[0]) - 65], 
		n[static_cast<int>(abc[1]) - 65], n[static_cast<int>(abc[2]) - 65]);
	return 0;
}