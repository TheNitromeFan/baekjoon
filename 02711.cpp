#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		unsigned m;
		string word;
		cin >> m >> word;
		for(unsigned j = 0; j < word.length(); ++j){
			if(j + 1 != m){
				cout << word[j];
			}
		}
		cout << '\n';
	}
	return 0;
}
