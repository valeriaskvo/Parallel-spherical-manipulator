from A1_motor import A1_motor, open_serial_port
from time import perf_counter
from time import sleep
import numpy as np

serial_port = open_serial_port()
ids = [0, 1, 2]
# pd = {"kp": 0.1, "kd": 2.5}
pd = {"kp": 0.05, "kd": 1}

motors = []
for id in ids:
    motors.append(A1_motor(id, serial_port, pd))

t = 0
t_max = 10
dt = 0
n = 0

A = np.deg2rad(10)
w = np.pi*0.5

input("Press any key")
t0 = perf_counter()

try:
    while t<t_max:
        t1 = perf_counter()

        q = A * np.sin(w*t)
        dq = A * w * np.cos(w*t)

        # q = A * np.sign(np.sin(w*t))
        # dq = 
        # print(q)

        for motor in motors:
            motor.set_q_and_dq(q, dq)
            sleep(0.00001)

        t2 = perf_counter()
        
        dt = dt + (t2 - t1)
        n = n + 1

        t = perf_counter() - t0
   
    print("Average run time:", dt/n,"sec")
    print("Average frequency:", n/dt,"sec")

except KeyboardInterrupt:
    print("Motor stop by keyboard")

except Exception as e:
    print("Motor stop by inner exception")
    print("Exception is", e.args[0])

finally:
    for motor in motors:
        motor.stop()