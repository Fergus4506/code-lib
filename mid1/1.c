#include<stdio.h>
int chBig(char* str,int n){
    int num=0,i=0;
    while(i<n){
        if(*(str+i)>='A' && *(str)<='Z')
            num+=1;
        i+=1;
    }
    return num;
}

int main(){
    char str[100];
    fgets(str,100,stdin);
    int n=sizeof(str)/sizeof(str[0]);
    if(n==0)
        printf("%d",n);
    else{
        int ans=chBig(&str[0],n);
        printf("%d",ans);
    }
    return 0;
}//11212