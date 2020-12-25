#include<iostream>
using namespace std;

int M;
struct Point{
    int color;
    int idx;
};

Point stack[20002];
int top;

int push(Point i) {
    stack[top].color = i.color;
    stack[top].idx = i.idx;
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

bool isPair(){
    if(stack[top-1].color!=stack[top-2].color) return true;
    else return false;
}

bool can_compare(){
    if(top>=2) return true;
    else return false;
}

int main(){
    cin>>M;
    for(int t=0;t<M;t++){
        int n;
        cin>>n;
        Point p[20002];
        for(int i=1;i<=2*n;i++){
            cin>>p[i].color;
            p[i].idx=i;
        }
        initstack();
        //push(p[1]);
        int res=0;
        for(int i=1;i<=2*n;i++){
            push(p[i]);
            if(can_compare()){
                if(isPair()){
                    int temp = abs(stack[top-1].idx-stack[top-2].idx);
                    pop();
                    pop();
                    res += temp;
                }
            }
        }
        cout<<res<<endl;
    }
}