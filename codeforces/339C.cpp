# include <bits/stdc++.h>

using namespace std;

int main(){
	char c;
	vector<unsigned int> w;
	unsigned int m;
	for (unsigned int i = 0; i < 10; ++i){
		scanf("%c",&c);
		if(c == '1')
			w.push_back(i + 1);
	}
	scanf("%u", &m);
	
	if(w.size() == 0){
		printf("%s\n", "NO");
		return 0;
	}

	if(w[0] == 2 and w[1] == 3 and (w[2] == 6 or w[2] == 5) and (w[3] == 10 or w[3] == 8)){
		cout << "YES\n" << w[2] << " " << w[3] << " " << w[2] << " " << w[1] << " ";
		std::vector<unsigned int> w2;
		w2.push_back(w[2]);
		w2.push_back(w[3]);
		w2.push_back(w[2]);
		w2.push_back(w[0]);

		for (unsigned int i = 0; i < 996; ++i){
			cout << w2[i % w2.size()] << " ";
		}

		cout <<"\n";
		return 0;
	}

	bool found = true;
	for (unsigned int k = 0; k < w.size(); ++k){
		size_t r = 0, l = 0;
		vector<unsigned int> ret;
		bool left = false;
		unsigned int element = w[k];
		l = element;
		ret.push_back(element);

		for (unsigned int i = 1; i < m; ++i){
			size_t size = ret.size();
			for (unsigned int j = 0; j < w.size(); ++j){
				if(w[j] != element){	
					if (left){
						if(w[j] + l > r){
							ret.push_back(w[j]);
							element =  w[j];
							l+=element;
							break;
						}

						
					}
					else{
						if(w[j] + r > l){
							ret.push_back(w[j]);
							element =  w[j];
							r+=element;
							break;
						}
						
					}
				}

			}

			if (size == ret.size()){
				found = false;
				break;
			}
			if (ret.size() == m){
				found = true;
				break;
			}
			left = !left;
		}
		if (found){
			printf("%s\n", "YES");
			for (size_t i = 0; i < ret.size(); ++i)
				printf("%u ", ret[i]);

			printf("\n");
			return 0;
		}		
	}

	if (!found)
		printf("%s\n", "NO");
	return 0;
}