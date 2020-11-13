#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<int> points(n + 1, 0);
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			int s;
			double know;
			scanf("%d %lf", &s, &know);
			if(points[s] < (int)(10 * know)){
				points[s] = (int)(10 * know);
			}
		}
	}
	sort(points.begin() + 1, points.end(), greater<int>());
	int sum = 0;
	for(int j = 1; j <= k; ++j){
		sum += points[j];
	}
	printf("%.1f", sum / 10.0);
	return 0;
}
