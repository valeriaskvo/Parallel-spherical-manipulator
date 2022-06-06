#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include <vector>
#include "serialPort/SerialPort.h"
#include <cmath>

using namespace std;
class A1_motor {
    public:
        A1_motor(const string& port_name) : serial(port_name) {
            motor_run.motorType = MotorType::A1Go1;
            motor_run.mode = 10;
            motor_run.K_P = 0.0;
            motor_run.K_W = 0.0;

            motor_stop.motorType = motor_run.motorType;
            motor_stop.mode = 0.0;

            motor_r.motorType = motor_run.motorType;

            modify_data(&motor_run);
            modify_data(&motor_stop);
        }

        vector<float> init(unsigned short id){
            vector<float> response = stop(id);
            for (int i=0; i<10; i++){
                response = stop(id);
            }
            bool is_zero = _is_zero_response(id, response);
            while (is_zero){
                response = stop(id);
                is_zero = _is_zero_response(id, response);
            }
            return response;
        }

        void set_pd(float kp, float kd){
            motor_run.K_P = kp;
            motor_run.K_W = kd;
            return;
        }

        vector<float> set_velocity(unsigned short id, float vel){
            motor_run.id = id;
            motor_run.W = vel;
            return _send_recieve(motor_run);
        }

        vector<float> set_position(unsigned short id, float pos){
            motor_run.id = id;
            motor_run.Pos = pos;
            return _send_recieve(motor_run);
        }

        vector<float> set_position_and_velocity(unsigned short id, float pos, float vel){
            motor_run.id = id;
            motor_run.Pos = pos;
            motor_run.W = vel;
            return _send_recieve(motor_run);
        }

        vector<float> stop(unsigned short id){
            motor_stop.id = id;
            return _send_recieve(motor_stop);
        }

    private:
        vector<float> _send_recieve(MOTOR_send& command){
            modify_data(&command);
            serial.sendRecv(&command, &motor_r);
            extract_data(&motor_r);
            vector<float> response = {static_cast<float>(motor_r.motor_id), motor_r.Pos, motor_r.W, motor_r.T};           
            return response;
        }

        bool _is_zero_response(unsigned short id, const vector<float>& response){
            return (static_cast<unsigned short>(response[0]) != id)
                    || (abs(response[1]) < _threshold)
                    || (abs(response[2]) < _threshold);
        }

        SerialPort serial;
        MOTOR_send motor_run, motor_stop;
        MOTOR_recv motor_r;
        float _threshold = 10e-6;
};

namespace py = pybind11;

PYBIND11_MODULE(A1_py_sdk, m) {
    py::class_<A1_motor>(m, "A1_motor")
        .def(py::init<const string&>())
        .def("set_pd", &A1_motor::set_pd)
        .def("init", &A1_motor::init)
        .def("set_velocity", &A1_motor::set_velocity)
        .def("set_position", &A1_motor::set_position)
        .def("set_position_and_velocity", &A1_motor::set_position_and_velocity)
        .def("stop", &A1_motor::stop);
}

