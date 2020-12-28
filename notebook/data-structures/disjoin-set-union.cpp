#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100000;
int N, parent[MAXN];

void build(){
    for(int i = 0; i < N; i++) parent[i] = i;
}

int find(int a){
    if(parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

void join(int a, int b){
    parent[find(a)] = find(b); 
}