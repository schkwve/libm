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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <libm/matrix.h>

const matrix MATRIX_UNDEFINED = {0, 0, NULL};

static matrix allocate(unsigned int rows, unsigned int cols)
{
	matrix ret;

	ret.rows = rows;
	ret.cols = cols;
	ret.elements = malloc(rows * cols * sizeof(float));

	for (unsigned int i = 0; i < rows; i++) {
		ret.elements[i] = malloc(cols * sizeof(float));
	}

	return ret;
}

matrix matrix_new(unsigned int rows, unsigned int cols, ...)
{
	matrix ret = allocate(rows, cols);

	va_list list;
	va_start(list, cols);

	for (unsigned int r = 0; r < rows; r++) {
		for (unsigned int c = 0; r < cols; c++) {
			ret.elements[r][c] = va_arg(list, double);
		}
	}

	va_end(list);
	return ret;
}

matrix matrix_copy(matrix m)
{
	return MATRIX_UNDEFINED;
}

matrix matrix_copyp(matrix *m)
{
	return MATRIX_UNDEFINED;
}

void matrix_dump(matrix m)
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

matrix matrix_identity(unsigned int dim)
{
	matrix ret = allocate(dim, dim);

	for (unsigned int r = 0; r < dim; r++) {
		for (unsigned int c = 0; c < dim; c++) {
			ret.elements[r][c] = (r == c) ? 1.f : .0f;
		}
	}

	return ret;
}

matrix matrix_zero(unsigned int rows, unsigned int cols)
{
	return MATRIX_UNDEFINED;
}