// CHECKSUM SENDER SIDE....
#include <stdio.h>
#include<string.h>

int main() {
    
   char dw[100];
   printf("enter the dataword: ");
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
       int databit=checksum[k];
       checksum[k]=(databit + (dw[i]-'0') + carry)%2;
       carry=(databit+(dw[i]-'0')+carry)/2;
       
        k++;
        k=k%size;
        
        if((k==0) && (carry == 1))
        {
            int temp=0;
            while(carry != 0)
            {
                int databit=checksum[temp];
                checksum[temp]=(databit + carry)%2;
                carry=(databit + carry)/2; 
                
                temp++;
                temp=temp%size;
            }
        }
   }
    
    for(int i=0; i<size; i++)
    {
        if(checksum[i] == 0)
        checksum[i]=1;
        else
        checksum[i]=0;
    }
    
    printf("the checksum generated for the above codeword is::");
    for(int i=size-1; i>=0; i--)
    {
       printf("%d",checksum[i]);
    }
    
    int dwlen=strlen(dw);
    char cw[dwlen+size];
    int sz=size-1;
    
    for(int i=0; i<(dwlen+size); i++)
    {
        if(i<strlen(dw))
        cw[i]=dw[i];
        else
        {
            char ch = checksum[sz]+'0';
            cw[i]=ch;
            sz--;
        }
    }
    
    printf("\nThe codeword for the dataword given is::");
    for(int i=0; i<(dwlen+size); i++)
    {
        printf(" %c",cw[i]);
    }

    return 0;
}
