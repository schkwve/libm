#include <stdio.h>

#include <libm/vector.h>

void vector_test(void)
{
	vector v1 = vector(2.0f, -3.0f, 1.0f);
	printf("Created vector 1: ");
	vec_dump(v1);
	
	vector v2 = vector(1.0f, 4.6f, 6.123f, 4.4f);
	printf("Created vector 2: ");
	vec_dump(v2);
	
	vector v3 = vector(2.0f, -3.0f, 1.0f);
	printf("Created vector 3: ");
	vec_dump(v3);

	printf("Vector 1 %s vector 2\n", vec_equals(v1, v2) ? "equals" : "does not equal");
	printf("Vector 1 %s vector 3\n", vec_equals(v1, v3) ? "equals" : "does not equal");

	///

	printf("Vector 1: ");
	vec_dump(v1);
	vec_smultp(&v1, 3.f);
	printf("Vector 1 multiplied by 3.f: ");
	vec_dump(v1);
	
	printf("Vector 2: ");
	vec_dump(v2);
	vec_powerp(&v2, 1.2f);
	printf("Vector 2 to the power of 1.2f: ");
	vec_dump(v2);
}