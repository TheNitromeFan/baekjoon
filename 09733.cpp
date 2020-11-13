#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> actions = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
	map<string, int> cnt;
	string action;
	int total = 0;
	while(cin >> action){
		if(cnt.find(action) == cnt.end()){
			cnt[action] = 1;
		}else{
			++cnt[action];
		}
		++total;
	}
	for(string a : actions){
		cout << a << ' ' << cnt[a] << ' ' << fixed << setprecision(2) << round(cnt[a] * 100.0 / total) / 100 << '\n';
	}
	cout << "Total " << total << " 1.00";
	return 0;
}
