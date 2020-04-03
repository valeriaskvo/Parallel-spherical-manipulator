/*
 * File: Weighted_error.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2020 13:49:12
 */

/* Include Files */
#include "Weighted_error.h"
#include "Forward_kinematics_v1.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * WEIGHTED_ERROR
 *     ERROR = WEIGHTED_ERROR(IN1,IN2,IN3,IN4,IN5)
 * Arguments    : const double in1[5]
 *                const double in3[3]
 *                const double in4[3]
 *                const double in5[3]
 * Return Type  : double
 */
double Weighted_error(const double in1[5], const double in3[3], const double
                      in4[3], const double in5[3])
{
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t38;
  double t39;
  double t24;
  double t40;
  double t41;
  double t43;
  double t44;
  double t45;
  double t49_tmp;
  double t85_tmp;
  double t85;
  double t52;
  double t53;
  double t54;
  double t55;
  double t107;
  double t108;
  double t109;
  double t114;
  double t171;
  double t116;
  double t117;
  double t118;
  double t127;
  double t138_tmp;
  double t138;
  double t435;
  double t140;
  double t141_tmp;
  double t141;
  double t142;
  double t159;
  double t160;
  double t163;
  double t67;
  double t69;
  double t78;
  double t79;
  double t112;
  double t113;
  double t115;
  double t121;
  double t128;
  double t129;
  double t131;
  double t132;
  double t137;
  double t150;
  double t151;
  double t155;
  double t158;
  double t170;
  double t233;
  double t234;
  double t144;
  double t146;
  double t153;
  double t154;
  double t167;
  double t222;
  double t223;
  double t134;
  double t172;
  double t174;
  double t175;
  double t176;
  double t177;
  double t181;
  double t230;
  double t231;
  double t207;
  double t490;
  double t251;
  double t253;
  double t254;
  double t255;
  double t211;
  double t213;
  double t214;
  double t215;
  double t216;
  double t252;
  double t258;
  double t259;
  double t260;
  double t262;
  double t263;
  double t264;
  double t265;
  double t486;
  double t274;
  double t275_tmp;
  double t276;
  double t485;
  double t279_tmp;
  double t280_tmp;
  double t306;
  double t307_tmp;
  double t307;
  double t311;
  double t333;
  double t343;
  double t352;
  double t227;
  double t229;
  double t292;
  double t304_tmp;
  double t304;
  double t314;
  double t315;
  double t316;
  double t324;
  double t329;
  double t347;
  double t355;
  double t359;
  double t365;
  double t370;
  double t393_tmp;
  double t393;
  double t271;
  double t272;
  double t298;
  double t319;
  double t328;
  double t337;
  double t342;
  double t361;
  double t363;
  double t405;
  double t417_tmp;
  double t417;
  double t418_tmp;
  double t356;
  double t378;
  double t382;

  /*     This function was generated by the Symbolic Math Toolbox version 8.4. */
  /*     01-Apr-2020 14:42:07 */
  t2 = cos(in1[0]);
  t3 = cos(in1[1]);
  t4 = cos(in3[0]);
  t5 = cos(in4[0]);
  t6 = cos(in5[0]);
  t7 = cos(in3[1]);
  t8 = cos(in4[1]);
  t9 = cos(in5[1]);
  t10 = cos(in3[2]);
  t11 = cos(in4[2]);
  t12 = cos(in5[2]);
  t13 = sin(in1[0]);
  t14 = sin(in1[1]);
  t15 = sin(in3[0]);
  t16 = sin(in4[0]);
  t17 = sin(in5[0]);
  t18 = sin(in3[1]);
  t19 = sin(in4[1]);
  t20 = sin(in5[1]);
  t21 = sin(in3[2]);
  t22 = sin(in4[2]);
  t23 = sin(in5[2]);
  t38 = in1[2] / 2.0;
  t39 = in1[3] / 2.0;
  t24 = t14 * t14;
  t40 = cos(t38);
  t41 = cos(t39);
  t43 = t6 / 2.0;
  t44 = sin(t38);
  t45 = sin(t39);
  t49_tmp = in1[4] * t13;
  t38 = t2 * t16 / 2.0;
  t85_tmp = t49_tmp * 1.7320508075688772;
  t85 = t85_tmp / 2.0;
  t52 = t40 * t40;
  t53 = t41 * t41;
  t54 = t44 * t44;
  t55 = t45 * t45;
  t107 = t13 * t40 * t44;
  t108 = t16 * t40 * t44;
  t109 = t17 * t40 * t44;
  t114 = t2 * t40 * t44 * 2.0;
  t171 = in1[4] * t15 * t40 * t44;
  t116 = t171 * 2.0;
  t117 = t2 * t5 * t40 * t44;
  t118 = t2 * t6 * t40 * t44;
  t127 = t4 * t18 * t41 * t45 * 2.0;
  t138_tmp = t2 * t15;
  t138 = t138_tmp * t18 * t41 * t45 * 2.0;
  t435 = t13 * t16;
  t140 = t435 * t19 * t41 * t45 * 2.0;
  t141_tmp = t13 * t17;
  t141 = t141_tmp * t20 * t41 * t45 * 2.0;
  t142 = in1[4] * t2 * t4 * t40 * t44 * -2.0;
  t159 = t38 + t5 * 1.7320508075688772 * -0.5;
  t39 = t2 * t17;
  t160 = t43 + t39 * 1.7320508075688772 * -0.5;
  t163 = t49_tmp * t15 * t18 * t41 * t45 * -2.0;
  t67 = t16 * t52;
  t69 = t17 * t52;
  t78 = t16 * t54;
  t79 = t17 * t54;
  t112 = in1[4] * t108;
  t113 = in1[4] * t109;
  t115 = t107 * 2.0;
  t121 = t85_tmp * t54;
  t128 = in1[4] * t117;
  t129 = in1[4] * t118;
  t131 = t5 * t107 * -2.0;
  t132 = t6 * t107 * -2.0;
  t137 = in1[4] * t127;
  t150 = t5 / 2.0 + 1.7320508075688772 * t38;
  t151 = t39 / 2.0 + 1.7320508075688772 * t43;
  t155 = in1[4] * t138;
  t158 = in1[4] * t141;
  t170 = t171 * t55 * 4.0;
  t38 = t19 * t41 * t45;
  t233 = t38 * t159 * 2.0;
  t39 = t20 * t41 * t45;
  t234 = t39 * t160 * 2.0;
  t144 = in1[4] * t132;
  t17 = t52 + -t54;
  t146 = t53 + -t55;
  t153 = 1.7320508075688772 * t112;
  t154 = 1.7320508075688772 * t113;
  t167 = 1.7320508075688772 * t128;
  t222 = t38 * t150 * 2.0;
  t223 = t39 * t151 * 2.0;
  t134 = in1[4] * (t4 * t115);
  t38 = t13 * t17;
  t39 = t2 * t17;
  t171 = t4 * t52 + -(t4 * t54);
  t172 = t5 * t52 + -(t5 * t54);
  t17 = t6 * t52 + -(t6 * t54);
  t174 = t7 * t53 + -(t7 * t55);
  t175 = t8 * t53 + -(t8 * t55);
  t176 = t9 * t53 + -(t9 * t55);
  t177 = t15 * t52 + -(t15 * t54);
  t52 = t18 * t53 + -(t18 * t55);
  t181 = t19 * t53 + -(t19 * t55);
  t53 = t20 * t53 + -(t20 * t55);
  t230 = in1[4] * t222;
  t231 = in1[4] * t223;
  t43 = t38 / 2.0;
  t207 = t2 * t17 / 2.0;
  t490 = t7 * t41 * t45;
  t6 = t490 * t177 * 2.0;
  t251 = t4 * t114 + t38;
  t253 = t4 * t107 * -2.0 + t39;
  t254 = t131 + t39;
  t255 = t132 + t39;
  t39 = 1.7320508075688772 * t43;
  t211 = t10 * t18 + t21 * t174;
  t132 = t11 * t19 + t22 * t175;
  t213 = t12 * t20 + t23 * t176;
  t214 = t7 * t21 + t10 * t52;
  t215 = t8 * t22 + t11 * t181;
  t216 = t9 * t23 + t12 * t53;
  t252 = in1[4] * t6;
  t258 = t114 + t13 * t171;
  t259 = t114 + t13 * t172;
  t260 = t114 + t13 * t17;
  t114 = in1[4] * t55;
  t262 = t114 * t251 * 2.0;
  t263 = t114 * t253 * 2.0;
  t264 = t114 * t254 * 2.0;
  t265 = t114 * t255 * 2.0;
  t486 = t22 * t41 * t45;
  t274 = t486 * t254;
  t275_tmp = t21 * t41 * t45;
  t55 = t23 * t41 * t45;
  t276 = t55 * t255;
  t485 = t10 * t41 * t45;
  t279_tmp = t11 * t41 * t45;
  t280_tmp = t12 * t41 * t45;
  t306 = (t117 + 1.7320508075688772 * t108) + t43;
  t307_tmp = t115 - t2 * t171;
  t307 = in1[4] * t7 * t41 * t45 * t307_tmp * 2.0;
  t311 = (t118 + -(1.7320508075688772 * t109)) + t43;
  t333 = (-t107 + t2 * t172 / 2.0) + 1.7320508075688772 * (t67 + -t78) / 2.0;
  t343 = ((t67 / 2.0 + -(t78 / 2.0)) + 1.7320508075688772 * t107) + t2 *
    1.7320508075688772 * t172 * -0.5;
  t352 = (t127 + t15 * t40 * t44 * t146 * 2.0) + t6;
  t227 = t7 * t10 + -(t21 * t52);
  t17 = t8 * t11 + -(t22 * t181);
  t229 = t9 * t12 + -(t23 * t53);
  t172 = t13 * t15;
  t171 = t490 * t258 * 2.0;
  t38 = t8 * t41 * t45;
  t292 = t38 * t259 * 2.0;
  t304_tmp = in1[4] * t9 * t41 * t45;
  t304 = t304_tmp * t260 * -2.0;
  t13 = (t109 + 1.7320508075688772 * t118) + t39;
  t109 = (-t108 + 1.7320508075688772 * t117) + t39;
  t314 = t114 * t306 * 2.0;
  t315 = t114 * t311 * 2.0;
  t316 = t486 * t306;
  t108 = t132 * t259;
  t324 = t55 * t311;
  t329 = (t107 + -t207) + 1.7320508075688772 * (t69 + -t79) / 2.0;
  t347 = ((t69 / 2.0 + -(t79 / 2.0)) + 1.7320508075688772 * -t107) +
    1.7320508075688772 * t207;
  t355 = t38 * t333 * 2.0;
  t207 = in1[4] * t24;
  t359 = t207 * t352;
  t7 = t38 * t343 * 2.0;
  t365 = t132 * t333;
  t370 = t132 * t343;
  t393_tmp = (t138 - t146 * t251) + t490 * t307_tmp * 2.0;
  t393 = -in1[4] * t24 * t393_tmp;
  t118 = t435 * t17;
  t271 = t150 * t17;
  t272 = t159 * t17;
  t298 = in1[4] * t171;
  t319 = t114 * t13 * 2.0;
  t328 = t114 * t109 * 2.0;
  t337 = t55 * t13;
  t342 = t486 * t109;
  t39 = t9 * t41 * t45;
  t43 = t39 * t329 * 2.0;
  t361 = in1[4] * t7;
  t363 = t39 * t347 * 2.0;
  t38 = t18 * t21 - t10 * t174;
  t405 = (t138_tmp * t214 + t485 * t251 * 2.0) + -(t38 * t307_tmp);
  t2 = (t172 * t214 - t485 * t253 * 2.0) + t258 * t38;
  t127 = -t3 * t2;
  t52 = t19 * t22 - t11 * t175;
  t417_tmp = (t435 * t215 - t279_tmp * t254 * 2.0) + t259 * t52;
  t417 = t14 * t417_tmp;
  t6 = t20 * t23 - t12 * t176;
  t418_tmp = (t141_tmp * t216 - t280_tmp * t255 * 2.0) + t260 * t6;
  t67 = t14 * t418_tmp;
  t78 = (-t233 + t146 * t306) + t355;
  t17 = (t159 * t215 + t279_tmp * t306 * 2.0) + t333 * t52;
  t356 = in1[4] * t43;
  t378 = (t15 * t21 * t40 * t41 * t44 * t45 * 4.0 + t4 * t227) + -(t177 * t211);
  t53 = in1[4] * t14;
  t38 = (t10 * t15 * t40 * t41 * t44 * t45 * 4.0 - t4 * t214) + t177 * t38;
  t382 = t53 * (-t3 * t38);
  t132 = (t172 * t18 * t41 * t45 * 2.0 + -t171) + t146 * t253;
  t181 = (t140 + -t292) + t146 * t254;
  t40 = (t141 + -(t39 * t260 * 2.0)) + t146 * t255;
  t15 = (t172 * t227 + t275_tmp * t253 * 2.0) + t211 * t258;
  t39 = t3 * t405;
  t22 = t53 * t127;
  t23 = in1[4] * t3;
  t21 = t23 * t67;
  t44 = (t223 + -(t146 * t311)) + t43;
  t258 = t207 * t78;
  t172 = t14 * t78 / 2.0;
  t4 = (t234 + t146 * t13) + t363;
  t10 = t3 * t352 + -t14 * t38;
  t12 = t14 * t352 + t3 * t38;
  t253 = (t151 * t216 + t280_tmp * t311 * 2.0) + -t329 * t6;
  t254 = t14 * t17;
  t55 = t3 * t17 / 2.0;
  t114 = (t150 * t215 + t279_tmp * t109 * 2.0) + -t343 * t52;
  t11 = (-(t160 * t216) + t280_tmp * t13 * 2.0) + t347 * t6;
  t306 = -t14 * t11;
  t52 = t207 * t132;
  t255 = t207 * t181;
  t352 = t207 * t40;
  t214 = t53 * t39;
  t435 = t207 * t44;
  t17 = (t222 + -(t146 * t109)) + t7;
  t6 = t207 * t4;
  t38 = t14 * t253;
  t43 = t14 * t114;
  t177 = -t14 * t393_tmp + t39;
  t138 = t207 * t17;
  t39 = t14 * t17 / 2.0;
  t171 = t23 * t38;
  t24 = t23 * t43;
  t176 = t14 * t132 + t127;
  t175 = t3 * t132 + t14 * t2;
  t9 = t3 * t181 + t417;
  t174 = t3 * t40 + t67;
  t485 = t3 * t44 + t38;
  t486 = t3 * t78 + -t254;
  t107 = t3 * t4 + t306;
  t69 = (t14 * t181 / 2.0 + t3 * t417_tmp * -0.5) + 1.7320508075688772 * ((t118
    + t274 * 2.0) + t108) / 2.0;
  t79 = t213 * t260;
  t117 = t141_tmp * t229;
  t490 = (((t117 / 2.0 + t276) + t79 / 2.0) + t14 * 1.7320508075688772 * t40 /
          2.0) + t3 * 1.7320508075688772 * t418_tmp * -0.5;
  t13 = (((t118 / 2.0 + t274) + t108 / 2.0) + t14 * 1.7320508075688772 * t181 *
         -0.5) + t3 * 1.7320508075688772 * t417_tmp / 2.0;
  t207 = (((t272 / 2.0 + -t316) + t365 / 2.0) + 1.7320508075688772 * t172) +
    1.7320508075688772 * t55;
  t109 = t160 * t229;
  t118 = t213 * t347;
  t108 = (((t109 / 2.0 + t337) + -(t118 / 2.0)) + t14 * 1.7320508075688772 * t4 /
          2.0) + t3 * 1.7320508075688772 * t11 / 2.0;
  t7 = t3 * t17 + t43;
  t2 = t151 * t229;
  t78 = t213 * t329;
  t127 = (((-(t2 / 2.0) + t324) + t78 / 2.0) + -(t14 * 1.7320508075688772 * t44 /
           2.0)) + t3 * 1.7320508075688772 * t253 / 2.0;
  t181 = (t172 + t55) + -(1.7320508075688772 * ((t272 + -(t316 * 2.0)) + t365) /
    2.0);
  t67 = (-t39 + t3 * t114 / 2.0) + 1.7320508075688772 * ((-t271 + t342 * 2.0) +
    t370) / 2.0;
  t55 = (((-(t271 / 2.0) + t342) + t370 / 2.0) + 1.7320508075688772 * t39) + t3 *
    1.7320508075688772 * t114 * -0.5;
  t172 = ((((((((((t134 + t144) + t158) + t163) + t263) + -t265) + t298) + t304)
            + t52) + -t352) + t22) + t21;
  t39 = in1[4] * t8 * t41 * t45;
  t114 = ((((((((((t134 + in1[4] * t140) + t163) + t263) - t264) + t298) + t52)
             - t255) + t22) + in1[4] * t131) + t23 * t417) - t39 * t259 * 2.0;
  t132 = (((((((((((((t85 + t113) + t116) + t137) + 1.7320508075688772 * t129) +
                  -t170) + in1[4] * t234) + t252) + -t319) + -t359) + in1[4] *
             t363) + t382) + -t6) + t23 * t306) + t85_tmp * -t54;
  t53 = ((((((((((((t128 + -t129) + t153) + t154) + t231) - t314) + t315) + t356)
             + in1[4] * t355) - t258) + -t435) + t171) + t23 * -t254) - in1[4] *
    t19 * t41 * t45 * t159 * 2.0;
  t52 = ((((((((((((((t112 - t113) + t121 * 2.0) - t167) + t230) + t319) + t328)
                + t361) + t6) - t138) + t24) + 1.7320508075688772 * -t129) -
           t85_tmp) + t23 * t14 * t11) - in1[4] * t20 * t41 * t45 * t160 * 2.0)
    - t304_tmp * t347 * 2.0;
  t38 = -(t49_tmp * 1.5) + t49_tmp * t54 * 3.0;
  t6 = ((((((((((((t38 - t128) + t142) - t153) + t155) + in1[4] * t233) + t262)
             + t307) + t314) + t393) + t214) + t258) + t23 * t254) - t39 * t333 *
    2.0;
  t171 += (((((((((((t38 + t142) + -t129) + t154) + t155) + t231) + t262) + t307)
              + t315) + t356) + t393) + t214) + -t435;
  t43 = (((((((((((((-t85 + t112) + t116) + t121) + t137) - t167) + -t170) +
               t230) + t252) + t328) + t361) + -t359) + t382) - t138) + t24;
  t17 = ((((((((((in1[4] * (t5 * t115) + t144) + t158) + t264) + -t265) + in1[4]
              * t292) + t304) + t255) + -t352) + t23 * (-t14 * t417_tmp)) + t21)
    - t49_tmp * t16 * t19 * t41 * t45 * 2.0;
  t39 = t14 * t405 + t3 * t393_tmp;
  t38 = (-(t138_tmp * t227) + t275_tmp * t251 * 2.0) + t211 * t307_tmp;
  return ((((((((t172 * t172 + t114 * t114) + t132 * t132) + t53 * t53) + t52 *
              t52) + t6 * t6) + t171 * t171) + t43 * t43) + t17 * t17) - 1000.0 *
    ((((((((((((((((((((((((((t12 * ((t14 * t4 / 2.0 - 1.7320508075688772 *
    ((t337 * 2.0 + t109) - t118) / 2.0) + t3 * t11 / 2.0) + t378 * t108) - t378 *
    t55) - t15 * t490) - t15 * t13) - t10 * t107) - t10 * t7) - t12 * t67) +
                       t175 * t9) + t175 * t174) + t9 * t174) - t176 * t69) +
                   t177 * t181) - t485 * t486) + t107 * t7) + t490 * t13) - t127
               * t207) - t108 * t55) - t177 * ((t14 * t44 / 2.0 - t3 * t253 /
    2.0) + 1.7320508075688772 * ((t324 * 2.0 - t2) + t78) / 2.0)) + t176 *
            ((1.7320508075688772 * ((t276 * 2.0 + t79) + t117) / 2.0 - t14 * t40
              / 2.0) + t3 * t418_tmp / 2.0)) - t485 * t39) + t486 * t39) + t69 *
         t69) + t181 * t181) + t67 * t67) + t127 * t38) - t207 * t38);
}

/*
 * File trailer for Weighted_error.c
 *
 * [EOF]
 */
