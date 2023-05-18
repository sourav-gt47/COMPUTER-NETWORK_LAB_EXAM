#include <stdio.h>
#include<string.h>
#include<math.h>

//2^r >= (r+m+1);
 

int main() {
    
    char dw[100];
    printf("Enter the dataword: ");
    gets(dw);
    
    int r=0;
    int dwlen=strlen(dw);
    
    while(pow(2,r) < (r+dwlen+1)){
       r++;
    }

    printf("Number of redundant bits are::%d", r);

    char cw[dwlen+r];

    for(int i=0;i<r;i++){
   
     int power=pow(2,i);
     cw[power-1]='9';

    }
    
    int j=0;

    for(int i=(dwlen+r-1);i>=0;i--){
         if(cw[i] != '9')
          cw[i] = dw[j++];
    }
  
    
   //puts(cw);
   
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
        cw[skip-1]='0';
        else
        cw[skip-1]='1';
    }
 
    printf("\nThe codeword generated is::");
    for(int i=strlen(cw)-1; i>=0; i--){
       if(cw[i]=='1' || cw[i]=='0')
         printf("%c",cw[i]);

    }
   

    return 0;
}