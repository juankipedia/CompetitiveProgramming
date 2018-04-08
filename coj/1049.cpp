# include <cstdio>

int main(){
	int n; 
	scanf("%d", &n);
	if(n >= 0)
		printf("%d\n", n * (n + 1) / 2);
	else
		printf("%d\n", (((n * - 1 ) * ((n * - 1 ) + 1) / 2) * -1) + 1);
	return 0;
}