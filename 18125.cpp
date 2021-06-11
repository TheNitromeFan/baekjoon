#include <iostream>
#define MAX 100

using namespace std;

bool wink(int pic[][MAX], int stud[][MAX], int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(stud[i][j] != pic[c - 1 - j][i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;
	int pic[MAX][MAX], students[MAX][MAX];
	for(int i = 0; i < c; ++i){
		for(int j = 0; j < r; ++j){
			cin >> pic[i][j];
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> students[i][j];
		}
	}
	if(wink(pic, students, r, c)){
		cout << "|>___/|        /}\n";
		cout << "| O < |       / }\n";
		cout << "(==0==)------/ }\n";
		cout << "| ^  _____    |\n";
		cout << "|_|_/     ||__|\n";
	}else{
		cout << "|>___/|     /}\n";
		cout << "| O O |    / }\n";
		cout << "( =0= )\"\"\"\"  \\\n";
		cout << "| ^  ____    |\n";
		cout << "|_|_/    ||__|\n";
	}
	return 0;
}
