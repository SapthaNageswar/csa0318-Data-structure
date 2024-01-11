#include<stdio.h>
int main()
{
	int a;
	printf("ENTER A NUMBER\n");
	scanf("%d",&a);
	if(a%2 == 0)
	{
		printf("%d is even number",a);
	}
	else
	{
		printf("%d it is odd number",a);
	}
	return 0;
}
