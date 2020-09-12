#include<stdio.h>
#include<stdlib.h>

void Merge(int R[], int low, int mid, int high)
{
	int *R1 = (int *)malloc((high-low+1)*sizeof(int));
	int i = low, j = mid+1,k=0;
	while(i<=mid && j<=high)
	{
		if(R[i] <= R[j])
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else
		{
			R1[k] = R[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		R1[k] = R[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		R1[k] = R[j];
		j++;
		k++;
	}
	for(k=0, i=low; i<=high; k++, i++)
	{
		R[i] = R1[k];
	}
	free(R1);
}

void MergeSort(int R[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(R, low, mid);
		MergeSort(R, mid+1, high);
		Merge(R, low, mid, high);
	}	
}

int main()
{
	int i = 0;
	int R[5] = {36,23,16,5,78};
	MergeSort(R, 0, 4);
	for(i=0; i<5; i++)
	{
		printf("%d ", R[i]);
	}
	printf("\n");
	return 0;
}
