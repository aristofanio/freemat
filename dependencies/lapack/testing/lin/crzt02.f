      REAL             FUNCTION CRZT02( M, N, AF, LDA, TAU, WORK,
     $                 LWORK )
*
*  -- LAPACK test routine (version 3.0) --
*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,
*     Courant Institute, Argonne National Lab, and Rice University
*     June 30, 1999
*
*     .. Scalar Arguments ..
      INTEGER            LDA, LWORK, M, N
*     ..
*     .. Array Arguments ..
      COMPLEX            AF( LDA, * ), TAU( * ), WORK( LWORK )
*     ..
*
*  Purpose
*  =======
*
*  CRZT02 returns
*       || I - Q'*Q || / ( M * eps)
*  where the matrix Q is defined by the Householder transformations
*  generated by CTZRZF.
*
*  Arguments
*  =========
*
*  M       (input) INTEGER
*          The number of rows of the matrix AF.
*
*  N       (input) INTEGER
*          The number of columns of the matrix AF.
*
*  AF      (input) COMPLEX array, dimension (LDA,N)
*          The output of CTZRZF.
*
*  LDA     (input) INTEGER
*          The leading dimension of the array AF.
*
*  TAU     (input) COMPLEX array, dimension (M)
*          Details of the Householder transformations as returned by
*          CTZRZF.
*
*  WORK    (workspace) COMPLEX array, dimension (LWORK)
*
*  LWORK   (input) INTEGER
*          Length of WORK array. LWORK >= N*N+N.
*
*  =====================================================================
*
*     .. Parameters ..
      REAL               ZERO, ONE
      PARAMETER          ( ZERO = 0.0E0, ONE = 1.0E0 )
*     ..
*     .. Local Scalars ..
      INTEGER            I, INFO
*     ..
*     .. Local Arrays ..
      REAL               RWORK( 1 )
*     ..
*     .. External Functions ..
      REAL               CLANGE, SLAMCH
      EXTERNAL           CLANGE, SLAMCH
*     ..
*     .. External Subroutines ..
      EXTERNAL           CLASET, CUNMRZ, XERBLA
*     ..
*     .. Intrinsic Functions ..
      INTRINSIC          CMPLX, MAX, REAL
*     ..
*     .. Executable Statements ..
*
      CRZT02 = ZERO
*
      IF( LWORK.LT.N*N+N ) THEN
         CALL XERBLA( 'CRZT02', 7 )
         RETURN
      END IF
*
*     Quick return if possible
*
      IF( M.LE.0 .OR. N.LE.0 )
     $   RETURN
*
*     Q := I
*
      CALL CLASET( 'Full', N, N, CMPLX( ZERO ), CMPLX( ONE ), WORK, N )
*
*     Q := P(1) * ... * P(m) * Q
*
      CALL CUNMRZ( 'Left', 'No transpose', N, N, M, N-M, AF, LDA, TAU,
     $             WORK, N, WORK( N*N+1 ), LWORK-N*N, INFO )
*
*     Q := P(m)' * ... * P(1)' * Q
*
      CALL CUNMRZ( 'Left', 'Conjugate transpose', N, N, M, N-M, AF, LDA,
     $             TAU, WORK, N, WORK( N*N+1 ), LWORK-N*N, INFO )
*
*     Q := Q - I
*
      DO 10 I = 1, N
         WORK( ( I-1 )*N+I ) = WORK( ( I-1 )*N+I ) - ONE
   10 CONTINUE
*
      CRZT02 = CLANGE( 'One-norm', N, N, WORK, N, RWORK ) /
     $         ( SLAMCH( 'Epsilon' )*REAL( MAX( M, N ) ) )
      RETURN
*
*     End of CRZT02
*
      END
