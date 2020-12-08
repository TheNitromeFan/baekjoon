#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int c;
	cin >> c;
	vector<int> chores(c);
	for(int i = 0; i < c; ++i){
		cin >> chores[i];
	}
	sort(chores.begin(), chores.end());
	int idx = 0;
	for(; idx < c; ++idx){
		if(t >= chores[idx]){
			t -= chores[idx];
		}else{
			break;
		}
	}
	cout << idx;
	return 0;
}
