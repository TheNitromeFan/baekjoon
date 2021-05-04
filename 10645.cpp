#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> rows(n), cols(n), leftdiag(2 * n - 1), rightdiag(2 * n - 1);
	int time = 1;
	for(; time <= n; ++time){
		int x, y;
		cin >> x >> y;
		++rows[x];
		++cols[y];
		++leftdiag[x - y + n - 1];
		++rightdiag[x + y - 2];
		if(rows[x] == k || cols[y] == k || leftdiag[x - y + n - 1] == k || rightdiag[x + y - 2] == k){
			break;
		}
	}
	cout << (time <= n ? time : -1);
	return 0;
}
