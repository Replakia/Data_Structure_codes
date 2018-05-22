#include <stdio.h>

void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;

    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];

    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];

    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

void quicksort(int number[25],int first,int last)//declare function of quick sort
{
   int i, j, pivot, temp;
   if(first<last)
   {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
            i++;
            while(number[j]>number[pivot])
            j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
    }
}

int main()
{
    int x, data[100], i, j, step, temp, a[30], n, count, number[25];
    printf("\t\tProject\n\n");
    printf("Christopher Juan Kong Yung Seng\t BCS17070002\n");
    printf("Muhammad Fazreen Bin Sijemat\t BCS17090008\n");
    printf("Jessica Tiong Kwong Weng\t BCS17090009\n");
    printf("Mohammad Syahmi Bin Mohd Yunus\t BCS17090014\n\n");
    printf(" 1.Bubble sort\n 2.Selection sort\n 3.Insertion sort\n 4.Merge sort\n 5.Quick sort\n");
    printf("Choose sort: ");
    scanf("%d",&x);

        if(x==1)//Bubble sort
        {
            printf("Enter no of elements: ");
            scanf("%d",&n);
            for(i=0;i<n;++i)
            {
                printf("Enter element %d : ",i+1);
                scanf("%d",&data[i]);
            }
            for(step=0;step<n-1;step++)
            for(i=0;i<n-step-1;i++)
            {
                if(data[i]>data[i+1])   /* To sort in descending order, change > to < in this line. */
                {
                    temp=data[i];
                    data[i]=data[i+1];
                    data[i+1]=temp;
                }
            }
            printf("Result: ");
            for(i=0;i<n;++i)
            printf("%d  ",data[i]);
        }

        else if(x==2)//Selection sort
        {
            printf("Enter no of elements: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter element %d : ",i+1);
                scanf("%d",&data[i]);
            }
            for(step=0;step<n-1;step++)
            for(i=0;i<n-step-1;i++)
            {
                if(data[i]>data[i+1])   /* To sort in descending order, change > to < in this line. */
                {
                    temp=data[i];
                    data[i]=data[i+1];
                    data[i+1]=temp;
                }
            }
            printf("Result: ");
            for(i=0;i<n;++i)
            printf("%d  ",data[i]);
        }

        else if(x==3)//Insertion sort
        {
            printf("Enter no of elements: ");
	        scanf("%d",&n);

	        for(i=0;i<n;i++)
	        {
	            printf("Enter element %d : ",i+1);
		        scanf("%d",&data[i]);
	        }
	        for(i=1;i<n;i++)
	        {
		        temp = data[i];
		        j=i-1;
		        while(temp<data[j] && j>=0)
 		        {
			        data[j+1] = data[j];
			        --j;
		        }
		    data[j+1]=temp;
	        }
	        printf("Result: ");
	        for(i=0; i<n; i++)
		    printf("%d  ",data[i]);
        }

        else if(x==4)//Merge sort
        {
            printf("Enter no of elements: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter element %d : ",i+1);
                scanf("%d",&a[i]);
            }
            mergesort(a,0,n-1);
            printf("Result:");
            for(i=0;i<n;i++)
            printf("%d  ",a[i]);
        }

        else if(x==5)//Quick sort
        {
            printf("Enter no of elements: ");
            scanf("%d",&count);
            for(i=0;i<count;i++)
            {
                printf("Enter element %d : ",i+1);
                scanf("%d",&number[i]);
            }

            quicksort(number,0,count-1);
            printf("Result: ");
            for(i=0;i<count;i++)
            printf("%d  ",number[i]);
        }
        else
        {
            printf("\nPlease enter no of sort !\n");
        }
    return 0;
}
