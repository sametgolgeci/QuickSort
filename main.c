//
//  main.c
//  Quick Sort
//
//  Created by Samet Gölgeci on 28/10/15.
//  Copyright © 2015 SametGolgeci. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quickSortBir(int[2000000],int,int,int);
void quickSortİki(int[2000000],int,int,int);
void quickSortUc( int[2000000],int,int,int);


int main(int argc, const char * argv[]) {
    
    int yontem,dizi[2000000],eleman,i;
    clock_t a,b;
    
    printf("Lütfen kullanılacak yöntemi seçiniz\n");
    printf("1) İlk elemanı pivot olarak alınız\n");
    printf("2) Rastgele bir elemanı pivot olarak alınız\n");
    printf("3) İlk,son ve orta elemanı alıp 2.büyük olanı pivot yapınız\n");
    
    scanf("%d",&yontem);
    
    switch (yontem) {
        case 1:
            printf("Dizinin eleman sayısını giriniz\n");
            scanf("%d",&eleman);
           // printf("Dizinin elemanlarını giriniz\n");
            for (i=0; i<eleman; i++) {
                dizi[i]=i;
            //    dizi[i]=rand()%20;
            //    scanf("%d",&dizi[i]);
            //    printf("%d ",dizi[i]);
            }
            //    printf("\n");
            
            a=clock();
            quickSortBir(dizi,0,eleman-1,eleman);
            b=clock();
            
            printf("Dizinin son hali\n");
            
            for (i=0; i<eleman; i++) {
                printf("%d ",dizi[i]);
            }
            
            printf("\n %lu mikrosaniye\n",(b-a));
            
            break;
            
        case 2:
            printf("Dizinin eleman sayısını giriniz\n");
            scanf("%d",&eleman);
            printf("Dizinin elemanlarını giriniz\n");
            for (i=0; i<eleman; i++) {
                //dizi[i]=i;
               // dizi[i]=rand()%100000;
                scanf("%d",&dizi[i]);
                //printf("%d ",dizi[i]);
            }
                //printf("\n");
            
            
            a=clock();
            quickSortİki(dizi,0,eleman-1,eleman);
            b=clock();
            
            printf("Dizinin son hali\n");
            
            for (i=0; i<eleman; i++) {
                printf("%d ",dizi[i]);
            }
            
            printf("\n%lu mikrosaniye\n",(b-a));

            break;
            
        case 3:
            printf("Dizinin eleman sayısını giriniz\n");
            scanf("%d",&eleman);
            printf("Dizinin elemanlarını giriniz\n");
            for (i=0; i<eleman; i++) {
                //dizi[i]=i;
                scanf("%d",&dizi[i]);
                //dizi[i]=rand()%100000;
                //printf("%d ",dizi[i]);
            }
                //printf("\n");
            
            a=clock();
            quickSortUc(dizi,0,eleman-1,eleman);
            b=clock();
            
            printf("Dizinin son hali\n");
            
            for (i=0; i<eleman; i++) {
                printf("%d ",dizi[i]);
            }
            
            printf("\n%lu mikrosaniye\n",(b-a));

            break;
            
        default:
            printf("Yanlış değer girdiniz");
            break;
    }

    return 0;
}

void quickSortBir(int dizi[2000000],int first,int last,int eleman){
    
    int pivot,tmp,i,j;
    
    
    if (first<last) {
        pivot=first;
        i=first;
        j=last;
        //printf("Pivot %d. eleman : %d\n",pivot+1,dizi[pivot]);
        
        while(i<j){
            while((dizi[i]<=dizi[pivot])&&(i<last))
                i++;
            while(dizi[j]>dizi[pivot])
                j--;
            if(i<j){
                tmp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=tmp;
                
                //printf("%d. eleman ile %d. eleman yer değiştiriyor\n",i+1,j+1);
                //int k;
                //for (k=0; k<eleman; k++) {
                //    printf("%d ",dizi[k]);
                //}
                //printf("\n");
            }
        }
        
        //printf("Pivot eleman ile %d. eleman yer değiştiriyor\n",j+1);
        
            tmp=dizi[pivot];
            dizi[pivot]=dizi[j];
            dizi[j]=tmp;

              //int k;
              //for (k=0; k<eleman; k++) {
              //    printf("%d ",dizi[k]);
              //}
              //printf("\n");
        
        quickSortBir(dizi,first,j-1,eleman);
        quickSortBir(dizi,j+1,last,eleman);
    }
}

void quickSortİki(int dizi[2000000],int first,int last,int eleman){
    
    int pivot,tmp,i,j,x,k;
    
    
    if (first<last) {

        x=first+rand()%(last-first+1);
        printf("Random olarak seçilen eleman %d\n",x+1);
        
        tmp=dizi[first];
        dizi[first]=dizi[x];
        dizi[x]=tmp;
        
        printf("%d. eleman ile %d. eleman yer değiştiriyor\n",first+1,x+1);
        for (k=0; k<eleman; k++) {
            printf("%d ",dizi[k]);
        }
        printf("\n");

        
        pivot=first;
        i=first;
        j=last;
        
        printf("Pivot %d. eleman : %d\n",pivot+1,dizi[pivot]);
        
        
        while(i<j){
            while((dizi[i]<=dizi[pivot])&&(i<last))
                i++;
            while(dizi[j]>dizi[pivot])
                j--;
            if(i<j){
                tmp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=tmp;
                
                printf("%d. eleman ile %d. eleman yer değiştiriyor\n",i+1,j+1);
                for (k=0; k<eleman; k++) {
                    printf("%d ",dizi[k]);
                }
                printf("\n");
            }
        }
        
        printf("Pivot eleman ile %d. eleman yer değiştiriyor\n",j+1);
        
        tmp=dizi[pivot];
        dizi[pivot]=dizi[j];
        dizi[j]=tmp;
        
        for (k=0; k<eleman; k++) {
            printf("%d ",dizi[k]);
        }
        printf("\n");
        quickSortİki(dizi,first,j-1,eleman);
        quickSortİki(dizi,j+1,last,eleman);
    }
}

void quickSortUc(int dizi[2000000],int first,int last,int eleman){
    
    int pivot,tmp,i,j,mid,k;
    
    
    if (first<last) {
        
        mid=((first+last)/2);
        
        printf("ilk eleman %d\n",dizi[first]);
        printf("mid eleman %d\n",dizi[mid]);
        printf("son eleman %d\n",dizi[last]);
        
        if (dizi[last]>dizi[first]) {
            if (dizi[mid]>dizi[last]) {
                tmp=dizi[first];
                dizi[first]=dizi[last];
                dizi[last]=tmp;
                printf("%d. eleman ile %d. eleman yer değiştiriyor\n",first+1,last+1);
                for (k=0; k<eleman; k++) {
                    printf("%d ",dizi[k]);
                }
                printf("\n");

            }
            else
            {
                if (dizi[mid]>dizi[first]) {
                    tmp=dizi[first];
                    dizi[first]=dizi[mid];
                    dizi[mid]=tmp;
                    
                    printf("%d. eleman ile %d. eleman yer değiştiriyor\n",first+1,mid+1);
                    for (k=0; k<eleman; k++) {
                        printf("%d ",dizi[k]);
                    }
                    printf("\n");

                }
            }
        }
        else
        {
            if (dizi[mid]<dizi[last]) {
                tmp=dizi[first];
                dizi[first]=dizi[last];
                dizi[last]=tmp;
                
                printf("%d. eleman ile %d. eleman yer değiştiriyor\n",first+1,last+1);
                for (k=0; k<eleman; k++) {
                    printf("%d ",dizi[k]);
                }
                printf("\n");

            }
            else
            {
                if (dizi[mid]<dizi[first]) {
                    tmp=dizi[first];
                    dizi[first]=dizi[mid];
                    dizi[mid]=tmp;
                    
                    printf("%d. eleman ile %d. eleman yer değiştiriyor\n",first+1,mid+1);
                    for (k=0; k<eleman; k++) {
                        printf("%d ",dizi[k]);
                    }
                    printf("\n");

                }
            }
        }
        
        
        pivot=first;
        i=first;
        j=last;
        
        printf("Pivot %d. eleman : %d\n",pivot+1,dizi[pivot]);
        
        
        while(i<j){
            while((dizi[i]<=dizi[pivot])&&(i<last))
                i++;
            while(dizi[j]>dizi[pivot])
                j--;
            if(i<j){
                tmp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=tmp;
                
                printf("%d. eleman ile %d. eleman yer değiştiriyor\n",i+1,j+1);
                for (k=0; k<eleman; k++) {
                    printf("%d ",dizi[k]);
                }
                printf("\n");
            }
        }
        printf("Pivot eleman ile %d. eleman yer değiştiriyor\n",j+1);
        
        tmp=dizi[pivot];
        dizi[pivot]=dizi[j];
        dizi[j]=tmp;
        
        int k;
        for (k=0; k<eleman; k++) {
            printf("%d ",dizi[k]);
        }
        printf("\n");
        quickSortUc(dizi,first,j-1,eleman);
        quickSortUc(dizi,j+1,last,eleman);
    }
}
