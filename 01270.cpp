#include <iostream>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		map<long long, int> soldiers;
		int ti;
		cin >> ti;
		int maxCnt = 0;
		long long troop = -1;
		for(int j = 0; j < ti; ++j){
			long long x;
			cin >> x;
			if(soldiers.find(x) == soldiers.end()){
				soldiers[x] = 1;
			}else{
				++soldiers[x];
			}
			if(maxCnt < soldiers[x]){
				maxCnt = soldiers[x];
				troop = x;
			}
		}
		if(maxCnt * 2 > ti){
			cout << troop << "\n";
		}else{
			cout << "SYJKGW\n";
		}
	}
	return 0;
}
