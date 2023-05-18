#include <stdio.h>
#include<string.h>
#include<math.h>

int main() {
    
    char input[100];
    printf("Enter the codeword: ");
    gets(input);
    
    char cw[100];
    int j=0;
    for(int i=strlen(input)-1; i>=0; i--)
    {
        cw[j++]=input[i];
    }
    
    int r=0;
    int cwlen=strlen(cw);
    int i=0;
    
    while(r<=cwlen)
    {
        r=pow(2,i++);
    }
    
    r=i-1;
    
    printf("\n Number of redundant bits are : %d\n", r);
    
    char error[r];
    for(int i=0; i<r; i++)
    {
        int c=0;
        int skip=pow(2,i);
        for(int j=skip; j<=strlen(cw); j=(j+(2*skip)))
        {
            for(int k=j; k<(j+skip); k++)
            {
                if(cw[k-1] == '1')
                c++;
            }
        }
        if(c%2 == 0)
        error[i]='0';
        else
        error[i]='1';
    }
    
    int position=0;
    for(int i=0; i<r; i++)
    {
        position+=((pow(2,i))*(error[i]-'0'));
    }
    
    if(position){
    printf("\nerror at position %d\n",position);
    printf("\n corrected codeword is\n");
    if(cw[position-1]=='0')
    cw[position-1]='1';
    else
    cw[position-1]='0';
    
    for(int i=strlen(cw)-1; i>=0; i--){
       if(cw[i]=='1' || cw[i]=='0')
         printf("%c",cw[i]);
    }
}
    else
    {
        printf("\nthe recieved codeword is correct\n");
    }
}