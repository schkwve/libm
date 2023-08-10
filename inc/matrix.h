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

#ifndef __MATRIX_H_
#define __MATRIX_H_

/**
 * @brief		A structure representing a matrix
 */
typedef struct {
	unsigned int rows;
	unsigned int cols;
	float **elements;
} mat;

extern const mat MAT_UNDEFINED;

/**
 * @brief		Allocate memory for a matrix
 * 
 * @param rows	Number of rows
 * @param cols	Number of columns
 * 
 * @return		The matrix
 */
mat matrix_alloc(unsigned int rows, unsigned int cols);

/**
 * @brief		Constructs an identity matrix
 * 				-> square matrix with 1's along the main diagonal
 * 
 * @param dim	The dimension of the matrix (rows/cols)
 * 
 * @return		The matrix
 */
mat matrix_identity(unsigned int dim);

/**
 * @brief		Constructs an empty matrix
 * 
 * @param rows	Number of rows
 * @param cols	Number of columns
 * 
 * @return		The matrix
 */
mat matrix_zero(unsigned int rows, unsigned int cols);

/**
 * @brief		Constructs a new matrix with specified values
 * @note		Values must be passed as floats
 * @note		Values must be passed row by row
 * 
 * @param rows	Number of rows
 * @param cols	Number of columns
 * @param ...	The values to put in the matrix
 * 
 * @return		The matrix
 */
mat matrix_new(unsigned int rows, unsigned int cols, ...);

/**
 * @brief		Prints the values of a matrix
 * 
 * @param m		The matrix
 */
void matrix_print(mat m);

/**
 * @brief		Copies matrix's values
 * 
 * @param m		The pointer to the matrix to be copied
 * 
 * @return		The copied matrix
 */
mat matrix_copy(mat *m);

#endif // __MATRIX_H_
