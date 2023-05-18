#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
 char str[100];
 printf("Enter codeword sent by sender::");
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
       printf("No error");
       int size=strlen(str);
       str[size-1]='\0';
       printf("\nDataword::%s",str);
    }

   else{
       
       printf("Error");
   }
 
  break;
 

 case 'o': 
  if(count % 2 == 0)
    {
       printf("Error");
    }

   else{
       printf("No error");
       int size=strlen(str);
       str[size-1]='\0';
       printf("\nDataword::%s",str);
   }

  break;

}

   return 0;
}