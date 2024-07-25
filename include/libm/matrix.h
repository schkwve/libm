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

#ifndef _LIBM_MATRIX_H
#define _LIBM_MATRIX_H

typedef struct {
	unsigned int rows;
	unsigned int cols;
	float **elements;
} matrix;

extern const matrix MATRIX_UNDEFINED;

matrix matrix_new(unsigned int rows, unsigned int cols, ...);

matrix matrix_copy(matrix m);
matrix matrix_copyp(matrix *m);

void matrix_dump(matrix m);

matrix matrix_identity(unsigned int dim);

matrix matrix_zero(unsigned int rows, unsigned int cols);

#endif /* _LIBM_MATRIX_H */