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

#include <matrix.h>

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

const mat MAT_UNDEFINED = { 0, 0, NULL };

/**
 * @brief		Allocate memory for a matrix
 * 
 * @param rows	Number of rows
 * @param cols	Number of columns
 * 
 * @return		The matrix
 */
mat matrix_alloc(unsigned int rows, unsigned int cols)
{
	mat ret;

	ret.rows = rows;
	ret.cols = cols;

	ret.elements = malloc(rows * sizeof(float));
	for (unsigned int i = 0; i < rows; i++) {
		ret.elements[i] = malloc(cols * sizeof(float));
	}

	return ret;
}

/**
 * @brief		Constructs an identity matrix
 * 				-> square matrix with 1's along the main diagonal
 * 
 * @param dim	The dimension of the matrix (rows/cols)
 * 
 * @return		The matrix
 */
mat matrix_identity(unsigned int dim)
{
	mat ret = matrix_alloc(dim, dim);

	for (unsigned int r = 0; r < dim; r++) {
		for (unsigned int c = 0; c < dim; c++) {
			ret.elements[r][c] = (r == c) ? 1.0f : 0.0f;
		}
	}

	return ret;
}

/**
 * @brief		Constructs an empty matrix
 * 
 * @param rows	Number of rows
 * @param cols	Number of columns
 * 
 * @return		The matrix
 */
mat matrix_zero(unsigned int rows, unsigned int cols)
{
	mat ret = matrix_alloc(rows, cols);

	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; c < cols; c++) {
			ret.elements[r][c] = 0.0f;
		}
	}

	return ret;
}

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
mat matrix_new(unsigned int rows, unsigned int cols, ...)
{
	mat ret = matrix_alloc(rows, cols);

	va_list list;
	va_start(list, cols);

	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; c < cols; c++) {
			ret.elements[r][c] = va_arg(list, double);
		}
	}

	va_end(list);

	return ret;
}

/**
 * @brief		Copies matrix's values
 * 
 * @param m		The pointer to the matrix to be copied
 * 
 * @return		The copied matrix
 */
mat matrix_copy(mat *m)
{
	(void)m;
	return matrix_zero(1, 1);
}

/**
 * @brief		Prints the values of a matrix
 * 
 * @param m		The matrix
 */
void matrix_print(mat m)
{
	for (unsigned int r = 0; r < m.rows; r++) {
		printf("\n");
		printf("|");
		for (unsigned int c = 0; c < m.cols; c++) {
			printf(" %f", m.elements[r][c]);
		}

		printf(" |");
	}
	printf("\n");
}
