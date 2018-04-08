# include <cstdio>
# include <algorithm>
using namespace std;

int main(){
	unsigned int t[3], aux;
	scanf("%u", &t[0]);
	scanf("%u", &t[1]);
	scanf("%u", &t[2]);

	sort(t, t + 3);
	
	if ((t[0] * t[0]) + (t[1] * t[1]) != (t[2] * t[2])){
		printf("NO\n");
		scanf("%u", &aux);
		scanf("%u", &aux);
		scanf("%u", &aux);
		return 0;
	}
	else{
		scanf("%u", &aux);
		if (aux != t[0] and aux != t[1] and aux != t[2]){
			printf("NO\n");
			return 0;
		}

		scanf("%u", &aux);
		if (aux != t[0] and aux != t[1] and aux != t[2]){
			printf("NO\n");
			return 0;
		}

		scanf("%u", &aux);
		if (aux != t[0] and aux != t[1] and aux != t[2]){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");
		return 0;
	}
}