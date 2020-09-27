#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char path1[100];
	DIR *dirp = opendir("/proc/");
	struct dirent *d;
	printf("%6s %30s %6s%6s\n","PID","COMMAND","PPID","STATE");
	
	while(d=readdir(dirp))
	{	
		if(!(strcmp(d->d_name,".") && strcmp(d->d_name,"..")))
			continue;
		if(d->d_type != DT_DIR)
			continue;
	
		// path generation		
		strcpy(path1,"/proc/");
		strcat(path1,d->d_name);
		strcat(path1,"/stat");
		
		FILE *fp = fopen(path1,"r");
		if(fp==NULL)
			continue;
		
		int pid;
		char cmd[100];
		char state;
		int ppid;
		char state1[20];
		
		switch(state)
		{
			case 'R': strcpy(state1,"Running");
						break;
			case 'S': strcpy(state1,"Intr Wait");
						break;
			case 'D': strcpy(state1,"Unintr wait");
						break;
			case 'Z': strcpy(state1,"Zombie");
						break;
			case 'T': strcpy(state1,"Traced");
						break;
			default: strcpy(state1,"Paging");					
		}
		
		fscanf(fp,"%d\t%s\t%c\t%d",&pid,cmd,&state,&ppid);
		
		printf("%6d %30s ",pid,cmd);
		
		if(argc==2)
		{
			if(!strcmp(argv[1],"--more"))
				printf("%6d %13s",ppid,state1);
		}
		
		printf("\n");
		fclose(fp);
	}
	return 0;
}
