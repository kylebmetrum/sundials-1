/*
 * -----------------------------------------------------------------
 * Programmer(s): Daniel Reynolds, Ashley Crawford @ SMU
 * -----------------------------------------------------------------
 * SUNDIALS Copyright Start
 * Copyright (c) 2002-2019, Lawrence Livermore National Security
 * and Southern Methodist University.
 * All rights reserved.
 *
 * See the top-level LICENSE and NOTICE files for details.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SUNDIALS Copyright End
 * -----------------------------------------------------------------
 * This is the header file for the dense implementation of the 
 * SUNLINSOL module.
 * 
 * Part I contains declarations specific to the dense implementation
 * of the supplied SUNLINSOL module.
 * 
 * Part II contains the prototype for the constructor 
 * SUNDenseLinearSolver as well as implementation-specific 
 * prototypes for various useful matrix operations.
 *
 * Notes:
 *
 *   - The definition of the generic SUNLinearSolver structure can 
 *     be found in the header file sundials_linearsolver.h.
 *
 *   - The definition of the type 'realtype' can be found in the
 *     header file sundials_types.h, and it may be changed (at the 
 *     configuration stage) according to the user's needs. 
 *     The sundials_types.h file also contains the definition
 *     for the type 'booleantype' and 'indextype'.
 *
 * -----------------------------------------------------------------
 */

#ifndef _SUNLINSOL_DENSE_H
#define _SUNLINSOL_DENSE_H

#include <sundials/sundials_linearsolver.h>
#include <sundials/sundials_matrix.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_dense.h>
#include <sunmatrix/sunmatrix_dense.h>

#ifdef __cplusplus  /* wrapper to enable C++ usage */
extern "C" {
#endif

/*
 * -----------------------------------------------------------------
 * PART I: Dense implementation of SUNLinearSolver
 *
 * The dense implementation of the SUNLinearSolver 'content' 
 * structure contains:
 *       N -- size of the linear system
 *	 pivots -- index array for partial pivoting in LU factorization
 *       last_flag -- last error return flag from internal setup/solve
 * -----------------------------------------------------------------
 */
  
struct _SUNLinearSolverContent_Dense {
  sunindextype N;
  sunindextype *pivots;
  long int last_flag;
};

typedef struct _SUNLinearSolverContent_Dense *SUNLinearSolverContent_Dense;

/*
 * -----------------------------------------------------------------
 * PART II: functions exported by sunlinsol_dense
 * 
 * CONSTRUCTOR:
 *    SUNLinSol_Dense creates and allocates memory for a dense 
 *       matrix solver
 * 
 *    SUNDenseLinearSolver (deprecated) wrapper for SUNLinSol_Dense
 * 
 * -----------------------------------------------------------------
 */

SUNDIALS_EXPORT SUNLinearSolver SUNLinSol_Dense(N_Vector y, SUNMatrix A);
  
/* deprecated */
SUNDIALS_EXPORT SUNLinearSolver SUNDenseLinearSolver(N_Vector y,
                                                     SUNMatrix A);

/*
 * -----------------------------------------------------------------
 * dense implementations of various useful linear solver operations
 * -----------------------------------------------------------------
 */

SUNDIALS_EXPORT SUNLinearSolver_Type SUNLinSolGetType_Dense(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolInitialize_Dense(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolSetup_Dense(SUNLinearSolver S, SUNMatrix A);
SUNDIALS_EXPORT int SUNLinSolSolve_Dense(SUNLinearSolver S, SUNMatrix A,
                                         N_Vector x, N_Vector b, realtype tol);
SUNDIALS_EXPORT long int SUNLinSolLastFlag_Dense(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolSpace_Dense(SUNLinearSolver S,
                                         long int *lenrwLS,
                                         long int *leniwLS);
SUNDIALS_EXPORT int SUNLinSolFree_Dense(SUNLinearSolver S);
  
#ifdef __cplusplus
}
#endif

#endif

