#include"stdio.h"
#include"string.h"
#include<vector>
#include<iostream>

using namespace std;

struct Node
{
    char name[20];
    int grade;
}node[100];


int main(){
    FILE *io;
    io  = fopen("data.txt","r");
    int count = 0;
    while(feof(io)){
        fscanf(io,"%s%d",node[count].name,node[count].grade);
        count++;
    }
    fclose(io);
    for(int j = 0;j<count;j++){
        int first = j;
        for(int k = j;k<count;k++){
            if(node[k].name[0]<node[first].name[0]){
                first = k;
            }
        }
        if(first!=j){
        char tmp1[20];
        int tmp2;
        strcpy(tmp1,node[first].name);
        tmp2 = node[first].grade;
        strcpy(node[first].name,node[j].name);
        node[first].grade = node[j].grade;
        strcpy(node[j].name,tmp1);
        node[j].grade = tmp2;
        }
    }
    io = fopen("student.txt","w");
    for(int i = 0;i<count;i++){
        fprintf(io,"%s %d\n",node[i].name,node[i].grade);
    }
    fclose(io);
    return 0;
}