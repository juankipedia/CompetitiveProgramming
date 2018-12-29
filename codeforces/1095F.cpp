#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void fastIO() {
	std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define FORE(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void mxze(T &x, U y) { if(x < y) x = y; }

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
	while(*sdbg != ',')cerr<<*sdbg++;
	cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(_i, (x)) cerr <<*_i <<", "; cerr <<"\n"; }}
#define debuga(x, sz) {{cerr <<#x <<" = "; FOR(_i, 0, sz) cerr << x[_i] <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

const int MAXN = 2e5+5;

struct edge{
	int from, to;
	ll w;
	bool operator<(const edge &o) const{
		return w < o.w || (w == o.w && make_pair(from,to) < make_pair(o.from, o.to));
	}
};

int n, m;
vector<edge> G[MAXN];
ll a[MAXN];
bool inT[MAXN];

multiset<ll> T;
multiset <pair<ll, int>> nT;
set<edge> E;

void insert(int v){
	auto it = nT.find({a[v], v});
	nT.erase(it);
	T.insert(a[v]);
	assert(!inT[v]);
	inT[v] = true;
	FOR(i,0,G[v].size()){
		E.insert(G[v][i]);
	}
}


int main(){
	scan(n,m);
	FOR(i,0,n) scan(a[i]);
	FOR(i,0,m){
		int a, b; ll w; scan(a,b,w); a--; b--;
		G[a].pb({a,b,w});
		G[b].pb({b,a,w});
	}
	FOR(i,0,n) nT.insert({a[i], i});
	insert(0);
	int cnt = 1;
	ll ans = 0;
	while(cnt < n){
		ll op1 = *(T.begin()) + nT.begin()->fst;
		while(!E.empty() && inT[E.begin()->to]) E.erase(E.begin());
		if(E.empty()){
			ans += op1;
			insert(nT.begin()->snd);
		}else{
			ll op2 = E.begin()->w;
			if(op2 < op1){
				ans += op2;
				insert(E.begin()->to);
			}else{
				ans += op1;
				insert(nT.begin()->snd);
			}
		}
		cnt++;
	}
	printf("%lld\n",ans);

}