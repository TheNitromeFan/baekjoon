#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	cin >> word;
	int cnt = 1;
	for(unsigned i = 0; i + 1 < word.length(); ++i){
		if(word[i] >= word[i + 1]){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
