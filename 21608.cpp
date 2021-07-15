#include <iostream>
#include <unordered_set>
#define MAX 21

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX] = {};
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	unordered_set<int> like[MAX * MAX];
	for(int i = 0; i < n * n; ++i){
		int num;
		cin >> num;
		for(int j = 0; j < 4; ++j){
			int x;
			cin >> x;
			like[num].insert(x);
		}
		int pos_r = -1, pos_c = -1;
		int pos_likes = -1;
		int pos_vacant = -1;
		for(int r = 1; r <= n; ++r){
			for(int c = 1; c <= n; ++c){
				if(a[r][c] != 0){
					continue;
				}
				int likes = 0, vacant = 0;
				for(int j = 0; j < 4; ++j){
					int nr = r + dx[j];
					int nc = c + dy[j];
					if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && a[nr][nc] == 0){
						++vacant;
					}else if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && like[num].find(a[nr][nc]) != like[num].end()){
						++likes;
					}
				}
				if(likes > pos_likes || (likes == pos_likes && vacant > pos_vacant)){
					pos_r = r;
					pos_c = c;
					pos_likes = likes;
					pos_vacant = vacant;
				}
			}
		}
		a[pos_r][pos_c] = num;
	}
	int score = 0;
	for(int r = 1; r <= n; ++r){
		for(int c = 1; c <= n; ++c){
			int num = a[r][c];
			int cnt = 0;
			for(int j = 0; j < 4; ++j){
				int nr = r + dx[j];
				int nc = c + dy[j];
				if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && like[num].find(a[nr][nc]) != like[num].end()){
					++cnt;
				}
			}
			switch(cnt){
				case 4:
					score += 1000;
					break;
				case 3:
					score += 100;
					break;
				case 2:
					score += 10;
					break;
				case 1:
					score += 1;
					break;
			}
		}
	}
	cout << score << '\n';
	return 0;
}
