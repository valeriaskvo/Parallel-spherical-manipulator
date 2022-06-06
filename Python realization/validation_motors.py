from A1_MOTOR import init_A1_sdk, A1_motor
from time import perf_counter, sleep
import numpy as np

c, port = init_A1_sdk()
motor = A1_motor(id = 0, c = c, port = port, pd = {"kp": 0.002, "kd": 0.35})

input("Press any key")

vel = 10
t0 = perf_counter()
t_max = 20
t = 0
w = 4*np.pi/t_max

period = 4
try:
    print("Motor start")
    while t < t_max:
        # sleep(0.1)
        if t % period >= period/2:
            qd = np.deg2rad(45)
        else: 
            qd = -np.deg2rad(45)
        motor.set_q(qd)
        t = perf_counter() - t0    

except KeyboardInterrupt:
    print("Motor stop by keyboard")
except Exception as e:
    print("Motor stop by inner exception")
    print("Exception is", e.args[0])
finally:
    motor.stop()
