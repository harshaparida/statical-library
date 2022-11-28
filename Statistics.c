#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float individual(float data[],int n);
float Descrete(float a[],int b[],int n);
float continous(float low[],float up[],int f[],int n);







float main(){

    
    int value,n,i,b[50],f[50];
    float data[50],a[50],up[50],low[50];
    printf("Enter 0 for Individual data series\n");
    printf("Enter 1 for Descrete data series\n");
    printf("Enter 2 for continous data series\n");
    scanf("%d",&value);

    
        
    

    if(value==0){


      
        printf("Enter the size of the data\n");
        scanf("%d",&n);

        printf("Enter the values of the data:\n");
       
        for(i=0;i<n;i++){
                 scanf("%f",&data[i]);
        }   

        individual(data,n);   
       
    };

    if(value==1){

        printf("Enter the size of the data table:\n");
        scanf("%d",&n);


        printf("Enter the data values:\n");
        for(i=0;i<n;i++){
            scanf("%f",&a[i]);
        }
        printf("Enter the corresponding frequencies:\n");

        for(i=0;i<n;i++){
           
            scanf("%d",&b[i]);

        
        
        }

         Descrete(a,b,n);
       
    
        
    };

    if(value==2){

        printf("Enter the size of the data:\n");
        scanf("%d",&n);

        printf("Enter the lower limit values:\n");

        for(i=0;i<n;i++){

            scanf("%f",&low[i]);

        }

        printf("\nEnter the upper limit values:\n");

        for(i=0;i<n;i++){

            scanf("%f",&up[i]);

        }

        printf("Enter the corresponding frequencies:\n");
        for(i=0;i<n;i++){

            scanf("%d",&f[i]);

        }
        continous(low,up,f,n);
    };

        
    

}

        
        

       




    

   
        
/*Individual Data Series*/

    float individual(float data[],int n){

    

    int i,j,k,m;     
    float mean,sum=0,s,median,t,mode=0,max=0,variance,std_devi,sum1=0;
    
    
    float x[n],temp[n];
    

    

    
    
    /*COMPUTE MEAN*/
    for(i=0;i<n;i++){
        sum=sum+data[i];
    }
    mean=sum/n;

    printf("Data\n");

    for(i=0;i<n;i++){

         printf("%f\n",data[i]);
    }
    printf("\nThe sum is:%f\n",sum);

    printf("\nThe mean is:%f\n",mean);
    /*MEAN COMPUTATION ENDS*/

   

     
    
    
 
    /*BUBBLE-SORT ALGORITHIM USED HERE*/ 
        
    for(i=1;i<=n-1;i++){    /*TO SORT THE GIVEN DATA IN INCREASING ORDER*/

      for(j=1;j<=n-i;j++){        
        if(data[j]<=data[j+1]){
            t=data[j];
            data[j]=data[j+1];
            data[j+1]=t;
         }
            
            
    }
}
                                                 
       
        if(n%2==0){
        median=(data[n/2]+(data[(n/2)+1]))/2.0;
    }else{
        median=data[(n+1)/2];
    }
    printf("\nThe median is:%f\n",median);
    /*MEDIAN COMPUTION ENDS*/
   



    /*  COMPUTE VARIANCE AND STANDARD DEVIATION  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((data[i] - mean), 2);
    }
    variance = sum1 / (float)n;
    std_devi = sqrt(variance);

    printf("\nvariance of all elements = %.2f\n", variance);

    printf("\nStandard deviation = %.2f\n", std_devi);
    /*VARIANCE AND STANDARD DEVIATION COMPUTATION ENDS*/
    
    

    /*COMPUTE MODE*/

   for (i = 0; i < n; i++) {
      m = 0;
      
      for (j = 0; j < n; j++) {
         if (data[j] == data[i])
         m++;
      }
      
      if (m > max) {
         max = m;
         mode = data[i];
      }
       
   }
    printf("\nThe mode is %f",mode);
    /*MODE COMPUTATION ENDS*/
    
    
    
}

float Descrete(float a[],int b[],int n){

    int i,j,e,d,l,max;
    float sum1=0,sum2=0,mean,sum4=0,sum5=0,c[n],cf[n],median,s,sum=0,k=0,t;
    float fx[n],q,h[n],sum3=0,w,variance,std_devi;

   



    for(i=0;i<n;i++){
        c[i]=a[i]*b[i];
    }
        
    for(i=0;i<n;i++){
        sum1=sum1+c[i];
    }
    
    for(i=0;i<n;i++){
        sum2=sum2+b[i];
    }
    printf("Data(x) frequency(f)\t  fx\n");

    for(i=0;i<n;i++){
        printf("%5.1f%7.2d \t \t%f\n",a[i],b[i],c[i] );

    }
    mean=sum1/sum2;

    
    printf("Hence the mean of the descrete distribution is:%f\n",mean);


    for(i=1;i<=n-1;i++){    /*TO SORT THE GIVEN DATA IN INCREASING ORDER*/

        for(j=1;j<=n-i;j++){        
            if(a[j]<=a[j+1]){
                
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;

            
            }
            
            
        }
    }
    



   
    cf[0]=b[0];
        for(i=0;i<n;i++){
            cf[i+1]=b[i+1]+cf[i];
        
            k=k+b[i];
        }

    
    k=k/2;
    

    
    
    
    for(i=0;i<n;i++){
        if(k>cf[i]){

           d=i;   

          }      
    }         
      
   

    printf("\n\n\tx\tfrequency(f)\t\tC.F\n\n");
    for(i=0;i<n;i++){
         printf("\n\t%f\t%d\t\t%f\n",a[i],b[i],cf[i]);
              
        }    
 
    printf("\n\t The median is %f\n",a[d+1]);


    
     max=b[0];
    for(i=0;i<n;i++){
        if(max<b[i]){
            max=b[i];
            l=i;
        }
    }
    printf("\n\tDATA\t\tFREQUENCY\n");
    for(i=0;i<n;i++){
        printf("\n\t%f\t%d\n",a[i],b[i]);
    }
    printf("\nMaximum frequency is:%d\n",max);
    printf("\nMode of the given descrete data series is:%f",a[l]);

    for(i=0;i<n;i++){
        fx[i]=b[i]*a[i];
    }
    for(i=0;i<n;i++){
        sum3=sum3+fx[i];


    }
    for(i=0;i<n;i++){
        sum4=sum4+b[i];
        
    }
    q=sum3/sum4;

    for(i=0;i<n;i++){
        h[i]=a[i]-q;
    }
    
    
    

    float sum6=0;

    for(i=0;i<n;i++){
        
        sum6=sum6+(b[i]*(h[i]*h[i]));
    }
    variance=sum6/sum4;
    std_devi=sqrt(variance);

    printf("\nVariance=%f\n",variance);
    printf("\nStandard deviation=%f\n",std_devi);


}


    float continous(float low[],float up[],int f[],int n){

    int i,A,D,l;    
    float sum1=0,sum2=0,sum4=0,sum5=0,h,mean,s,z,N,L1,median,max,mode,c=0;
    float x[n],fx[n],q,j[n],sum3=0,d[n],w,variance,std_devi;
    
   

    float mv[n],Fd[n],cf[n];
    

    
    
     for(i=0;i<n;i++){
        mv[i]=(up[i]+low[i])/2;
    }
     h=up[0]-low[0];
    A=n/2;
    for(i=0;i<n;i++){
        d[i]=(mv[i]-mv[A])/h;
    }
    for(i=0;i<n;i++){
        Fd[i]=f[i]*d[i];
    }
     for(i=0;i<n;i++){
        sum1=sum1+Fd[i];
        sum2=sum2+f[i];
    }
    mean=mv[A]+((sum1/sum2)*h);
    printf("\n\tclass     frequency(f)  middle value(x)     d\t\t\tfd\n");
    for(i=0;i<n;i++){
        printf("%5f-%7f \t%d \t%f\t%f\t   %f\n",low[i],up[i],f[i],mv[i],d[i],Fd[i]);
    }
    printf("sum of Fd is:%f\n",sum1);
    printf("sum of frequencies is:%f\n",sum2);
    printf("Hence,The mean of the above continous distribution is:%f\n",mean);

    cf[0]=f[0];
    for(i=0;i<n;i++){
        cf[i+1]=f[i+1]+cf[i];
        c=c+f[i];
        
    }
    N=c/2;
    for(i=0;i<n;i++){
        if(N>cf[i]){
            D=i;
            s=cf[i-1];
            z=f[i+1];
        }
        
    }
    
    L1=low[D];
    h=up[0]-low[0];
    median=L1+(((N-s)/z)*h);
    printf("\n\tclass\t\tfrequency\tC.F\n\n");
    for(i=0;i<n;i++){
        printf("\n\t%f-%f\t%d\t%f\n",low[i],up[i],f[i],cf[i]);
    }
    printf("The median of this contnious data distribution is:%f",median);

    max=f[0];
    for(i=0;i<n;i++){
        if(max<f[i]){
            max=f[i];
            l=i;
        }
    }
    mode=(low[l]+((max-f[l-1])/(2*max-f[l-1]-f[l+1]))*h);
    printf("\n\tclass\t\tFrequency");
        for(i=0;i<n;i++){
            printf("\n\t %4.9f-%f\t%d\n",low[i],up[i],f[i]);
        }
    printf("\n Hence,the mode is:--(%f)",mode);

    for(i=0;i<n;i++){

        x[i]=((low[i]+up[i])/2);
        
        
    }
    for(i=0;i<n;i++){
        fx[i]=f[i]*x[i];
    }
    for(i=0;i<n;i++){
        sum3=sum3+fx[i];


    }
    for(i=0;i<n;i++){
        sum4=sum4+f[i];
        
    }
    q=sum3/sum4;

    for(i=0;i<n;i++){
        j[i]=x[i]-q;
    }
    
    
    

    float sum6=0;

    for(i=0;i<n;i++){
        
        sum6=sum6+(f[i]*(j[i]*j[i]));
    }
    variance=sum6/sum4;
    std_devi=sqrt(variance);

    printf("\nVariance=%f\n",variance);
    printf("\nStandard deviation=%f",std_devi);

}








