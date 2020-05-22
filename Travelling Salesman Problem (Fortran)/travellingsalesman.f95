!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! PROGRAM P4
!             Traveling Salesman Problem in FORTRAN 95
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!  Program 4
! Solves the best path for the traveling salesman problem
! CS320-1
! 10-28-2019
! @author  Brian Arlantico cssc0443

PROGRAM P4

IMPLICIT NONE

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Variable declarations
INTEGER i , j, count, status, permutations, distance, best_dist
CHARACTER(30) :: filename
CHARACTER(20),ALLOCATABLE,DIMENSION(:) :: cities
INTEGER,ALLOCATABLE,DIMENSION(:,:) :: dist_table
INTEGER,ALLOCATABLE,DIMENSION(:) :: path, best_path


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Open the file and read number of cities
PRINT *, 'Program #4, cssc0443, Brian Arlantico'
PRINT *,"Enter filename: "
READ *, filename

OPEN(UNIT=19, FILE=filename, FORM="FORMATTED", ACTION="READ",&
                                     STATUS="OLD",IOSTAT=status)
    
IF (status /= 0) THEN
    PRINT *, "ERROR, could not open file for reading."
    stop
END IF

READ (UNIT=19, FMT=100) count


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Allocate memory for all needed arrays

ALLOCATE (cities(1:count),dist_table(1:count,1:count),path(1:count)&
            , best_path(1:count))
  
best_dist = 10000000
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Fill in arrays from data file

DO i = 1, count
    READ (UNIT=19, FMT = 200) cities(i)
    DO j = 1, count
        READ (UNIT=19, FMT = 100) dist_table(i,j)
    END DO
END DO

CLOSE(19)

DO i = 1, count 
    path(i) = i
    best_path(i) = i
END DO


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Use recursion to find minimal distance
call permute(2,count)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Print formatted output
PRINT *,

DO i = 1, count - 1

    write(*, '(1A20, 1A3, 1A20, 1A4, I5, A6)'), TRIM(cities(best_path(i))), ' to ', TRIM(cities(best_path(i+1)))&
            , ' -- ', dist_table(best_path(i),best_path(i+1)), ' miles'
END DO   

 write(*, '(1A20, 1A3, 1A20, 1A4, I5, A6)'), TRIM(cities(best_path(count))), ' to ', TRIM(cities(path(1)))&
            , ' -- ', dist_table(best_path(count),best_path(1)), ' miles'

PRINT *, 
write(*, '(1A20, I5, A6)') 'Best distance is :', best_dist, 'miles'

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Format labels
100 FORMAT (I6)
200 FORMAT (A)


CONTAINS
!Permute function
RECURSIVE SUBROUTINE permute(first, last)

INTEGER, INTENT(IN) :: first, last
INTEGER :: i, temp

    IF (first == last) THEN 
        distance = dist_table(1,path(2))
        DO i = 2, last-1 
            distance = distance + dist_table(path(i),path(i+1))
        END DO
        distance = distance + dist_table(path(last),path(1))

        permutations = permutations + 1

        IF (distance < best_dist) THEN
            best_dist = distance
            DO i = 2, count 
            best_path(i) = path(i)
            END DO
        END IF 

    ELSE 
        DO i = first, last 
            temp = path(i)
            path(i) = path(first)
            path(first) = temp

            call permute(first+1, last)

            temp = path(i)
            path(i) = path(first)
            path(first) = temp
        END DO
    END IF 


END SUBROUTINE permute    

