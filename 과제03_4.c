#include <stdio.h>

void swap(int *px, int *py)
{
    *px += *py;
    *py = *px - *py;
    *px -= *py;
}


int main(void)
{	
    int a = 100, b = 200;

	printf("swap() ȣ���� a=%d b=%d\n", a, b);

	swap(&a, &b);

	printf("swap() ȣ���� a=%d b=%d\n", a, b);

	return 0;

}
