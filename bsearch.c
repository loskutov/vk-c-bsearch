#include <stddef.h>
#include <stdio.h>

/**
 * bsearch - find the first number greater than the given one
 * in a sorted array
 * @arr:  the sorted (in non-decreasing order) array to query
 * @n:    the number of elements in @arr
 * @x:    the number to look for
 *
 * returns: index of the first element in @arr strictly greater than @x,
 *          or @n if all the elements of @arr are less than or equal to @x
 */
size_t bsearch(const int arr[], size_t n, int x)
{
	size_t l = -1, r = n;
	while (l + 1 < r) {
		size_t m = l + (r - l) / 2;
		if (arr[m] > x)
			r = m;
		else
			l = m;
	}
	return r;
}

int main()
{
	int arr[] = {1, 2, 3, 5, 8, 8, 8, 13, 21, 34, 55};
	size_t n = sizeof(arr) / sizeof(arr[0]);
	int q;
	do {
		scanf("%d", &q);
		size_t ans = bsearch(arr, n, q);
		if (ans < n)
			printf("arr[%zu]=%d\n", ans, arr[ans]);
		else
			printf("arr[0..%zu] <= %d\n", n - 1, q);
	} while (q != -1);
}
