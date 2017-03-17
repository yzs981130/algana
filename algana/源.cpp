#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 200010
struct Point
{
	double x, y;
	bool t;
	void rotate(double r)
	{
		double X = x, Y = y; 
		x = cos(r) * X + sin(r) * Y; 
		y = cos(r) * Y - sin(r) * X;
	}
}p[MAXN];

bool cmp(const Point &a,const Point &b)
{
	return a.x < b.x; 
}
double calc(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main()
{
	int t;
	cin >> t;
	double rd = rand(); 
	while(t--)
	{
		int n;
		cin >> n;
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		for (int i = 0; i < n; i++)
		{	
			scanf("%lf %lf", &p[i + n].x, &p[i + n].y);
			p[n + i].t = true;
		}

		for (int i = 0; i < 2 * n; ++i) p[i].rotate(rd);
		sort(p, p + 2 * n, cmp);

		double ans = 1e100 ; 
		for(int i = 0 ; i < 2 * n ; ++ i)
			for(int j = i + 1 ; j < 2 * n ; ++ j)
			{
				if (p[j].x - p[i].x > ans)
					break; 
				if (p[j].t ^ p[i].t)
					ans = min(ans, calc(p[j], p[i]));
			}
		printf("%.3lf\n", ans);
	}
	system("pause");
	return 0;
}