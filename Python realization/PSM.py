from math import sin, cos, pi, atan, sqrt, acos
import numpy as np

class Asymmetry_PSM(object):
  def __init__(self, phi_1 = 0, phi_2 = 0, phi_3 = 0, 
               q_1_0 = np.array([-pi/2, -pi/2, -pi/2]),
               q_2_0 = np.array([pi/2, pi/2, pi/2]),
               q_3_0 = np.array([-pi/2, -pi/2, -pi/2])):
    
    self.phi_1 = phi_1
    self.phi_2 = phi_2
    self.phi_3 = phi_3
    
    self.legs = np.array([0, 1, 2])
    self.eta_i = np.array([0, 2*pi/3, 4*pi/3])
    
    self.q_1 = np.array([-pi/2, -pi/2, -pi/2])
    self.q_2 = np.array([pi/2, pi/2, pi/2])
    self.q_3 = np.array([-pi/2, -pi/2, -pi/2])

    self.q_1_0 = q_1_0
    self.q_2_0 = q_2_0
    self.q_3_0 = q_3_0
    
    self.dphi_1 = 0
    self.dphi_2 = 0
    self.dphi_3 = 0

    self.dq_1 = np.array([0, 0, 0])
    self.dq_2 = np.array([0, 0, 0])
    self.dq_3 = np.array([0, 0, 0])

    self.sc = {"s_eta_i": np.sin(self.eta_i),
               "c_eta_i": np.cos(self.eta_i),
               "s_phi_1": sin(self.phi_1),
               "c_phi_1": cos(self.phi_1),
               "s_phi_2": sin(self.phi_2),
               "c_phi_2": cos(self.phi_2),
               "s_phi_3": sin(self.phi_3),
               "c_phi_3": cos(self.phi_3),
               "s_q_1": np.sin(self.q_1),
               "c_q_1": np.cos(self.q_1),
               "s_q_2": np.sin(self.q_2),
               "c_q_2": np.cos(self.q_2),
               "s_q_3": np.sin(self.q_3),
               "c_q_3": np.cos(self.q_3)}
  
  def _upd_phi_data(self):
    self.sc["s_phi_1"] = sin(self.phi_1)
    self.sc["c_phi_1"] = cos(self.phi_1)
    self.sc["s_phi_2"] = sin(self.phi_2)
    self.sc["c_phi_2"] = cos(self.phi_2)
    self.sc["s_phi_3"] = sin(self.phi_3)
    self.sc["c_phi_3"] = cos(self.phi_3)
    return
  
  def _upd_q_data(self, q_2 = False, q_3 = False):
    self.sc["s_q_1"] = np.sin(self.q_1)
    self.sc["c_q_1"] = np.cos(self.q_1)

    if q_2:
      self.sc["s_q_2"] = np.sin(self.q_2)
      self.sc["c_q_2"] = np.cos(self.q_2)

      if q_3:
        self.sc["s_q_3"] = np.sin(self.q_3)
        self.sc["c_q_3"] = np.cos(self.q_3)
    return

  def _q1_coef(self, leg):
    self._upd_phi_data()

    s_eta_i = self.sc["s_eta_i"][leg]
    c_eta_i = self.sc["c_eta_i"][leg]

    A_q1 = c_eta_i**2*self.sc["c_phi_2"]*self.sc["c_phi_3"] - \
           c_eta_i**2*self.sc["c_phi_1"]*self.sc["c_phi_3"] - \
           self.sc["c_phi_2"]*self.sc["c_phi_3"] + \
           c_eta_i**2*self.sc["s_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"] - \
           c_eta_i*self.sc["c_phi_1"]*s_eta_i*self.sc["s_phi_3"] + \
           c_eta_i*self.sc["c_phi_2"]*s_eta_i*self.sc["s_phi_3"] - \
           c_eta_i*self.sc["c_phi_3"]*s_eta_i*self.sc["s_phi_1"]*self.sc["s_phi_2"]

    B_q1 = 2*c_eta_i**2*self.sc["c_phi_1"]*self.sc["s_phi_3"] - \
           2*self.sc["c_phi_1"]*self.sc["s_phi_3"] - \
           2*c_eta_i**2*self.sc["c_phi_2"]*self.sc["s_phi_3"] - \
           2*self.sc["c_phi_3"]*self.sc["s_phi_1"]*self.sc["s_phi_2"] + \
           2*c_eta_i**2*self.sc["c_phi_3"]*self.sc["s_phi_1"]*self.sc["s_phi_2"] - \
           2*c_eta_i*self.sc["c_phi_1"]*self.sc["c_phi_3"]*s_eta_i + \
           2*c_eta_i*self.sc["c_phi_2"]*self.sc["c_phi_3"]*s_eta_i + \
           2*c_eta_i*s_eta_i*self.sc["s_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"]

    C_q1 = self.sc["c_phi_2"]*self.sc["c_phi_3"] + \
           c_eta_i**2*self.sc["c_phi_1"]*self.sc["c_phi_3"] - \
           c_eta_i**2*self.sc["c_phi_2"]*self.sc["c_phi_3"] - \
           c_eta_i**2*self.sc["s_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"] + \
           c_eta_i*self.sc["c_phi_1"]*s_eta_i*self.sc["s_phi_3"] - \
           c_eta_i*self.sc["c_phi_2"]*s_eta_i*self.sc["s_phi_3"] + \
           c_eta_i*self.sc["c_phi_3"]*s_eta_i*self.sc["s_phi_1"]*self.sc["s_phi_2"]

    return A_q1, B_q1, C_q1

  def _q2_coef(self, leg):
    self._upd_q_data()
    
    s_eta_i = self.sc["s_eta_i"][leg]
    c_eta_i = self.sc["c_eta_i"][leg]
    s_q_1 = self.sc["s_q_1"][leg]
    c_q_1 = self.sc["c_q_1"][leg]

    A_q2 = - self.sc["c_phi_1"]*self.sc["c_phi_2"]

    B_q2 = 2*c_eta_i*c_q_1*self.sc["s_phi_2"] - \
            2*s_eta_i*self.sc["s_phi_2"]*s_q_1 + \
            2*c_eta_i*self.sc["c_phi_2"]*self.sc["s_phi_1"]*s_q_1 + \
            2*self.sc["c_phi_2"]*c_q_1*s_eta_i*self.sc["s_phi_1"] 
    
    C_q2 = self.sc["c_phi_1"]*self.sc["c_phi_2"]
    
    return A_q2, B_q2, C_q2

  def _ik_solver(self, A, B, C, q_2 = False):
    try:
      if q_2:
        return 2*atan((-B - sqrt(B**2 - 4*A*C)) / (2*A))
      else:
        return 2*atan((-B + sqrt(B**2 - 4*A*C)) / (2*A))
    except Exception as e:
      print("Singularity")
      return None
  
  def _q3_solver(self, leg):
    self._upd_q_data(q_2 = True)
    
    s_eta_i = self.sc["s_eta_i"][leg]
    c_eta_i = self.sc["c_eta_i"][leg]
    s_q_1 = self.sc["s_q_1"][leg]
    c_q_1 = self.sc["c_q_1"][leg]
    s_q_2 = self.sc["s_q_2"][leg]
    c_q_2 = self.sc["c_q_2"][leg]

    c_q_3 = -(s_q_2*(c_eta_i*(self.sc["s_phi_1"]*self.sc["s_phi_3"] - \
            self.sc["c_phi_1"]*self.sc["c_phi_3"]*self.sc["s_phi_2"]) - \
            s_eta_i*(self.sc["c_phi_3"]*self.sc["s_phi_1"] + \
            self.sc["c_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"])) + \
            c_q_2*(c_eta_i*s_q_1 + \
            c_q_1*s_eta_i)*(c_eta_i*(self.sc["c_phi_1"]*self.sc["s_phi_3"] + \
            self.sc["c_phi_3"]*self.sc["s_phi_1"]*self.sc["s_phi_2"]) - \
            s_eta_i*(self.sc["c_phi_1"]*self.sc["c_phi_3"] - \
            self.sc["s_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"])) + \
            c_q_2*(c_eta_i*self.sc["c_phi_2"]*self.sc["c_phi_3"] + \
            self.sc["c_phi_2"]*s_eta_i*self.sc["s_phi_3"])*(s_eta_i*s_q_1 - \
            c_eta_i*c_q_1))/((s_q_2**2 + \
            c_q_2**2*(c_eta_i*s_q_1 + \
            c_q_1*s_eta_i)**2 + \
            c_q_2**2*(s_eta_i*s_q_1 - \
            c_eta_i*c_q_1)**2)**(1/2)*((c_eta_i*(self.sc["c_phi_1"]*self.sc["s_phi_3"] + \
            self.sc["c_phi_3"]*self.sc["s_phi_1"]*self.sc["s_phi_2"]) - \
            s_eta_i*(self.sc["c_phi_1"]*self.sc["c_phi_3"] - \
            self.sc["s_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"]))**2 + \
            (c_eta_i*(self.sc["s_phi_1"]*self.sc["s_phi_3"] - \
            self.sc["c_phi_1"]*self.sc["c_phi_3"]*self.sc["s_phi_2"]) - \
            s_eta_i*(self.sc["c_phi_3"]*self.sc["s_phi_1"] + \
            self.sc["c_phi_1"]*self.sc["s_phi_2"]*self.sc["s_phi_3"]))**2 + \
            (c_eta_i*self.sc["c_phi_2"]*self.sc["c_phi_3"] + \
            self.sc["c_phi_2"]*s_eta_i*self.sc["s_phi_3"])**2)**(1/2))
    
    q_3 = -acos(c_q_3)
    self.sc["c_q_3"][leg] = c_q_3
    self.sc["s_q_3"][leg] = sin(self.q_3[leg])

    return q_3

  def _ik_leg(self, leg):
    A_q1, B_q1, C_q1 = self._q1_coef(leg)
    self.q_1[leg] = self._ik_solver(A_q1, B_q1, C_q1)
    
    A_q2, B_q2, C_q2 = self._q2_coef(leg)
    self.q_2[leg] = self._ik_solver(A_q2, B_q2, C_q2, True)

    self.q_3[leg] = self._q3_solver(leg)
    return

  def inverse_kinematics(self, phi_1, phi_2, phi_3):
    self.phi_1 = phi_1
    self.phi_2 = phi_2
    self.phi_3 = phi_3

    for leg in self.legs:
      self._ik_leg(leg)
    
    return self.q_1-self.q_1_0, self.q_2-self.q_2_0, self.q_3-self.q_3_0

  def _J_leg(self, leg):
    s_eta_i = self.sc["s_eta_i"][leg]
    c_eta_i = self.sc["c_eta_i"][leg]
    s_q_1 = self.sc["s_q_1"][leg]
    c_q_1 = self.sc["c_q_1"][leg]
    s_q_2 = self.sc["s_q_2"][leg]
    c_q_2 = self.sc["c_q_2"][leg]
    
    J_1 = np.zeros((3,1))
    J_1[2,0] = -1

    J_2 = np.zeros((3,1))
    J_2[0,0] = c_eta_i*s_q_1 + c_q_1*s_eta_i
    J_2[1,0] = c_eta_i*c_q_1 - s_eta_i*s_q_1

    J_3 = np.zeros((3,1))
    J_3[0,0] = c_eta_i*c_q_1*s_q_2 - s_eta_i*s_q_1*s_q_2
    J_3[1,0] = - c_eta_i*s_q_1*s_q_2 - c_q_1*s_eta_i*s_q_2
    J_3[2,0] = c_q_2
    return J_1, J_2, J_3, np.hstack((J_1, J_2, J_3))
  
  def _J_ee(self):
    J = np.zeros((3,3))
    J[0,0] = 1

    J[1,1] = self.sc["c_phi_1"]
    J[2,1] = self.sc["s_phi_1"]

    J[0,2] = self.sc["s_phi_2"]
    J[1,2] = -self.sc["c_phi_2"]*self.sc["s_phi_1"]
    J[2,2] = self.sc["c_phi_1"]*self.sc["c_phi_2"]
    return J

  def forward_diff_kinematics(self, dq_11, dq_21, dq_22, dq_23):
    self.dq_1[0] = dq_11
    self.dq_2 = np.array([dq_21, dq_22, dq_23])

    J_end = self._J_ee()
    dq = np.array([[dq_11], [dq_21], [dq_22], [dq_23]])
    u1, w1, v1, J_1 = self._J_leg(self.legs[0])
    u2, w2, v2, _  = self._J_leg(self.legs[1])
    u3, w3, v3, _ = self._J_leg(self.legs[2])

    zero = np.zeros((3,1))
    J_act = np.vstack((np.hstack((u1, w1, -w2, zero)),
                      np.hstack((zero, zero, -w2, w3))))
    
    J_pass = np.vstack((np.hstack((v1, -u2, -v2, zero, zero)),
                        np.hstack((zero, -u2, -v2, u3, v3))))

    J_rel = -np.linalg.pinv(J_pass) @ J_act
    J_relation = np.array([[1, 0, 0, 0],
                          [0, 1, 0, 0],
                          [J_rel[0,0], J_rel[0,1], J_rel[0,2], J_rel[0,3]]])
    
    dphi = np.linalg.inv(J_end) @ J_1 @ J_relation @ dq
    
    self.dphi_1 = dphi[0,0]
    self.dphi_2 = dphi[1,0]
    self.dphi_3 = dphi[2,0]
    return self.dphi_1, self.dphi_2, self.dphi_3

  def inverse_diff_kinematics(self, dphi_1, dphi_2, dphi_3):
    self.dphi_1 = dphi_1
    self.dphi_2 = dphi_2
    self.dphi_3 = dphi_3

    dphi = np.array([[dphi_1], [dphi_2], [dphi_3]])
    J_end = self._J_ee()

    dq_1, dq_2, dq_3 = [], [], []
    for leg in self.legs:
      _, _, _, J = self._J_leg(leg)
      dq = np.linalg.inv(J) @ J_end @ dphi
      dq_1.append(dq[0,0])
      dq_2.append(dq[1,0])
      dq_3.append(dq[2,0])

    self.dq_1 = np.array(dq_1)
    self.dq_2 = np.array(dq_2)
    self.dq_3 = np.array(dq_3)
    
    return self.dq_1, self.dq_2, self.dq_3