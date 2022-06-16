#include <stdio.h>

int quick_sort();
int swap();
int fun();

int main() 
{
	int arr[5] = { 3, 5, 7, 1, 6},i;
	printf("Array before sorting : \n");
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}

	quick_sort(arr,0,4);

	printf("\nArray after sorting : \n");
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int quick_sort(int* arr, int size1, int size2)
{
	if (size1 < size2) 
	{
		int var = fun(arr, size1, size2);
		quick_sort(arr, size1, var - 1);
		quick_sort(arr, var + 1, size2);
	}
}

int swap(int *num1, int *num2) 
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int fun(int *arr, int size1, int size2) 
{
	int var1 = arr[size1];
	int i = (size1+ 1);
	int j = size2;
	do
	{
		while(arr[i] <= var1)
		{
			i++;
		}

		while(arr[j] >= var1)
		{
			j--;
		}

		if(i < j)
		{
			swap(&arr[i], &arr[j]);
		}

	}while(i < j);

	swap(&arr[size1],&arr[j]);
	return j;
}
