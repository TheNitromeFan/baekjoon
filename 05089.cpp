#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		set<string> towns;
		string town;
		getline(cin, town);
		for(int i = 0; i < n; ++i){
			getline(cin, town);
			towns.insert(town);
		}
		cout << "Week " << cnt << ' ' << towns.size() << '\n';
	}
	return 0;
}
