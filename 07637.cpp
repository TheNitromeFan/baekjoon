#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

bool overlap(vector<pair<int, int>> &times, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(!(times[i].second <= times[j].first || times[j].second <= times[i].first)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<pair<int, int>> times(n);
		for(int i = 0; i < n; ++i){
			int h1, m1, h2, m2;
			scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
			times[i] = make_pair(60 * h1 + m1, 60 * h2 + m2);
		}
		printf("%s\n", overlap(times, n) ? "conflict" : "no conflict");
	}
	return 0;
}
