#include<stdio.h>
// int chBig(char* str,int n){
//     int num=0,i=0;
//     while(i<n){
//         if(*(str+i)>='A' && *(str+i)<='Z')
//             num+=1;
//         i+=1;
//     }
//     return num;
// }

// int chBig(char* str,int n){
//     int num=0;
//     for(int i=0;i<n;i++){
//         if(*(str+i)>='A' && *(str+i)<='Z')
//             num+=1;
//     }
//     return num;
// }

int chBig(char* str,int n){
    if(*(str)=='\0')
        return 0;
    if(*(str)>='A' && *(str)<='Z')
        return chBig(str+1,n)+1;
    else
        return chBig(str+1,n);
}

int main(){
    /*char str[100];
    fgets(str,100,stdin);*/
    char str[]="AAAA123456afdadA";
    int n=sizeof(str)/sizeof(str[0]);
    if(n==0)
        printf("%d",n);
    else{
        int ans=chBig(&str[0],n);
        printf("%d",ans);
    }
    return 0;
}