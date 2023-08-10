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

#ifndef __LIBM_H_
#define __LIBM_H_

/**
 * @brief		calculates the number of arguments in a __VA_ARGS__ list
 * 
 * @param type	the type of the argument in the list
 * @param ...	the list
 * 
 * @return		the number of arguments in the list
 */
#define NUMARGS(type, ...) (sizeof((type[]){0.0f,__VA_ARGS__}) / sizeof(type) - 1)

#endif // __LIBM_H_
