#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool all_same_count(vector<int> &points, queue<int> &q){
	int c = points[q.front()];
	bool ret = true;
	for(unsigned i = 0; i < q.size(); ++i){
		int player = q.front();
		q.pop();
		if(points[player] != c){
			ret = false;
		}
		q.push(player);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int t;
		cin >> t;
		vector<int> points(n);
		queue<int> q;
		for(int player = 0; player < n; ++player){
			q.push(player);
		}
		do{
			for(int j = 0; j < t - 1; ++j){
				int player = q.front();
				q.pop();
				++points[player];
				q.push(player);
			}
			q.pop();
		}while(!all_same_count(points, q));
		cout << q.size() << ' ' << points[q.front()] << '\n';
	}
	return 0;
}
