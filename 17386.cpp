#include <iostream>
#include <algorithm>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	long long cmp = (long long)(x2 - x1) * (y3 - y1) - (long long)(x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

bool disjoint(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return b < c || d < a;
}

bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int cmp1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int cmp2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if(cmp1 == 0 && cmp2 == 0){
		return !disjoint(x1, x2, x3, x4) && !disjoint(y1, y2, y3, y4);
	}
	return cmp1 <= 0 && cmp2 <= 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cout << intersect(x1, y1, x2, y2, x3, y3, x4, y4);
	return 0;
}
