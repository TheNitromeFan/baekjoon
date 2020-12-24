#include <iostream>
#include <string>
#include <algorithm>
#define MAX 25

using namespace std;

struct segment{
	int x1, y1, x2, y2;
} lines[MAX];

void coordinates(int n, int &x, int &y){
	if(n == 0){
		x = 4;
		y = 2;
		return;
	}
	x = (n - 1) / 3 + 1;
	y = (n - 1) % 3 + 1;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp == 0){
		return 0;
	}else if(cmp > 0){
		return 1;
	}else{
		return -1;
	}
}

bool intersect(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return !(b < c || d < a);
}

bool can_combine(segment line1, segment line2){
	int cmp1 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x1, line2.y1);
	int cmp2 = ccw(line1.x1, line1.y1, line1.x2, line1.y2, line2.x2, line2.y2);
	return cmp1 == 0 && cmp2 == 0
	&& intersect(line1.x1, line1.x2, line2.x1, line2.x2)
	&& intersect(line1.y1, line1.y2, line2.y1, line2.y2);
}

int find_parent(int parent[MAX], int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(int parent[MAX], int x, int y, int &cnt){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x != y){
		--cnt;
		parent[y] = x;
	}
}

string complexity(string number){
	int cnt = 0;
	int parent[MAX];
	for(unsigned i = 0; i + 1 < number.length(); ++i){
		if(number[i] == number[i + 1]){
			continue;
		}
		coordinates(number[i] - '0', lines[cnt].x1, lines[cnt].y1);
		coordinates(number[i + 1] - '0', lines[cnt].x2, lines[cnt].y2);
		parent[cnt] = cnt;
		++cnt;
	}
	int numLines = cnt;
	for(int i = 0; i < cnt; ++i){
		for(int j = 0; j < i; ++j){
			if(can_combine(lines[i], lines[j])){
				unite(parent, i, j, numLines);
			}
		}
	}
	if(numLines <= 3){
		return "EXCELLENT";
	}else if(numLines == 4){
		return "GOOD";
	}else{
		return "BAD";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string number;
		cin >> number;
		cout << complexity(number) << '\n';
	}
	return 0;
}
