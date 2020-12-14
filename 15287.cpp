#include <iostream>
#include <vector>

using namespace std;

void simulate(vector<int> &enemies, int n){
	int unicorns = 0;
	vector<int> items(1001);
	vector<int> requests;
	for(int i = 0; i < n; ++i){
		if(enemies[i] > 0){
			++items[enemies[i]];
		}else if(enemies[i] < 0){
			if(items[-enemies[i]] > 0){
				--items[-enemies[i]];
			}else if(unicorns > 0){
				--unicorns;
				requests.push_back(-enemies[i]);
			}else{
				cout << "No";
				return;
			}
		}else{
			++unicorns;
		}
	}
	while(unicorns > 0){
		--unicorns;
		requests.push_back(1);
	}
	cout << "Yes\n";
	for(int request : requests){
		cout << request << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> enemies(n);
	for(int i = 0; i < n; ++i){
		cin >> enemies[i];
	}
	simulate(enemies, n);
	return 0;
}
