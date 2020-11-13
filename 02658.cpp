#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	}
} cmp;

/*
vector<pair<int, int>> count_row(int a[][10], int r){
	pair<int, int> ret;
	for(int j = 0; j < 10; ++j){
		if(a[r][j]){
			ret.push_back(make_pair(r, j))
		}
	}
	return ret;
}

vector<pair<int, int>> count_col(int a[][10], int c){
	pair<int, int> ret;
	for(int i = 0; i < 10; ++i){
		if(a[i][c]){
			ret.push_back(make_pair(i, c));
		}
	}
	return ret;
}
*/

vector<pair<int, int>> triangle(vector<pair<int, int>> &p1, vector<pair<int, int>> &p2){
	vector<pair<int, int>> ret;
	if(p1.size() < 3){
		return ret;
	}
	bool left = (p2[0].second != p2[1].second);
	bool right = (p2[p2.size()-1].second != p2[p2.size()-2].second);
	bool top = (p1[0].first != p1[1].first);
	bool bottom = (p1[p1.size()-1].first != p1[p1.size()-2].first);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	vector<pair<int, int>> p3;
	if(left && right && top){
		x1 = p1[0].first;
		y1 = p1[0].second;
		x2 = p2[0].first;
		y2 = p2[0].second;
		x3 = p2[p2.size()-1].first;
		y3 = p2[p2.size()-1].second;
		// printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
		if(!(y2 < y3 && x2 == x3 && 2 * y1 == y2 + y3)){
			return ret;
		}
		for(int i = x1; i <= x2; ++i){
			for(int j = y1 - (i - x1); j <= y1 + (i - x1); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(left && right && bottom){
		x1 = p2[0].first;
		y1 = p2[0].second;
		x2 = p2[p2.size()-1].first;
		y2 = p2[p2.size()-1].second;
		x3 = p1[p1.size()-1].first;
		y3 = p1[p1.size()-1].second;
		if(!(y1 < y2 && x1 == x2 && 2 * y3 == y1 + y2)){
			return ret;
		}
		for(int i = x1; i <= x3; ++i){
			for(int j = y3 - (x3 - i); j <= y3 + (x3 - i); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(left && top && bottom){
		x1 = p1[0].first;
		y1 = p1[0].second;
		x2 = p2[0].first;
		y2 = p2[0].second;
		x3 = p1[p1.size()-1].first;
		y3 = p1[p1.size()-1].second;
		if(!(x1 < x3 && y1 == y3 && 2 * x2 == x1 + x3)){
			return ret;
		}
		for(int i = x1; i < x2; ++i){
			for(int j = y1 - (i - x1); j <= y1; ++j){
				p3.push_back(make_pair(i, j));
			}
		}
		for(int i = x2; i <= x3; ++i){
			for(int j = y3 - (x3 - i); j <= y3; ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(right && top && bottom){
		x1 = p1[0].first;
		y1 = p1[0].second;
		x2 = p2[p2.size()-1].first;
		y2 = p2[p2.size()-1].second;
		x3 = p1[p1.size()-1].first;
		y3 = p1[p1.size()-1].second;
		if(!(x1 < x3 && y1 == y3 && 2 * x2 == x1 + x3)){
			return ret;
		}
		for(int i = x1; i < x2; ++i){
			for(int j = y1; j <= y1 + (i - x1); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
		for(int i = x2; i <= x3; ++i){
			for(int j = y3; j <= y3 + (x3 - i); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(left && top){
		x1 = p1[0].first;
		y1 = p1[0].second;
		x2 = p2[0].first;
		y2 = p2[0].second;
		x3 = x2;
		y3 = y1;
		for(int i = x1; i <= x2; ++i){
			for(int j = y1 - (i - x1); j <= y1; ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(left && bottom){
		x1 = p2[0].first;
		y1 = p2[0].second;
		x3 = p1[p1.size()-1].first;
		y3 = p1[p1.size()-1].second;
		x2 = x1;
		y2 = y3;
		for(int i = x1; i <= x3; ++i){
			for(int j = y3 - (x3 - i); j <= y3; ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(right && top){
		x1 = p1[0].first;
		y1 = p1[0].second;
		x3 = p2[p2.size()-1].first;
		y3 = p2[p2.size()-1].second;
		x2 = x3;
		y2 = y1;
		for(int i = x1; i <= x3; ++i){
			for(int j = y1; j <= y1 + (i - x1); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}else if(right && bottom){
		x2 = p2[p2.size()-1].first;
		y2 = p2[p2.size()-1].second;
		x3 = p1[p1.size()-1].first;
		y3 = p1[p1.size()-1].second;
		x1 = x2;
		y1 = y3;
		for(int i = x1; i <= x3; ++i){
			for(int j = y1; j <= y1 + (x3 - i); ++j){
				p3.push_back(make_pair(i, j));
			}
		}
	}
	if(p1 != p3){
		return ret;
	}
	ret.push_back(make_pair(x1, y1));
	ret.push_back(make_pair(x2, y2));
	ret.push_back(make_pair(x3, y3));
	return ret;
}

int main(){
	vector<pair<int, int>> points1;
	string line;
	for(int i = 0; i < 10; ++i){
		cin >> line;
		for(int j = 0; j < 10; ++j){
			if(line[j] == '1'){
				points1.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	vector<pair<int, int>> points2 = points1;
	sort(points2.begin(), points2.end(), cmp);
	/*
	for(pair<int, int> p : points2){
		printf("%d %d\n", p.first, p.second);
	}
	*/
	vector<pair<int, int>> points = triangle(points1, points2);
	if(!points.empty()){
		for(pair<int, int> p: points){
			printf("%d %d\n", p.first, p.second);
		}
	}else{
		printf("0");
	}
	return 0;
}
