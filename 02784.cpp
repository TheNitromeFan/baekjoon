#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> words(6, "");
	for(int i = 0; i < 6; ++i){
		cin >> words[i];
	}
	bool flag;
	do{
		flag = true;
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(words[i][j] != words[j + 3][i]){
					flag = false;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		if(flag){
			for(int i = 0; i < 3; ++i){
				cout << words[i] << '\n';
			}
			return 0;
		}
	}while(next_permutation(words.begin(), words.end()));
	cout << 0;
	return 0;
}
