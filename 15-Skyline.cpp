#include<iostream>
#include<vector>
#include<math.h>
#include<set>
using namespace std;

int N;

struct Build{
    int left;
    int right;
    int h;
};

struct Point{
    int x;
    int h;
};

Build a[50001];
vector<Point> res;

int main(){
    cin>>N;
    for(int j=0;j<N;j++) cin>>a[j].left>>a[j].right>>a[j].h;
    multiset<pair<int,int> > all;
    for(int j=0;j<N;j++){
        all.insert(make_pair(a[j].left,-a[j].h)); 
        //对muliset遍历时，首先会取出横坐标小的点。如果2个点横坐标相等，会先取出second小的点
        //对于负数来说，其实就是高度更高的建筑
        all.insert(make_pair(a[j].right,a[j].h));
    }

    multiset<int> heights; // 保存当前位置所有高度。
    heights.insert(0);
    Point last; // 上一个位置的横坐标以及高度
    last.x = 0;
    last.h = 0;
    for (auto& p : all) {
        if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
        else heights.erase(heights.find(p.second)); // 右端点，高度出堆            
        
        auto maxHeight = *heights.rbegin();
            
        // 当前最大高度如果不同于上一个高度，说明这是一个转折点
        if (last.h != maxHeight) {
            // 更新last，并加入结果集
            last.x = p.first;
            last.h = maxHeight;
            res.push_back(last);
        }
    }

    for(int i=0;i<res.size();i++) cout<<res[i].x<<" "<<res[i].h<<endl;
}