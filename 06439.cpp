#include <iostream>
#include <algorithm>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
	long long cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp == 0){
		return 0;
	}else if(cmp > 0){
		return 1;
	}else{
		return -1;
	}
}

bool intersect(long long a, long long b, long long c, long long d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return !(b < c || d < a);
}

bool cross(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4){
	int cmp1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int cmp2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if(cmp1 == 0 && cmp2 == 0){
		return intersect(x1, x2, x3, x4) && intersect(y1, y2, y3, y4);
	}
	return cmp1 <= 0 && cmp2 <= 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		long long xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
		if(xleft > xright){
			swap(xleft, xright);
		}
		if(ybottom > ytop){
			swap(ybottom, ytop);
		}
		if(cross(xstart, ystart, xend, yend, xleft, ytop, xright, ytop)
		|| cross(xstart, ystart, xend, yend, xright, ytop, xright, ybottom)
		|| cross(xstart, ystart, xend, yend, xright, ybottom, xleft, ybottom)
		|| cross(xstart, ystart, xend, yend, xleft, ybottom, xleft, ytop)
		|| (xstart >= xleft && xstart <= xright && ystart >= ybottom && ystart <= ytop)){
			cout << 'T';
		}else{
			cout << 'F';
		}
		cout << '\n';
	}
	return 0;
}
