/*
 * muldiv.hpp
 * Header definitions for muldiv.cpp.
 *
 * Author: Z. Wallace
 * Last edit: 12 Sept. 2017
 */


/*
 * Store a single entry in both the multiplication and division tables.
 */

#ifndef MULDIV_H
# define MULDIV_H

struct muldiv_entry {
    int mul;
    float div;
};

struct muldiv_entry** generate_tables(int n);
void print_tables(struct muldiv_entry** tables, int n);
void free_tables(struct muldiv_entry** tables, int n);

#endif /* MULDIV_H */
