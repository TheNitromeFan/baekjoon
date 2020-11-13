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
		vector<int> m(n + 1, 0);
		for(int i = 1; i <= n; ++i){
			cin >> m[i];
		}
		cout << "Machine " << cnt << '\n';
		while(true){
			string name;
			int e;
			cin >> name >> e;
			if(name == "#" && e == 0){
				break;
			}
			int energy = 0;
			for(int j = 0; j < e; ++j){
				int level, d;
				cin >> level >> d;
				energy += m[level] * d;
			}
			cout << name << ' ' << energy << '\n';
		}
	}
	return 0;
}
