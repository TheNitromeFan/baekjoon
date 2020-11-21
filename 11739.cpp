#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, k;
	cin >> n >> k;
	vector<vector<int>> p(n);
	for(unsigned i = 0; i < n; ++i){
		unsigned pi;
		cin >> pi;
		p[i].resize(pi);
		for(unsigned j = 0; j < pi; ++j){
			cin >> p[i][j];
		}
	}
	unsigned judge = 0;
	unsigned judge_round = 0;
	int sum = 0;
	while(k > 0){
		if(judge_round < p[judge].size() && sum <= p[judge][judge_round]){
			sum += p[judge][judge_round];
			--k;
		}else if(judge_round >= p[judge].size()){
			sum += 50;
			--k;
		}
		++judge;
		if(judge == n){
			++judge_round;
			judge = 0;
		}
	}
	cout << sum;
	return 0;
}
