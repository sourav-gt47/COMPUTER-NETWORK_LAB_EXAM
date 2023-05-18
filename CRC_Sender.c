#include<stdio.h>
#include<string.h>

int main(){

char dw[100], div[100];
printf("Dataword::");
scanf("%s",&dw); // gets(dw)


printf("Coefficients of generator polynomial::");
scanf("%s",&div);

int dw_len = strlen(dw);
int div_len = strlen(div);

int i=0;
char cw[100];
while(i < (dw_len + div_len)-1){
  
  if(i < dw_len)
    cw[i] = dw[i];
  else
    cw[i] = '0';
 i++;
}
cw[dw_len+div_len-1] = '\0';

printf("\nUpdated divident::%s",cw);

int k=0;
for(int i=0;i<strlen(cw);i++){
    
    if(cw[i]=='1' && i<=(strlen(cw)-div_len))
      {
           k=0;
           for(int j=i;j<i+div_len;j++){

                  if(cw[j]=='0' && div[k]=='0')
                    cw[j]='0';
                
                  else  if(cw[j]=='1' && div[k]=='0')
                    cw[j]='1';

                  else if(cw[j]=='0' && div[k]=='1')
                    cw[j]='1';

                  else if(cw[j]=='1' && div[k]=='1')
                    cw[j]='0';

                   k++;
           }

      }

}
 int l=0 ;
 char crc[10];
 
  for(int i=0;i<strlen(cw);i++)
  {
    if(i<dw_len)
     cw[i] = dw[i];

    else
    crc[l++]=cw[i];       
  }
  crc[l]='\0';

printf("\nThe codeword is::%s",cw);
printf("\nThe crc bit's are::%s",crc);
return 0;

}