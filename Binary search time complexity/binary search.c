/*** Name - MD MAFUJUL HASAN
     ID - CSE1903018137
     Section - 18A2(Bruce)**/

            /* Binary search time complexity */

    #include<stdio.h>
    #include<time.h>
    #define CLOCK_PER_SEC 1000
    long int data[400000];
    int main()
    {
        long int i,n;
        double end;
        int size = sizeof(data)/sizeof(data[0]);
        int find = 10;
        clock_t start;
        FILE *fp1;
        FILE *fp;

        fp=fopen("input8137.txt","r");
        fp1=fopen("outbinary8137.txt","a");
        fscanf(fp,"%d",&n);
        printf("\nReading data from file...");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        printf("\nData Reading complete");
        printf("\nSorting process started...WAIT");
        start=clock();

        int result = binary_search(data,0,size-1,find);

        end=((double)clock()-start)/CLOCK_PER_SEC;
        printf("\nSorting complete.");
        printf("\n\nNo. of data\tTime needed for execution");
        printf("\n-----------|------------------------------");
        printf("\n%d\t\t%lf",n,end);
        printf("\n\nThis information is added to file named 'outbinary8137.txt'");
        fprintf(fp1,"%d %lf\n",n,end);
    }

int binary_search(int data[],int min,int max,int key)
{
    while(min<max)
    {
        int mid = (max+min)/2;
        if (data[mid]>key)
            max = mid-1;
        else if(data[mid]<key)
            min = mid+1;
        else
            return mid;
    }
    return -1;
}
