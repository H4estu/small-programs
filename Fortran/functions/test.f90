!======================================================================!
! File: test.f90                                                       !
! Compiled with ifort test.f90 -o test                                 !
! Last edit: 11 Aug 2016                                               !
!                                                                      !
! This program tests function behaviors in Fortran       9              !
!                                                                      !
!    A      :  first value                                             !
!    B      :  second value                                            !
!    C      :  third value                                             !
!    AV     :  average of A,B,C                                        !
!    AVSQ1  :  average of A,B,C squared                                !
!    AVSQ2  :  average of the squares of A,B,C                         !
!                                                                      !
! Input:   None                                                        !
! Output:  AV, AVSQ1, AVSQ                                             !
!======================================================================!

PROGRAM TEST
    IMPLICIT NONE
    
    REAL A, B, C, SEED 
    REAL AV, AVSQ1, AVSQ2
    REAL AVRAGE
    
    REAL CRYPA, CRYPB, CRYPC
    REAL CRYPTO
    
    ! Enter the data
    DATA A,B,C /2.0, 3.0, 5.0/
    ! Calculate the average of the numbers
    AV = AVRAGE(A,B,C)
    AVSQ1 = AVRAGE(A,B,C)**2
    AVSQ2 = AVRAGE(A**2,B**2,C**2)
    
    ! 'Encrypt' the numbers
    CRYPA = CRYPTO(A)
    CRYPB = CRYPTO(B)
    CRYPC = CRYPTO(C)
    
    PRINT *,'AVERAGES'
    PRINT *,'The average of the numbers is: ',AV
    PRINT *,'The average squared of the numbers is: ',AVSQ1
    PRINT *,'The average of the squared numbers is: ',AVSQ2

    PRINT *,'ENCRYPTED NUMBERS'
    PRINT *,'A encrypted: ',CRYPA
    PRINT *,'B encrypted: ',CRYPB
    PRINT *,'C encrypted: ',CRYPC
    
END


!----------------------------------------------------------------------
! FUNCTION AVRAGE                                                      
! Calculates the average of the three numbers passed to it.            
!                                                                      
! Inputs:   X,Y,Z                                                      
! Outputs:  AVRAGE                                                     
!----------------------------------------------------------------------

REAL FUNCTION AVRAGE(X,Y,Z) 
    REAL, INTENT(IN) :: X,Y,Z
    REAL SUM
    
    SUM = X+Y+Z
    AVRAGE = SUM/3.0
    
    RETURN 
END FUNCTION AVRAGE


!----------------------------------------------------------------------
! FUNCTION CRYPTO
! 'Encrypts' the inputed value by multiplying by 2 and dividing by pi
!
! Inputs: X
! Outputs: CRYPTO
!----------------------------------------------------------------------

REAL FUNCTION CRYPTO(X)
    REAL, INTENT(IN) :: X
    REAL, PARAMETER  :: PI = 3.14159

    CRYPTO = X*2.0 / PI

    RETURN
END FUNCTION CRYPTO
