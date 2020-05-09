#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
void sorting(int n, float ratio[], float p[],float w[])
{
int i=0,j=0;
float pivot;
for (i = 0; i < n; i++)
  {
      for (j = i + 1; j < n; j++)
	{
         if (ratio[i] < ratio[j])
	{
            pivot = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = pivot;

            pivot = w[j];
            w[j] = w[i];
            w[i] = pivot;

            pivot = p[j];
            p[j] = p[i];
            p[i] = pivot;
         }
       }
  }
}

float knapsack(int n, float w[], float p[],int capacity)
{
	int b[30]; 
	float result=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(w[i]<capacity)
		{
		   b[i]=w[i];
		   capacity=capacity-b[i];
		}
		else
		{
		   b[i]=capacity;
		   capacity=capacity-b[i];
		}
		result += (p[i]/w[i])*b[i];
		if(capacity==0)
            break;
	}
	return result;
}
int main(int argc, char *argv[])
 {
	FILE *fptr1;
	float a[100];
  	int capacity;
	int i=0,j=0,n=0;
	float temp;
  	capacity=atoi(argv[2]);
	if(argc!=3)
	{
		printf("Not enough arguements or more arguements");
		exit(0);
	}
	fptr1=fopen(argv[1],"r");
	if(fptr1==NULL)
	{
		printf("ERROR...\nCannot open file:%s\n",argv[1]);
		printf("Check filename once properly,Either filename is incorrect or it doesnot exixts");
		exit(0);
	}
	while( !feof(fptr1))
	{
		fscanf(fptr1,"%f",&temp);
		a[i]=temp;
		i++;
		n++;
	}
	fclose(fptr1);
	float p[n/2], w[n/2];
	float ratio[n/2];
	for(i=0;i<n/2;i++)
		p[i]=a[i];
	int k=0;
	for(i=n/2;i<n;i++)
	{
		w[k]=a[i];
		k++;
	}
	for(i=0;i<n/2;i++)
		ratio[i]=p[i]/w[i];
	
	sorting(n/2, ratio, p, w);
		
	printf("optimal solution is : %f",knapsack(n/2,w,p,capacity));
	return 0;
 }

