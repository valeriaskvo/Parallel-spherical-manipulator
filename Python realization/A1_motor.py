#!/usr/bin/env python3
import build.A1_py_sdk as A1
from numpy import rad2deg
from time import sleep

def open_serial_port(port = "/dev/ttyUSB0"):
    serial_port = A1.A1_motor(port)
    return serial_port

class A1_motor(object):
    def __init__(self, id, serial_port, pd = {"kp": 0.01, "kd": 0.7}):

        self.transmission_ratio = 9
        self.serial_port = serial_port
        for i in range(100):
            serial_port.stop(id)

        self.id = id
        self.q = 0
        self.dq = 0
        self.tau = 0
        
        self.serial_port.set_pd(pd["kp"], pd["kd"])
        self.resp = serial_port.init(id)
        self.pos_0 = self.resp[1]
        
        self.pos = 0
        self.vel = 0
        self.f = 0            
        
        if self.pos_0 > 2 * 3.14 * self.transmission_ratio:
            print("Restart the motor", id, "its angle is too large to set the control")
            del self
            raise Exception('MotorEncoderOverflowed')
        else:
            print("Motor", id, "initialized in zero position",\
              rad2deg(self.pos_0/self.transmission_ratio), "[deg]")

    def unpack_response(self):
        sleep(0.00001)       
        self.pos = self.resp[1] - self.pos_0
        self.vel = self.resp[2]
        self.f = self.resp[3]
        
        self.q = self.pos / self.transmission_ratio
        self.dq = self.vel / self.transmission_ratio
        self.tau = self.f * self.transmission_ratio

    def set_pd(self, pd = {"kp": 0.01, "kd": 0.7}):
        self.serial_port.set_pd(pd["kp"], pd["kd"])

    def set_q(self, q):
        self.resp = self.serial_port.set_position(self.id, q * self.transmission_ratio + self.pos_0)
        self.unpack_response()

    def set_dq(self, dq):
        self.resp = self.serial_port.set_velocity(self.id, dq * self.transmission_ratio)
        self.unpack_response()

    def set_q_and_dq(self, q, dq):
        self.resp = self.serial_port.set_position_and_velocity( self.id, 
                                                                q * self.transmission_ratio + self.pos_0,
                                                                dq * self.transmission_ratio)
        self.unpack_response()

    def stop(self):
        self.serial_port.stop(self.id)
        del self
