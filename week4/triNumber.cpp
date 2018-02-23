#include "triNumber.h"

/***************************************************************************************************
**	// a function which takes a number of rows, n, and returns the triangular number for n
***************************************************************************************************/
int triNum(int n)
{
	if (n < 1)
	{
		return 0;
	}
	else
	{
		return n + triNum(n - 1);
	}
}