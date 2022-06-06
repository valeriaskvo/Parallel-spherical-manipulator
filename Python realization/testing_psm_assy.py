from pyrsistent import dq
from A1_motor import A1_motor, open_serial_port
from PSM import Asymmetry_PSM
from time import perf_counter, sleep
import numpy as np

def sin_traj(t, traj_params):
    return traj_params["A"]*np.sin(traj_params["w"]*t)

def dsin_traj(t, traj_params):
    return traj_params["A"]*traj_params["w"]*np.cos(traj_params["w"]*t)

serial_port = open_serial_port()

pd = {"kp": 0.1, "kd": 2.5}
ids = [0, 1, 2]
motors = []
for id in ids:
    motors.append(A1_motor(id, serial_port, pd))

psm = Asymmetry_PSM()
input("Press any key")

t_max = 10
traj_params_1 = {"A":np.deg2rad(20),
               "w":np.pi}

traj_params_2 = {"A":np.deg2rad(40),
               "w":np.pi/2}

t0 = perf_counter()
t = 0
dt = 0
n = 0
tr = 9
try:
    print("Motor start")
    while t < t_max:
        phi_1 = sin_traj(t, traj_params_1)
        phi_2 = sin_traj(t, traj_params_2)
        phi_3 = 0
        q1, q2, q3 = psm.inverse_kinematics(phi_1, phi_2, phi_3)

        dphi_1 = dsin_traj(t, traj_params_1)
        dphi_2 = dsin_traj(t, traj_params_2)
        dphi_3 = 0
        dq1, dq2, dq3 = psm.inverse_diff_kinematics(dphi_1, dphi_2, dphi_3)
        
        q = list(q2.copy())
        dq = list(dq2.copy())

        # print(np.rad2deg(q))

        t1 = perf_counter()
        for i, motor in enumerate(motors):
            motor.set_q_and_dq(q[i], dq[i])

        t2 = perf_counter()
        t = perf_counter() - t0
        
        n = n + 1
        dt = dt + (t2 - t1)
    
except KeyboardInterrupt:
    print("Motor stop by keyboard")
except Exception as e:
    print("Motor stop by inner exception")
    print("Exception is", e.args[0])
finally:
    print("Motor stop")

    for id, motor in enumerate(motors):
        print("Motor", id, "initialized in zero position",\
              np.rad2deg(motor.q), "[deg]")
        motor.stop()


print("Average run time:", dt/n,"sec")
print("Average frequency:", n/dt,"sec")