#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){
	vector<int> front(4, 0), back(8, 0);
	for(int i = 1; i <= 3; ++i){
		scanf("%d", &front[i]);
	}
	for(int j = 1; j <= 7; ++j){
		scanf("%d", &back[j]);
	}
	vector<tuple<double, int, int>> combos;
	for(int i = 1; i <= 3; ++i){
		for(int j = 1; j <= 7; ++j){
			combos.push_back(make_tuple(front[i] / (double)back[j], i, j));
		}
	}
	sort(combos.begin(), combos.end());
	for(auto t : combos){
		printf("%.2f %d %d\n", get<0>(t), get<1>(t), get<2>(t));
	}
	return 0;
}
