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
		if(line.substr(0, 10) == "Simon says"){
			cout << line.substr(10) << '\n';
		}
	}
	return 0;
}
