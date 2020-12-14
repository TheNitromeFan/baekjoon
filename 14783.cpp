#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	queue<int> circle, seq;
	for(int i = 1; i <= n; ++i){
		circle.push(i);
	}
	int x;
	while(cin >> x){
		seq.push(x);
	}
	while(circle.size() > 1){
		for(int j = 1; j < seq.front(); ++j){
			circle.push(circle.front());
			circle.pop();
		}
		// cout << circle.front();
		circle.pop();
		seq.push(seq.front());
		seq.pop();
	}
	cout << circle.front();
	return 0;
}
