/*
 * Copyright (c) 2024 Jozef Nagy <schkwve@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _LIBM_VECTOR_H
#define _LIBM_VECTOR_H

#include <stdbool.h>

#include <libm/libm.h>

typedef struct {
	unsigned int dim;
	float *elements;
} vector;

extern const vector VEC_UNDEFINED;

vector vec_new(unsigned int dim, ...);

vector vec_copy(vector v);
vector vec_copyp(vector *v);

bool vec_equals(vector v1, vector v2);

vector vec_add(vector v1, vector v2);
bool vec_addp(vector *v1, vector v2);

vector vec_sub(vector v1, vector v2);
bool vec_subp(vector *v1, vector v2);

vector vec_mult(vector v1, vector v2);
bool vec_multp(vector *v1, vector v2);

vector vec_div(vector v1, vector v2);
bool vec_divp(vector *v1, vector v2);

vector vec_power(vector v, float k);
void vec_powerp(vector *v, float k);

vector vec_smult(vector v, float k);
void vec_smultp(vector *v, float k);

vector vec_sdiv(vector v, float k);
void vec_sdivp(vector *v, float k);

float vec_dot(vector v1, vector v2);
bool vec_orthogonal(vector v1, vector v2);
vector vec_cross(vector v1, vector v2);

float vec_magnitude(vector v);
float vec_magnitudesq(vector v);

void vec_normalize(vector *v);
vector vec_normalized(vector v);

void vec_dump(vector v);

#define vector(...) vec_new(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)

vector vec_default(unsigned int dim, float val);
vector vec_empty(unsigned int dim);

#endif /* _LIBM_VECTOR_H */