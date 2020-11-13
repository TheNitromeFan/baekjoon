#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<pair<int, int>> points(n);
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &points[i].first, &points[i].second);
		}
		int x = points[n / 2].first, y = points[n / 2].second;
		int stan = 0, ollie = 0;
		for(int i = 0; i < n; ++i){
			int px = points[i].first, py = points[i].second;
			if((px > x && py > y) || (px < x && py < y)){
				++stan;
			}else if((px > x && py < y) || (px < x && py > y)){
				++ollie;
			}
		}
		printf("%d %d\n", stan, ollie);
	}
	return 0;
}
