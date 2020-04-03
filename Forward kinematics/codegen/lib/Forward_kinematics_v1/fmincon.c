/*
 * File: fmincon.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "fmincon.h"
#include "Forward_kinematics_v1.h"
#include "Weighted_error.h"
#include "computeFiniteDifferences.h"
#include "driver.h"
#include "factoryConstruct.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double fun_tunableEnvironment_f1[5]
 *                const double fun_tunableEnvironment_f2[3]
 *                const double x0[6]
 *                double x[6]
 * Return Type  : void
 */
void fmincon(const double fun_tunableEnvironment_f1[5], const double
             fun_tunableEnvironment_f2[3], const double x0[6], double x[6])
{
  d_struct_T TrialState;
  int i;
  e_struct_T FcnEvaluator;
  f_struct_T WorkingSet;
  static const signed char t3_sizesPhaseOne[5] = { 0, 0, 0, 1, 0 };

  static const signed char t3_isActiveIdxPhaseOne[6] = { 1, 1, 1, 1, 2, 2 };

  static const signed char t3_sizesRegPhaseOne[5] = { 0, 0, 0, 1, 0 };

  static const signed char t3_isActiveIdxRegPhaseOne[6] = { 1, 1, 1, 1, 2, 2 };

  double b_fun_tunableEnvironment_f2[3];
  double c_fun_tunableEnvironment_f2[3];
  double d_fun_tunableEnvironment_f2[3];
  double fval;
  g_struct_T FiniteDifferences;
  h_struct_T MeritFunction;
  i_struct_T QRManager;
  j_struct_T QPObjective;
  c_struct_T memspace;
  double Hessian[36];
  k_struct_T CholManager;
  TrialState.nVarMax = 7;
  TrialState.mNonlinIneq = 0;
  TrialState.mNonlinEq = 0;
  TrialState.mIneq = 0;
  TrialState.mEq = 0;
  TrialState.iNonIneq0 = 1;
  TrialState.iNonEq0 = 1;
  TrialState.sqpFval_old = 0.0;
  for (i = 0; i < 6; i++) {
    TrialState.xstarsqp_old[i] = 0.0;
  }

  TrialState.FunctionEvaluations = 0;
  TrialState.sqpIterations = 0;
  TrialState.sqpExitFlag = 0;
  TrialState.lambdasqp = 0.0;
  TrialState.lambdasqp_old = 0.0;
  TrialState.steplength = 1.0;
  TrialState.lambda_old = 0.0;
  TrialState.workingset_old = 0;
  TrialState.fstar = 0.0;
  TrialState.lambda = 0.0;
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
  for (i = 0; i < 7; i++) {
    TrialState.grad[i] = 0.0;
    TrialState.grad_old[i] = 0.0;
    TrialState.delta_x[i] = 0.0;
    TrialState.socDirection[i] = 0.0;
    TrialState.gradLag[i] = 0.0;
    TrialState.delta_gradLag[i] = 0.0;
    TrialState.xstar[i] = 0.0;
    TrialState.searchDir[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    TrialState.xstarsqp[i] = x0[i];
  }

  for (i = 0; i < 5; i++) {
    FcnEvaluator.objfun.tunableEnvironment.f1[i] = fun_tunableEnvironment_f1[i];
  }

  FcnEvaluator.objfun.tunableEnvironment.f2[0] = fun_tunableEnvironment_f2[0];
  FcnEvaluator.objfun.tunableEnvironment.f2[1] = fun_tunableEnvironment_f2[1];
  FcnEvaluator.objfun.tunableEnvironment.f2[2] = fun_tunableEnvironment_f2[2];
  FcnEvaluator.nVar = 6;
  FcnEvaluator.mCineq = 0;
  FcnEvaluator.mCeq = 0;
  FcnEvaluator.NonFiniteSupport = true;
  FcnEvaluator.SpecifyObjectiveGradient = false;
  FcnEvaluator.SpecifyConstraintGradient = false;
  FcnEvaluator.ScaleProblem = false;
  WorkingSet.mConstr = 0;
  WorkingSet.mConstrOrig = 0;
  WorkingSet.mConstrMax = 1;
  WorkingSet.nVar = 6;
  WorkingSet.nVarOrig = 6;
  WorkingSet.nVarMax = 7;
  WorkingSet.ldA = 7;
  WorkingSet.mEqRemoved = 0;
  for (i = 0; i < 7; i++) {
    WorkingSet.lb[i] = 0.0;
    WorkingSet.ub[i] = 0.0;
    WorkingSet.indexLB[i] = 0;
    WorkingSet.indexUB[i] = 0;
    WorkingSet.indexFixed[i] = 0;
    WorkingSet.ATwset[i] = 0.0;
  }

  WorkingSet.bwset = 0.0;
  WorkingSet.nActiveConstr = 0;
  WorkingSet.maxConstrWorkspace = 0.0;
  for (i = 0; i < 5; i++) {
    WorkingSet.sizes[i] = 0;
    WorkingSet.sizesNormal[i] = 0;
    WorkingSet.sizesPhaseOne[i] = t3_sizesPhaseOne[i];
    WorkingSet.sizesRegularized[i] = 0;
    WorkingSet.sizesRegPhaseOne[i] = t3_sizesRegPhaseOne[i];
  }

  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdx[i] = 1;
    WorkingSet.isActiveIdxNormal[i] = 1;
    WorkingSet.isActiveIdxPhaseOne[i] = t3_isActiveIdxPhaseOne[i];
    WorkingSet.isActiveIdxRegularized[i] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[i] = t3_isActiveIdxRegPhaseOne[i];
  }

  WorkingSet.isActiveConstr = false;
  WorkingSet.Wid = 0;
  WorkingSet.Wlocalidx = 0;
  for (i = 0; i < 5; i++) {
    WorkingSet.nWConstr[i] = 0;
  }

  WorkingSet.probType = 3;
  WorkingSet.SLACK0 = 1.0E-5;
  b_fun_tunableEnvironment_f2[0] = fun_tunableEnvironment_f2[0];
  b_fun_tunableEnvironment_f2[1] = TrialState.xstarsqp[0];
  b_fun_tunableEnvironment_f2[2] = TrialState.xstarsqp[1];
  c_fun_tunableEnvironment_f2[0] = fun_tunableEnvironment_f2[1];
  c_fun_tunableEnvironment_f2[1] = TrialState.xstarsqp[2];
  c_fun_tunableEnvironment_f2[2] = TrialState.xstarsqp[3];
  d_fun_tunableEnvironment_f2[0] = fun_tunableEnvironment_f2[2];
  d_fun_tunableEnvironment_f2[1] = TrialState.xstarsqp[4];
  d_fun_tunableEnvironment_f2[2] = TrialState.xstarsqp[5];
  fval = Weighted_error(fun_tunableEnvironment_f1, b_fun_tunableEnvironment_f2,
                        c_fun_tunableEnvironment_f2, d_fun_tunableEnvironment_f2);
  TrialState.sqpFval = fval;
  factoryConstruct(fun_tunableEnvironment_f1, fun_tunableEnvironment_f2,
                   &FiniteDifferences);
  computeFiniteDifferences(&FiniteDifferences, fval, TrialState.xstarsqp,
    TrialState.grad);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  setProblemType(&WorkingSet, 3);
  WorkingSet.isActiveConstr = false;
  WorkingSet.nWConstr[0] = 0;
  WorkingSet.nWConstr[1] = 0;
  WorkingSet.nWConstr[2] = 0;
  WorkingSet.nWConstr[3] = 0;
  WorkingSet.nWConstr[4] = 0;
  WorkingSet.nActiveConstr = 0;
  MeritFunction.initFval = fval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  MeritFunction.initConstrViolationIneq = 0.0;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  QRManager.ldq = 7;
  memset(&QRManager.QR[0], 0, 49U * sizeof(double));
  memset(&QRManager.Q[0], 0, 49U * sizeof(double));
  QRManager.mrows = 0;
  QRManager.ncols = 0;
  QRManager.minRowCol = 0;
  QRManager.usedPivoting = false;
  for (i = 0; i < 7; i++) {
    QRManager.jpvt[i] = 0;
    QRManager.tau[i] = 0.0;
    QPObjective.grad[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    QPObjective.Hx[i] = 0.0;
  }

  QPObjective.hasLinear = true;
  QPObjective.nvar = 6;
  QPObjective.maxVar = 7;
  QPObjective.beta = 0.0;
  QPObjective.rho = 0.0;
  QPObjective.objtype = 3;
  QPObjective.prev_objtype = 3;
  QPObjective.prev_nvar = 0;
  QPObjective.prev_hasLinear = false;
  QPObjective.gammaScalar = 0.0;
  driver(&TrialState, &MeritFunction, &FcnEvaluator, &FiniteDifferences,
         &memspace, &WorkingSet, &QRManager, &QPObjective, Hessian, &CholManager);
  for (i = 0; i < 6; i++) {
    x[i] = TrialState.xstarsqp[i];
  }
}

/*
 * File trailer for fmincon.c
 *
 * [EOF]
 */
