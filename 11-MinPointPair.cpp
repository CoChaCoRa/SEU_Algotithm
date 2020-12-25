#include<iostream>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

typedef struct{
    int x;
    int y;
}Point;
Point pos[50001],tpos[50001];
int M,N;

double dist(Point p1, Point p2){
    return sqrt(pow(p1.x - p2.x,2)+pow(p1.y-p2.y,2));
}

int cmp_y(const void *a , const void *b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->y - p2->y;
}

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

double divide(int left,int right){

    if(left>=right) return INT64_MAX;
    if(left+1 == right) {
        return dist(pos[left], pos[right]);
    }
    int mid = (left+right)/2;
    double mid_x = pos[mid].x;

    double dis_min = min(divide(left,mid),divide(mid+1,right));

    int idx=0;
    for(int i=left;i<=right;i++){
        if(fabs(mid_x-pos[i].x)<dis_min) {
            tpos[idx].x=pos[i].x;
            tpos[idx].y=pos[i].y;
            idx++;
        }
    }
    qsort(tpos,idx,sizeof(Point),cmp_y);
    for(int i=0;i<idx;i++){
        for(int j=i+1;j<idx;j++){
            dis_min = min(dis_min,dist(tpos[i],tpos[j]));
        }
    }
    return dis_min;
}

int main(){
    cin>>M;
    cin.get();

    for(int i=0;i<M;i++){
        cin>>N;
        for(int j=0;j<N;j++) cin>>pos[j].x>>pos[j].y;
        //for(int j=0;j<N;j++) cout<<pos[j].x<<pos[j].y<<endl;
        qsort(pos,N,sizeof(Point),cmp_xy);
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<divide(0,N-1)<<endl;
    }
}