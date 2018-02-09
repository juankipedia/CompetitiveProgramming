# include <iostream>
# include <vector>
# include <utility>
# include <cmath>
# include <iterator>
# include <algorithm>
using namespace std;

bool compare(const pair<unsigned int, double> &A, const pair<unsigned int, double> &B)
{
	return(A.second < B.second);
}

int main(){
	

	unsigned int F,M, N;
	cin >> F >> M >> N;
	pair<unsigned int, unsigned int> p[N];

	for (unsigned int i = 0; i < N; ++i)
	{
		unsigned int aux, aux2;
		cin >> aux >> aux2;
		p[i] = make_pair(aux, aux2);
	}

	vector<pair<unsigned int, double> > r;
	for (int i = 0; i < pow(2,N); ++i)
	{
		unsigned int f = 0, m = 0;
		for (unsigned int j = 0; j < N; ++j)
		{
			if((i & (1 << j))){
				f += p[N - j - 1].first;
				m += p[N - j - 1].second;
			}

		}

		r.push_back(make_pair(i, static_cast<double>(F + f)/(M + m)));
	}

	unsigned int d = distance(r.begin(), max_element(r.begin(), r.end(), compare));

	if (!d){
		cout << "NONE";
		return 0;
	}
	else{
		std::vector<unsigned int> v_aux;
		unsigned int bits = r[d].first;
		for (unsigned int j = 0; j < N; ++j)
		{
			if((bits & (1 << j))){
				v_aux.push_back(N - j);
			}

		}
		sort(v_aux.begin(), v_aux.end());
		for (const unsigned int &j : v_aux)
		{
			cout << j << "\n";
		}

	}


	//for(auto elem : r) cout << elem.first << " : " <<  elem.second << "\n";

	return 0;
}