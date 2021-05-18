#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, width, length, height, area, m;
		cin >> n >> width >> length >> height >> area >> m;
		if(n == 0 && width == 0 && length == 0 && height == 0 && area == 0 && m == 0){
			break;
		}
		int paint = 2 * width * height + 2 * length * height + width * length;
		for(int i = 0; i < m; ++i){
			int w, h;
			cin >> w >> h;
			paint -= w * h;
		}
		int total_paint = n * paint;
		cout << (total_paint % area == 0 ? total_paint / area : total_paint / area + 1) << '\n';
	}
	return 0;
}
