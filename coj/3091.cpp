# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void combinations(vector<size_t> &a, vector<size_t> &x, size_t n, size_t c, size_t power)
{
    for (size_t i = 1; i < (1 << n); i++)
    {
        size_t s = 0;
        for (size_t j = 0; j < n; j++)
            if (i & (1 << j))
                s += a[j + c];
       	if (s <= power)
        	x.push_back(s);
    }
}

int main()
{
	size_t h_power;
	unsigned int w_number;

	cin >> w_number >>h_power;

	vector<size_t> w_powers, comb_a, comb_b;
	size_t sub_sum = 0;
	for (unsigned int j = 0; j < w_number; ++j){
		size_t aux;
		cin >> aux;
		if (aux <= h_power){	
			w_powers.push_back(aux);
		}
	}
	size_t n = w_powers.size();
	combinations(w_powers, comb_a, n/2, 0, h_power);
    combinations(w_powers, comb_b, n - n/2, n/2, h_power);

    sort(comb_a.begin(), comb_a.end());
    sort(comb_b.begin(), comb_b.end());

    size_t count = comb_a.size() + comb_b.size();
    size_t round = 0;

    for (int i = 0; i < comb_a.size(); i++) {
        if( i - 1 >= 0 and comb_a[i] == comb_a[i - 1] ){
            count += round;
            continue;
        }
        round = 0;
        for (int j = 0; j < comb_b.size(); j++) {
            if (comb_a[i] + comb_b[j] <= h_power) {
                count++;
                round++;
            }
            else
                break;
        }
    }

    cout << count << endl;

	return 0;
}