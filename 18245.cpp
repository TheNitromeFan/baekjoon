#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned skip = 1;
	while(true){
		string line;
		getline(cin, line);
		if(line == "Was it a cat I saw?"){
			break;
		}
		++skip;
		for(unsigned idx = 0; idx < line.length(); idx += skip){
			cout << line[idx];
		}
		cout << '\n';
	}
	return 0;
}
