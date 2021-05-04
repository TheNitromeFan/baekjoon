#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	vector<int> tea(k);
	for(int i = 0; i < k; ++i){
		cin >> tea[i];
	}
	int jugs = 0;
	for(int i = 0; i < k; ++i){
		while(n > 0 && tea[i] >= 10){
			++jugs;
			n -= 10;
			tea[i] -= 10;
		}
		if(n <= 0){
			break;
		}
	}
	if(n > 0){
		sort(tea.begin(), tea.end(), greater<int>());
		for(int i = 0; i < k; ++i){
			++jugs;
			n -= tea[i];
			if(n <= 0){
				break;
			}
		}
	}
	cout << jugs;
	return 0;
}
