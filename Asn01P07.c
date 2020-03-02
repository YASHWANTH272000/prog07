//Team, Yashwanth.K and Vinod malali 
/*Question 7:Given N number of DOB,identify the pair of dates which are closest to each other.there can be more than one such pair. 
Instruction:first enter how many dates you should enter and then enter the dates any order
example:Enter the number of dates
	5
	enter the dates
	03
	04
	2020
	02
	03
	2020
	25
	2
	1995
	16
	8
	2002
	27
	03
	2020
	3-4-2020 and 27-3-2020
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
int dater(int);
struct people
{
  int d,m,y;
};

void main()
{
struct people *D;

int i,j,k,z,min,ref,dd1,dd2,temp=999999,ld,lm,ly,ld1,lm1,ly1;
char last,last1;
printf("enter the number of dates\n");
scanf("%d",&z);
D=malloc(sizeof(struct people)*z);
printf("enter the dates\n");
for(int n=0;n<z;n++)
{ 
   scanf("%d%d%d",&D[n].d,&D[n].m,&D[n].y);
}
for(i=0;i<(z-1);i++)
{
   for(j=1;j<=(z-1);j++)
 {  
    ref=D[i].y;
    if(D[j].y<D[i].y)
     ref=D[j].y;
dd1=0;
dd1=dater(D[i].m);
for(k=ref;k<D[i].y;k++)
{
    if(k%4==0)
 dd1+=1;
}
dd1=dd1+D[i].d+(D[i].y-ref)*365;
dd2=0;
dd2=dater(D[j].m);
  for(k=ref;k<D[j].y;k++)
{
    if(k%4==0)
 dd2+=1;
}
dd2=dd2+D[j].d+((D[j].y-ref)*365);
min=abs(dd2-dd1);
if(min!=0&&min<temp)
 {
  temp=min;
 ld=D[i].d;
 lm=D[i].m;
 ly=D[i].y;
 ld1=D[j].d;
 lm1=D[j].m;
 ly1=D[j].y;
//printf("%d-%d-%d and %d-%d-%d\n",ld,lm,ly,ld1,lm1,ly1);
}
}
j=0;
}
printf("%d-%d-%d and %d-%d-%d\n",ld,lm,ly,ld1,lm1,ly1);
}
int dater(x)
{
int y=0;
switch(x)
{
case 1:y=0;break;
case 2:y=31;break;
case 3:y=59;break;
case 4:y=90;break;
case 5:y=120;break;
case 6:y=151;break;
case 7:y=181;break;
case 8:y=212;break;
case 9:y=243;break;
case 10:y=273;break;
case 11:y=304;break;
case 12:y=334;break;
default:printf("invalid input\n");
exit(1);
}
return(y);
}     
