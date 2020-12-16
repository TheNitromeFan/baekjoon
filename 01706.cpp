#include <cstdio>
#include <string>
#define MAX 21

using std::string;

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char board[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", board[i]);
	}
	string ans(21, 'z');
	for(int i = 0; i < r; ++i){
		string word;
		for(int j = 0; j < c; ++j){
			if(board[i][j] == '#'){
				if(word.length() >= 2 && ans > word){
					ans = word;
				}
				word = "";
			}else{
				word += board[i][j];
			}
		}
		if(word.length() >= 2 && ans > word){
			ans = word;
		}
	}
	for(int j = 0; j < c; ++j){
		string word;
		for(int i = 0; i < r; ++i){
			if(board[i][j] == '#'){
				if(word.length() >= 2 && ans > word){
					ans = word;
				}
				word = "";
			}else{
				word += board[i][j];
			}
		}
		if(word.length() >= 2 && ans > word){
			ans = word;
		}
	}
	printf("%s", ans.c_str());
	return 0;
}
