# include <bits/stdc++.h>
using namespace std;

template <class T> class Graph : public unordered_map<T, pair<vector<T>, bool> >{
	public:
		Graph(){}
		~Graph(){} 
};

//############################################# dfs###############################################
template <class T, class Function> void __dft(const T &n, Graph<T> &g, const Function &f){
	if(g[n].second)
		return;
	g[n].second = true;
	f(n);
	for (const T &e : g[n].first) __dft(e, g, f);
}

template <class T, class Function> void dft(Graph<T> & g, const Function &f){
	for(const pair<T, pair<vector<T>, bool> > &n : g)
		if(n.second.second) continue;
		else __dft<T, Function>(n.first, g, f);
}

//############################################# bfs###############################################
template <class T, class Function> void bft(const T &n, Graph<T> &g, const Function &f){
	queue <T> q;
	g[n].second = true;
	q.push(n);
	while(q.size()){
		T p = q.front();
		q.pop();
		f(p);
		for(const T &n_p : g[p].first){
			if(g[n_p].second)
				continue;
			g[n_p].second = true;
			q.push(n_p);
		}
	}
}

//######################################Path Between 2 vertices ###################################

template <class T> bool __dft_path(const T &n, const T &e, Graph<T> &g, vector<T> &p){
	if(g[n].second)
		return false;
	p.push_back(n);
	if(n == e)
		return true;
	g[n].second = true;
	for (const T &b : g[n].first) if(__dft_path(b, e, g, p)) return true;
	p.pop_back();
	return false;
}

template <class T> vector<T> dft_path(const T &b, const T &e, Graph<T> & g){
	vector<T> p;
	p.push_back(b);
	g[b].second = true;
	for(const T &n : g[b].first)
		if(g[n].second) continue;
		else if(__dft_path(n, e, g, p)) return p;
	p.pop_back();
	return p;
}

//############################# Minimal Path Between 2 vertices ###################################

template <class T> bool __minimal_path(const T &n, const T &e, Graph<T> &g, const T &d_val, unordered_map<T, T> &parents){
	queue <T> q;
	g[n].second = true;
	q.push(n);

	for(const auto &v : g)
		parents[v.first] = d_val;
	
	while(q.size()){
		T p = q.front();
		q.pop();
		for(const T &n_p : g[p].first){
			if(g[n_p].second)
				continue;
			g[n_p].second = true;
			q.push(n_p);
			parents[n_p] = p;
			if (n_p == e) 
                return true; 
		}
	}
	return false;
}


template <class T> vector<T> minimal_path(const T &n, const T &e, Graph<T> &g, const T &d_val){
	vector<T> p;
	unordered_map<T, T> parents;
	if(__minimal_path(n, e, g, d_val, parents)){
		T cur = e;
		while(parents[cur] != d_val){
			p.insert(p.begin(), cur);
			cur = parents[cur];
		}
		p.insert(p.begin(), n);
	}
	return p;
}

//##################################### obtain all subgraphs ######################################

template <class T> void __copy(const T &n, Graph<T> &g, Graph<T> &s_g){
	if(g[n].second)
		return;
	g[n].second = true;
	s_g[n] = make_pair(vector<T>(), false);
	for (const T &e : g[n].first){ 
		__copy(e, g, s_g);
		s_g[n].first.push_back(e);
	};
}

template <class T> void split(Graph<T> & g, vector<Graph<T> > &l){
	
	for(const pair<T, pair<vector<T>, bool> > &n : g)
		if(n.second.second) continue;
		else {
			Graph<T> s_g;
			__copy<T>(n.first, g, s_g);
			l.push_back(move(s_g));
		}
}

//##################################### Ordered Graph Class #######################################
template <class T> class O_graph : public map<T, pair<vector<T>, bool> >{
	public:
		O_graph(){}
		~O_graph(){} 
};

//################################### Mark All elements as Unseen ##################################
template <class T> void mark_unseen(O_graph<T> &g){
	for(pair<const T, pair<vector<T>, bool> > &n : g)
		n.second.second = false;
}


//##################################### Get Topological Ordering ###################################
template <class T> void __dft_topological(const T &n, O_graph<T> &g, stack<T> &t_o){
	if(g[n].second) return;
	g[n].second = true;
	for (const T &e : g[n].first) __dft_topological(e, g, t_o);
	t_o.push(n);
}

template <class T> void topological_order(O_graph<T> & g, stack<T> &t_o){
	for(const pair<T, pair<vector<T>, bool> > &n : g)
		if(n.second.second) continue;
		else __dft_topological<T>(n.first, g, t_o);
}


int main(){

	O_graph<int> g;
	g[0] = make_pair(vector<int>({2, 3}), false);
	g[1] = make_pair(vector<int>({0}), false);
	g[2] = make_pair(vector<int>({1}), false);
	g[3] = make_pair(vector<int>({4}), false);
	g[4] = make_pair(vector<int>({}), false);

	mark_unseen(g);

	/*Graph<unsigned int> g;
	unsigned int k = 0;
	g[1] = make_pair(vector<unsigned int>({2, 3}), false);
	g[2] = make_pair(vector<unsigned int>({4, 1}), false);
	g[3] = make_pair(vector<unsigned int>({1, 4, 5}), false);
	g[4] = make_pair(vector<unsigned int>({1, 2, 3, 5}), false);
	g[5] = make_pair(vector<unsigned int>({3, 4, 6, 7}), false);
	g[6] = make_pair(vector<unsigned int>({5, 7}), false);
	g[7] = make_pair(vector<unsigned int>({6, 5}), false);
	g[8] = make_pair(vector<unsigned int>({9}), false);
	g[9] = make_pair(vector<unsigned int>({8}), false);
	g[10] = make_pair(vector<unsigned int>({}), false);
	g[11] = make_pair(vector<unsigned int>({12, 13}), false);
	g[12] = make_pair(vector<unsigned int>({11}), false);
	g[13] = make_pair(vector<unsigned int>({11}), false);*/
	/*O_graph<char> g;
	g['a'] = make_pair(vector<char>({'b', 'f'}), false);
	g['b'] = make_pair(vector<char>({'h'}), false);
	g['c'] = make_pair(vector<char>(), false);
	g['d'] = make_pair(vector<char>({'c', 'e', 'i', 'h'}), false);
	g['e'] = make_pair(vector<char>({'i'}), false);
	g['f'] = make_pair(vector<char>({}), false);
	g['g'] = make_pair(vector<char>({'a', 'b', 'c'}), false);
	g['h'] = make_pair(vector<char>({}), false);
	g['i'] = make_pair(vector<char>({'c'}), false);
	g['j'] = make_pair(vector<char>({'e'}), false);

	stack<char> s;
	topological_order(g, s);
	while (s.empty() == false) { 
        cout << s.top() << " "; 
        s.pop(); 
    }*/

	/*for (int i = 0; i < l.size(); ++i){
		cout << "GRAPH #" << i << endl;
		for(const auto &e: l[i]){
			cout << e.first << endl;
			for (auto elem : e.second.first){
				cout << elem << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/

	/*
	auto p = minimal_path(1u, 7u, g, 0u);
	for(const auto & elem : p)
		cout << elem << endl;


	bft((unsigned int)1,g, [](const unsigned int & a){cout << a << endl; return;});
	auto p = dft_path(5u, 1u, g);
	for(const auto & elem : p)
		cout << elem << endl;*/

	return 0;
}