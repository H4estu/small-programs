/*
 * muldiv_print.cpp
 * Main module for muldiv program.
 *
 * Author: Z. Wallace
 * Last edit: 12 Sept. 2017
 */


#include <iostream>

#include "muldiv.hpp"


int main(int argc, char *argv[])
{
    int n;
    muldiv_entry **muldiv_tables;
        
    // Command line argument checking.
    if (argc > 2) {
	std::cerr << "Too many command line arguments." << std::endl;
	exit(-1);
    } else if (argc < 2) {
	std::cerr << "Too few command line arguments." << std::endl;
	exit(-1);
    }
    if (!isdigit(*argv[1])) {
	std::cerr << "Command line argument not an integer" << std::endl;
	exit(-1);
    }

    n = atoi(argv[1]);
    std::cout << "Integer: " << n << std::endl;
    
    // Generate tables
    std::cout << "Generating tables..." << std::endl;
    muldiv_tables = generate_tables(n);
    
    // Print tables
    std::cout << "Printing tables..." << std::endl;
    print_tables(muldiv_tables, n);
    
    // Free memory
    std::cout << "Freeing memory..." << std::endl;
    free_tables(muldiv_tables, n);

    return 0;
}
