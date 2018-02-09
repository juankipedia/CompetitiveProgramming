# include <iostream>
# include <vector>
using namespace std;

size_t binary_search(const size_t *a, const size_t &O, int l, int r)
{
	int m=(l+r)/2;
	if (l>r)
		return(m + 1);
		
	if (O < a[m])
		return binary_search(a,O,l,m-1);
	else if(a[m] < O)
		return binary_search(a,O,m+1,r);

	return(m);
}

int main(){
	size_t n;
	cin >> n;
	size_t a[n];
	cin >> a[0];
	for (size_t i = 1; i < n; ++i){
		cin >> a[i];
		a[i] = a[i] + a[i - 1];
	}

	size_t q;
	cin >> q;
	vector<size_t> r;

	for (size_t i = 0; i < q; ++i)
	{
		size_t query;
		cin >> query;
		if(query > a[n - 1]){
			r.push_back(0);
			continue;
		}

		if(query < a[0]){
			r.push_back(1);
			continue;
		}		

		r.push_back(binary_search(a, query, 0, n - 1) + 1);

	}

	for (const size_t &e : r){
		if(e)
			cout << e << "\n";
		else
			cout << "none\n";
	}

	return 0;
}