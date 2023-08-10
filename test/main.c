/**
 * LibM
 * Copyright (C) 2023 Jozef Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stddef.h>
#include <stdio.h>

#include <libm.h>
#include <vec.h>

int main()
{
	printf("Testing NUMARGS macro...");
	if (NUMARGS(int, 1, 2, 3, 4) == 4) {
		printf(" OK\n");
	} else {
		printf(" failed!\n");
	}

	printf("Testing vec_new()... ");
	vec static_vec = vec_new(2.0f, -3.0f, 1.0f);
	vec_print(static_vec);

	printf("Testing vec_construct_default()... ");
	vec default_vec = vec_construct_default(2, 4.2f);
	vec_print(default_vec);

	printf("Testing vec_empty()... ");
	vec empty_vec = vec_empty(3);
	vec_print(empty_vec);

	printf("Testing vec_copy()... ");
	vec copied_vec = vec_copy(&default_vec);
	vec_print(copied_vec);

	printf("Testing vec_equals()... ");
	printf("expected: true, got: %s\n", vec_equals(default_vec, copied_vec) ? "true" : "false");

	printf("Testing vec_equals()... ");
	printf("expected: false, got: %s\n", vec_equals(default_vec, empty_vec) ? "true" : "false");

	///// Scalar operations
	printf("Testing scalar_mult()... ");
	vec mult_vec = vec_new(1.0f, 2.0f, -3.0f);
	vec mult_res = scalar_mult(mult_vec, 3.0f);
	vec_print(mult_res);
	
	printf("Testing scalar_div()... ");
	vec div_vec = vec_new(1.0f, 2.0f, -3.0f);
	vec div_res = scalar_div(div_vec, 3.0f);
	vec_print(div_res);

	printf("Testing power()... ");
	vec pow_vec = vec_new(1.0f, 4.2f, 5.0f);
	vec pow_res = power(pow_vec, 2.0f);
	vec_print(pow_res);

	return 0;
}
