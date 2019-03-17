/*========================================================================
** Circular buffer
** ECEN5813
**========================================================================*/
#include "../Include/ring.h"
/*typedef struct
{
	char *Buffer;
	int Length;
	int Ini;
	int Outi;
	int count;
} ring_t;*/

enum ring_status
{
    success,
    fail
};

ring_t *init( int length )
{	
	//enum ring_status status;	
	printf("entered init\n");
	if (length <= 0)
	{
		printf("length<0 error\n");
		return NULL;
		//status = fail;
		//return status;
	}
	ring_t *ptr= malloc(sizeof(ring_t));
	printf("pointer add =%p\n",ptr);
	if(ptr == NULL)
	{
		printf("ptr alloc failed in init\n");
		return NULL;
		//status = fail;
		//return status;
	}
	ptr->Buffer = (char*)malloc(sizeof(length));
	
	if(ptr->Buffer==NULL)
	{
		printf("ptr->buffer alloc failed in init\n");
		return NULL;
		//status = fail;
		//return status;
	}
	
	else
	{	
		printf("entered else \n");
		ptr->Length = length;
		ptr->Ini = 0;
		ptr->Outi = 0;
		ptr->count = 0;
	}
	
	return ptr;
}


int insert( ring_t *ring, char data )
{
	enum ring_status status;	
	
	/*if((ring->Ini- ring->Outi) > (ring->Length)-1) // if(ring->Ini==ring->(Length-1))
	{
		status = fail;
	}*/
	
	if(((ring->Ini+1)%ring->Length )==ring->Outi)
	{
	printf("buffer full\n");
	status = fail;
	}
	
	else if(ring->Ini== ring->Length-1)
    {
		ring->Buffer[ring->Ini]= data;
		printf("[Inside insert ]position=%d, element=%d\n",ring->Ini,ring->Buffer[ring->Ini]);
		ring->Ini=0;
		ring->count++;
		status=success;
    }
    
    else
    {
		ring->Buffer[ring->Ini]= data;
		printf("[Inside insert ]position=%d, element=%d\n",ring->Ini,ring->Buffer[ring->Ini]);
		//printf("[Inside insert ]%d\n",ring->Buffer[ring->Ini]);
		ring->Ini++;
		ring->count++;
		status=success;
    }
	
	return status;
	
}

int remove_element( ring_t *ring, char *data )
{
		
	enum ring_status status;	
	printf("Outi value is %d\n", ring->Outi);
	printf("Ini value is %d\n", ring->Ini);
	
	if(ring->Ini==ring->Outi) //change the condition 
	{
		//printf("Entered remove ka if\n");
		printf("empty buffer");
		status = fail;
	}
	
	else if(ring->Outi==(ring->Length)-1)
    {
		printf("Entered remove ka 1st else if\n");
		*data = ring->Buffer[ring->Outi];
		printf("[Inside remove ]%d\n",ring->Buffer[ring->Outi]);
		ring->Outi=0;
		ring->count--;
		status=success;
    }
    
    else
    {
		printf("Entered remove ka 2nd else if\n");
		*data = ring->Buffer[ring->Outi];
		printf("[Inside remove ]%d\n",ring->Buffer[ring->Outi]);
		ring->Outi++;
		ring->count--;
		status=success;
    }
	
	return status;
	if(ring->Outi != ring->Ini)
	*data=ring->Buffer[ring->Outi++ & ring->Length];
	
}

int entries( ring_t *ring )
{
	int num_elements;
	printf("Number of elements present in the Buffer is: %d\n",ring->count);
	
	if(ring->Ini >= ring->Outi)
	{
		num_elements = ring->Ini - ring->Outi;
	}
	else
	{
		num_elements = ring->Length-(ring->Ini - ring->Outi);
	}
	
	printf("Number of elements present in the Buffer is: %d\n",num_elements);
}
