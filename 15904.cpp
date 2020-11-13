#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	getline(cin, line);
	int match = 0;
	for(char c : line){
		if(c == 'U' && match == 0){
			++match;
		}else if(c == 'C' && match == 1){
			++match;
		}else if(c == 'P' && match == 2){
			++match;
		}else if(c == 'C' && match == 3){
			++match;
		}
	}
	cout << "I " << ((match == 4) ? "love" : "hate") << " UCPC";
	return 0;
}
