#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		char letter = line[0];
		int ans = 0;
		for(unsigned idx = 2; idx < line.length(); ++idx){
			if(line[idx] == letter || line[idx] == letter - 'a' + 'A'){
				++ans;
			}
		}
		cout << letter << ' ' << ans << '\n';
	}
	return 0;
}
