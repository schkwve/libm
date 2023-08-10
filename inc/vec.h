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

typedef struct {
	unsigned int dim;
	float *elements;
} vec;

extern const vec VEC_UNDEFINED;

/**
 * @brief
 */
vec vec_alloc(unsigned int dim);

/**
 * @brief
 */
vec vec_construct_default(unsigned int dim, float value);

/**
 * @brief
 */
vec vec_empty(unsigned int dim);

/**
 * @brief
 */
vec vec_copy(vec *v);

/**
 * @brief
 */
void vec_print(vec v);

/**
 * @brief
 */
bool vec_equals(vec a, vec b);

/**
 * @brief
 */
vec vec_add(vec a, vec b);

/**
 * @brief
 */
bool vec_add_to(vec *a, vec *b);

/**
 * @brief
 */
vec vec_sub(vec a, vec b);

/**
 * @brief
 */
bool vec_sub_from(vec *a, vec *b);

/**
 * @brief
 */
vec vec_mult(vec a, vec b);

/**
 * @brief
 */
bool vec_mult_by(vec *a, vec *b);

/**
 * @brief
 */
vec vec_div(vec a, vec b);

/**
 * @brief
 */
bool vec_div_by(vec *a, vec *b);

/**
 * @brief
 */
vec scalar_mult(vec v, float k);

/**
 * @brief
 */
void scalar_mult_ptr(vec *v, float k);

/**
 * @brief
 */
vec scalar_div(vec v, float k);

/**
 * @brief
 */
void scalar_div_ptr(vec *v, float k);

/**
 * @brief
 */
vec power(vec v, float k);

/**
 * @brief
 */
void power_of(vec *v, float k);

/**
 * @brief
 */
float dot(vec a, vec b);

/**
 * @brief
 */
bool orthogonal(vec a, vec b);

/**
 * @brief
 */
vec cross(vec a, vec b);

/**
 * @brief
 */
float magnitude(vec v);

/**
 * @brief
 */
float magnitude_squared(vec v);

/**
 * @brief
 */
vec normalized(vec v);

/**
 * @brief
 */
void normalize(vec *v);

/**
 * @brief
 */
vec __vec_new(unsigned int dim, ...);

/**
 * @brief
 */
#define vec_new(...) __vec_new(NUMARGS(float, __VA_ARGS__), __VA_ARGS__)

#endif // __VEC_H_
