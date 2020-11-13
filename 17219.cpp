#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> pass;
	for(int i = 0; i < n; ++i){
		string site, password;
		cin >> site >> password;
		pass[site] = password;
	}
	for(int j = 0; j < m; ++j){
		string site;
		cin >> site;
		cout << pass[site] << '\n';
	}
	return 0;
}
