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

const vec VEC_UNDEFINED = { 0, NULL };

/**
 * @brief		Allocates memory for a vector
 * 
 * @param dim	Dimension of the vector
 * 
 * @return		The vector
 */
vec vec_alloc(unsigned int dim)
{
	vec ret;
	ret.dim = dim;
	ret.elements = malloc(dim * sizeof(float));

	return ret;
}

/**
 * @brief		Frees a vector's memory
 * 
 * @param v		The vector
 */
void vec_free(vec *v)
{
	free(v->elements);
	v->dim = 0;
	v->elements = NULL;
}

/**
 * @brief		Constructs a vector with a default value for all elements
 * 
 * @param dim	Dimension of the vector
 * @param value	Default value
 * 
 * @return		The vector
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
 * @brief		Constructs a vector with a default value of 0
 * 
 * @param dim	Dimension of the vector
 * 
 * @return		The vector
 */
vec vec_empty(unsigned int dim)
{
	return vec_construct_default(dim, 0.0f);
}

/**
 * @brief		Copies a vector
 * 
 * @param v		Pointer to a vector to be copied
 * 
 * @return		The copied vector
 */
vec vec_copy(vec *v)
{
	vec ret;
	memcpy(&ret, v, sizeof(vec));
	return ret;
}

/**
 * @brief		Prints vector's values
 * 
 * @param v		The vector
 */
void vec_print(vec v)
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

/**
 * @brief		Tests for equality between two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		True if the vectors are equal
 * 				Otherwise, false
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
 * @brief		Adds corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Sum of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
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
 * @brief		Adds corresponding elements of two vectors to another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_add_to(vec *a, vec b)
{
	if (a->dim != b.dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] += b.elements[i];
	}

	return true;
}

/**
 * @brief		Subtracts corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Difference of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
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
 * @brief		Subtracts corresponding elements of two vectors from another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_sub_from(vec *a, vec b)
{
	if (a->dim != b.dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] -= b.elements[i];
	}

	return true;
}

/**
 * @brief		Multiplies corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Product of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
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
 * @brief		Multiplies corresponding elements of two vectors by another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_mult_by(vec *a, vec b)
{
	if (a->dim != b.dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] *= b.elements[i];
	}

	return true;
}

/**
 * @brief		Divides corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Quotient of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
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
 * @brief		Divides corresponding elements of two vectors by another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_div_by(vec *a, vec b)
{
	if (a->dim != b.dim) {
		return false;
	}

	for (unsigned int i = 0; i < a->dim; i++) {
		a->elements[i] /= b.elements[i];
	}

	return true;
}

/**
 * @brief		Adds a scalar to the values of a vector
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The summed vector
 */
vec vec_scalar_add(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] + k;
	}

	return ret;
}

/**
 * @brief		Directly adds a scalar to the values of a vector
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_add_to(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] += k;
	}
}

/**
 * @brief		Subtracts a scalar from the values of a vector
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The subtracted vector
 */
vec vec_scalar_sub(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] - k;
	}

	return ret;
}

/**
 * @brief		Directly subtracts a scalar from the values of a vector
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_sub_from(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] -= k;
	}
}

/**
 * @brief		Multiplies the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The multiplied vector
 */
vec vec_scalar_mult(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] * k;
	}

	return ret;
}

/**
 * @brief		Directly multiplies the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_mult_by(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] *= k;
	}
}

/**
 * @brief		Divides the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The divided vector
 */
vec vec_scalar_div(vec v, float k)
{
	vec ret = vec_alloc(v.dim);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / k;
	}

	return ret;
}

/**
 * @brief		Directly divides the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_div_by(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= k;
	}
}

/**
 * @brief		Raises the values of a vector to a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The resultant vector
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
 * @brief		Directly raises the values of a vector to a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void power_of(vec *v, float k)
{
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] = powf(v->elements[i], k);
	}
}

/**
 * @brief		Calculates the dot product of two vectors
 * 
 * @param a		The first vector
 * @param b		The second vector
 * 
 * @return		The dot product of the vectors
 * 				0.0f if they have different dimensions
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
 * @brief		Determines whether two vectors are orthogonal or not
 * 
 * @param a		The first vector
 * @param b		The second vector
 * 
 * @return		True if the vectors have the same dimension and
 * 				the dot product is zero
 * 				Otherwise, false
 */
bool orthogonal(vec a, vec b)
{
	return a.dim == b.dim ? dot(a, b) == 0.0f : false;
}

/**
 * @brief		Calculates the cross product of two vectors in three dimensions
 * 				-> vector perpendicular to both vectors
 * 
 * @param a		The first vector
 * @param b		The second vector
 * 
 * @return		The cross product of the vectors
 * 				VEC_UNDEFINED if the vectors are not 3-dimensional
 */
vec cross(vec a, vec b)
{
	if (a.dim != 3 || b.dim != 3) {
		return VEC_UNDEFINED;
	}

	vec ret = vec_alloc(3);

	ret.elements[0] =
		(a.elements[1] * b.elements[2]) - (a.elements[2] * b.elements[1]);
	ret.elements[1] = -1 * ((a.elements[0] * b.elements[2]) -
							(a.elements[2] * b.elements[0]));
	ret.elements[2] =
		(a.elements[0] * b.elements[1]) - (a.elements[1] * b.elements[0]);

	return ret;
}

/**
 * @brief		Calculates the magnitude of the vector
 * 
 * @param v		The vector
 * 
 * @return		The magnitude
 * 				-> sqrt(a2 + b2 + ... + n2)
 */
float vec_magnitude(vec v)
{
	return sqrt(vec_magnitude_squared(v));
}

/**
 * @brief		Calculates the magnitude of the vector
 * 
 * @param v		The vector
 * 
 * @return		The magnitude
 * 				-> a2 + b2 + ... + n2
 */
float vec_magnitude_squared(vec v)
{
	float ret = 0.0f;

	for (unsigned int i = 0; i < v.dim; i++) {
		ret += v.elements[i] * v.elements[i];
	}

	return ret;
}

/**
 * @brief		Calculates the unit (normal) vector for a vector
 * 				-> divide each value by the magnitude
 * 
 * @param v		The vector
 * 
 * @return		The normal vector
 */
vec vec_normalized(vec v)
{
	vec ret = vec_alloc(v.dim);
	float mag_sq = vec_magnitude_squared(v);

	for (unsigned int i = 0; i < ret.dim; i++) {
		ret.elements[i] = v.elements[i] / mag_sq;
	}

	return ret;
}

/**
 * @brief		Calculates the dot product of two vectors
 * 
 * @param a		The pointer to the vector
 */
void vec_normalize(vec *v)
{
	float mag_sq = vec_magnitude_squared(*v);
	for (unsigned int i = 0; i < v->dim; i++) {
		v->elements[i] /= mag_sq;
	}
}

/**
 * @brief		Constructs a new vector with the specified values
 * @note		Arguments must be floats
 * 
 * @warning		This function is not to be called from outside of this
 * 				file. Use the wrapper __vec_new() instead.
 * 
 * @param ...	Values put into the vector
 * 
 * @return		The vector
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
