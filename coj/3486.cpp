# include <bits/stdc++.h>
using namespace std;

bool contains(vector<tuple<int, int, int> > & v, int r, int c, int s){
	for (int i = 0; i < v.size(); ++i)
		if(get<0>(v[i]) == r or get<1>(v[i]) == c or get<2>(v[i]) == s)
			return true;
	v.push_back(make_tuple(r, c, s));
	return false;
}

int main(){
	unsigned int a, b, c;
	unordered_map<int, vector<tuple<int, int, int> > > m;
	char d;
	bool w = false;

	m[1] = vector<tuple<int, int, int> >(); m[2] = vector<tuple<int, int, int> >(); m[3] = vector<tuple<int, int, int> >();
	m[4] = vector<tuple<int, int, int> >(); m[5] = vector<tuple<int, int, int> >(); m[6] = vector<tuple<int, int, int> >();
	m[7] = vector<tuple<int, int, int> >(); m[8] = vector<tuple<int, int, int> >(); m[9] = vector<tuple<int, int, int> >();

	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 0, 0, 0) or contains(m[b], 0, 1, 0) or contains(m[c], 0, 2, 0)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 0, 3, 1) or contains(m[b], 0, 4, 1) or contains(m[c], 0, 5, 1)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 0, 6, 2) or contains(m[b], 0, 7, 2) or contains(m[c], 0, 8, 2)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 1, 0, 0) or contains(m[b], 1, 1, 0) or contains(m[c], 1, 2, 0)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 1, 3, 1) or contains(m[b], 1, 4, 1) or contains(m[c], 1, 5, 1)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 1, 6, 2) or contains(m[b], 1, 7, 2) or contains(m[c], 1, 8, 2)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 2, 0, 0) or contains(m[b], 2, 1, 0) or contains(m[c], 2, 2, 0)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 2, 3, 1) or contains(m[b], 2, 4, 1) or contains(m[c], 2, 5, 1)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 2, 6, 2) or contains(m[b], 2, 7, 2) or contains(m[c], 2, 8, 2)){
		w = true;	
	}
	getchar();

	scanf("------+-------+-----%c",&d);
	//_____________________________________________________________________________________________________________

	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 3, 0, 3) or contains(m[b], 3, 1, 3) or contains(m[c], 3, 2, 3)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 3, 3, 4) or contains(m[b], 3, 4, 4) or contains(m[c], 3, 5, 4)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 3, 6, 5) or contains(m[b], 3, 7, 5) or contains(m[c], 3, 8, 5)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 4, 0, 3) or contains(m[b], 4, 1, 3) or contains(m[c], 4, 2, 3)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 4, 3, 4) or contains(m[b], 4, 4, 4) or contains(m[c], 4, 5, 4)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 4, 6, 5) or contains(m[b], 4, 7, 5) or contains(m[c], 4, 8, 5)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 5, 0, 3) or contains(m[b], 5, 1, 3) or contains(m[c], 5, 2, 3)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 5, 3, 4) or contains(m[b], 5, 4, 4) or contains(m[c], 5, 5, 4)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 5, 6, 5) or contains(m[b], 5, 7, 5) or contains(m[c], 5, 8, 5)){
		w = true;	
	}
	getchar();

	scanf("------+-------+-----%c",&d);
	//_____________________________________________________________________________________________________________



	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 6, 0, 6) or contains(m[b], 6, 1, 6) or contains(m[c], 6, 2, 6)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 6, 3, 7) or contains(m[b], 6, 4, 7) or contains(m[c], 6, 5, 7)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 6, 6, 8) or contains(m[b], 6, 7, 8) or contains(m[c], 6, 8, 8)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 7, 0, 6) or contains(m[b], 7, 1, 6) or contains(m[c], 7, 2, 6)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 7, 3, 7) or contains(m[b], 7, 4, 7) or contains(m[c], 7, 5, 7)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 7, 6, 8) or contains(m[b], 7, 7, 8) or contains(m[c], 7, 8, 8)){
		w = true;	
	}
	getchar();


	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 8, 0, 6) or contains(m[b], 8, 1, 6) or contains(m[c], 8, 2, 6)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 8, 3, 7) or contains(m[b], 8, 4, 7) or contains(m[c], 8, 5, 7)){
		w = true;	
	}
	scanf(" %c ", &d);
	
	scanf("%u %u %u", &a, &b, &c);
	if(contains(m[a], 8, 6, 8) or contains(m[b], 8, 7, 8) or contains(m[c], 8, 8, 8)){
		w = true;	
	}
	getchar();
	//_____________________________________________________________________________________________________________


	if(!w)
		printf("%s\n", "CORRECT");
	else
		printf("%s\n", "WRONG");
	return 0;
}