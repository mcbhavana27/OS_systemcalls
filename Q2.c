#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include <errno.h>

int main(int arg, char* inputfiles[])
{
		const char* dir;
		dir=inputfiles[3];

    if(arg<4){
    write(1,"not sufficient\n",strlen("not sufficient\n"));
    return 0;
    }


  		struct stat sfile;
  		struct stat ffile;
  		struct stat tfile;
  		if(stat(inputfiles[2],&sfile)<0){
        write(1,"old file does not exist\n",strlen("old file does not exist\n"));
		    return 1;
      }
  		if(stat(inputfiles[1],&tfile) < 0){
        write(1,"new file does not exist\n",strlen("new file does not exist\n"));
		    return 1;
      }

		//sfile->newfile
		//tfile->Directory
		//ffile->oddfile
  if(stat(dir,&tfile)==0 && S_ISDIR(tfile.st_mode)){
    write(1,"Directory is created: Yes \n",strlen("Directory is created: Yes \n"));
  }
  else{
    write(1,"Directory is created: No \n",strlen("Directory is created: No \n"));
    return 0;
  }
  // for new files

  		write(1,"\nPermissions for New File\n\n",strlen("\nPermissions for New File\n\n"));
  //user
  		if((sfile.st_mode & S_IRUSR))
  		write(1,"User has read permissions on newfile : Yes\n" ,43);
  		else
  		write(1,"User has read permissions on newfile : No\n", 43);
  		if((sfile.st_mode & S_IWUSR) )
  		write(1,"User has write permissions on newfile : Yes\n" ,44);
  		else
  		write(1,"User has write permissions on newfile : No\n" ,44);
  		if((sfile.st_mode & S_IXUSR) )
  		write(1,"User has execute permissions on newfile:Yes\n", 47);
  		else
  		write(1,"User has execute permissions on newfile:No\n", 47);
  //group
  		if((sfile.st_mode & S_IRGRP) )
  		write(1,"Group has read permissions on newfile : Yes\n" ,44);
  		else
  		write(1,"Group has read permissions on newfile : No\n", 44);
  		if((sfile.st_mode & S_IWGRP) )
  		write(1,"Group has write permissions on newfile : Yes\n" ,45);
  		else
  		write(1,"Group has write permissions on newfile : No\n" ,45);
  		if((sfile.st_mode & S_IXGRP) )
  		write(1,"Group has execute permissions on newfile:Yes\n", 48);
  		else
  		write(1,"Group has execute permissions on newfile:No\n", 48);

 //others
  		if((sfile.st_mode & S_IROTH) )
  		write(1,"Others has read permissions on newfile : Yes\n" ,45);
  		else
  		write(1,"Others has read permissions on newfile : No\n", 45);
  		if((sfile.st_mode & S_IWOTH))
  		write(1,"Others has write permissions on newfile : Yes\n" ,48);
  		else
  		write(1,"Others has write permissions on newfile : No\n" ,48);
  		if((sfile.st_mode & S_IXOTH) )
  		write(1,"Others has execute permissions on newfile:Yes\n\n", 50);
  		else
  		write(1,"Others has execute permissions on newfile:No\n\n", 50);

// For old file
	write(1,"Permissions for Old file\n\n",strlen("Permissions for Old file\n\n"));

//user
	if((ffile.st_mode & S_IRUSR))
	write(1,"User has read permissions on old file: Yes \n",strlen("User has read permissions on old file: Yes \n"));
	else
	write(1,"User has read permissions on old file: No \n",strlen("User has read permissions on old file: No \n"));

	if((ffile.st_mode & S_IWUSR) )
	write(1,"User has write permissions on old file: Yes \n",strlen("User has write permissions on old file: Yes \n"));
	else
	write(1,"User has write permissions on old file: No \n",strlen("User has write permissions on old file: No \n"));

	if((ffile.st_mode & S_IXUSR))
	write(1,"User has execute permissions on old file: Yes \n",strlen("User has execute permissions on old file: Yes \n"));
	else
	write(1,"User has execute permissions on old file: No \n",strlen("User has execute permissions on old file: No \n"));

// group
	if((ffile.st_mode & S_IRGRP))
	write(1,"Group has read permissions on old file: Yes \n",strlen("Group has read permissions on old file: Yes \n"));
	else
	write(1,"Group has read permissions on old file: No \n",strlen("Group has read permissions on old file: Noo \n"));

	if((ffile.st_mode & S_IWGRP) )
	write(1,"Group has write permissions on old file: Yes \n",strlen("Group has write permissions on old file: Yes \n"));
	else
	write(1,"Group has write permissions on old file: No \n",strlen("Group has write permissions old file: No  \n"));

	if((ffile.st_mode & S_IXGRP))
	write(1,"\nGroup has execute permissions on old file: Yes \n",strlen("\nGroup has execute permissions on old file: Yes \n"));
	else
	write(1,"\nGroup has execute permissions on old file: No \n",strlen("\nGroup has execute permissions on old file: No \n"));

	// Others

	if((ffile.st_mode & S_IROTH))
	write(1,"Others has read permissions on old file: Yes \n",strlen("Others has read permissions on old file: Yes \n"));
	else
	write(1,"Others has read permissions on old file: No \n",strlen("Others has read permissions on old file: No \n"));

	if((ffile.st_mode & S_IWOTH) )
	write(1,"Others has write permissions on old file: Yes \n",strlen("Others has write permissions on old file: Yes \n"));
	else
	write(1,"Others has write permissions on old file: No \n",strlen("Others has write permissions on old file: No \n"));

	if((tfile.st_mode & S_IXOTH))
	write(1,"Others has execute permissions on old file: Yes \n",strlen("Others has execute permissions on old file: Yes \n"));
	else
	write(1,"Others has execute permissions on old file: No \n",strlen("Others has execute permissions on old file: No \n"));

//For Directory

	write(1,"\nPermissions for Directory\n\n",strlen("\nPermissions for Directory\n\n"));

	

//user
	if((tfile.st_mode & S_IRUSR))
	write(1,"User has read permissions on Directory: Yes \n",strlen("User has read permissions on Directory: Yes \n"));
	else
	write(1,"User has read permissions on Directory: No \n",strlen("User has read permissions on Directory: No \n"));

	if((tfile.st_mode & S_IWUSR))
	write(1,"User has write permissions on Directory: Yes \n",strlen("User has write permissions on Directory: Yes \n"));
	else
	write(1,"User has write permissions on Directory: No \n",strlen("User has write permissions on Directory: No \n"));

	if((tfile.st_mode & S_IXUSR))
	write(1,"User has execute permissions on Directory: Yes \n",strlen("User has execute permissions on Directory: Yes \n"));
	else
	write(1,"User has execute permissions on Directory: No \n",strlen("User has execute permissions on Directory: No \n"));

// group
	if((tfile.st_mode & S_IRGRP))
	write(1,"Group has read permissions on Directory: Yes \n",strlen("Group has read permissions on Directory: Yes \n"));
	else
	write(1,"Group has read permissions on Directory: No \n",strlen("Group has read permissions on Directory: No \n"));

	if((tfile.st_mode & S_IWGRP))
	write(1,"Group has write permissions on Directory: Yes \n",strlen("Group has write permissions on Directory: Yes \n"));
	else
	write(1,"Group has write permissions on Directory: No \n",strlen("Group has write permissions on Directory: No \n"));

	if((tfile.st_mode & S_IXGRP))
	write(1,"Group has execute permissions on Directory: Yes \n",strlen("Group has execute permissions on Directory: Yes \n"));
	else
	write(1,"Group has execute permissions on Directory: No \n",strlen("Group has execute permissions on Directory: No \n"));

// Others

	if((tfile.st_mode & S_IROTH))
	write(1,"Others has read permissions on Directory: Yes \n",strlen("Others has read permissions on Directory: Yes \n"));
	else
	write(1,"Others has read permissions on Directory: No \n",strlen("Others has read permissions on Directory: No \n"));

	if((tfile.st_mode & S_IWOTH))
	write(1,"Others has write permissions on Directory: Yes \n",strlen("Others has write permissions on Directory: Yes \n"));
	else
	write(1,"Others has write permissions on Directory: No \n",strlen("Others has write permissions on Directory: No \n"));

	if((tfile.st_mode & S_IXOTH))
	write(1,"Others has execute permissions on Directory: Yes \n",strlen("Others has execute permissions on Directory: Yes \n"));
	else
	write(1,"Others has execute permissions on Directory: No \n",strlen("Others has execute permissions on Directory: No \n"));

//  check the reverse the file

	write(1,"\nChecking whether given two files are reverse of one other\n",strlen("\nChecking whether given two files are reverse of one other\n"));

	int old=open(inputfiles[1],O_RDONLY);
	int new=open(inputfiles[2],O_RDONLY);
	long long int start,end,cnt,m,n;
	char *newdata=(char *)calloc(1000000,sizeof(char));
  char *olddata = (char *) calloc(1000000, sizeof(char));
    end=cnt=lseek(old,0,SEEK_END);
    start=lseek(new,0,SEEK_END);
    long long int flag=0;
    n=cnt/1000000;
    m=cnt%1000000;
    long long int i,j,k;
    	if(start!=end)
    	{
    		flag=1;
   		}
   		else
   		{
   				n=cnt/1000000;
    			for(i=0;i<n;i++)
    			{
    				//printf("a..");

    				lseek(new,1000000*i,SEEK_SET);
    				read(new,newdata,1000000);
    				lseek(old,(-1000000)*(i+1),SEEK_END);
    				read(old,olddata,1000000);
    				for(j=0;j<1000000;j++)
    				{
    					if(newdata[j]!= olddata[1000000-j-1])
    					{
    						flag=1;
    						printf("j: %lld",j);
    						break;
    					}
    				}
    			}
    			lseek(old,0,SEEK_SET);
    			lseek(new,-m,SEEK_END);
    			read(new,newdata,m);
    			read(old,olddata,m);
    			for(k=0;k<m;k++)
    			{
    				//printf("b..");
      				if(newdata[k]!=olddata[m-k-1])
    				{
    					flag=1;
    					printf("k: %lld\n",k);
    					break;
    				}
    			}
    			free(newdata);
    			free(olddata);
    	}

    if(flag==1){
      write(1,"No\n",3);
    }
    else{
      write(1,"Yes\n",4);
    }

}
