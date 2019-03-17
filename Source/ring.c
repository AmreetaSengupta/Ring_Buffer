/*========================================================================
** Circular buffer
** ECEN5813
** Author: Amreeta Sengupta
**========================================================================*/
#include "../Include/ring.h"

enum ring_status
{
    success,
    fail
};

ring_t *init( int length )
{	
		
	
	if (length <= 0)
	{
		return NULL;
	}
	ring_t *ptr= malloc(sizeof(ring_t));
	
	if(ptr == NULL)
	{
		return NULL;
		
	}
	ptr->Buffer = (char*)malloc(sizeof(length));
	
	if(ptr->Buffer==NULL)
	{
		return NULL;
		
	}
	
	else
	{	
		ptr->Length = length;
		ptr->Ini = 0;
		ptr->Outi = 0;
	}
	
	return ptr;
}


int insert( ring_t *ring, char data )
{
	enum ring_status status;	
	
	if(((ring->Ini+1)%ring->Length )==ring->Outi)
	{
		printf("Buffer full\n");
		status = fail;
	}
	
	else if(ring->Ini== ring->Length-1)
    {
		ring->Buffer[ring->Ini]= data;
		ring->Ini=0;
		status=success;
    }
    
    else
    {
		ring->Buffer[ring->Ini]= data;
		ring->Ini++;
		status=success;
    }
	
	return status;
	
}

int remove_element( ring_t *ring, char *data )
{
		
	enum ring_status status;	
	
	if(ring->Ini==ring->Outi) 
	{
		printf("Empty buffer\n");
		status = fail;
	}
	
	else if(ring->Outi==(ring->Length)-1)
    {
		*data = ring->Buffer[ring->Outi];
		ring->Outi=0;
		status=success;
    }
    
    else
    {
		*data = ring->Buffer[ring->Outi];
		ring->Outi++;
		status=success;
    }
	
	return status;
	if(ring->Outi != ring->Ini)
	*data=ring->Buffer[ring->Outi++ & ring->Length];
	
}

int entries( ring_t *ring )
{
	int num_elements;
	if(ring->Ini >= ring->Outi)
	{
		num_elements = ring->Ini - ring->Outi;
	}
	else
	{
		num_elements = ring->Length-(ring->Outi - ring->Ini);
	}
	
	printf("Number of elements present in the Buffer is: %d\n",num_elements);
}
