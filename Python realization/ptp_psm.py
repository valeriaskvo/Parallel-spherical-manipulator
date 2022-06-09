from PSM import Asymmetry_PSM
import numpy as np


def ptp_trajectory(t, alpha):
    q_eq = np.array([1, t, t**2, t**3])
    dq_eq = np.array([0, 1, 2*t, 3*t**2])
    ddq_eq = np.array([0, 0, 2, 6*t])
    return q_eq.T @ alpha, dq_eq.T @ alpha, ddq_eq.T @ alpha

def compute_alpha(t, q_0, q_des):
    A = np.array([[1, 0 , 0, 0],
                    [1, t, t**2, t**3],
                    [0, 1, 0, 0],
                    [0, 1, 2*t, 3*t**2]])
    state = np.array([q_0, q_des, 0, 0])
    return np.linalg.pinv(A) @ state

def check_constr(t_max, q_0, q_des, dq_max, ddq_max):
    alpha = compute_alpha(t_max, q_0, q_des)
    _, _, ddq_constr = ptp_trajectory(0, alpha)
    _, dq_constr, _ = ptp_trajectory(t_max/2, alpha)
    return np.abs(ddq_constr) > ddq_max or np.abs(dq_constr) > dq_max

def compute_trajectory_time(q_0, q_des, dq_max = np.pi**2/2, ddq_max = np.pi**3/2):
    q = np.abs(q_des - q_0)
    t = np.array([2*np.sqrt(q/ddq_max), q / dq_max])
    t_f = np.max(t)

    while check_constr(t_f, q_0, q_des, dq_max, ddq_max):
        t_f = t_f + 0.01
    return t_f

def ptp_trajectory_init(phi_des, phi_0):
    t_f = []
    for i in range(3):
        t_f.append(compute_trajectory_time(phi_0[i], phi_des[i]))
    
    t_f = np.max(t_f)
    coefs = []
    for i in range(3):
        coefs.append(compute_alpha(t_f, phi_0[i], phi_des[i]))
    
    return t_f, coefs

def ptp_trajectory_generation(t, coefs, psm):
    phi = []
    dphi = []
    ddphi = []
    for alpha in coefs:
        phi_i, dphi_i, ddphi_i = ptp_trajectory(t, alpha)
        phi.append(phi_i)
        dphi.append(dphi_i)
        ddphi.append(ddphi_i)
    
    _, q2, _ = psm.inverse_kinematics(phi[0], phi[1], phi[2])
    _, dq2, _ = psm.inverse_diff_kinematics(dphi[0], dphi[1], dphi[2])
    return q2, dq2, phi, dphi, ddphi