/*
 * File: Forward_kinematics_v1_types.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 23:47:49
 */

#ifndef FORWARD_KINEMATICS_V1_TYPES_H
#define FORWARD_KINEMATICS_V1_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  int MaxIterations;
  double StepTolerance;
  double OptimalityTolerance;
  double ConstraintTolerance;
  double ObjectiveLimit;
  boolean_T DisplayQP;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_cell_4
#define typedef_cell_4

typedef struct {
  double f1[5];
  double f2[3];
} cell_4;

#endif                                 /*typedef_cell_4*/

#ifndef typedef_c_coder_internal_anonymous_func
#define typedef_c_coder_internal_anonymous_func

typedef struct {
  cell_4 tunableEnvironment;
} c_coder_internal_anonymous_func;

#endif                                 /*typedef_c_coder_internal_anonymous_func*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  double workspace_double[49];
  int workspace_int[7];
  int workspace_sort[7];
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  int nVarMax;
  int mNonlinIneq;
  int mNonlinEq;
  int mIneq;
  int mEq;
  int iNonIneq0;
  int iNonEq0;
  double sqpFval;
  double sqpFval_old;
  double xstarsqp[6];
  double xstarsqp_old[6];
  double grad[7];
  double grad_old[7];
  int FunctionEvaluations;
  int sqpIterations;
  int sqpExitFlag;
  double lambdasqp;
  double lambdasqp_old;
  double steplength;
  double delta_x[7];
  double socDirection[7];
  double lambda_old;
  int workingset_old;
  double gradLag[7];
  double delta_gradLag[7];
  double xstar[7];
  double fstar;
  double lambda;
  int state;
  double maxConstr;
  int iterations;
  double searchDir[7];
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  c_coder_internal_anonymous_func objfun;
  int nVar;
  int mCineq;
  int mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

#ifndef typedef_f_struct_T
#define typedef_f_struct_T

typedef struct {
  int mConstr;
  int mConstrOrig;
  int mConstrMax;
  int nVar;
  int nVarOrig;
  int nVarMax;
  int ldA;
  double lb[7];
  double ub[7];
  int indexLB[7];
  int indexUB[7];
  int indexFixed[7];
  int mEqRemoved;
  double ATwset[7];
  double bwset;
  int nActiveConstr;
  double maxConstrWorkspace;
  int sizes[5];
  int sizesNormal[5];
  int sizesPhaseOne[5];
  int sizesRegularized[5];
  int sizesRegPhaseOne[5];
  int isActiveIdx[6];
  int isActiveIdxNormal[6];
  int isActiveIdxPhaseOne[6];
  int isActiveIdxRegularized[6];
  int isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr;
  int Wid;
  int Wlocalidx;
  int nWConstr[5];
  int probType;
  double SLACK0;
} f_struct_T;

#endif                                 /*typedef_f_struct_T*/

#ifndef typedef_g_struct_T
#define typedef_g_struct_T

typedef struct {
  c_coder_internal_anonymous_func objfun;
  double f_1;
  double f_2;
  int nVar;
  int mIneq;
  int mEq;
  int numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T hasLB[6];
  boolean_T hasUB[6];
  boolean_T hasBounds;
  int FiniteDifferenceType;
} g_struct_T;

#endif                                 /*typedef_g_struct_T*/

#ifndef typedef_h_struct_T
#define typedef_h_struct_T

typedef struct {
  double penaltyParam;
  double threshold;
  int nPenaltyDecreases;
  double linearizedConstrViol;
  double initFval;
  double initConstrViolationEq;
  double initConstrViolationIneq;
  double phi;
  double phiPrimePlus;
  double phiFullStep;
  double feasRelativeFactor;
  double nlpPrimalFeasError;
  double nlpDualFeasError;
  double nlpComplError;
  double firstOrderOpt;
  boolean_T hasObjective;
} h_struct_T;

#endif                                 /*typedef_h_struct_T*/

#ifndef typedef_i_struct_T
#define typedef_i_struct_T

typedef struct {
  int ldq;
  double QR[49];
  double Q[49];
  int jpvt[7];
  int mrows;
  int ncols;
  double tau[7];
  int minRowCol;
  boolean_T usedPivoting;
} i_struct_T;

#endif                                 /*typedef_i_struct_T*/

#ifndef typedef_j_struct_T
#define typedef_j_struct_T

typedef struct {
  double grad[7];
  double Hx[6];
  boolean_T hasLinear;
  int nvar;
  int maxVar;
  double beta;
  double rho;
  int objtype;
  int prev_objtype;
  int prev_nvar;
  boolean_T prev_hasLinear;
  double gammaScalar;
} j_struct_T;

#endif                                 /*typedef_j_struct_T*/

#ifndef typedef_k_struct_T
#define typedef_k_struct_T

typedef struct {
  double UU[49];
  double x[7];
  int ldu;
  int ndims;
  int info;
} k_struct_T;

#endif                                 /*typedef_k_struct_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int stepType;
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/*
 * File trailer for Forward_kinematics_v1_types.h
 *
 * [EOF]
 */
