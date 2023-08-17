#include <stdio.h>
#include <math.h>
char main_Data[100];
char Encoded[100];
int Odd_parity_Hamming(int a,int b)
{
int count=0,i,j;
i=a-1;
while(i<b)
{
for(j=i;j<i+a;j++)
{
if(Encoded[j] == '1')
count++;
}
i=i+2*a;
}
if(count%2 == 0)
return '0';
else
return '1';
}


void main()
{

    printf("\n\t\tWelcome to our Project\n");
    printf("\t-------------------------------------\n\n\n");
    int option1;
    printf("Do you want to secure your data?\n");
    printf("\t 1.Yes\t 2.No");
    printf("\n Enter your opinion: ");
    scanf("%d",&option1);

    if(option1 == 1){



int i=0,G=0,R=0,Z,j,k;
printf("\n\nEnter the hamming data in number: ");
scanf("%s", main_Data);
printf("\n");
while( main_Data[i]!='\0')
{
 G++;
 i++;
}
i=0;
while(G>(int)pow(2,i)-(i+1))
{
R++;
i++;
}

Z = R + G;

j=k=0;
for(i=0;i<Z;i++)
{
if(i==((int)pow(2,k)-1))
{
Encoded[i]=0;
k++;
}
else
{
Encoded[i]=main_Data[j];
j++;
}
}
for(i=0;i<R;i++)
{
int X = (int)pow(2,i);
int Y = Odd_parity_Hamming(X,Z);
Encoded[X-1]= Y;
}
printf("Encoded data of Hamming: %s",Encoded);
printf("\n");

 char a[100],c[100],E1[100];
    printf("\nEnter the main data to secure: ");
    scanf("%s",a);
    int r,s,Ro;
    strcpy(E1,a);
    i=0;
    r=0;
    while(a[i]!='\0'){
    a[i] =a[i]+1;
    i++;
    r++;
    }
    printf("\n\n\n\tAfter encryption: %s",a);

    char Output_1[100];

    i=0;
    j=0;

    while(a[i]!='\0')
    {
    if(a[i]=='O')
    {
    Output_1[j]='R';
    Output_1[j+1]='O';

    j+=2;
    i++;
    }
    else if(a[i]=='R')
    {
    Output_1[j]='R';
    Output_1[j+1]='R';

    j+=2;
    i++;
    }

    else
    {
    Output_1[j++]=a[i++];
    }

    }
    Output_1[j]='\0';

    printf("\n\n\tAfter bit stuffing : %s",Output_1);
    Ro = strlen(Output_1);

    i=0;
    while(Encoded[i]!='\0'){
    c[i]=Encoded[i];
    i++;
    }
    j=i;


    i=0;
    while(Output_1[i]!='\0'){
    c[j]=Output_1[i];
    i++;
    j++;
    }

    i=0;

    while(Encoded[i] != '\0' ){
    c[j]=Encoded[i];
    i++;
    j++;
    }
    printf("\n\nNow the full Stuffing: %s",c);


    char d[100],e[100];
    i=0;
    while(i<Ro)
    {
        d[i]=c[Z];
        i++;
        Z++;
    }
    d[i]='\0';

    printf("\n\n\n\tThe de-stuffing data is: %s",d);

    char Output_2[100];

    i= 0;
    j= 0;

    while(d[i]!='\0')
    {
    if(d[i]=='R' && (d[i+1]=='O'))
    {
    Output_2[j]='O';
    j++;
    i=i+2;
    }
    else if(d[i]=='R' && d[i+1]=='R')
    {
    Output_2[j]='R';
    j++;
    i=i+2;
    }

    else
    {
    Output_2[j++]=d[i++];
    }

    }
    Output_2[j]='\0';

    printf("\n\n\tAfter bit de-stuffing: %s",Output_2);

    i=0;
    while(Output_2[i]!='\0'){
    Output_2[i] =Output_2[i]-1;
    i++;
    }

    printf("\n\nNow the decryption data: %s",Output_2);
    printf("\n\n");

    int flag,option;

    printf("\nDo you want to error check?");
    printf("\n\t 1.Yes\t 2.No");
    printf("\n Enter your opinion: ");
    scanf("%d",&option);

if(option==1){
        i=0;
    while(Output_2[i]!='\0'){
        if(E1[i]== Output_2[i]){
            flag=1;
        }
        else{
            flag=0;
        }
        i++;
    }

    if(flag==1){
        printf("\nCongratulations, There are no error.");
    }
    else{
        printf("\nSorry, It has error.");
    }

}

else{
    printf("\n");
}

    printf("\n\n\n\t\tThank you\n");
    printf("\t-------------------------\n\n");


}

else{
    printf("\n");
}

}
