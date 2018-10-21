#include <stdio.h>
#include <stdlib.h>
    #include <unistd.h>
 #include <math.h>   
int main()
{
    int x, space, rows, z=0,val,sp,sb,y,n;
    int lisz[]={'A', '0', 'B', '0', '0', 'C' , 'D'  };
     n = sizeof(lisz);
     n = n/sizeof(int);
    //printf("size is : %d\n",n);
    sp = n;
    sb=n;
    rows = floor(n/2);
    //printf("%d",rows);
    for(x=1; x<=rows; x++)
    {
        
        int nd=pow(2,(x-1));
        
      for(val=1;val<=nd;val++){
          
      if(val==1){
           sp = sp/2;
        for(y=1;y<=sp;y++){
            printf("*");
            
        }
       }
       
       else{
           sb = n/((x-1)*2);
           for(y=1;y<=sb;y++){
            printf(" ");
            }
            sb=n;
       }
       if(lisz[z]!='0'){
        printf("%c",lisz[z++]);
       }
        else{
        printf(" ");
        z++;
        }
      }
      printf("\n");
    }
    return 0;
}

