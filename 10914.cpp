#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string word;
	while(cin >> word){
		for(unsigned i = 0; i + 2 <= word.length(); i += 2){
			int val = (word[i] - 'a') + (word[i + 1] - 'a') - n + 'a';
			if(val < 'a'){
				val += 26;
			}else if(val > 'z'){
				val -= 26;
			}
			cout << (char)val;
		}
		cout << ' ';
	}
	return 0;
}
