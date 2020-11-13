#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n, m;
		cin >> n >> m;
		map<string, int> list;
		int cnt = 0;
		for(int j = 0; j < n + m; ++j){
			string x;
			cin >> x;
			if(list.find(x) == list.end()){
				list[x] = 1;
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
