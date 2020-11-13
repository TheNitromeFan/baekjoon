#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	map<string, int> cnt;
	int warn = 0;
	for(int i = 1; i <= n; ++i){
		string name;
		cin >> name;
		if(cnt.find(name) == cnt.end()){
			cnt[name] = 1;
		}else{
			++cnt[name];
		}
		if(cnt[name] - 1 > i - cnt[name]){
			++warn;
		}
	}
	cout << warn;
	return 0;
}
