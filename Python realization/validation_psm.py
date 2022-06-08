from PSM import Asymmetry_PSM
import numpy as np
import matplotlib.pyplot as plt
from copy import deepcopy

def sin_traj(t, traj_params):
    return traj_params["A"]*np.sin(traj_params["w"]*t)

def dsin_traj(t, traj_params):
    return traj_params["A"]*traj_params["w"]*np.cos(traj_params["w"]*t)

t = 0
t_max = 20
dt = 0.1

traj_params_1 = {"A":np.deg2rad(20),
                 "w":3*np.pi/t_max}

traj_params_2 = {"A":np.deg2rad(40),
                 "w":6*np.pi/(t_max)}

psm = Asymmetry_PSM()
while t < t_max:
  phi_1 = sin_traj(t, traj_params_1)
  phi_2 = sin_traj(t, traj_params_2)
  phi_3 = 0

  dphi_1 = dsin_traj(t, traj_params_1)
  dphi_2 = dsin_traj(t, traj_params_2)
  dphi_3 = 0

  q1, q2, q3 = psm.inverse_kinematics(phi_1, phi_2, phi_3)
  dq1, dq2, dq3 = psm.inverse_diff_kinematics(dphi_1, dphi_2, dphi_3)
  phi_1_calc, phi_2_calc, phi_3_calc = psm.forward_kinematics(q1[0], q2[0], q2[1], q2[2])
  dphi_1_calc, dphi_2_calc, dphi_3_calc = psm.forward_diff_kinematics(dq1[0], dq2[0], dq2[1], dq2[2])

  data_t = np.hstack((np.array([t]), q2, dq2, np.array([phi_1_calc, phi_2_calc, phi_3_calc, dphi_1_calc, dphi_2_calc, dphi_3_calc])))

  if t == 0:
    data = data_t
  else:
    data = np.vstack((data, data_t))
  
  t += dt


print("Done!")
plt.plot(data[:,0], np.rad2deg(data[:, 1:4]))
plt.xlabel('Time [sec]')
plt.ylabel('Angle [deg]')
plt.legend(['leg 1', 'leg 2', 'leg 3'])
plt.show()

plt.plot(data[:,0], np.rad2deg(data[:, 4:7]))
plt.xlabel('Time [sec]')
plt.ylabel('Velocity [deg/sec]')
plt.legend(['leg 1', 'leg 2', 'leg 3'])
plt.show()

plt.plot(data[:,0], np.rad2deg(data[:, 7:10]))
plt.xlabel('Time [sec]')
plt.ylabel('Angle [deg]')
plt.legend(['phi_1', 'phi_2', 'phi_3'])
plt.show()

plt.plot(data[:,0], np.rad2deg(data[:, 10:13]))
plt.xlabel('Time [sec]')
plt.ylabel('Velocity [deg/sec]')
plt.legend(['dphi_1', 'dphi_2', 'dphi_3'])
plt.show()