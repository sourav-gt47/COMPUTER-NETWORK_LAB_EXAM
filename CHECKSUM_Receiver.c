#include <stdio.h>
#include<string.h>
int main() {
    
   char dw[100];
   printf("enter the codeword: ");
   gets(dw);
   
   int size;
   printf("enter the segment size: ");
   scanf("%d",&size);
   
   if(size & (size-1) != 0) {
	printf("Invalid segment length\n");
	 return 0;
	}
   
   int checksum[size];
   for(int i=0; i<size; i++)
      checksum[i]=0;
   
   int sum=0;
   int carry=0;
   int k=0;
   for(int i=strlen(dw)-1; i>=0; i--)
   {  
       int d = checksum[k];
       checksum[k]=(d + (dw[i]-'0') + carry)%2;
       carry=(d + (dw[i]-'0') + carry)/2;
       
        k++;
        k=k%size;
        
        if((k==0) && (carry == 1))
        {
            int temp=0;
            while(carry != 0)
            {
                int d = checksum[temp];  
                checksum[temp]=(d + carry)%2;
                carry=(d + carry)/2; 
                
                temp++;
                temp=temp%size;
            }
        }
   }
    //1's complement of checksum..

    for(int i=0; i<size; i++)
    {
        if(checksum[i] == 0)
        checksum[i]=1;
        else
        checksum[i]=0;
    }
    
    int counter=0;
    printf("the checksum generated for the above codeword is::");
    for(int i=size-1; i>=0; i--)
    {
        if(checksum[i] != 0)
           counter++;
       printf("%d",checksum[i]);
    }
    
    if(counter == 0){
      printf("\nACCCEPTED");
      for(int i=0;i<strlen(dw)-size;i++){
          printf("%c ",dw[i]);
  }
}
    else{ 
        printf("\nNOT_ACCEPTED");
     }

    return 0;
}