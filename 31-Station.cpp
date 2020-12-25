#include<iostream>
#include<math.h>
using namespace std;

int m,n,d;
typedef struct{
    double x;
    double y;
}Point;
Point p[10001];

typedef struct{
    double l;
    double r;
}Region;
Region r[10001];

int cmp_xy(const void *a , const void *b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if(p1->x != p2->x) {
        return p1->x - p2->x;
    }
    else {
        return p1->y - p2->y;
    }
}
/*
bool inCircle(Point p, double center){
    if((p.x-center)*(p.x-center) + p.y*p.y - d*d <= 1e-10) return true;
    else return false;
}*/

bool hasOverlap(double now_right,double r_left){
    if(r_left-now_right>=1e-10) return false;
    else return true;
}

double len(Point p){
    return sqrt(d*d-p.y*p.y);
}

int main(){
    cin>>m;
    for(int t=0;t<m;t++){
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        qsort(p,n,sizeof(Point),cmp_xy);
        for(int i=0;i<n;i++){
            double length = len(p[i]);
            r[i].l = p[i].x-length;
            r[i].r = p[i].x+length;
        }
        //int visit[10001]={0};
        int count=1;
        double now = r[0].r;
        for(int i=1;i<n;i++){
            if(!hasOverlap(now,r[i].l)){
                count++;
                now = r[i].r;
            }
            else if(r[i].r-now<1e-10){
                now=r[i].r;
            }
            /*
            if(visit[i]==0){
                count++;
                visit[i]=1;
                for(int j=i+1;j<n;j++){
                    if(inCircle(p[j],new_center)) visit[j]=1;
                    else break;
                }
            }*/
        }
        cout<<count<<endl;
    }
}