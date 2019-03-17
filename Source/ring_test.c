/*========================================================================
** ring_test.c
** Circular buffer testing
** ECEN5813
**========================================================================*/

#include "../Include/ring.h"

ring_t *ring;

int main()
{
	ring_t *ptr;
	ptr= init(7);
	if(ptr==NULL)
	printf("init failedd\n");
	char ele;
	
	for(int i=0;i<4;i++)
	{
		//printf("added %d element\n",i);
		insert(ptr,i);
	}
	
	for(int i=0;i<6;i++)
	{
		remove_element(ptr,&ele);
		printf("%d\n",ele);
	}
	
	entries(ptr);
	return 0;
	
	
	
}
