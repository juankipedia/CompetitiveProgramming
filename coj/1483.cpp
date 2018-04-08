# include <bits/stdc++.h>

int main(){
	char s[10];
	unsigned int a,b;
	scanf("%s ", s);
	if(strlen(s) < 9){
		scanf("%u", &a);
		printf("%u\n", a * a);
	}
	else{
		scanf("%u %u", &a, &b);
		printf("%u\n", a * b);
	}
	return 0;
}