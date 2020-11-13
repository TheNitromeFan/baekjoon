#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int> number;
	map<int, string> name;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		string pokemon;
		cin >> pokemon;
		number[pokemon] = i;
		name[i] = pokemon;
	}
	for(int q = 0; q < m; ++q){
		string query;
		cin >> query;
		if(query[0] >= 'A' && query[0] <= 'Z'){
			cout << number[query];
		}else{
			cout << name[stoi(query)];
		}
		cout << '\n';
	}
	return 0;
}
