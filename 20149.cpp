#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

bool equals(double a, double b){
	return fabs(a - b) < 1e-11;
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

int meet(int &a, int &b, int &c, int &d, int &ans){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	if(b == c){
		ans = b;
		return 1;
	}else if(d == a){
		ans = a;
		return 1;
	}
	if(b < c || d < a){
		return 0;
	}
	return 2;
}

void intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int cmp1 = ccw(x1, y1, x2, y2, x3, y3);
	int cmp2 = ccw(x1, y1, x2, y2, x4, y4);
	int cmp3 = ccw(x3, y3, x4, y4, x1, y1);
	int cmp4 = ccw(x3, y3, x4, y4, x2, y2);
	if(cmp1 == 0 && cmp2 == 0){
		int x, y;
		int ans1 = meet(x1, x2, x3, x4, x), ans2 = meet(y1, y2, y3, y4, y);
		cout << (ans1 > 0 && ans2 > 0) << '\n';
		if(ans1 == 1 && ans2 == 1){
			cout << x << ' ' << y;
		}
	}else if(cmp1 == 0){
		cout << (cmp3 * cmp4 <= 0) << '\n';
		if(cmp3 * cmp4 <= 0){
			cout << x3 << ' ' << y3;
		}
	}else if(cmp2 == 0){
		cout << (cmp3 * cmp4 <= 0) << '\n';
		if(cmp3 * cmp4 <= 0){
			cout << x4 << ' ' << y4;
		}
	}else if(cmp3 == 0){
		cout << (cmp1 * cmp2 <= 0) << '\n';
		if(cmp1 * cmp2 <= 0){
			cout << x1 << ' ' << y1;
		}
	}else if(cmp4 == 0){
		cout << (cmp1 * cmp2 <= 0) << '\n';
		if(cmp1 * cmp2 <= 0){
			cout << x2 << ' ' << y2;
		}
	}else{
		cout << (cmp1 * cmp2 < 0 && cmp3 * cmp4 < 0) << '\n';
		if(cmp1 * cmp2 < 0 && cmp3 * cmp4 < 0){
			double xstart = x3, ystart = y3, xend = x4, yend = y4;
			double xmid, ymid;
			for(int i = 0; i < 1000; ++i){
				double xmid = (xstart + xend) / 2, ymid = (ystart + yend) / 2;
				if(ccw(x1, y1, x2, y2, xmid, ymid) == 0){
					break;
				}else if(ccw(x1, y1, x2, y2, xmid, ymid) * ccw(x1, y1, x2, y2, xstart, ystart) > 0){
					xstart = xmid;
					ystart = ymid;
				}else{
					xend = xmid;
					yend = ymid;
				}
			}
			cout << fixed << setprecision(16) << xmid << ' ' << ymid;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	intersect(x1, y1, x2, y2, x3, y3, x4, y4);
	return 0;
}
