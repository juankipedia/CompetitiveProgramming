# include <bits/stdc++.h>
using namespace std;


vector<int> pset(1000);
void initSet(int _size){
 pset.resize(_size); 
 for (int i = 0; i <= _size - 1; i++)
 	pset[i] = i; 
}
int findSet(int i){ return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int main(){
	int t;
    char s[10];
    scanf("%d ", &t);
    while(t--) {
        gets(s);
        initSet(s[0]-'A' + 1);
        int ans = s[0]-'A'+1;
        while(gets(s)) {
            if(s[0] == '\0')
                break;
            if(not isSameSet(s[0]-'A', s[1]-'A')){
            	unionSet(s[0]-'A', s[1]-'A');
            	ans--;
            }
        }
        printf("%d\n", ans);
        if(t)
            puts("");
    }
	return 0;
}