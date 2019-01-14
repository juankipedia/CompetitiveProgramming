# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t, n;
	cin >> t;
	while(t--){
		priority_queue <string> pq;
		string s, l;
		cin >> n;
		while(n--){ cin >> l; pq.push(l);}
		
		while(not pq.empty()){
			l = pq.top();
				pq.pop();
			s += l[0];
			if(l.length() > 1) pq.push(l.substr(1, l.length() - 1));
		}

		cout << s << endl;
	}
	return 0;
}