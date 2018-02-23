#include "sumArray.h"

/***************************************************************************************************
**	// a function which takes an array and its length, and returns its sum
***************************************************************************************************/
int sumArray(int arr[], int size)
{
	if (size == 1)
	{
		return arr[size - 1];
	}
	else
	{
		return arr[size - 1] + sumArray(arr, size - 1);
	}
}