#include<iostream>
using namespace std;

int T;
int num_nations,num_edges,num_start,num_end,num_money;
int B[501];
int edges[501][501];
//int s[501];
//int top;
int min_dis;
int list[501][501];
/*
int push(int i) {
    s[top] = i;
    top++;
    return top;
}

int initstack() {
    top = 0;
}

int pop() {
    top--;
    return top;
}
*/
void DFS(int start,bool visit[],int bill,int distance){
    if(distance>min_dis) return;
    /*
    int list[1000];
    int len_list=0;
    for(int i=1;i<=num_nations;i++){
        if(edges[i][start]!=INT32_MAX && i!=start){
            list[len_list]=i;
            len_list++;
        }
    }*/

    visit[start] = true;
	//push(start);
    if(start!=num_start) bill+=B[start];
	
    for (int j=1;j<list[start][0];j++){
        if (start==num_end){
            /*
            int tmp_top=top;
            int dist=0;
			for (int i=0;i<tmp_top;i++) {
                if(i!=tmp_top-1) dist+=edges[s[i]][s[i+1]];
			}
            min_dis = (min_dis<dist)? min_dis:dist;
            */
           min_dis = distance;
			
            //pop();
			visit[start] = false;
			break;
		}
		if(!visit[list[start][j]]) {
            if(bill+B[list[start][j]]<=num_money){
                distance += edges[start][list[start][j]];
                DFS(list[start][j],visit,bill,distance);
            }
		}
		if(j==list[start][0]-1) {
		    //pop();
		    visit[start] = false;
            return;
		}
	}
}

int main(){
    cin>>T;

    for(int l=0;l<T;l++){
        scanf("%d %d %d %d %d",&num_nations,&num_edges,&num_start,&num_end,&num_money);
        //int B[501];
        //int edges[501][501];
        //for(int i=1;i<=num_nations;i++) B[i]=INT32_MAX;
        for(int i=1;i<=num_nations;i++){
            scanf("%d",&B[i]);
        }
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++) edges[i][j]=INT32_MAX;
        }

        for(int i=0;i<num_edges;i++){
            int start,end,weight;
            scanf("%d %d %d",&start,&end,&weight);
            if(edges[start][end]>weight) edges[start][end]=edges[end][start]=weight;
        }

        bool visit[501]={false};
        //initstack();
        min_dis = INT32_MAX;

        //list[start][0]存放结点start相邻的结点数量+1，len_list
        //list[start][1～len_list-1]存放结点start相邻的结点
        for(int start=1;start<=num_nations;start++){
            int len_list=1;
            for(int i=1;i<=num_nations;i++){
                if(edges[i][start]!=INT32_MAX && i!=start){
                    list[start][len_list]=i;
                    len_list++;
                }
            }
            list[start][0]=len_list;
        }


        DFS(num_start,visit,0,0);

        if(min_dis!=INT32_MAX) cout<<min_dis<<endl;
        else cout<<-1<<endl;
    }
}