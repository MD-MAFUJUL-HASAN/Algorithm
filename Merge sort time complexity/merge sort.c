/*** Name - MD MAFUJUL HASAN
     ID - CSE1903018137
     Section - 18A2(Bruce)**/

            /* Merge Sort time complexity */

    #include<stdio.h>
    #include<time.h>
    #define CLOCK_PER_SEC 1000
    void merge_sort(int i, int j, int data[], int a[]);
    long int data[400000];
    long int a[400000];
    int main()
    {
        long int n;
        long int i,j,save;
        double end;
        clock_t start;
        FILE *fp1;
        FILE *fp;

        fp=fopen("input8137.txt","r");
        fp1=fopen("outmerge8137.txt","a");
        fscanf(fp,"%d",&n);
        printf("\nReading data from file...");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        printf("\nData Reading complete");
        printf("\nSorting process started...WAIT");
        start=clock();

        merge_sort(0, n - 1, data, a);

        end=((double)clock()-start)/CLOCK_PER_SEC;
        printf("\nSorting complete.");
        printf("\n\nNo. of data\tTime needed for execution");
        printf("\n-----------|------------------------------");
        printf("\n%d\t\t%lf",n,end);
        printf("\n\nThis information is added to file named 'outmerge8137.txt'");
        fprintf(fp1,"%d %lf\n",n,end);
    }

// function to sort the subsection data[i .. j] of the array data[]

void merge_sort(int i, int j, int data[], int a[])
{
    if (j <= i)
    {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;
    // left sub-array is data[i .. mid]
    // right sub-array is data[mid + 1 .. j]
    merge_sort(i, mid, data, a);        // sort the left sub-array recursively
    merge_sort(mid + 1, j, data, a);    // sort the right sub-array recursively
    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    for (k = i; k <= j; k++)
    {
        if (pointer_left == mid + 1)
        {
            a[k] = data[pointer_right];
            pointer_right++;
        }
        else if(pointer_right == j + 1)
        {
            a[k] = data[pointer_left];
            pointer_left++;
        }
        else if (data[pointer_left] < data[pointer_right])
        {
            a[k] = data[pointer_left];
            pointer_left++;
        }
        else
        {
            a[k] = data[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++)
    {
        data[k] = a[k];
    }
}
