/*** Name - MD MAFUJUL HASAN
     ID - CSE1903018137
     Section - 18A2(Bruce)**/

            /* Linear search time complexity */

    #include<stdio.h>
    #include<time.h>
    #define CLOCK_PER_SEC 1000
    int search(int data[], int size, int x);
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
        fp1=fopen("outlinear8137.txt","a");
        fscanf(fp,"%d",&n);
        printf("\nReading data from file...");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        printf("\nData Reading complete");
        printf("\nSorting process started...WAIT");
        start=clock();

        int result = search(data,size,find);

        end=((double)clock()-start)/CLOCK_PER_SEC;
        printf("\nSorting complete.");
        printf("\n\nNo. of data\tTime needed for execution");
        printf("\n-----------|------------------------------");
        printf("\n%d\t\t%lf",n,end);
        printf("\n\nThis information is added to file named 'outlinear8137.txt'");
        fprintf(fp1,"%d %lf\n",n,end);
    }

int search(int data[], int size, int x)
{
    int i=0;
        for (i=0; i<size; i++)
            if (data[i] == x)
                return i;
        return -1;
}
