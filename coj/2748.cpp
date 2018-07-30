# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	scanf("%u", &n);
	int r = 0 ,x,y;
	while(n --){
		scanf("%d %d", &x,&y);
		if (r < x * x + y * y)
			r = x * x + y * y;
	}
	printf("%d\n", r);
	return 0;
}