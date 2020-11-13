#include <cstdio>
#include <cstring>


void next(char s[101], int length){
	
	for(int turn = length - 1; turn >= 0; turn--)
		for(int i = length - 1; i > turn; i--)
			if(s[i] > s[turn]){
				char temp = s[i];
				s[i] = s[turn];
				s[turn] = temp;
				for(int j = 0; j  <= turn; j++)
					printf("%c", s[j]);
				for(int j = length - 1; j > turn; j--)
					printf("%c", s[j]);
				printf("\n");
				return;
			}
	printf(s);
	printf("\n");
}

int main(void){
	
	int t;
	scanf("%d", &t);
	char word[101];
	for(int i = 0; i < t; i++){
		scanf("%s", word);
		int len = strlen(word);
		next(word, len);
	}
	return 0;
}
