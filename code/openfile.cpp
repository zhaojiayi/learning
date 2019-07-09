#include<iostream>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

using namespace std;

int main(int argc, char *argv[]){
    if(argc!=2||strcmp(argv[1],"--help")==0){
        fprintf(stderr,"usage error");
        exit(1);
    }
    int input1,input2;
    input1 = open(argv[1],O_RDONLY);
    if(input1==-1){
        //perror("error occurs");
        cout<<strerror(errno);
        exit(EXIT_FAILURE);
    }
    close(input1);
    return 0;
}
