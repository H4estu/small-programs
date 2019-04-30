# find_string_from_hash.py

from math import remainder

def compute_hash_from_string(s, str_len, letters):
    '''find a 9 letter string of characters that contains only letters from 
        acdegilmnoprstuw such that the hash(the_string) is 910897038977002 
        if hash is defined by the following pseudo-code: 
            Int64 hash (String s) 
            { 
                Int64 h = 7 
                String letters = "acdegilmnoprstuw" 

                for(Int32 i = 0; i < s.length; i++) 
                { 
                    h = (h * 37 + letters.indexOf(s[i])) 
                } 
                return h 
            } 
        For example, if we were trying to find the 7 letter string where 
        hash(the_string) was 680131659347, the answer would be "leepadg".
    '''
    
    h = 7

    for i in range(str_len):
        h = h * 37 + letters.find(s[i])

    return h


def compute_string_from_hash(hv, str_len, letters):
    """Generator for computing a string of characters reversed from a hash
       defined by the following pseudocode:
                Int64 hash (String s) 
                { 
                    Int64 h = 7 
                    String letters = "acdegilmnoprstuw" 

                    for(Int32 i = 0; i < s.length; i++) 
                    { 
                        h = (h * 37 + letters.indexOf(s[i])) 
                    } 
                    return h 
                } 

        Input:
            hv(int) -- hashed numerical representation of a string.
            str_len(int) -- number of characters in the unhashed character 
                            string.
            letters(str) -- array of letters from which to select to compute
                            the unhashed string.  

        Yields: 
            A generator function containing the ith letter in the unhashed 
            string.  
    """
    for i in range(str_len):
        # Loop through indices of the letters array until the first factor of
        # hv is found.  The index modifier j used to compute this
        # factor of hv is used to look up the corresponding letter in the 
        # letters array.  That letter will become the ith letter in the 
        # unhashed string.  
        for j in range(len(letters)):
            h_prev = (hv - j) / 37
            if remainder(hv - j, h_prev) == 0:
                hv = h_prev
                yield(letters[j])
                break

def main():
    #the_string = "leepadg"
    #string_length = len(the_string)
    #hash_value = 680131659347
    #string_length = 7
    #hash_value = compute_hash_from_string(the_string, string_length, letters)

    # Set known parameters to be passed to generator function.
    letters = "acdegilmnoprstuw" 
    hash_value = 910897038977002
    string_length = 9

    # Instantiate generator function for efficient lazy evaluation of unhashed 
    # string.
    string_value_generator = compute_string_from_hash(
        hash_value, string_length, letters)

    # Iterate over generator object to build unhashed string.  
    string_value = "".join(
        reversed([letter for letter in string_value_generator]))

    msg = "The string computed from hash {} is {}"
    print(msg.format(hash_value, string_value))

    # Verify the solution by rerunning the string through the hash function
    hv = compute_hash_from_string(string_value, string_length, letters)
    msg = "The hash of the string {} is {}"
    print(msg.format(string_value, hv))

    if hash_value == hv:
        print("Success!")
    else:
        print("Values do not match.")

if __name__ == "__main__":
    main()
