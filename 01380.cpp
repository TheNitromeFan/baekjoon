#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int case_num = 0;
	while(true){
		++case_num;
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<string> names(n + 1, "");
		getline(cin, names[0]);
		for(int i = 1; i <= n; ++i){
			getline(cin, names[i]);
		}
		vector<int> cnt(n + 1, 0);
		for(int j = 0; j < 2 * n - 1; ++j){
			int x;
			char c;
			cin >> x >> c;
			++cnt[x];
		}
		cout << case_num << ' ';
		for(int i = 1; i <= n; ++i){
			if(cnt[i] == 1){
				cout << names[i];
				break;
			}
		}
		cout << '\n';
	}
	return 0;
}
