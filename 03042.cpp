#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#define MAX 101

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	vector<pair<int, int>> letters;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < n; ++j){
			if(map[i][j] != '.'){
				letters.push_back(make_pair(i, j));
			}
		}
	}
	int cnt = 0;
	for(unsigned idx1 = 0; idx1 < letters.size(); ++idx1){
		int x1 = letters[idx1].first, y1 = letters[idx1].second;
		for(unsigned idx2 = 0; idx2 < idx1; ++idx2){
			int x2 = letters[idx2].first, y2 = letters[idx2].second;
			for(unsigned idx3 = 0; idx3 < idx2; ++idx3){
				int x3 = letters[idx3].first, y3 = letters[idx3].second;
				if((x3 - x1) * (y2 - y1) == (x2 - x1) * (y3 - y1)){
					++cnt;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
