#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main(){
	char s[800001];
	fgets(s, 800000, stdin);
	int n = strlen(s);
	list<char> editor(s, s + n - 1);
	list<char>::iterator cursor = editor.end();
	int m;
	scanf("%d", &m);
	char command[11];
	fgets(command, 10, stdin);
	for(int i = 0; i < m; ++i){
		fgets(command, 10, stdin);
		if(command[0] == 'L' && cursor != editor.begin()){
			--cursor;
		}else if(command[0] == 'D' && cursor != editor.end()){
			++cursor;
		}else if(command[0] == 'B' && cursor != editor.begin()){
			--cursor;
			cursor = editor.erase(cursor);
		}else if(command[0] == 'P'){
			cursor = editor.insert(cursor, command[2]);
			++cursor;
		}
	}
	for(char x : editor){
		printf("%c", x);
	}
	return 0;
}
