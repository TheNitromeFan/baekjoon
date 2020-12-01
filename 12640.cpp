#include <cstdio>
#include <cmath>

double norm(double x, double y, double z){
	return sqrt(x * x + y * y + z * z);
}

double inner(double x1, double y1, double z1, double x2, double y2, double z2){
	return x1 * x2 + y1 * y2 + z1 * z2;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		double mx = 0, my = 0, mz = 0, vx = 0, vy = 0, vz = 0;
		for(int i = 0; i < n; ++i){
			int x, y, z, vix, viy, viz;
			scanf("%d %d %d %d %d %d", &x, &y, &z, &vix, &viy, &viz);
			mx += x;
			my += y;
			mz += z;
			vx += vix;
			vy += viy;
			vz += viz;
		}
		mx /= n;
		my /= n;
		mz /= n;
		vx /= n;
		vy /= n;
		vz /= n;
		printf("Case #%d: ", a0);
		if(vx == 0 && vy == 0 && vz == 0){
			printf("%.8lf 0.00000000\n", norm(mx, my, mz));
			continue;
		}
		double m1x = mx + vx, m1y = my + vy, m1z = mz + vz;
		double d = norm(my * m1z - mz * m1y, mz * m1x - mx * m1z, mx * m1y - my * m1x) / norm(m1x - mx, m1y - my, m1z - mz);
		double t = -inner(mx, my, mz, m1x - mx, m1y - my, m1z - mz) / inner(m1x - mx, m1y - my, m1z - mz, m1x - mx, m1y - my, m1z - mz);
		printf("%.8lf %.8lf\n", d, t);
	}
	return 0;
}
