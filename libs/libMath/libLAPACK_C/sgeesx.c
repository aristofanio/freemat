/* ../../../dependencies/lapack/src/sgeesx.f -- translated by f2c (version 20061008).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__8 = 8;
static integer c_n1 = -1;
static integer c__4 = 4;

/* Subroutine */ int sgeesx_(char *jobvs, char *sort, L_fp select, char *
	sense, integer *n, real *a, integer *lda, integer *sdim, real *wr, 
	real *wi, real *vs, integer *ldvs, real *rconde, real *rcondv, real *
	work, integer *lwork, integer *iwork, integer *liwork, logical *bwork,
	 integer *info, ftnlen jobvs_len, ftnlen sort_len, ftnlen sense_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, vs_dim1, vs_offset, i__1, i__2, i__3, i__4;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, k, i1, i2, ip, ihi, ilo;
    static real dum[1], eps;
    static integer ibal, maxb;
    static real anrm;
    static integer ierr, itau, iwrk, inxt, icond, ieval;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static logical cursl;
    extern /* Subroutine */ int scopy_(integer *, real *, integer *, real *, 
	    integer *), sswap_(integer *, real *, integer *, real *, integer *
	    );
    static logical lst2sl;
    extern /* Subroutine */ int slabad_(real *, real *);
    static logical scalea;
    static real cscale;
    extern /* Subroutine */ int sgebak_(char *, char *, integer *, integer *, 
	    integer *, real *, integer *, real *, integer *, integer *, 
	    ftnlen, ftnlen), sgebal_(char *, integer *, real *, integer *, 
	    integer *, integer *, real *, integer *, ftnlen);
    extern doublereal slamch_(char *, ftnlen), slange_(char *, integer *, 
	    integer *, real *, integer *, real *, ftnlen);
    extern /* Subroutine */ int sgehrd_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, integer *, integer *), xerbla_(char 
	    *, integer *, ftnlen);
    extern integer ilaenv_(integer *, char *, char *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    static real bignum;
    extern /* Subroutine */ int slascl_(char *, integer *, integer *, real *, 
	    real *, integer *, integer *, real *, integer *, integer *, 
	    ftnlen), slacpy_(char *, integer *, integer *, real *, integer *, 
	    real *, integer *, ftnlen);
    static logical wantsb, wantse, lastsl;
    extern /* Subroutine */ int sorghr_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, integer *, integer *), shseqr_(char 
	    *, char *, integer *, integer *, integer *, real *, integer *, 
	    real *, real *, real *, integer *, real *, integer *, integer *, 
	    ftnlen, ftnlen);
    static integer minwrk, maxwrk;
    static logical wantsn;
    static real smlnum;
    static integer hswork;
    extern /* Subroutine */ int strsen_(char *, char *, logical *, integer *, 
	    real *, integer *, real *, integer *, real *, real *, integer *, 
	    real *, real *, real *, integer *, integer *, integer *, integer *
	    , ftnlen, ftnlen);
    static logical wantst, wantsv, wantvs;


/*  -- LAPACK driver routine (version 3.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     June 30, 1999 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */
/*     .. Function Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  SGEESX computes for an N-by-N real nonsymmetric matrix A, the */
/*  eigenvalues, the real Schur form T, and, optionally, the matrix of */
/*  Schur vectors Z.  This gives the Schur factorization A = Z*T*(Z**T). */

/*  Optionally, it also orders the eigenvalues on the diagonal of the */
/*  real Schur form so that selected eigenvalues are at the top left; */
/*  computes a reciprocal condition number for the average of the */
/*  selected eigenvalues (RCONDE); and computes a reciprocal condition */
/*  number for the right invariant subspace corresponding to the */
/*  selected eigenvalues (RCONDV).  The leading columns of Z form an */
/*  orthonormal basis for this invariant subspace. */

/*  For further explanation of the reciprocal condition numbers RCONDE */
/*  and RCONDV, see Section 4.10 of the LAPACK Users' Guide (where */
/*  these quantities are called s and sep respectively). */

/*  A real matrix is in real Schur form if it is upper quasi-triangular */
/*  with 1-by-1 and 2-by-2 blocks. 2-by-2 blocks will be standardized in */
/*  the form */
/*            [  a  b  ] */
/*            [  c  a  ] */

/*  where b*c < 0. The eigenvalues of such a block are a +- sqrt(bc). */

/*  Arguments */
/*  ========= */

/*  JOBVS   (input) CHARACTER*1 */
/*          = 'N': Schur vectors are not computed; */
/*          = 'V': Schur vectors are computed. */

/*  SORT    (input) CHARACTER*1 */
/*          Specifies whether or not to order the eigenvalues on the */
/*          diagonal of the Schur form. */
/*          = 'N': Eigenvalues are not ordered; */
/*          = 'S': Eigenvalues are ordered (see SELECT). */

/*  SELECT  (input) LOGICAL FUNCTION of two REAL arguments */
/*          SELECT must be declared EXTERNAL in the calling subroutine. */
/*          If SORT = 'S', SELECT is used to select eigenvalues to sort */
/*          to the top left of the Schur form. */
/*          If SORT = 'N', SELECT is not referenced. */
/*          An eigenvalue WR(j)+sqrt(-1)*WI(j) is selected if */
/*          SELECT(WR(j),WI(j)) is true; i.e., if either one of a */
/*          complex conjugate pair of eigenvalues is selected, then both */
/*          are.  Note that a selected complex eigenvalue may no longer */
/*          satisfy SELECT(WR(j),WI(j)) = .TRUE. after ordering, since */
/*          ordering may change the value of complex eigenvalues */
/*          (especially if the eigenvalue is ill-conditioned); in this */
/*          case INFO may be set to N+3 (see INFO below). */

/*  SENSE   (input) CHARACTER*1 */
/*          Determines which reciprocal condition numbers are computed. */
/*          = 'N': None are computed; */
/*          = 'E': Computed for average of selected eigenvalues only; */
/*          = 'V': Computed for selected right invariant subspace only; */
/*          = 'B': Computed for both. */
/*          If SENSE = 'E', 'V' or 'B', SORT must equal 'S'. */

/*  N       (input) INTEGER */
/*          The order of the matrix A. N >= 0. */

/*  A       (input/output) REAL array, dimension (LDA, N) */
/*          On entry, the N-by-N matrix A. */
/*          On exit, A is overwritten by its real Schur form T. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(1,N). */

/*  SDIM    (output) INTEGER */
/*          If SORT = 'N', SDIM = 0. */
/*          If SORT = 'S', SDIM = number of eigenvalues (after sorting) */
/*                         for which SELECT is true. (Complex conjugate */
/*                         pairs for which SELECT is true for either */
/*                         eigenvalue count as 2.) */

/*  WR      (output) REAL array, dimension (N) */
/*  WI      (output) REAL array, dimension (N) */
/*          WR and WI contain the real and imaginary parts, respectively, */
/*          of the computed eigenvalues, in the same order that they */
/*          appear on the diagonal of the output Schur form T.  Complex */
/*          conjugate pairs of eigenvalues appear consecutively with the */
/*          eigenvalue having the positive imaginary part first. */

/*  VS      (output) REAL array, dimension (LDVS,N) */
/*          If JOBVS = 'V', VS contains the orthogonal matrix Z of Schur */
/*          vectors. */
/*          If JOBVS = 'N', VS is not referenced. */

/*  LDVS    (input) INTEGER */
/*          The leading dimension of the array VS.  LDVS >= 1, and if */
/*          JOBVS = 'V', LDVS >= N. */

/*  RCONDE  (output) REAL */
/*          If SENSE = 'E' or 'B', RCONDE contains the reciprocal */
/*          condition number for the average of the selected eigenvalues. */
/*          Not referenced if SENSE = 'N' or 'V'. */

/*  RCONDV  (output) REAL */
/*          If SENSE = 'V' or 'B', RCONDV contains the reciprocal */
/*          condition number for the selected right invariant subspace. */
/*          Not referenced if SENSE = 'N' or 'E'. */

/*  WORK    (workspace/output) REAL array, dimension (LWORK) */
/*          On exit, if INFO = 0, WORK(1) returns the optimal LWORK. */

/*  LWORK   (input) INTEGER */
/*          The dimension of the array WORK.  LWORK >= max(1,3*N). */
/*          Also, if SENSE = 'E' or 'V' or 'B', */
/*          LWORK >= N+2*SDIM*(N-SDIM), where SDIM is the number of */
/*          selected eigenvalues computed by this routine.  Note that */
/*          N+2*SDIM*(N-SDIM) <= N+N*N/2. */
/*          For good performance, LWORK must generally be larger. */

/*  IWORK   (workspace/output) INTEGER array, dimension (LIWORK) */
/*          Not referenced if SENSE = 'N' or 'E'. */
/*          On exit, if INFO = 0, IWORK(1) returns the optimal LIWORK. */

/*  LIWORK  (input) INTEGER */
/*          The dimension of the array IWORK. */
/*          LIWORK >= 1; if SENSE = 'V' or 'B', LIWORK >= SDIM*(N-SDIM). */

/*  BWORK   (workspace) LOGICAL array, dimension (N) */
/*          Not referenced if SORT = 'N'. */

/*  INFO    (output) INTEGER */
/*          = 0: successful exit */
/*          < 0: if INFO = -i, the i-th argument had an illegal value. */
/*          > 0: if INFO = i, and i is */
/*             <= N: the QR algorithm failed to compute all the */
/*                   eigenvalues; elements 1:ILO-1 and i+1:N of WR and WI */
/*                   contain those eigenvalues which have converged; if */
/*                   JOBVS = 'V', VS contains the transformation which */
/*                   reduces A to its partially converged Schur form. */
/*             = N+1: the eigenvalues could not be reordered because some */
/*                   eigenvalues were too close to separate (the problem */
/*                   is very ill-conditioned); */
/*             = N+2: after reordering, roundoff changed values of some */
/*                   complex eigenvalues so that leading eigenvalues in */
/*                   the Schur form no longer satisfy SELECT=.TRUE.  This */
/*                   could also be caused by underflow due to scaling. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. Local Arrays .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Test the input arguments */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --wr;
    --wi;
    vs_dim1 = *ldvs;
    vs_offset = 1 + vs_dim1;
    vs -= vs_offset;
    --work;
    --iwork;
    --bwork;

    /* Function Body */
    *info = 0;
    wantvs = lsame_(jobvs, "V", (ftnlen)1, (ftnlen)1);
    wantst = lsame_(sort, "S", (ftnlen)1, (ftnlen)1);
    wantsn = lsame_(sense, "N", (ftnlen)1, (ftnlen)1);
    wantse = lsame_(sense, "E", (ftnlen)1, (ftnlen)1);
    wantsv = lsame_(sense, "V", (ftnlen)1, (ftnlen)1);
    wantsb = lsame_(sense, "B", (ftnlen)1, (ftnlen)1);
    if (! wantvs && ! lsame_(jobvs, "N", (ftnlen)1, (ftnlen)1)) {
	*info = -1;
    } else if (! wantst && ! lsame_(sort, "N", (ftnlen)1, (ftnlen)1)) {
	*info = -2;
    } else if (! (wantsn || wantse || wantsv || wantsb) || ! wantst && ! 
	    wantsn) {
	*info = -4;
    } else if (*n < 0) {
	*info = -5;
    } else if (*lda < max(1,*n)) {
	*info = -7;
    } else if (*ldvs < 1 || wantvs && *ldvs < *n) {
	*info = -12;
    }

/*     Compute workspace */
/*      (Note: Comments in the code beginning "RWorkspace:" describe the */
/*       minimal amount of real workspace needed at that point in the */
/*       code, as well as the preferred amount for good performance. */
/*       IWorkspace refers to integer workspace. */
/*       NB refers to the optimal block size for the immediately */
/*       following subroutine, as returned by ILAENV. */
/*       HSWORK refers to the workspace preferred by SHSEQR, as */
/*       calculated below. HSWORK is computed assuming ILO=1 and IHI=N, */
/*       the worst case. */
/*       If SENSE = 'E', 'V' or 'B', then the amount of workspace needed */
/*       depends on SDIM, which is computed by the routine STRSEN later */
/*       in the code.) */

    minwrk = 1;
    if (*info == 0 && *lwork >= 1) {
	maxwrk = (*n << 1) + *n * ilaenv_(&c__1, "SGEHRD", " ", n, &c__1, n, &
		c__0, (ftnlen)6, (ftnlen)1);
/* Computing MAX */
	i__1 = 1, i__2 = *n * 3;
	minwrk = max(i__1,i__2);
	if (! wantvs) {
/* Computing MAX */
	    i__1 = ilaenv_(&c__8, "SHSEQR", "SN", n, &c__1, n, &c_n1, (ftnlen)
		    6, (ftnlen)2);
	    maxb = max(i__1,2);
/* Computing MIN */
/* Computing MAX */
	    i__3 = 2, i__4 = ilaenv_(&c__4, "SHSEQR", "SN", n, &c__1, n, &
		    c_n1, (ftnlen)6, (ftnlen)2);
	    i__1 = min(maxb,*n), i__2 = max(i__3,i__4);
	    k = min(i__1,i__2);
/* Computing MAX */
	    i__1 = k * (k + 2), i__2 = *n << 1;
	    hswork = max(i__1,i__2);
/* Computing MAX */
	    i__1 = maxwrk, i__2 = *n + hswork, i__1 = max(i__1,i__2);
	    maxwrk = max(i__1,1);
	} else {
/* Computing MAX */
	    i__1 = maxwrk, i__2 = (*n << 1) + (*n - 1) * ilaenv_(&c__1, "SOR"
		    "GHR", " ", n, &c__1, n, &c_n1, (ftnlen)6, (ftnlen)1);
	    maxwrk = max(i__1,i__2);
/* Computing MAX */
	    i__1 = ilaenv_(&c__8, "SHSEQR", "SV", n, &c__1, n, &c_n1, (ftnlen)
		    6, (ftnlen)2);
	    maxb = max(i__1,2);
/* Computing MIN */
/* Computing MAX */
	    i__3 = 2, i__4 = ilaenv_(&c__4, "SHSEQR", "SV", n, &c__1, n, &
		    c_n1, (ftnlen)6, (ftnlen)2);
	    i__1 = min(maxb,*n), i__2 = max(i__3,i__4);
	    k = min(i__1,i__2);
/* Computing MAX */
	    i__1 = k * (k + 2), i__2 = *n << 1;
	    hswork = max(i__1,i__2);
/* Computing MAX */
	    i__1 = maxwrk, i__2 = *n + hswork, i__1 = max(i__1,i__2);
	    maxwrk = max(i__1,1);
	}
	work[1] = (real) maxwrk;
    }
    if (*lwork < minwrk) {
	*info = -16;
    }
    if (*liwork < 1) {
	*info = -18;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("SGEESX", &i__1, (ftnlen)6);
	return 0;
    }

/*     Quick return if possible */

    if (*n == 0) {
	*sdim = 0;
	return 0;
    }

/*     Get machine constants */

    eps = slamch_("P", (ftnlen)1);
    smlnum = slamch_("S", (ftnlen)1);
    bignum = 1.f / smlnum;
    slabad_(&smlnum, &bignum);
    smlnum = sqrt(smlnum) / eps;
    bignum = 1.f / smlnum;

/*     Scale A if max element outside range [SMLNUM,BIGNUM] */

    anrm = slange_("M", n, n, &a[a_offset], lda, dum, (ftnlen)1);
    scalea = FALSE_;
    if (anrm > 0.f && anrm < smlnum) {
	scalea = TRUE_;
	cscale = smlnum;
    } else if (anrm > bignum) {
	scalea = TRUE_;
	cscale = bignum;
    }
    if (scalea) {
	slascl_("G", &c__0, &c__0, &anrm, &cscale, n, n, &a[a_offset], lda, &
		ierr, (ftnlen)1);
    }

/*     Permute the matrix to make it more nearly triangular */
/*     (RWorkspace: need N) */

    ibal = 1;
    sgebal_("P", n, &a[a_offset], lda, &ilo, &ihi, &work[ibal], &ierr, (
	    ftnlen)1);

/*     Reduce to upper Hessenberg form */
/*     (RWorkspace: need 3*N, prefer 2*N+N*NB) */

    itau = *n + ibal;
    iwrk = *n + itau;
    i__1 = *lwork - iwrk + 1;
    sgehrd_(n, &ilo, &ihi, &a[a_offset], lda, &work[itau], &work[iwrk], &i__1,
	     &ierr);

    if (wantvs) {

/*        Copy Householder vectors to VS */

	slacpy_("L", n, n, &a[a_offset], lda, &vs[vs_offset], ldvs, (ftnlen)1)
		;

/*        Generate orthogonal matrix in VS */
/*        (RWorkspace: need 3*N-1, prefer 2*N+(N-1)*NB) */

	i__1 = *lwork - iwrk + 1;
	sorghr_(n, &ilo, &ihi, &vs[vs_offset], ldvs, &work[itau], &work[iwrk],
		 &i__1, &ierr);
    }

    *sdim = 0;

/*     Perform QR iteration, accumulating Schur vectors in VS if desired */
/*     (RWorkspace: need N+1, prefer N+HSWORK (see comments) ) */

    iwrk = itau;
    i__1 = *lwork - iwrk + 1;
    shseqr_("S", jobvs, n, &ilo, &ihi, &a[a_offset], lda, &wr[1], &wi[1], &vs[
	    vs_offset], ldvs, &work[iwrk], &i__1, &ieval, (ftnlen)1, (ftnlen)
	    1);
    if (ieval > 0) {
	*info = ieval;
    }

/*     Sort eigenvalues if desired */

    if (wantst && *info == 0) {
	if (scalea) {
	    slascl_("G", &c__0, &c__0, &cscale, &anrm, n, &c__1, &wr[1], n, &
		    ierr, (ftnlen)1);
	    slascl_("G", &c__0, &c__0, &cscale, &anrm, n, &c__1, &wi[1], n, &
		    ierr, (ftnlen)1);
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    bwork[i__] = (*select)(&wr[i__], &wi[i__]);
/* L10: */
	}

/*        Reorder eigenvalues, transform Schur vectors, and compute */
/*        reciprocal condition numbers */
/*        (RWorkspace: if SENSE is not 'N', need N+2*SDIM*(N-SDIM) */
/*                     otherwise, need N ) */
/*        (IWorkspace: if SENSE is 'V' or 'B', need SDIM*(N-SDIM) */
/*                     otherwise, need 0 ) */

	i__1 = *lwork - iwrk + 1;
	strsen_(sense, jobvs, &bwork[1], n, &a[a_offset], lda, &vs[vs_offset],
		 ldvs, &wr[1], &wi[1], sdim, rconde, rcondv, &work[iwrk], &
		i__1, &iwork[1], liwork, &icond, (ftnlen)1, (ftnlen)1);
	if (! wantsn) {
/* Computing MAX */
	    i__1 = maxwrk, i__2 = *n + (*sdim << 1) * (*n - *sdim);
	    maxwrk = max(i__1,i__2);
	}
	if (icond == -15) {

/*           Not enough real workspace */

	    *info = -16;
	} else if (icond == -17) {

/*           Not enough integer workspace */

	    *info = -18;
	} else if (icond > 0) {

/*           STRSEN failed to reorder or to restore standard Schur form */

	    *info = icond + *n;
	}
    }

    if (wantvs) {

/*        Undo balancing */
/*        (RWorkspace: need N) */

	sgebak_("P", "R", n, &ilo, &ihi, &work[ibal], n, &vs[vs_offset], ldvs,
		 &ierr, (ftnlen)1, (ftnlen)1);
    }

    if (scalea) {

/*        Undo scaling for the Schur form of A */

	slascl_("H", &c__0, &c__0, &cscale, &anrm, n, n, &a[a_offset], lda, &
		ierr, (ftnlen)1);
	i__1 = *lda + 1;
	scopy_(n, &a[a_offset], &i__1, &wr[1], &c__1);
	if ((wantsv || wantsb) && *info == 0) {
	    dum[0] = *rcondv;
	    slascl_("G", &c__0, &c__0, &cscale, &anrm, &c__1, &c__1, dum, &
		    c__1, &ierr, (ftnlen)1);
	    *rcondv = dum[0];
	}
	if (cscale == smlnum) {

/*           If scaling back towards underflow, adjust WI if an */
/*           offdiagonal element of a 2-by-2 block in the Schur form */
/*           underflows. */

	    if (ieval > 0) {
		i1 = ieval + 1;
		i2 = ihi - 1;
		i__1 = ilo - 1;
		slascl_("G", &c__0, &c__0, &cscale, &anrm, &i__1, &c__1, &wi[
			1], n, &ierr, (ftnlen)1);
	    } else if (wantst) {
		i1 = 1;
		i2 = *n - 1;
	    } else {
		i1 = ilo;
		i2 = ihi - 1;
	    }
	    inxt = i1 - 1;
	    i__1 = i2;
	    for (i__ = i1; i__ <= i__1; ++i__) {
		if (i__ < inxt) {
		    goto L20;
		}
		if (wi[i__] == 0.f) {
		    inxt = i__ + 1;
		} else {
		    if (a[i__ + 1 + i__ * a_dim1] == 0.f) {
			wi[i__] = 0.f;
			wi[i__ + 1] = 0.f;
		    } else if (a[i__ + 1 + i__ * a_dim1] != 0.f && a[i__ + (
			    i__ + 1) * a_dim1] == 0.f) {
			wi[i__] = 0.f;
			wi[i__ + 1] = 0.f;
			if (i__ > 1) {
			    i__2 = i__ - 1;
			    sswap_(&i__2, &a[i__ * a_dim1 + 1], &c__1, &a[(
				    i__ + 1) * a_dim1 + 1], &c__1);
			}
			if (*n > i__ + 1) {
			    i__2 = *n - i__ - 1;
			    sswap_(&i__2, &a[i__ + (i__ + 2) * a_dim1], lda, &
				    a[i__ + 1 + (i__ + 2) * a_dim1], lda);
			}
			sswap_(n, &vs[i__ * vs_dim1 + 1], &c__1, &vs[(i__ + 1)
				 * vs_dim1 + 1], &c__1);
			a[i__ + (i__ + 1) * a_dim1] = a[i__ + 1 + i__ * 
				a_dim1];
			a[i__ + 1 + i__ * a_dim1] = 0.f;
		    }
		    inxt = i__ + 2;
		}
L20:
		;
	    }
	}
	i__1 = *n - ieval;
/* Computing MAX */
	i__3 = *n - ieval;
	i__2 = max(i__3,1);
	slascl_("G", &c__0, &c__0, &cscale, &anrm, &i__1, &c__1, &wi[ieval + 
		1], &i__2, &ierr, (ftnlen)1);
    }

    if (wantst && *info == 0) {

/*        Check if reordering successful */

	lastsl = TRUE_;
	lst2sl = TRUE_;
	*sdim = 0;
	ip = 0;
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    cursl = (*select)(&wr[i__], &wi[i__]);
	    if (wi[i__] == 0.f) {
		if (cursl) {
		    ++(*sdim);
		}
		ip = 0;
		if (cursl && ! lastsl) {
		    *info = *n + 2;
		}
	    } else {
		if (ip == 1) {

/*                 Last eigenvalue of conjugate pair */

		    cursl = cursl || lastsl;
		    lastsl = cursl;
		    if (cursl) {
			*sdim += 2;
		    }
		    ip = -1;
		    if (cursl && ! lst2sl) {
			*info = *n + 2;
		    }
		} else {

/*                 First eigenvalue of conjugate pair */

		    ip = 1;
		}
	    }
	    lst2sl = lastsl;
	    lastsl = cursl;
/* L30: */
	}
    }

    work[1] = (real) maxwrk;
    if (wantsv || wantsb) {
	iwork[1] = *sdim * (*n - *sdim);
    } else {
	iwork[1] = 1;
    }

    return 0;

/*     End of SGEESX */

} /* sgeesx_ */
