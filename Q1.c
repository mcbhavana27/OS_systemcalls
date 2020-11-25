#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include<errno.h>

int main(int argc,char *argv[])
{

    long long int fi,wf,n,cre;
    fi = open(argv[1], O_RDONLY);
    // the file created have the read and write permissions for the user...
    if(argc<2){
        write(1,"not sufficient\n",strlen("not sufficient\n"));
        return 0;
    }
    if(fi==-1)
    {
        write(1,"No file\n",strlen("No file\n"));
    }
    char b[100]="Assignment/";
    strcat(b,argv[1]);
   // directory created have read, write,execute permissions for user...
    cre= mkdir("Assignment",0700);
    wf = open(b,  O_CREAT | O_RDWR |O_APPEND , 0600);
    long long int s,l,rs,cnt,m,k;
    //char data[100000000];
    //char reversedata[100000000];
    cnt= lseek(fi, 0 , SEEK_END);
    n=cnt/1000000;
    m=cnt%1000000;
    k=-1000000; 
    long int j=1;
    long int i=0;
    long int pe=0;
    while(j<=n)
    {
            char *data=(char *)calloc(1000000,sizeof(char));
            char *reversedata = (char *) calloc(1000000, sizeof(char)); 
            l = lseek(fi, k*j , SEEK_END);
            //printf("%lld\n",l);
            read(fi, data, 1000000);
            for(i=0;i<1000000;i++)
            {
                pe++;
                reversedata[i] = data[1000000-i-1];
                //printf("%c",reversedata[i]);
            }
            write(wf, reversedata, 1000000);
            free(data);
            free(reversedata);
            j++;
            float p=((float)(pe)/(float)cnt)*100;
            char per[50];
            sprintf(per,"%.2f%%",p);
            write(1,"\r",strlen("\r"));
            write(1,per,strlen(per));
            fflush(stdout);
    }
    char *data=(char *)calloc(100000000,sizeof(char));
    char *reversedata = (char *) calloc(100000000, sizeof(char));
    long long int x;
    x= lseek(fi, 0 , SEEK_SET);
   // printf("%lld\n",x);
    read(fi,data,m);
    for(int j=0;j<m;j++)
    {
        pe++;
        reversedata[j] = data[m-j-1];
    }
    //printf("%s\n",data);
    //printf("%s\n",reversedata );
    write(wf, reversedata, strlen(reversedata));
    float p=((float)(pe)/(float)cnt)*100;
    char per[50];
   // write(1,"Progress----",strlen("Progress----"));
    sprintf(per,"%.2f%%",p);
    write(1,"\r",strlen("\r"));
    write(1,per,strlen(per));
    fflush(stdout);
    free(data);
    free(reversedata);
    close(fi);
    close(wf);

    int st;
    char* str=argv[1];
    int len=strlen(argv[1]);
   

   //Renaming reverse file
    
//  printf("%s\n",arr2);
    return 0;
}
