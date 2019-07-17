#include <bits/stdc++.h>
using namespace std;

using namespace std;

#define MAXLEN 100 

int m[MAXLEN+1][MAXLEN+1]; // DP sub-problem
char p[MAXLEN+1][MAXLEN+1]; // decision matrix

// s[1...], t[1...] 
int string_compare(char *s, char *t){ 
	int i, j, k; 
	int opt[3]; // cost of the tree option
	int s_len, t_len; 
	s_len = strlen(s); 
	t_len = strlen(t); // length boundary
	m[0][0] = 0; 
	p[0][0] = -1; 
	for(i=1; i<MAXLEN; ++i){ 
		m[0][i] = i; // source is empty, insert i times
		p[0][i] = 1; // mark insert operation
		m[i][0] = i; // target is empty, delete i times
		p[i][0] = 2; // mark delete operation
	}

	for(i=1; i<s_len; i++) {
		for(j=1; j<t_len; j++){ 
			opt[0] = m[i-1][j-1] + (s[i]==t[j] ? 0: 1); // match or substitute 
			opt[1] = m[i][j-1] + 1; // insert 
			opt[2] = m[i-1][j] + 1; // delete

			//m[i][j] = min(opt[0..2]) 
			m[i][j] = opt[0]; 
			p[i][j] = 0; 
			for(k=0; k<3; ++k){
				if(opt[k]<m[i][j]){ 
					m[i][j] = opt[k];
					p[i][j] = k; 
				} 
			}
		} 
	}
	return m[s_len-1][t_len-1]; 
}

// build the sequence of operations
void traceback(char *s, char *t){ 
	char st[MAXLEN + MAXLEN +2]; // sequence 
	int len; // length of the sequence
	int i, j, k; 
	
	i = strlen(s) - 1; 
	j = strlen(t) - 1; 
	k = 0; 
	

	while(true){ 
		if(p[i][j] == -1) 
			break; 
		else if(p[i][j] == 0){
			if(s[i] == t[j]) 
				st[k] = 'M'; 
			else 
				st[k] = 'S'; --i, --j; 
		} 
		else if(p[i][j] == 1){ 
			st[k] = 'I'; --j; 
		} 
		else if(p[i][j] == 2){ 
			st[k] = 'D'; --i; 
		} k++; 
	} 
	
	len = k; 
	i = j = 0; 
	int u, v; 
	u = 1; //the u-th operation
	v = 1; //the v-th operating position
	
	for(k=len-1; k>=0; --k){ 
		if(st[k] == 'M'){ 
			++i;
			++j; 
			++v; 
		} 
		else if(st[k] == 'S'){
			++i; 
			++j; 
			printf("%d Replace %d,%c\n", u, v, t[j]); 
			++v; 
			++u; 
		} 
		else if(st[k] == 'I'){
			++j; 
			printf("%d Insert %d,%c\n", u, v, t[j]); 
			++v; 
			++u; 
		} 
		else if(st[k] == 'D'){
			++i; 
			printf("%d Delete %d\n", u, v); 
			++u; 
		} 
	}

}

int main(){ 
// freopen("in", "r", stdin);
	int ld; 
	char s[MAXLEN+1], t[MAXLEN+1]; 
	s[0] = t[0] = ' '; 
	bool first = true; //output blank line control
	while(gets(&s[1])){
		gets(&t[1]); 
		if(!first) 
			printf("\n"); 
		else 
			first = false; 
		ld = string_compare(s, t);
		printf("%d\n", ld); 
		traceback(s, t); 
	} 
	return 0; 
}