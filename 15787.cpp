#include <iostream>
#include <vector>
#include <unordered_set>
#define MOD (1 << 20)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> trains(n);
	for(int a0 = 0; a0 < m; ++a0){
		int command;
		cin >> command;
		if(command == 1){
			int i, x;
			cin >> i >> x;
			--i;
			--x;
			trains[i] |= (1 << x);
		}else if(command == 2){
			int i, x;
			cin >> i >> x;
			--i;
			--x;
			if(trains[i] & (1 << x)){
				trains[i] -= (1 << x);
			}
		}else if(command == 3){
			int i;
			cin >> i;
			--i;
			trains[i] <<= 1;
			trains[i] %= MOD;
		}else{
			int i;
			cin >> i;
			--i;
			trains[i] >>= 1;
		}
	}
	int cnt = 0;
	unordered_set<int> passed;
	for(int train : trains){
		if(passed.find(train) == passed.end()){
			++cnt;
			passed.insert(train);
		}
	}
	cout << cnt;
	return 0;
}
