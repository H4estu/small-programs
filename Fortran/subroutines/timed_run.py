'''multi_run.py
Basic shell script calling one of several Fortran program based on 
arguments passed in at the command line.
Clock time [time.clock()] should be used for benchmarking purposes as 
it is more accurate than using time since epoch [time.time()].

*** Usage ***
python timed_run.py -<test>
tests available:
- f: function test -- test function aspect of the Fortran language
- s: subroutine test -- test subroutine aspect of the Fortran

Author: Z. Wallace
Last edit: 15 Aug 2016
'''


#from subprocess import call
from subprocess import call
from time import clock

import sys


def timed_function():
    
    reps = 1000
    
    print 'Executing test.f90...'
    print ' **************************************** '
    
    print 'Running ' + str(reps) + ' loops...'
    start = clock(); print 'start clock:', start
    # epstart = time.time()
    
    for i in range(reps):
        call(["/Users/zach/Documents/Code/Fortran/functions/test"])
    
    end = clock(); print 'end clock', end
    # epend = time.time()
    clock_time = end - start
    # epoch_time = epend - epstart
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', clock_time
    # print 'Epoch time', epoch_time
    
    
def timed_subroutine():
   
    reps = 1000
    
    print 'Executing array.f90...'
    print ' **************************************** '
    
    print 'Running ' + str(reps) + ' loops...'
    start = clock(); print 'start clock:', start
    # epstart = time.time()
    
    for i in range(reps):
        call(["/Users/zach/Documents/Code/Fortran/subroutines/array"])
    
    end = clock(); print 'end clock', end
    # epend = time.time()
    clock_time = end - start
    # epoch_time = epend - epstart
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', clock_time
    # print 'Epoch time', epoch_time


def choose_tests(test):
    
    t1 = '-f'
    t2 = '-s' 
    
    if test == t1:
        timed_function()
    elif test == t2:
        timed_subroutine()
    else:
        print 'Command line argument not recognized.'
        print 'Options are -f or -s'
        print 'Try again:'
        choose_again()
 
        
def choose_again():
    flag = 0
    op1 = '-f'
    op2 = '-s'
    
    while flag == 0:
        usr_str = raw_input()
        if usr_str == op1:
            choose_tests(usr_str)
            flag = 1
        elif usr_str == op2:
            choose_tests(usr_str)
            flag = 1
        else:
            print 'Command line argument not recognized.'
            print 'Options are -f or -s'
            print 'Try again:'
    
    
def main():
    
    if len(sys.argv) < 2:
        print 'No tests stated.  Exiting...'
        sys.exit(0)
    elif len(sys.argv) > 2:
        print 'Too many command line arguments.  Exiting...'
        sys.exit(0)
    else:        
        run = sys.argv[1]
        choose_tests(run)


if __name__ == "__main__":
    main()