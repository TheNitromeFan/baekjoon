#include <iostream>
#include <string>
#define ANSWERS "1 2 3 4 5 1 2 3 4 5"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 1; i <= n; ++i){
		getline(cin, line);
		if(line == ANSWERS){
			cout << i << '\n';
		}
	}
	return 0;
}
