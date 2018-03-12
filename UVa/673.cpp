# include <bits/stdc++.h>

using namespace std;

int main(){

	char buffer[128];
	char a_c;
	size_t n;
	cin >> n;
	getchar();
	for (size_t i = 0; i < n; ++i){
		stack<char> s;
		bool p = false;
		do{
			scanf("%c", &a_c);
			if(p)
				continue;
			if (a_c == ')'){
				if(s.empty()){
					printf("%s\n", "No");
					p = true;
				}
				else if (s.top() != '('){
					printf("%s\n", "No");
					p = true;
				}
				else
					s.pop();
			}
			else if(a_c == ']'){
				if(s.empty()){
					printf("%s\n", "No");
					p = true;
				}
				else if (s.top() != '['){
					printf("%s\n", "No");
					p = true;
				}
				else
					s.pop();
			}
			else if(a_c != '\n')
				s.push(a_c);
		}while(a_c != '\n');

		if (s.empty() and not p)
			printf("%s\n", "Yes");
		else if(not p)
			printf("%s\n", "No");
	}
	return 0;
}