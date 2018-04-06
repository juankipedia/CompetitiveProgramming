# include <bits/stdc++.h>

using namespace std;

vector<vector<short> > sol;

bool can_draw(vector<short> p, short pos){
	if (p.size() == 0)
		return true;
	
	if (p.size() > 1)
		if(p[p.size() - 2] == pos)
			return false;

	short last = p[p.size() - 1];

	for (int i = 1; i < p.size() - 1; ++i)
	{
		if(p[i] == pos)
			if (p[i + 1] == last or p[i - 1] == last)
				return false;

		if(p[i] == last)
			if (p[i + 1] == pos or p[i - 1] == pos)
				return false;
	}

	return true;
}

void back_tracking(vector<short> h[], vector<short> p, short pos){

	if(not can_draw(p,pos))
		return;

	p.push_back(pos);

	if(p.size() == 9)
		sol.push_back(p);

	for (int i = 0; i < h[pos].size(); ++i)
	{
		back_tracking(h, p, h[pos][i]);
	}

}


int main(){

	vector<short> h[6] = {{}, {2,3,5}, {1,3,5}, {1,2,4,5}, {3,5}, {1,2,3,4}};

	back_tracking(h, {}, 1);

	for (auto elem : sol){
		for (auto num : elem)
			cout << num;
		cout << "\n";
	}
	return 0;
}