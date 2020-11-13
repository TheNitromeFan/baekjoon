#include <cstdio>
#include <map>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	char line[1000];
	fgets(line, 999, stdin);
	for(int i = 0; i < t; ++i){
		char message[1000] = {}, conversion[1000] = {};
		fgets(message, 999, stdin);
		fgets(conversion, 999, stdin);
		map<char, char> code;
		for(int i = 0; i < 26; ++i){
			code['A' + i] = conversion[i];
		}
		for(int j = 0; message[j] != '\n'; ++j){
			if(message[j] >= 'A' && message[j] <= 'Z'){
				printf("%c", code[message[j]]);
			}else{
				printf("%c", message[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
