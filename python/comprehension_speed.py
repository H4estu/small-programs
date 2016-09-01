'''comprehension_speed.py
    Tests the speed of python's list and dictionary comprhensions vs 
    traditional for loop style.  Imports Vincent's 2001 ROMS/NEMURO data for 
    use in storing extra large data sets.  Hopefully manipulating larger 
    datasets more clearly illuminates the speed differences.

    *** Note ***
    Wall clock time seems to depend on the order these are run in.  If run 
    sequentially as currently written.  Speeds are loop < dict < list (i.e.     
    for loop is fastest).  If run one at a time, however, then it appears to
    go dict < list < loop (i.e. dictionary comprehension is fastest).  

    Author: Z. Wallace
    Last edit: 23 Aug. 2016
'''


import os

from netCDF4 import Dataset
from time import clock


def speed_forloop(datafile, nc):
    '''Tests the speed of the for loop at importing netcdf data.
    
        Returns: time taken to import the data
    '''
    
    print 'testing for-loop speed...'
    print ' **************************************** '
    
    start = clock(); print 'start clock:', start 
    varnamelist = []
    
    for i in nc.variables:
        if len(nc.variables[i].dimensions) == 4:
            varnamelist.append(nc.variables[i].name)
            varnamelist.append(nc.variables[i][:])
    end = clock(); print 'end clock', end
    
    loop_speed = end - start
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', loop_speed
    
    return loop_speed


def speed_listcomp(datafile, nc):
    '''Tests the speed of the list comprehension at importing netcdf data.
    
        Returns: time taken to import the data
    '''
    
    print 'testing list comprehension speed...'
    print ' **************************************** '
    
    start = clock(); print 'start clock:', start
    varnamelist = [nc.variables[x][:] for
        x in nc.variables if 
            len(nc.variables[x].dimensions) == 4]
    end = clock(); print 'end clock', end
    
    list_speed = end - start
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', list_speed
    
    return list_speed


def speed_dictcomp(datafile, nc):
    '''Tests the speed of the dictionary comprehension at importing netcdf data
        
        Returns: time taken to import the data
    '''
    
    print 'testing dictionary comprehension speed...'
    print ' **************************************** '
    
    start = clock(); print 'start clock:', start
    varnamelist = {nc.variables[x].name: nc.variables[x][:] 
        for x in nc.variables if len(nc.variables[x].dimensions) == 4}
    end = clock(); print 'end clock', end
   
    dict_speed = end - start
    
    print ' **************************************** '
    print 'Success!'
    print 'Wall clock time: ', dict_speed
    
    return dict_speed
    
    
def main():
    
    # load first file in directory
    filepath = '/Users/zach/Documents/MATLAB/VData/test_DEMO_GUI/nc_files/'
    datafile = filepath + os.listdir(filepath)[0]    
    
    # instantiate netcdf instance to use for all tests
    nc = Dataset(datafile, mode='r')
    
    print '*************************************************'
    loop_speed = speed_forloop(datafile, nc)
    list_speed = speed_listcomp(datafile, nc)
    dict_speed = speed_dictcomp(datafile, nc)
    
    nc.close()
    
    print '******************** Results ********************'
    print 'for-loop speed: ', loop_speed
    print 'list speed:     ', list_speed
    print 'dict speed:     ', dict_speed
    print '*************************************************'

if __name__ == '__main__':
    main()