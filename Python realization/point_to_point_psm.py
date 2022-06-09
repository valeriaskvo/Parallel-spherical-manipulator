from time import perf_counter
from PSM import Asymmetry_PSM
from A1_motor import A1_motor, open_serial_port
from ptp_psm import ptp_trajectory_init, ptp_trajectory_generation
import numpy as np

serial_port = open_serial_port()

pd = {"kp": 0.1, "kd": 2.8}
ids = [0, 1, 2]
motors = []
for id in ids:
    motors.append(A1_motor(id, serial_port, pd))

psm = Asymmetry_PSM()

# phi_1_des = np.deg2rad([30, 15, 0, -30, -15, 0,  0,  0, 0,   0,  0,  0])
# phi_2_des = np.deg2rad([0,  0, 0,   0,  0,  0,  30, 15, 0, -30, -15, 0])
# phi_3_des = np.deg2rad([0,  0, 0,   0,  0,  0,   0,  0, 0,   0,  0,  0])

phi_1_des = np.deg2rad([30,  0, -30, -30,   0, 0])
phi_2_des = np.deg2rad([0,  30, -15,   0, -30, 0])
phi_3_des = np.deg2rad([0,  0,    0,   0,   0, 0])

try:
    for step in range(len(phi_1_des)):
        input("Press any key to continue...")
        phi_1, phi_2, phi_3 = psm.forward_kinematics(0, motors[0].q, motors[1].q, motors[2].q)
        phi_0 = np.array([phi_1, phi_2, phi_3])
        phi_des = np.array([phi_1_des[step], phi_2_des[step], phi_3_des[step]])
        t_f, coefs = ptp_trajectory_init(phi_des, phi_0)
        
        t0 = perf_counter()
        t = 0

        while t < t_f:
            q, dq, _, _, _ = ptp_trajectory_generation(t, coefs, psm)
            for i, motor in enumerate(motors):
                motor.set_q_and_dq(q[i], dq[i])
            t = perf_counter() - t0
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
