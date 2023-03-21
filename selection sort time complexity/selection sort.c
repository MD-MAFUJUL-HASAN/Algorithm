/*** Name - MD MAFUJUL HASAN
     ID - CSE1903018137
     Section - 18A2(Bruce)**/

            /* Selection Sort time complexity */

    #include<stdio.h>
    #include<time.h>
    #define CLOCK_PER_SEC 1000
    long int data[400000];
    int main()
    {
        long int n;
        long int i,j,save;
        int position, swap;
        double end;
        clock_t start;
        FILE *fp1;
        FILE *fp;

        fp=fopen("input8137.txt","r");
        fp1=fopen("outselection8137.txt","a");
        fscanf(fp,"%d",&n);
        printf("\nReading data from file...");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        printf("\nData Reading complete");
        printf("\nSorting process started...WAIT");
        start=clock();

        for(i = 0; i < n - 1; i++)
        {
            position=i;
            for(j = i + 1; j < n; j++)
            {
                if(data[position] > data[j])
                position=j;
            }
            if(position != i)
            {
                swap=data[i];
                data[i]=data[position];
                data[position]=swap;
            }
        }
        end=((double)clock()-start)/CLOCK_PER_SEC;
        printf("\nSorting complete.");
        printf("\n\nNo. of data\tTime needed for execution");
        printf("\n-----------|------------------------------");
        printf("\n%d\t\t%lf",n,end);
        printf("\n\nThis information is added to file named 'outselection8137.txt'");
        fprintf(fp1,"%d %lf\n",n,end);
    }

