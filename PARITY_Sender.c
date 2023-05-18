#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
 char str[100];
 printf("Enter dataword::");
 gets(str);


int i=0,count=0;
 while(str[i]!='\0'){
   if(str[i] == '1')
     count++;
     i++;
 }
 char ch; 
 printf("Enter the mode of parity 'e' for even 'o' for odd::");
 scanf("%c",&ch);


switch(ch){

 case 'e': 
  if(count % 2 == 0)
    {
      strcat(str,"0");
    }

   else{
       
       strcat(str,"1");
   }
  printf("Even parity codeword:: %s",str);
  break;
 

 case 'o': 
  if(count % 2 == 0)
    {
      strcat(str,"1");
    }

   else{
       
       strcat(str,"0");
   }
  printf("Odd parity codeword:: %s",str);
  break;

}

   return 0;
}