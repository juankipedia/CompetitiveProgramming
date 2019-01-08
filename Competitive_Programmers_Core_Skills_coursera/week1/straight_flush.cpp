# include <bits/stdc++.h>
using namespace std;

int from_char_to_num(char &c){
	switch (c) {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
    }
    return c - '0';
}

int main(){
	int c[5];
	char p, f, a;
	bool d = false;
	scanf("%c", &a);
	scanf("%c", &f);
	c[0] = from_char_to_num(a);
	getchar();
	for (int i = 1; i < 5; ++i){
		scanf("%c", &a);
		c[i] = from_char_to_num(a);
		scanf("%c", &p);
		getchar();
		if(p != f)
			d = true;
	}

	if(not d){
		sort(c, c + 5);
		int n = 5;
		if(c[0] == 2 and c[n - 1] == 14)
			n = n - 1;
		for (int i = 0; i < n - 1; ++i){
			if(c[i] + 1 != c[i + 1]){
				cout << "NO\n";
				return 0;
			}
		}

		cout << "YES\n";
	}
	else cout << "NO\n";
	return 0;
} 