/*
 * File: setProblemType.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 01-Apr-2020 16:21:00
 */

/* Include Files */
#include "setProblemType.h"
#include "Forward_kinematics_v1.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : f_struct_T *obj
 *                int PROBLEM_TYPE
 * Return Type  : void
 */
void setProblemType(f_struct_T *obj, int PROBLEM_TYPE)
{
  int i;
  int mIneq;
  int mEq;
  int offsetIneq_tmp_tmp;
  int offsetEq1_tmp_tmp;
  int idx_col;
  int i1;
  int i2;
  int idx_lb;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = obj->nVarOrig;
    obj->mConstr = obj->mConstrOrig;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesNormal[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
    break;

   case 1:
    obj->nVar = obj->nVarOrig + 1;
    obj->mConstr = obj->mConstrOrig + 1;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }

    modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }

    if (obj->probType != 4) {
      mIneq = obj->sizes[2];
      mEq = obj->sizes[1];
      offsetIneq_tmp_tmp = obj->nVarOrig + 1;
      offsetEq1_tmp_tmp = obj->nVarOrig + obj->sizes[2];
      i = obj->sizes[0];
      for (idx_col = 0; idx_col < i; idx_col++) {
        i1 = obj->nVarOrig + 1;
        i2 = obj->nVar;
        if (i1 <= i2) {
          memset(&obj->ATwset[i1 + -1], 0, ((i2 - i1) + 1) * sizeof(double));
        }
      }

      for (idx_col = 0; idx_col < mIneq; idx_col++) {
        i = (offsetIneq_tmp_tmp + idx_col) - 1;
        for (idx_lb = offsetIneq_tmp_tmp; idx_lb <= i; idx_lb++) {
          abort();
        }

        abort();
      }

      for (idx_col = 0; idx_col < mEq; idx_col++) {
        for (idx_lb = offsetIneq_tmp_tmp; idx_lb <= offsetEq1_tmp_tmp; idx_lb++)
        {
          abort();
        }

        i = offsetEq1_tmp_tmp + 1;
        i1 = offsetEq1_tmp_tmp + idx_col;
        for (idx_lb = i; idx_lb <= i1; idx_lb++) {
          abort();
        }

        abort();
      }

      idx_lb = obj->nVarOrig;
      i = obj->sizesNormal[3] + 1;
      i1 = obj->sizesRegularized[3];
      for (mIneq = i; mIneq <= i1; mIneq++) {
        idx_lb++;
        obj->indexLB[mIneq - 1] = idx_lb;
      }

      i = obj->nVarOrig + 1;
      i1 = (obj->nVarOrig + obj->sizes[2]) + (obj->sizes[1] << 1);
      if (i <= i1) {
        memset(&obj->lb[i + -1], 0, ((i1 - i) + 1) * sizeof(double));
      }

      idx_lb = obj->isActiveIdx[2];
      i = obj->nActiveConstr;
      for (idx_col = idx_lb; idx_col <= i; idx_col++) {
        switch (obj->Wid) {
         case 3:
          i1 = (offsetIneq_tmp_tmp + obj->Wlocalidx) - 2;
          if (offsetIneq_tmp_tmp <= i1) {
            memset(&obj->ATwset[offsetIneq_tmp_tmp + -1], 0, ((i1 -
                     offsetIneq_tmp_tmp) + 1) * sizeof(double));
          }

          obj->ATwset[(offsetIneq_tmp_tmp + obj->Wlocalidx) - 2] = -1.0;
          i1 = offsetIneq_tmp_tmp + obj->Wlocalidx;
          i2 = obj->nVar;
          if (i1 <= i2) {
            memset(&obj->ATwset[i1 + -1], 0, ((i2 - i1) + 1) * sizeof(double));
          }
          break;

         default:
          i1 = obj->nVar;
          if (offsetIneq_tmp_tmp <= i1) {
            memset(&obj->ATwset[offsetIneq_tmp_tmp + -1], 0, ((i1 -
                     offsetIneq_tmp_tmp) + 1) * sizeof(double));
          }
          break;
        }
      }
    }
    break;

   default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }

    modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

/*
 * File trailer for setProblemType.c
 *
 * [EOF]
 */
