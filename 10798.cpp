#include <cstdio>


struct string{
	
	char s[15];
	int end;
};

int main(void){
	
	struct string strings[5];
	for(int i = 0; i < 5; i++){
		scanf("%s", &strings[i].s);
		strings[i].end = 1;
	}
	for(int j = 0; j < 15; j++)
		for(int i = 0; i < 5; i++){
			if(strings[i].end && strings[i].s[j] == '\0') strings[i].end = 0;
			else if(strings[i].end) printf("%c", strings[i].s[j]);
		}
	return 0;
}
