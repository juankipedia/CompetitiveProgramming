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
   
    unsigned int t;
    scanf("%u", &t);
    for (unsigned int ct = 0; ct < t; ++ct){
        string s;
        unsigned int c, a, b, u = 0, us = 0;
        char q;
        scanf("\n%u\n",&c);
        initSet(c);

        while(true){
            
            if(!getline(cin,s) || s.empty()){
                break;
            }
            
            sscanf(s.c_str(),"%c %u %u",&q,&a,&b);
            
            if(q == 'c'){
                if(not isSameSet(a - 1, b - 1)){
                    unionSet(a - 1, b - 1);
                }
            }
            else if(q == 'q'){
                if(isSameSet(a - 1, b - 1)){
                    u++;
                }
                else{
                    us++;
                }
            }
        }

        if(ct!=0) printf("\n");
        printf("%d,%d\n",u,us);
    }
	return 0;
}