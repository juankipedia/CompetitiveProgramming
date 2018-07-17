# include <bits/stdc++.h>
int main(){
	char s[9];
	double a, b;
	scanf("%s", s);
	if(s[0] == 't'){
		scanf("%lf %lf", &a, &b);
		printf("%.2lf\n",a * b / 2.0);
	}
	else if(s[0] == 'c'){
		scanf("%lf", &a);
		printf("%.2lf\n",a * a * 3.14);
	}
	else{
		scanf("%lf %lf", &a, &b);
		printf("%.2lf\n",a * b / 2.0);
	}
	return 0;
}