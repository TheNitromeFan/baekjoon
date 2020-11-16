#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	vector<pair<int, int>> problems(11);
	for(int i = 0; i < 11; ++i){
		scanf("%d %d", &problems[i].first, &problems[i].second);
	}
	sort(problems.begin(), problems.end());
	int penalty = 0, time = 0;
	for(int i = 0; i < 11; ++i){
		time += problems[i].first;
		penalty += time + problems[i].second * 20;
	}
	printf("%d", penalty);
	return 0;
}
