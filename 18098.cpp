#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> rooms(n + 1);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int ai;
		cin >> ai;
		if(ai <= n && !rooms[ai]){
			rooms[ai] = true;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
