/*
 * muldiv.cpp
 * Create a dynamic 2D array of structs to store and print the 
 * multiplication and division tables for the values between an integer
 * 1 and n.
 *
 * Author: Z. Wallace
 * Last edit: 12 Sept. 2017
 */

#include <iostream>
#include <iomanip>   // to set decimal precision


/*
 * Store a single entry in both the multiplication and division tables.
 */
struct muldiv_entry {
    int mul;
    float div;
};


/*
 * Allocate space for an n x n array of structs and fill with the 
 * appropriate multiplication and division values.
 */
struct muldiv_entry** generate_tables(int n)
{
    int i, j;

    muldiv_entry** muldiv_arr = new muldiv_entry*[n];
    
    // Allocate space for 2D arrays on heap
    for (i = 0; i < n; i++) {
	muldiv_arr[i] = new muldiv_entry[n];
    }

    // Fill array with multiplication and division values.
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    muldiv_arr[i][j].mul = (i+1)*(j+1);
	    muldiv_arr[i][j].div = (float(i)+1)/(float(j)+1);
	}
    }

    return muldiv_arr;
}


/*
 * Inputs: 2D array, array size
 * Outputs: print the multiplication and divison tables.
 */
void print_tables(struct muldiv_entry** tables, int n)
{
    int i, j;

    // Print multiplication table
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Multiplication Table:" << std::endl;
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    std::cout << tables[i][j].mul << " ";
	}
	std::cout << "" << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    
    // Print division table
    std::cout << "Division Table:" << std::endl;
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    std::cout << std::setprecision(2) << 
	    std::fixed << tables[i][j].div << " ";
	}
	std::cout << "" << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}


/*
 * Release memory allocated to the 2D array.
 * Inputs: 2D array, array size
 * Outputs: None
 */
void free_tables(struct muldiv_entry** tables, int n)
{
    for (int i = 0; i < n; i++) {
	delete[] tables[i];
	std::cout << "deleted pointer: " << i << std::endl;
    }
    
    delete[] tables;
    std::cout << "deleted table " << std::endl;
}


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
