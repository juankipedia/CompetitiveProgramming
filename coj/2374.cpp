# include <bits/stdc++.h>

using namespace std;

int main(){
	char a[1000001], b[1000001], a1[1000001], b1[1000001];

	cin >> a >> b;

		
	for (unsigned int i = 0; i < strlen(a); ++i)
		if(a[i] == '6')
			a1[i] = '5';
		else
			a1[i] = a[i];

	for (unsigned int i = 0; i < strlen(b); ++i)
		if(b[i] == '6')
			b1[i] = '5';
		else
			b1[i] = b[i];

	cout << atoi(a1) + atoi(b1) << " ";

	for (unsigned int i = 0; i < strlen(a); ++i)
		if(a[i] == '5')
			a1[i] = '6';
		else
			a1[i] = a[i];

	for (unsigned int i = 0; i < strlen(b); ++i)
		if(b[i] == '5')
			b1[i] = '6';
		else
			b1[i] = b[i];

	cout << atoi(a1) + atoi(b1) << " ";

	return 0;
}