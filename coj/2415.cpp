# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t, n, r, h;
	double v;
	scanf("%u", &t);
	while(t --){
		v = 0;
		scanf("%u", &n);
		while(n --){
			scanf("%u %u", &r, &h);
			v += 3.14159265358979323846 * r * r * h;
		}
		printf("%.2lf\n", v);
	}
	return 0;
}