# include <bits/stdc++.h>
using namespace std;

void printSuperSeq(string &a, string &b) { 
    int m = a.length(), n = b.length(); 
    int dp[m+1][n+1]; 
  
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
           if (!i) 
               dp[i][j] = j; 
           else if (!j) 
               dp[i][j] = i; 
           else if (a[i-1] == b[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1]; 
           else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]); 
        } 
    }
 
   int index = dp[m][n]; 
   
   string res(index+1, '\0'); 
   
   int i = m, j = n; 
   while (i > 0 && j > 0) { 
      if (a[i-1] == b[j-1]) { 
          res[index-1] = a[i-1]; 
          i--; j--; index--; 
      } 
      else if (dp[i-1][j] < dp[i][j-1]) { 
      	res[index-1] = a[i-1];   i--;  index--; 
      } 
      else {
      	res[index-1] = b[j-1];  j--; index--; 
      } 
   } 
  
   while (i > 0) { 
       res[index-1] = a[i-1];   i--;  index--; 
   } 
  
   while (j > 0) { 
       res[index-1] = b[j-1];  j--; index--; 
   } 
  
   cout << res << endl; 
} 

int main(){
	string  w1, w2;
	while(cin >> w1 and cin >> w2){
		printSuperSeq(w1, w2);
	}
	return 0;
}