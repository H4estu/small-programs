!======================================================================!
!                                                                      !
! File: array.f90                                                      !
! Compiled with ifort array.f90 -o array                               !
! Last edit: 11 Aug 2016                                               !
!                                                                      !
! This program tests subroutine behaviors in Fortran                   !
!                                                                      !
!======================================================================!

PROGRAM ARRAY
    IMPLICIT NONE
    
    INTERFACE
        SUBROUTINE MEANVAR(X, N, MEAN, VAR)
            INTEGER, INTENT(IN)            :: N 
            REAL, DIMENSION(N), INTENT(IN) :: X
            REAL, INTENT(OUT)              :: MEAN, VAR
        END SUBROUTINE MEANVAR
        SUBROUTINE MEANVARARR(X, MEAN, VAR)
            REAL, DIMENSION(:), INTENT(IN) :: X
            REAL, INTENT(OUT)              :: MEAN, VAR
        END SUBROUTINE MEANVARARR
    END INTERFACE
    
    ! Local variable declarations
    INTEGER            :: I
    REAL               :: MEAN, VAR
    INTEGER, PARAMETER :: LENGTH = 20
    REAL, DIMENSION(LENGTH) :: ARR
    
!     DO I=1, N
!         X(I) = I
!     END DO
    ARR(1:LENGTH) = (/ (I**2.0/8, I=1,LENGTH) /) ! initialize values 

    CALL MEANVAR(ARR, LENGTH, MEAN, VAR)    ! Using DO constructs
    !CALL MEANVARARR(ARR, MEAN, VAR) ! Matrix manipulation only
END PROGRAM ARRAY


SUBROUTINE MEANVAR(X, N, MEAN, VAR)
!----------------------------------------------------------------------
!   SUBROUTINE MEANVAR
!   Calculates the mean and variance of array X of extent N
!   Uses DO loops to iterate through array X
!
!   Inputs:   X, N, MEAN, VAR
!   Outputs:  mean, variance
!----------------------------------------------------------------------
    INTEGER :: I
    REAL    :: SUM, SQDIFF
    
    INTEGER, INTENT(IN) :: N
    REAL, DIMENSION(N), INTENT(IN) :: X

    REAL, INTENT(OUT) :: MEAN, VAR
    
    PRINT*, '************** SUBROUTINE MEANVAR **************'
    
    ! Calculate mean
    DO I=1, N
        SUM = SUM + X(I) 
    END DO
    MEAN = SUM / N
    PRINT*, 'Mean: ', MEAN
    
    ! Calculate variance
    DO I=1, N
        SQDIFF = (X(I)-MEAN)**2 / (N-1) 
        VAR = VAR + SQDIFF
    END DO
    PRINT*, 'Variance: ', VAR
    PRINT*, '****************** END MEANVAR *****************'

    RETURN
END SUBROUTINE MEANVAR
SUBROUTINE MEANVARARR(X, MEAN, VAR)
!----------------------------------------------------------------------
!   SUBROUTINE MEANVARARR
!   Calculates the mean and variance of array X of extent N
!   Uses matrix functions on array X to calculate the results
!
!   Inputs:   X, MEAN, VAR
!   Outputs:  mean, variance
!----------------------------------------------------------------------
    ! REAL, DIMENSION(:), INTENT(IN) :: X
    REAL, INTENT(IN)  :: X(:)
    REAL, INTENT(OUT) :: MEAN, VAR
    
    PRINT*, '************* SUBROUTINE MEANVARARR ************'
    MEAN = SUM(X) / SIZE(X)
    PRINT*, 'Mean: ', MEAN
    
    VAR = SUM((X-MEAN)**2) / (SIZE(X)-1)
    PRINT*, 'Variance: ', VAR
    
    PRINT*, '**************** END MEANVARARR ***************'
    RETURN
END SUBROUTINE MEANVARARR