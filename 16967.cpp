#include <iostream>
#define MAX 601

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	int b[MAX][MAX];
	for(int i = 0; i < h + x; ++i){
		for(int j = 0; j < w + y; ++j){
			cin >> b[i][j];
		}
	}
	int a[MAX][MAX];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(i >= x && j >= y){
				a[i][j] = b[i][j] - a[i - x][j - y];
			}else{
				a[i][j] = b[i][j];
			}
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
