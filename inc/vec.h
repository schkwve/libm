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

#ifndef __VEC_H_
#define __VEC_H_

#include <stdarg.h>
#include <stdbool.h>

/**
 * @brief	A structure representing a vector
 */
typedef struct {
	unsigned int dim;
	float *elements;
} vec;

// no dimension
extern const vec VEC_UNDEFINED;

/**
 * @brief		Allocates memory for a vector
 * 
 * @param dim	Dimension of the vector
 * 
 * @return		The vector
 */
vec vec_alloc(unsigned int dim);

/**
 * @brief		Frees a vector's memory
 * 
 * @param v		The vector
 */
void vec_free(vec *v);

/**
 * @brief		Constructs a vector with a default value for all elements
 * 
 * @param dim	Dimension of the vector
 * @param value	Default value
 * 
 * @return		The vector
 */
vec vec_construct_default(unsigned int dim, float value);

/**
 * @brief		Constructs a vector with a default value of 0
 * 
 * @param dim	Dimension of the vector
 * 
 * @return		The vector
 */
vec vec_empty(unsigned int dim);

/**
 * @brief		Copies a vector
 * 
 * @param v		Pointer to a vector to be copied
 * 
 * @return		The copied vector
 */
vec vec_copy(vec *v);

/**
 * @brief		Prints vector's values
 * 
 * @param v		The vector
 */
void vec_print(vec v);

/**
 * @brief		Tests for equality between two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		True if the vectors are equal
 * 				Otherwise, false
 */
bool vec_equals(vec a, vec b);

/**
 * @brief		Adds corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Sum of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
 */
vec vec_add(vec a, vec b);

/**
 * @brief		Adds corresponding elements of two vectors to another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_add_to(vec *a, vec b);

/**
 * @brief		Subtracts corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Difference of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
 */
vec vec_sub(vec a, vec b);

/**
 * @brief		Subtracts corresponding elements of two vectors from another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_sub_from(vec *a, vec b);

/**
 * @brief		Multiplies corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Product of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
 */
vec vec_mult(vec a, vec b);

/**
 * @brief		Multiplies corresponding elements of two vectors by another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_mult_by(vec *a, vec b);

/**
 * @brief		Divides corresponding elements of two vectors
 * 
 * @param a		First vector
 * @param b		Second vector
 * 
 * @return		Quotient of the two vectors
 * 				or VEC_UNDEFINED if the vectors' dimensions do not match.
 */
vec vec_div(vec a, vec b);

/**
 * @brief		Divides corresponding elements of two vectors by another vector
 * 
 * @param a		First vector (destination)
 * @param b		Second vector
 * 
 * @return		True if the vectors have matching dimensions
 * 				Otherwise, false
 */
bool vec_div_by(vec *a, vec b);

/**
 * @brief		Multiplies the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The multiplied vector
 */
vec vec_scalar_mult(vec v, float k);

/**
 * @brief		Directly multiplies the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_mult_by(vec *v, float k);

/**
 * @brief		Divides the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The divided vector
 */
vec vec_scalar_div(vec v, float k);

/**
 * @brief		Directly divides the values of a vector by a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void vec_scalar_div_by(vec *v, float k);

/**
 * @brief		Raises the values of a vector to a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 * 
 * @return		The resultant vector
 */
vec power(vec v, float k);

/**
 * @brief		Directly raises the values of a vector to a scalar
 * 
 * @param v		The vector
 * @param k		The scalar
 */
void power_of(vec *v, float k);

/**
 * @brief		Calculates the dot product of two vectors
 * 
 * @param a		The first vector
 * @param b		The second vector
 * 
 * @return		The dot product of the vectors
 * 				0.0f if they have different dimensions
 */
float dot(vec a, vec b);

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
bool orthogonal(vec a, vec b);

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
vec cross(vec a, vec b);

/**
 * @brief		Calculates the magnitude of the vector
 * 
 * @param v		The vector
 * 
 * @return		The magnitude
 * 				-> sqrt(a2 + b2 + ... + n2)
 */
float vec_magnitude(vec v);

/**
 * @brief		Calculates the magnitude of the vector
 * 
 * @param v		The vector
 * 
 * @return		The magnitude
 * 				-> a2 + b2 + ... + n2
 */
float vec_magnitude_squared(vec v);

/**
 * @brief		Calculates the unit (normal) vector for a vector
 * 				-> divide each value by the magnitude
 * 
 * @param v		The vector
 * 
 * @return		The normal vector
 */
vec vec_normalized(vec v);

/**
 * @brief		Calculates the dot product of two vectors
 * 
 * @param a		The pointer to the vector
 */
void vec_normalize(vec *v);

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
vec __vec_new(unsigned int dim, ...);

/**
 * @brief		Constructs a new vector with the specified values
 * @note		Arguments must be floats
 * 
 * @param ...	Values put into the vector
 * 
 * @return		The vector
 */
#define vec_new(...) __vec_new(NUMARGS(float, __VA_ARGS__), __VA_ARGS__)

#endif // __VEC_H_
