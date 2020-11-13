#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "***"){
			break;
		}
		reverse(line.begin(), line.end());
		cout << line << '\n';
	}
	return 0;
}
