#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 3001

using namespace std;

struct segment{
	double x1, y1, x2, y2;
} lines[MAX];

bool equals(double a, double b){
	return fabs(a - b) < 0.00001;
}

int ccw(double x1, double y1, double x2, double y2, double x3, double y3){
	double cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(equals(cmp, 0)){
		return 0;
	}else if(cmp > 0){
		return 1;
	}else{
		return -1;
	}
}

bool intersect(double a, double b, double c, double d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return !(b < c || d < a);
}

bool can_combine(segment line1, segment line2){
	int cmp1 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x1, line2.y1)
	* ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x2, line2.y2);
	int cmp2 = ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x1, line1.y1)
	* ccw(line2.x1, line2.y1, line2.x2, line2.y2, line1.x2, line1.y2);
	if(cmp1 == 0 && cmp2 == 0){
		return intersect(line1.x1, line1.x2, line2.x1, line2.x2)
		&& intersect(line1.y1, line1.y2, line2.y1, line2.y2);
	}
	return cmp1 <= 0 && cmp2 <= 0;
}

int find_parent(int parent[MAX], int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(int parent[MAX], int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x != y){
		parent[y] = x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int parent[MAX];
	for(int i = 0; i < n; ++i){
		cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
		parent[i] = i;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(can_combine(lines[i], lines[j])){
				unite(parent, i, j);
			}
		}
	}
	int groupCnt = 0, maxElements = 0;
	int groups[MAX] = {};
	for(int i = 0; i < n; ++i){
		if(groups[find_parent(parent, i)] == 0){
			++groupCnt;
		}
		++groups[find_parent(parent, i)];
		if(groups[find_parent(parent, i)] > maxElements){
			maxElements = groups[find_parent(parent, i)];
		}
	}
	cout << groupCnt << '\n' << maxElements;
	return 0;
}
