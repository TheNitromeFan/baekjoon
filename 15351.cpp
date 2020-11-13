#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		int score = 0;
		for(char c : line){
			if(c >= 'A' && c <= 'Z'){
				score += c - 'A' + 1;
			}
		}
		if(score == 100){
			cout << "PERFECT LIFE\n";
		}else{
			cout << score << '\n';
		}
	}
	return 0;
}
