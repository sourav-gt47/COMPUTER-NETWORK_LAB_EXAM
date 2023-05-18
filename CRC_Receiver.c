#include <stdio.h>
#include<string.h>

int main() {
    char cw[100],data[100];
    printf("enter the codeword: ");
    gets(cw);
    strcpy(data,cw);
    
    char div[10];
    printf("enter the divisor/polynomial function: ");
    gets(div);
    
    int divlen=strlen(div);
    
    
    for(int i=0; i<strlen(cw); i++)
    {
        if(cw[i] == '1' && i<=(strlen(cw)-divlen))
        {
            int k=0;
            for(int j=i; j<i+divlen; j++)
            {
                if(cw[j] == '1' && div[k]=='1')
                cw[j]='0';
                else if(cw[j] == '0' && div[k]=='1')
                cw[j]='1';
                else if(cw[j] == '1' && div[k]=='0')
                cw[j]='1';
                else if(cw[j] == '0' && div[k]=='0')
                cw[j]='0';
                k++;
            }
        }
    }
    
   
  //check if any '1' is present in the codeword or not....
  // if '1' is present then wrong data is received.
  //if only '0' present in the codeword then original data is received. 

   int flag=0;
   for(int i=0;i<strlen(cw);i++){
       if(cw[i] == '1')
            flag=1;
 }


  if(flag==0){
      printf("Original data is received\n");
       for(int i=0; i<=(strlen(cw)- divlen);i++){
            printf("%c ", data[i]);

      }
  }

  else
   printf("Wrong data is received");


 return 0;

}