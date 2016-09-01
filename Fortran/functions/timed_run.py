# mult_run.py
# Basic shell script testing the speed of a python call to a Fortran 
# program.
# Clock time [time.clock()] should be used for benchmarking purposes as 
# it is more accurate than using time since epoch [time.time()].


from subprocess import call
import time

def main():
    reps = 1000
    
    print 'Executing test.f90...'
    print ' **************************************** '
    
    print 'Running ' + str(reps) + ' loops...'
    start = time.clock(); print 'start clock:', start
    # epstart = time.time()
    
    for i in range(reps):
        call(["./test"])
    
    end = time.clock(); print 'end clock', end
    # epend = time.time()
    clock_time = end - start
    # epoch_time = epend - epstart
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', clock_time
    # print 'Epoch time', epoch_time


if __name__ == "__main__":
    main()