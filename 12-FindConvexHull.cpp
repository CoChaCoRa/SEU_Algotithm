#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

int M,N;

struct Point
{
	int x;
	int y;
}p[10000];

//计算叉积，小于0说明p1在p2的逆时针方向(右边)，即p0p1的极角大于p0p2的极角
double cross_product(Point p0, Point p1, Point p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

//计算距离
double dis(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

bool com(const Point &p1, const Point &p2)
{
	double temp = cross_product(p[0], p1, p2);
	if (fabs(temp) < 1e-6)
    {
        return dis(p[0], p1) < dis(p[0], p2);
    }
	else
    {
        return temp > 0;
    }
}

vector<Point> graham_scan(int n)
{
	vector<Point> ch;
	int top = 2;
	int index = 0;
	for (int i = 1; i < n; ++i)
	{
		if (p[i].y < p[index].y || (p[i].y == p[index].y && p[i].x < p[index].x))
		{
			index = i;
		}
	}
	swap(p[0], p[index]);
	ch.push_back(p[0]);

	sort(p + 1, p + n, com);
	ch.push_back(p[1]);
	ch.push_back(p[2]);
	for (int i = 3; i < n; ++i)
	{
		while (top > 0 && cross_product(ch[top - 1], p[i], ch[top]) >= 0)
		{
			--top;
			ch.pop_back();
		}
		ch.push_back(p[i]);
		++top;
	}
	return ch;
}

int isonline(Point p0, Point p1, Point p2) {
    if((p1.y-p0.y)*(p2.x-p0.x)==(p2.y-p0.y)*(p1.x-p0.x)) {
        return 1;
    }
    return 0;
}


int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>p[j].x>>p[j].y;
        }
        //for(int j=0;j<N;j++) cout<<p[j].x<<p[j].y<<endl;
        vector<Point> res = graham_scan(N);

        for(int j=0;j<res.size()-2;j++){
            if(isonline(res[j],res[j+1],res[j+2])){
                res.erase (res.begin()+j+1);
            }
        }
        cout<<"case "<<i+1<<":"<<endl;
        for(int j=0;j<res.size();j++){
            cout<<res[j].x<<" "<<res[j].y<<endl;
        }
        
    }
}

