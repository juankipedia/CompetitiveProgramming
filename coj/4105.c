# include <stdio.h>

int main(){
  long unsigned int n, s, x;
  scanf("%lu", &n);
  s =  n * (n + 1)/2;
  n--;
  while(n--){scanf("%lu", &x); s -= x;}
  printf("%lu\n", s); 
  return 0;
}