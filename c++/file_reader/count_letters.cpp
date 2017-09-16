/*
 * file_reader.cpp
 * Read in a text file, count the frequency of occurrence of each letter
 * and write the letter counts to a tab-separated-value file.
 *
 * Author: Z. Wallace
 * Last edit: 15 Sept. 2017
 */


#include<iostream>
#include<fstream>
#include<cctype>   // tolower()


void count_letters(std::ifstream& ifs, int* n) 
{
    char letter;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j', 'k','l','m',
			 'n','o','p','q','r','s','t','u','v','w','x','y','z'};

    while(ifs.get(letter)) {       // loop through file
	letter = tolower(letter);  // ensure case insensitivity
	
	for (int i = 0; i < sizeof(alphabet); i++) {
	    if (letter == alphabet[i])
		n[i] += 1;
	    else if (ifs.eof())
		break;
	    else continue;
	}
    }

    // Check frequency    
    for (int i = 0; i < 26; i++)
 	std::cout << n[i] << std::endl;

    return;
}


void write_counts(std::ofstream& ifs, int* n) 
{
    
} 


int main(int argc, char* argv[])
{
    const int ARR_SIZE = 26;   // number of letters to track
    
    int* n = new int[ARR_SIZE];
    std::ifstream ifs(argv[1]);

    // check if file can be opened
    if (!ifs.is_open()) {
	std::cerr << "Error opening file." << std::endl;
	exit(-1);
    }
    
    // initialize array to zeroes
    for (int i = 0; i < ARR_SIZE; i++) {
	n[i] = 0;
    }

    count_letters(ifs, n);
    ifs.close();   // Close after 
    
    delete [] n;   // deallocate n
    n = 0;         // reset to null pointer
}
