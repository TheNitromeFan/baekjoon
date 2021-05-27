#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

bool stripe_row(int a[][MAX], int w, int row){
	for(int j = 1; j <= w; ++j){
		if(!a[row][j]){
			return false;
		}
	}
	return true;
}

bool stripe_column(int a[][MAX], int h, int col){
	for(int i = 1; i <= h; ++i){
		if(!a[i][col]){
			return false;
		}
	}
	return true;
}

void fill_row(int b[][MAX], int w, int row){
	for(int j = 1; j <= w; ++j){
		b[row][j] = 1;
	}
}

void fill_column(int b[][MAX], int h, int col){
	for(int i = 1; i <= h; ++i){
		b[i][col] = 1;
	}
}

bool match(int a[][MAX], int b[][MAX], int h, int w){
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			if(a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	int a[MAX][MAX] = {}, b[MAX][MAX] = {};
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cin >> a[i][j];
		}
	}
	vector<int> ans;
	if(h <= w){
		for(int i = 1; i <= h; ++i){
			if(stripe_row(a, w, i) && !stripe_row(b, w, i)){
				fill_row(b, w, i);
				ans.push_back(-i);
			}
		}
		for(int j = 1; j <= w; ++j){
			if(stripe_column(a, h, j) && !stripe_column(b, h, j)){
				fill_column(b, h, j);
				ans.push_back(j);
			}
		}
	}else{
		for(int j = 1; j <= w; ++j){
			if(stripe_column(a, h, j) && !stripe_column(b, h, j)){
				fill_column(b, h, j);
				ans.push_back(j);
			}
		}
		for(int i = 1; i <= h; ++i){
			if(stripe_row(a, w, i) && !stripe_row(b, w, i)){
				fill_row(b, w, i);
				ans.push_back(-i);
			}
		}
	}
	if(match(a, b, h, w)){
		cout << ans.size() << '\n';
		for(int x : ans){
			cout << x << ' ';
		}
	}else{
		cout << -1;
	}
	return 0;
}
