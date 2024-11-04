#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
	float sum=0;
	for(int i=1;i<argc;i++){
		if(atof(argv[i])>0){
			sum+=atof(argv[i]);
		}
	}
	printf("Sum:%.1f",sum);
    /*int dem=0;
    if (argc>=2)
    {
        for (int i = 0; i < argc; i++)
        {
            if(atoi(argv[i])%2!=0) dem++;
        }
    }
    printf("DemLe:%d",dem);*/
}