#include <iostream>
#include <string>
#define MAX 600000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string words[31];
	getline(cin, words[0]);
	for(int i = 0; i < n; ++i){
		getline(cin, words[i]);
	}
	bool used[256] = {};
	unsigned pos[31];
	for(int i = 0; i < n; ++i){
		pos[i] = MAX;
	}
	for(int i = 0; i < n; ++i){
		for(unsigned idx = 0; idx < words[i].length(); ++idx){
			if((idx == 0 || words[i][idx - 1] == ' ') && !used[tolower(words[i][idx])]){
				pos[i] = idx;
				used[tolower(words[i][idx])] = true;
				break;
			}
		}
		if(pos[i] != MAX){
			continue;
		}
		for(unsigned idx = 0; idx < words[i].length(); ++idx){
			if(words[i][idx] != ' ' && !used[tolower(words[i][idx])]){
				pos[i] = idx;
				used[tolower(words[i][idx])] = true;
				break;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(unsigned idx = 0; idx < words[i].length(); ++idx){
			if(pos[i] == idx){
				cout << '[' << words[i][idx] << ']';
			}else{
				cout << words[i][idx];
			}
		}
		cout << '\n';
	}
	return 0;
}
