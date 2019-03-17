/*========================================================================
** ring_test.c
** Circular buffer testing
** ECEN5813
** Reference: http://cunit.sourceforge.net/example.html
** Author: Amreeta Sengupta
**========================================================================*/

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include <CUnit/CUnit.h>
#include "../Include/ring.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}


void test_init()
{
	ring_t *ptr;
	ptr= init(7);
	CU_ASSERT_NOT_EQUAL(ptr,NULL);
}

void test_insert()
{
	ring_t *ptr;
	ptr= init(7);
	for(int i =0; i<4; i++)
	{
		CU_ASSERT_EQUAL(insert(ptr,i),0);
	}
}

void test_remove()
{
	ring_t *ptr;
	char ele;
	ptr= init(7);
	for(int i =0; i<4; i++)
	{
		CU_ASSERT_EQUAL(insert(ptr,i),0);
	}
	for(int i =0; i<4; i++)
	{
		CU_ASSERT_EQUAL(remove_element(ptr,&ele),0);
	}
	
}
/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of INIT()", test_init)) ||
       (NULL == CU_add_test(pSuite, "test of INSERT()", test_insert)) ||
       (NULL == CU_add_test(pSuite, "test of REMOVE()", test_remove)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

