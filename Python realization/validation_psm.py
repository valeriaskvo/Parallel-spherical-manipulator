from PSM import Asymmetry_PSM
import numpy as np
import matplotlib.pyplot as plt
from copy import deepcopy

def sin_traj(t, A, w):
  return A*np.sin(w*t)

t = 0
t_max = 60
dt = 0.01

w = 3*np.pi/t_max
A = np.deg2rad(45)

psm = Asymmetry_PSM()
while t < t_max:
  phi_1 = sin_traj(t, A, w)
  phi_2 = 0
  phi_3 = 0

  q1, q2, q3 = psm.inverse_kinematics(phi_1, phi_2, phi_3)

  data_t = np.hstack((np.array([t]), q2))

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
