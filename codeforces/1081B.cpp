#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
	ui n;
	cin >> n;
	ui a[n], b[n];
	map<ui, pair<ui, ui> > f;
	bool imp = false, hz = false, dz = false;
	ui j = 1;
	for (ui i = 0; i < n; ++i){
		cin >> a[i];
		if(n - a[i] == 1){
			b[i] = j;
			j++;
		}
		else{
			if(f.find(a[i]) != f.end()){
				f[a[i]].first--;
				b[i] = f[a[i]].second;
				if(f[a[i]].first == 0)
					f.erase(a[i]);
			}
			else{
				f[a[i]] = make_pair(n - a[i] - 1, j);
				b[i] = j;
				j++;
			}
		}

		if(a[i] == 0)
			hz = true;
		else if(hz)
			imp = true;
		else
			dz = true;
	}

	if(imp or (hz and dz)){
		cout << "Impossible" << endl;
	}
	else if(hz){
		cout << "Possible\n";
		for (ui i = 0; i < n; ++i)
			cout << 1 << " ";
		cout << endl;
	}
	else if(f.size() == 0){
		cout << "Possible\n";
		for (const auto &bi : b)
			cout << bi << " ";
		cout << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
    return 0;
}