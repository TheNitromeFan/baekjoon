#include <cstdio>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	vector<int> hor = {0, c}, vert = {0, r};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int d, x;
		scanf("%d %d", &d, &x);
		if(d == 0){
			hor.push_back(x);
		}else{
			vert.push_back(x);
		}
	}
	sort(hor.begin(), hor.end());
	sort(vert.begin(), vert.end());
	int maxHor = 0, maxVert = 0;
	for(unsigned i = 0; i + 1 < hor.size(); ++i){
		if(maxHor < hor[i + 1] - hor[i]){
			maxHor = hor[i + 1] - hor[i];
		}
	}
	for(unsigned j = 0; j + 1 < vert.size(); ++j){
		if(maxVert < vert[j + 1] - vert[j]){
			maxVert = vert[j + 1] - vert[j];
		}
	}
	printf("%d", maxHor * maxVert);
	return 0;
}
