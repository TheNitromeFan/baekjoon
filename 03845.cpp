#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

bool cut(vector<double> &x, vector<double> &y, double w){
	if(x[0] > w / 2 || y[0] > w / 2 || x[x.size() - 1] < 75 - w / 2 || y[y.size() - 1] < 100 - w / 2){
		return false;
	}
	for(unsigned i = 0; i < x.size() - 1; ++i){
		if(x[i + 1] - x[i] > w){
			return false;
		}
	}
	for(unsigned j = 0; j < y.size() - 1; ++j){
		if(y[j + 1] - y[j] > w){
			return false;
		}
	}
	return true;
}

int main(){
	while(true){
		int nx, ny;
		double w;
		scanf("%d %d %lf", &nx, &ny, &w);
		if(nx == 0 && ny == 0 && w == 0){
			break;
		}
		vector<double> x(nx), y(ny);
		for(int i = 0; i < nx; ++i){
			scanf("%lf", &x[i]);
		}
		for(int j = 0; j < ny; ++j){
			scanf("%lf", &y[j]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if(cut(x, y, w)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
