from A1_MOTOR import init_A1_sdk, A1_motor
from time import perf_counter, sleep
import numpy as np
from sensors import SensorRJ
from can import CAN_Bus

c, port = init_A1_sdk()
motor = A1_motor(id = 1, c = c, port = port, pd = {"kp": 0, "kd": 3})

bus = CAN_Bus(interface = 'can0')
sensors = SensorRJ(bus)

input("Press any key")

vel = 10
t0 = perf_counter()
t_max = 3
t = 0

qs_data = []
q_data = []
pos_data = []
t_data = []
try:
    print("Motor start")
    while t < t_max:
        
        # sleep(0.05)
        motor.send_velocity(vel)
        _, q_sens = sensors.read_encoders()
        # qs_data.append(q_sens)
        # print(round(np.rad2deg(q_sens),4), round(np.rad2deg(motor.q),4))

        qs_data.append(q_sens)
        q_data.append(motor.q)
        pos_data.append(motor.pos)
        t_data.append(t)

        # print("pos0 =", np.rad2deg(motor.pos_0), "deg")

        # print("q =", np.rad2deg(motor.q),\
        #       "deg, dq =", motor.dq, "rad/sec\n")

        t = perf_counter() - t0    

except KeyboardInterrupt:
    print("Motor stop by keyboard")
except Exception as e:
    print("Motor stop by inner exception")
    print("Exception is", e.args[0])
finally:
    motor.stop()

qs = np.array(qs_data)
pos = np.array(pos_data)
t = np.array(t_data)
q = np.array(q_data)

tr = pos/qs

import matplotlib.pyplot as plt
plt.plot(t, tr)
plt.show()

plt.plot(t, q)
plt.plot(t, qs)
plt.show()

print("Calculated transmission ratio",np.mean(tr))