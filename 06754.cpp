#include <iostream>
#include <vector>

using namespace std;

int bridge(vector<int> &trucks, int n, int w){
	int i = 1;
	int sum = 0;
	for(; i <= n; ++i){
		if(i > 4){
			sum -= trucks[i - 4];
		}
		sum += trucks[i];
		if(sum > w){
			break;
		}
	}
	return i - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w;
	cin >> w;
	int n;
	cin >> n;
	vector<int> trucks(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> trucks[i];
	}
	cout << bridge(trucks, n, w);
	return 0;
}
