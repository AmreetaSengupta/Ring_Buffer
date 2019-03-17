#include "../Include/ring.h"

ring_t *ring;

int main()
{
	ring_t *ptr;
	ptr= init(7);
	if(ptr==NULL)
	printf("Init failed\n");
	char ele;
	
	for(int i=0;i<6;i++)
	{
		printf("Added %d element\n",i);
		insert(ptr,i);
	}
	
	for(int i=0;i<3;i++)
	{
		remove_element(ptr,&ele);
		printf("%d\n",ele);
	}
	entries(ptr);
	return 0;
	
	
	
}
