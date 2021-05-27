#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		pos[x] = i;
	}
	int claps = 0;
	for(int i = 1; i < n; ++i){
		if(pos[i] > pos[i + 1]){
			++claps;
		}
	}
	cout << claps;
	return 0;
}
