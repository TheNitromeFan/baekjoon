#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> multiple_of_10s, non_multiple_of_10s;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x % 10 == 0){
			multiple_of_10s.push(x);
		}else{
			non_multiple_of_10s.push(x);
		}
	}
	int cakes = 0;
	for(int j = 0; j < m; ++j){
		while(!multiple_of_10s.empty() && multiple_of_10s.top() == 10){
			multiple_of_10s.pop();
			++cakes;
		}
		if(!multiple_of_10s.empty()){
			int x = multiple_of_10s.top();
			multiple_of_10s.pop();
			multiple_of_10s.push(10);
			multiple_of_10s.push(x - 10);
			continue;
		}
		while(!non_multiple_of_10s.empty() && non_multiple_of_10s.top() < 10){
			non_multiple_of_10s.pop();
		}
		if(!non_multiple_of_10s.empty()){
			int x = non_multiple_of_10s.top();
			non_multiple_of_10s.pop();
			multiple_of_10s.push(10);
			non_multiple_of_10s.push(x - 10);
		}
	}
	while(!multiple_of_10s.empty() && multiple_of_10s.top() == 10){
		multiple_of_10s.pop();
		++cakes;
	}
	cout << cakes;
	return 0;
}
