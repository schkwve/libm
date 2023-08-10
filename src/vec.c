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

#include <vec.h>

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <math.h>

const vec VEC_UNDEFINED = {0, NULL};

/**
 * @brief
 */
vec vec_alloc(unsigned int dim)
{
	vec ret;
	ret.dim = dim;
	ret.elements = malloc(dim * sizeof(float));

	return ret;
}

/**
 * @brief
 */
vec vec_construct_default(unsigned int dim, float value)
{
	vec ret = vec_alloc(dim);

	for (unsigned int i = 0; i < dim; i++) {
		ret.elements[i] = value;
	}

	return ret;
}

/**
 * @brief
 */
vec vec_empty(unsigned int dim)
{
	return vec_construct_default(dim, 0.0f);
}

/**
 * @brief
 */
vec vec_copy(vec *v)
{
	vec ret;
	memcpy(&ret, v, sizeof(vec));
	return ret;
}

/**
 * @brief
 */
void vec_print(vec v)
{
	printf("[ ");

	for (unsigned int i = 0; i < v.dim; i++) {
		printf("%f", v.elements[i]);

		if (i < v.dim-1) {
			printf(", ");
		}
	}

	printf(" ]\n");
}

/**
 * @brief
 */
bool vec_equals(vec a, vec b)
{
	if (a.dim == b.dim) {
		for (unsigned int i = 0; i < a.dim; i++) {
			if (a.elements[i] != b.elements[i]) {
				return false;
			}
		}

		return true;
	}

	return false;
}

/**
 * @brief
 */
vec vec_add(vec a, vec b)
{
	if (a.dim != b.dim) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(a.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = a.elements[i] + b.elements[i];
	}

	return ret;
}

/**
 * @brief
 */
bool vec_add_to(vec *a, vec *b)
{
	if (a->dim != b->dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] += b->elements[i];
	}

	return true;
}

/**
 * @brief
 */
vec vec_sub(vec a, vec b)
{
	if (a.dim != b.dim) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(a.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = a.elements[i] - b.elements[i];
	}

	return ret;
}

/**
 * @brief
 */
bool vec_sub_from(vec *a, vec *b)
{
	if (a->dim != b->dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] -= b->elements[i];
	}

	return true;
}

/**
 * @brief
 */
vec vec_mult(vec a, vec b)
{
	if (a.dim != b.dim) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(a.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = a.elements[i] * b.elements[i];
	}

	return ret;
}

/**
 * @brief
 */
bool vec_mult_by(vec *a, vec *b)
{
	if (a->dim != b->dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] *= b->elements[i];
	}

	return true;
}

/**
 * @brief
 */
vec vec_div(vec a, vec b)
{
	if (a.dim != b.dim) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(a.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = a.elements[i] / b.elements[i];
	}

	return ret;
}

/**
 * @brief
 */
bool vec_div_by(vec *a, vec *b)
{
	if (a->dim != b->dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] /= b->elements[i];
	}

	return true;
}

/**
 * @brief
 */
vec scalar_mult(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] * k;
	}

	return ret;
}

/**
 * @brief
 */
void scalar_mult_ptr(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] *= k;
	}
}

/**
 * @brief
 */
vec scalar_div(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / k;
	}

	return ret;
}

/**
 * @brief
 */
void scalar_div_ptr(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= k;
	}
}

/**
 * @brief
 */
vec power(vec v, float k)
{
	vec ret = vec_alloc(v.dim);
	
	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = powf(v.elements[i], k);
	}

	return ret;
}

/**
 * @brief
 */
void power_of(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] = powf(v->elements[i], k);
	}
}

/**
 * @brief
 */
float dot(vec a, vec b)
{
	float ret = 0.0f;

	if (a.dim == b.dim) {
		for (unsigned int i = 0; i < a.dim; i++) {
			ret += a.elements[i] * b.elements[i];
		}
	}

	return ret;
}

/**
 * @brief
 */
bool orthogonal(vec a, vec b)
{
	return a.dim == b.dim ? dot(a, b) == 0.0f : false;
}

/**
 * @brief
 */
vec cross(vec a, vec b)
{
	if (a.dim != 3 || b.dim != 3) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(3);

	ret.elements[0] = (a.elements[1] * b.elements[2]) - (a.elements[2] * b.elements[1]);
	ret.elements[1] = -1 * ((a.elements[0] * b.elements[2]) - (a.elements[2] * b.elements[0]));
	ret.elements[2] = (a.elements[0] * b.elements[1]) - (a.elements[1] * b.elements[0]);

	return ret;
}

/**
 * @brief
 */
float magnitude(vec v)
{
	return sqrt(magnitude_squared(v));
}

/**
 * @brief
 */
float magnitude_squared(vec v)
{
	float ret = 0.0f;

	for (unsigned int i = 0; i < v.dim; i++) {
		ret += v.elements[i] * v.elements[i];
	}

	return ret;
}

/**
 * @brief
 */
vec normalized(vec v)
{
	vec ret = vec_alloc(v.dim);
	float mag_sq = magnitude_squared(v);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / mag_sq;
	}
	
	return ret;
}

/**
 * @brief
 */
void normalize(vec *v)
{
	float mag_sq = magnitude_squared(*v);
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= mag_sq;
	}
}

/**
 * @brief
 */
vec __vec_new(unsigned int dim, ...)
{
	vec ret = vec_alloc(dim);

	va_list list;
	va_start(list, dim);

	for (unsigned int i = 0; i < dim; i++) {
		ret.elements[i] = va_arg(list, double);
	}

	va_end(list);
	return ret;
}
