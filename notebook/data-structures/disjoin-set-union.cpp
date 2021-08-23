struct DSU {
	int n, comp = n;
	vector<int> p, len;
	DSU(int n) : n(n){
		p.assign(n + 10, 0); 
        iota(p.begin(), p.end(), 0);
		len.assign(n + 10, 1);
	}
	int find(int n){ return p[n] = p[n] == n ? n : find(p[n]); }
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(len[a] < len[b]) swap(a, b);
		len[a] += len[b];
		p[b] = a;
		comp--;
	}
};