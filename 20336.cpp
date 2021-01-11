#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	cout << m;
	for(int i = 0; i < m; ++i){
		string food;
		cin >> food;
		cout << '\n' << food;
	}
	return 0;
}
