#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		set<string> cities;
		for(int j = 0; j < n; ++j){
			string city;
			cin >> city;
			cities.insert(city);
		}
		cout << cities.size() << '\n';
	}
	return 0;
}
