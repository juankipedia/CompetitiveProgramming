# include <stdio.h>

int are_anagram(char str1[], char str2[]) { 
    int count[26] = { 0 }, i = 0, j = 0;;
    while(1){
        if(str1[i] != '\0' && str1[i] != ' ') count[str1[i] - 'a']++;
        if(str2[j] != '\0' && str2[j] != ' ') count[str2[j] - 'a']--; 
        if(str1[i] == '\0' && str2[j] == '\0') break;
        if(str1[i] != '\0') i++;
        if(str2[j] != '\0') j++;
    }
    for (i = 0; i < 26; i++)  if (count[i] != 0) return 0; 
    return 1; 
} 


int main() {
    int t;
    scanf("%d\n", &t);
    char str1[101], str2[101];
    while(t--){
        scanf ("%[^\n]%*c", str1);
        scanf ("%[^\n]%*c", str2);
        if(are_anagram(str1, str2)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}