#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int m;
		cin >> m;
		int cnt = 0;
		for(int j = 0; j < m; ++j){
			string word;
			cin >> word;
			if(word == "sheep"){
				++cnt;
			}
		}
		cout << "Case " << i << ": This list contains " << cnt << " sheep.\n\n";
	}
	return 0;
}
