#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

int rgb_dist(int r1, int b1, int g1, int r2, int b2, int g2){
	return (r1 - r2) * (r1 - r2) + (b1 - b2) * (b1 - b2) + (g1 - g2) * (g1 - g2);
}

int main(){
	vector<tuple<int, int, int>> v(16);
	for(int i = 0; i < 16; ++i){
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		v[i] = make_tuple(r, g, b);
	}
	int r, g, b;
	while(scanf("%d %d %d", &r, &g, &b) == 3){
		int bestr = -1, bestg = -1, bestb = -1;
		int best_dist = 1000000000;
		for(int i = 0; i < 16; ++i){
			int r1 = get<0>(v[i]), g1 = get<1>(v[i]), b1 = get<2>(v[i]);
			int cmp = rgb_dist(r, g, b, r1, g1, b1);
			if(cmp < best_dist){
				bestr = r1;
				bestg = g1;
				bestb = b1;
				best_dist = cmp;
			}
		}
		printf("%*d %*d %*d maps to %*d %*d %*d\n", 3, r, 3, g, 3, b, 3, bestr, 3, bestg, 3, bestb);
	}
	return 0;
}
