#include <iostream>
#include <string>
#include <vector>

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
		vector<string> names(n, "");
		vector<vector<int>> nasty;
		nasty.resize(n);
		bool kind = true;
		for(int i = 0; i < n; ++i){
			cin >> names[i];
			for(int j = (i + n - 1) % n; j != i; j = (j + n - 1) % n){
				char c;
				cin >> c;
				if(c == 'N'){
					nasty[i].push_back(j);
					kind = false;
				}
			}
		}
		cout << "Group " << cnt << '\n';
		if(kind){
			cout << "Nobody was nasty\n\n";
			continue;
		}
		for(int i = 0; i < n; ++i){
			for(int j : nasty[i]){
				cout << names[j] << " was nasty about " << names[i] << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}
