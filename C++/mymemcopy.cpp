#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
 
void myMemCpy(void *dest, void *src, int n)
{
cout<<n<<endl;
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
 
   char *temp = new char[n];

   for (int i=0; i<n; i++){
       temp[i] = csrc[i];
     }
 
   for (int i=0; i<n; i++)
       cdest[i] = temp[i];
}
 
int main()
{
   /*char csrc[] = "GeeksforGeeks";
   char cdest[100];
   myMemCpy(cdest, csrc, strlen(csrc)+1);
   printf("Copied string is %s", cdest);*/
 
   int isrc[] = {1, 2};
   int n = sizeof(isrc)/sizeof(isrc[0]);
   cout<<n<<endl;
   int idest[n], i;
   cout<<"address of source in main: "<<(int)isrc<<endl;
   cout<<"address of destination in main: "<<(int)idest<<endl;
    
   myMemCpy(idest, isrc,  sizeof(isrc));
   printf("\nCopied array is ");
   for (i=0; i<n; i++)
     printf("%d ", idest[i]);
   return 0;
}