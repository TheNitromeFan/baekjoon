#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		vector<int> v(12);
		for(int i = 0; i < 12; ++i){
			cin >> v[i];
		}
		if(v == vector<int>(12)){
			break;
		}
		sort(v.begin(), v.end());
		cout << (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]
		&& v[4] == v[5] && v[5] == v[6] && v[6] == v[7]
		&& v[8] == v[9] && v[9] == v[10] && v[10] == v[11] ? "yes\n" : "no\n");
	}
	return 0;
}
