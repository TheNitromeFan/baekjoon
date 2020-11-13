#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int rgb(int r1, int g1, int b1, int r2, int g2, int b2){
	return (r2 - r1) * (r2 - r1) + (g2 - g1) * (g2 - g1) + (b2 - b1) * (b2 - b1);
}

int main(){
	int k;
	scanf("%d", &k);
	vector<pair<int, int>> ans;
	for(int i = 1; i <= k; ++i){
		int colors[200][3] = {};
		int n;
		scanf("%d", &n);
		ans.clear();
		int max_rgb = 0;
		for(int j = 0; j < n; ++j){
			for(int m = 0; m < 3; ++m){
				scanf("%d", &colors[j][m]);
			}
		}
		for(int j = 0; j < n; ++j){
			for(int ell = j+1; ell < n; ++ell){
				int cmp = rgb(colors[ell][0], colors[ell][1], colors[ell][2],
				colors[j][0], colors[j][1], colors[j][2]);
				if(cmp > max_rgb){
					max_rgb = cmp;
					ans.clear();
					ans.push_back(make_pair(j, ell));
			    }else if(cmp == max_rgb){
			    	ans.push_back(make_pair(j, ell));
				}
			}
		}
		printf("Data Set %d:\n", i);
		for(pair<int, int> p : ans){
			printf("%d %d\n", p.first + 1, p.second + 1);
		}
	}
	return 0;
}
