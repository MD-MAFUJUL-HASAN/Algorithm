/*** Name - MD MAFUJUL HASAN
     ID - CSE1903018137
     Section - 18A2(Bruce)**/

            /* Quick Sort time complexity */

    #include<stdio.h>
    #include<time.h>
    #define CLOCK_PER_SEC 1000
    void quick_sort(int data[],int l,int u);
    int partition(int data[],int l,int u);
    long int data[400000];
    int main()
    {
        long int n;
        long int i,j,save;
        double end;
        clock_t start;
        FILE *fp1;
        FILE *fp;

        fp=fopen("input8137.txt","r");
        fp1=fopen("outquick8137.txt","a");
        fscanf(fp,"%d",&n);
        printf("\nReading data from file...");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%d\n",data[i]);
        }
        printf("\nData Reading complete");
        printf("\nSorting process started...WAIT");
        start=clock();

        quick_sort(data,0,n-1);

        end=((double)clock()-start)/CLOCK_PER_SEC;
        printf("\nSorting complete.");
        printf("\n\nNo. of data\tTime needed for execution");
        printf("\n-----------|------------------------------");
        printf("\n%d\t\t%lf",n,end);
        printf("\n\nThis information is added to file named 'outquick8137.txt'");
        fprintf(fp1,"%d %lf\n",n,end);
    }

void quick_sort(int data[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(data,l,u);
		quick_sort(data,l,j-1);
		quick_sort(data,j+1,u);
	}
}

int partition(int data[],int l,int u)
{
	int v,i,j,temp;
	v=data[l];
	i=l;
	j=u+1;

	do
	{
		do
			i++;

		while(data[i]<v&&i<=u);

		do
			j--;
		while(v<data[j]);

		if(i<j)
		{
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	}while(i<j);

	data[l]=data[j];
	data[j]=v;

	return(j);
}



