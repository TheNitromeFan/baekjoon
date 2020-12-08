#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<double, vector<double>, greater<double>> pq;
	for(int i = 0; i < n; ++i){
		double x;
		cin >> x;
		pq.push(x);
	}
	while(pq.size() > 1){
		double x = pq.top();
		pq.pop();
		double y = pq.top();
		pq.pop();
		pq.push((x + y) / 2);
	}
	cout << fixed << setprecision(6) << pq.top();
	return 0;
}
