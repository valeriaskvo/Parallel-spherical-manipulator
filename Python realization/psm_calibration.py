from A1_motor import A1_motor, open_serial_port, save_obj, load_obj


serial_port = open_serial_port()

ids = [0, 1, 2]
pd = {"kp": 0.1, "kd": 2.8}
motors = []
# for id in ids:
#     motors.append(A1_motor(id, serial_port, pd, calib=True))
# pos_0 = {}

# for i, motor in enumerate(motors):
#     pos_0[ids[i]] = motor.pos_0

# save_obj(pos_0)

for id in ids:
    motors.append(A1_motor(id, serial_port, pd))

for motor in motors:
    print(motor.pos_0)