#include<algorithm>
#include<iostream>

using namespace std;

struct Node{
    int num;
    Node* l;
    Node* r;
};

void creat(Node* &p,int* count,int* num,int &numidx,int min,int max,int height,int countsum){
    if(numidx==countsum){
        p = NULL;
        return;
    }
    if(num[numidx]>=min&&num[numidx]<=max){
        p = new Node;
        p->num = num[numidx];
        //cout<<p->num;
        count[height]++;
        int idx = numidx;
        numidx++;
        creat(p->l,count,num,numidx,min,num[idx],height+1,countsum);
        creat(p->r,count,num,numidx,num[idx],max,height+1,countsum);
    }else{
        return;
    }
}

int main(){
    Node* head;
    Node* p = head;
    int count[20]={0};
    int num[] = {5,2,4,3,6};
    int numidx = 0;
    creat(head,count,num,numidx,2,6,0,5);
    int max = count[0];
    for(int i = 1;i<20;i++){
        if(count[i]>max)
        max = count[i];
    }
    for(int i = 0;i<20;i++){
        cout<<count[i]<<' ';
    }
    //cout<<head->r->num;
    return 0;
}
