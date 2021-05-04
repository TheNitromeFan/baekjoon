#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	vector<int> simplest(p + 1);
	vector<bool> hardest(p + 1);
	for(int i = 0; i < n; ++i){
		vector<int> ratings(p + 1);
		int min = 100000, max = -100000;
		for(int j = 1; j <= p; ++j){
			cin >> ratings[j];
			if(ratings[j] < min){
				min = ratings[j];
			}
			if(ratings[j] > max){
				max = ratings[j];
			}
		}
		for(int j = 1; j <= p; ++j){
			if(ratings[j] == min){
				++simplest[j];
			}
			if(ratings[j] == max){
				hardest[j] = true;
			}
		}
	}
	vector<int> verysimple;
	for(int j = 1; j <= p; ++j){
		if(2 * simplest[j] > n && !hardest[j]){
			verysimple.push_back(j);
		}
	}
	if(!verysimple.empty()){
		for(int problem : verysimple){
			cout << problem << ' ';
		}
	}else{
		cout << 0;
	}
	return 0;
}
