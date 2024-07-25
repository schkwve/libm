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

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include <libm/vector.h>

const vector VEC_UNDEFINED = {0, NULL};

static vector allocate(unsigned int dim)
{
	vector ret;

	ret.dim = dim;
	ret.elements = malloc(dim * sizeof(float));
	return ret;
}

vector vec_new(unsigned int dim, ...)
{
	vector ret = allocate(dim);

	va_list list;
	va_start(list, dim);

	for (unsigned int i = 0; i < dim; i++) {
		ret.elements[i] = va_arg(list, double);
	}

	va_end(list);
	return ret;
}

vector vec_copy(vector v)
{
	return v;
}

vector vec_copyp(vector *v)
{
	vector ret;
	memcpy(&ret, v, sizeof(vector));
	return ret;
}

bool vec_equals(vector v1, vector v2)
{
	if (v1.dim != v2.dim)
		return false;

	for (unsigned int i = 0; i < v1.dim; i++) {
		if (v1.elements[i] != v2.elements[i]) {
			return false;
		}
	}

	return true;
}

vector vec_add(vector v1, vector v2)
{
	if (v1.dim != v2.dim) {
		return VEC_UNDEFINED;
	}

	vector ret = allocate(v1.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v1.elements[i] + v2.elements[i];
	}

	return ret;
}

bool vec_addp(vector *v1, vector v2)
{
	if (v1->dim != v2.dim) {
		return false;
	}

	for (unsigned int i = 0; i < v1->dim; i++) {
		v1->elements[i] += v2.elements[i];
	}

	return true;
}

vector vec_sub(vector v1, vector v2)
{
	if (v1.dim != v2.dim) {
		return VEC_UNDEFINED;
	}

	vector ret = allocate(v1.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v1.elements[i] - v2.elements[i];
	}

	return ret;
}

bool vec_subp(vector *v1, vector v2)
{
	if (v1->dim != v2.dim) {
		return false;
	}

	for (unsigned int i = 0; i < v1->dim; i++) {
		v1->elements[i] -= v2.elements[i];
	}

	return true;
}

vector vec_mult(vector v1, vector v2)
{
	if (v1.dim != v2.dim) {
		return VEC_UNDEFINED;
	}

	vector ret = allocate(v1.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v1.elements[i] * v2.elements[i];
	}

	return ret;
}

bool vec_multp(vector *v1, vector v2)
{
	if (v1->dim != v2.dim) {
		return false;
	}

	for (unsigned int i = 0; i < v1->dim; i++) {
		v1->elements[i] *= v2.elements[i];
	}

	return true;
}

vector vec_div(vector v1, vector v2)
{
	if (v1.dim != v2.dim) {
		return VEC_UNDEFINED;
	}

	vector ret = allocate(v1.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v1.elements[i] / v2.elements[i];
	}

	return ret;
}

bool vec_divp(vector *v1, vector v2)
{
	if (v1->dim != v2.dim) {
		return false;
	}

	for (unsigned int i = 0; i < v1->dim; i++) {
		v1->elements[i] /= v2.elements[i];
	}

	return true;
}

vector vec_power(vector v, float k)
{
	vector ret = allocate(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = powf(v.elements[i], k);
	}

	return ret;
}

void vec_powerp(vector *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] = powf(v->elements[i], k);
	}
}

vector vec_smult(vector v, float k)
{
	vector ret = allocate(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] * k;
	}

	return ret;
}

void vec_smultp(vector *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] *= k;
	}
}

vector vec_sdiv(vector v, float k)
{
	vector ret = allocate(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / k;
	}

	return ret;
}

void vec_sdivp(vector *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= k;
	}
}

float vec_dot(vector v1, vector v2)
{
	float ret = .0f;

	if (v1.dim == v2.dim) {
		for (unsigned int i = 0; i < v1.dim; i++) {
			ret += v1.elements[i] * v2.elements[i];
		}
	}

	return ret;
}

bool vec_orthogonal(vector v1, vector v2)
{
	return v1.dim == v2.dim
		? vec_dot(v1, v2) == .0f
		: false;
}

vector vec_cross(vector v1, vector v2)
{
	if (v1.dim != 3 || v2.dim != 3) {
		return VEC_UNDEFINED;
	}

	vector ret = allocate(3);

	ret.elements[0] = (v1.elements[1] * v2.elements[2]) - (v1.elements[2] * v2.elements[1]);
	ret.elements[1] = -1 * ((v1.elements[0] * v2.elements[2]) - (v1.elements[2] * v2.elements[0]));
	ret.elements[2] = (v1.elements[0] * v2.elements[1]) - (v1.elements[1] * v2.elements[0]);

	return ret;
}

float vec_magnitude(vector v)
{
	return sqrt(vec_magnitudesq(v));
}

float vec_magnitudesq(vector v)
{
	float ret = .0f;

	for (unsigned int i = 0; i < v.dim; i++) {
		ret += v.elements[i] * v.elements[i];
	}

	return ret;
}

void vec_normalize(vector *v)
{
	float mag = vec_magnitude(*v);

	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= mag;
	}
}

vector vec_normalized(vector v)
{
	vector ret = allocate(v.dim);
	float mag = vec_magnitude(v);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / mag;
	}
	
	return ret;
}

void vec_dump(vector v)
{
	printf("[ ");

	for (unsigned int i = 0; i < v.dim; i++) {
		printf("%f", v.elements[i]);

		if (i < v.dim - 1) {
			printf(", ");
		}
	}
	printf(" ]\n");
}

vector vec_default(unsigned int dim, float val)
{
	vector ret = allocate(dim);

	for (unsigned int i = 0; i < dim; i++) {
		ret.elements[i] = val;
	}

	return ret;
}

vector vec_empty(unsigned int dim)
{
	return vec_default(dim, 0.0f);
}