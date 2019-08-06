#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, d;
	for (a = 0; a <= 1; a++)
	for (b = 0; b <= 1; b++)
	for (c = 0; c <= 1; c++)
	for (d = 0; d <= 1; d++)
	if (!a + c + !d + d == 3 && a + b + c + d == 1)
		printf("A:%d B:%d C:%d D:%d", a, b, c, d);//1代表小偷 0代表不是小偷
	return 0;
}
