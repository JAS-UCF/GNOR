#ifndef D3BB135D_F1AA_4FEC_A5D0_C611841345DD
#define D3BB135D_F1AA_4FEC_A5D0_C611841345DD
// The minimum a motor will ever put out, even when under max steer, values below 0.5 will have the motors spin less than half speed
#define STEERING_CORRECTION_MIN 0.2
// uncomment the line below if you want to compile to code into calibration mode

// The lines below help the compiler decide which mode to load into, calibration or RUN

// #define CALIBRATE 1
#define RUN 1

// below are some constants that help control the PID controllers for the motor
#define PID_GAIN 0.001
#define PID_INTEGRAL 3
#define PID_DERIVATIVE 5

#endif /* D3BB135D_F1AA_4FEC_A5D0_C611841345DD */
