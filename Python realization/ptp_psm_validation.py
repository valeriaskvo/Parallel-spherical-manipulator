from ptp_psm import ptp_trajectory_init, ptp_trajectory_generation
from PSM import Asymmetry_PSM
import numpy as np
import matplotlib.pyplot as plt

psm = Asymmetry_PSM()

# phi_1_des = np.deg2rad([0, 30, 15, 0, -30, -15, 0,  0,  0, 0,   0,  0,  0])
# phi_2_des = np.deg2rad([0,  0,  0, 0,   0,  0,  0, 30, 15, 0, -30, -15, 0])
# phi_3_des = np.deg2rad([0,  0,  0, 0,   0,  0,  0,  0,  0, 0,   0,  0,  0])

phi_1_des = np.deg2rad([0, 30, 0])
phi_2_des = np.deg2rad([0,  0, 0])
phi_3_des = np.deg2rad([0,  0, 0])

phi_data = []
dphi_data = []
ddphi_data = []
q_data = []
dq_data = []
for step in range(1, len(phi_1_des)):
    phi_0 = np.array([phi_1_des[step-1], phi_2_des[step-1], phi_3_des[step-1]])
    phi_des = np.array([phi_1_des[step], phi_2_des[step], phi_3_des[step]])
    t_f, coefs = ptp_trajectory_init(phi_des, phi_0)
    
    time = np.linspace(0, t_f, 1000)

    if step == 1:
        time_general = time
    else:
        time_general = np.hstack((time_general, np.max(time_general)+time))

    for t in time:
        q2, dq2, phi, dphi, ddphi = ptp_trajectory_generation(t, coefs, psm)

        phi_data.append(phi)
        dphi_data.append(dphi)
        ddphi_data.append(ddphi)
        q_data.append(q2)
        dq_data.append(dq2)  

time = time_general
phi = np.array(phi_data)
dphi = np.array(dphi_data)
ddphi = np.array(ddphi_data)
q = np.array(q_data)
dq = np.array(dq_data)

dq_max = np.pi/4
ddq_max = np.pi**2/4
dq_max = np.ones(time.shape)*dq_max
ddq_max = np.ones(time.shape)*ddq_max

print("Maximum time:", t_f, "sec")

fig, (ax1, ax2, ax3) = plt.subplots(3, 1, sharex=True)

ax1.plot(time, np.rad2deg(phi))
ax1.legend(['phi_1', 'phi_2', 'phi_3'])
ax1.set_title('Position')
ax1.grid(linestyle='--')

ax2.plot(time, np.rad2deg(dphi))
ax2.plot(time, np.rad2deg(dq_max), 'r--')
ax2.plot(time, -np.rad2deg(dq_max), 'r--')
ax2.legend(['dphi_1', 'dphi_2', 'dphi_3'])
ax2.set_title('Velocity')
ax2.grid(linestyle='--')

ax3.plot(time, np.rad2deg(ddphi))
ax3.plot(time, np.rad2deg(ddq_max), 'r--')
ax3.plot(time, -np.rad2deg(ddq_max), 'r--')
ax3.legend(['ddphi_1', 'ddphi_2', 'ddphi_3'])
ax3.set_title('Acceleration')
ax3.grid(linestyle='--')

fig.set_size_inches(18.5, 10.5)
fig.tight_layout()
plt.show()



fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)

ax1.plot(time, np.rad2deg(q))
ax1.legend(['leg 1', 'leg 2', 'leg 3'])
ax1.set_title('Position')
ax1.grid(linestyle='--')

ax2.plot(time, np.rad2deg(dq))
ax2.legend(['leg 1', 'leg 2', 'leg 3'])
ax2.set_title('Velocity')
ax2.grid(linestyle='--')

fig.set_size_inches(10.5, 10.5)
fig.tight_layout()
plt.show()