init_heli;
LQR;

%% Lab 5 - Prediction step

%State Space model
A = zeros(6,6);
B = zeros(6,2);
C = zeros(5,6);
D = 0;

A(1,2) = 1;
A(3,4) = 1;
A(5,6) = 1;
A(6,1) = K_3;

B(2,2) = K_1;
B(4,1) = K_2;

C(1,2) = 1;
C(2,4) = 1;
C(3,6) = 1;
C(4,1) = 1;
C(5,3) = 1;
test_var = 0;
sys_cont = ss(A,B,C,D);

%Discrete model
Ts = 0.002;     %Sample time = Time-Step
sys_disc = c2d(sys_cont, Ts);

A_d = sys_disc.A;
B_d = sys_disc.B;
C_d = sys_disc.C;

Q_d = diag([0.0001 0.001 0.001 0.001 0.0001 0.0001]);



%Noise for v_d
IMU = load('Flight_noise.mat');
IMU_vals = IMU.ans(:, 20000:end); % remove incorrect start data
IMU_timestamp = IMU_vals(1,:);
IMU_pitch_r = IMU_vals(2,:);
IMU_elevation_r = IMU_vals(3,:);
IMU_travel_r = IMU_vals(4,:);
IMU_pitch = IMU_vals(5,:);
IMU_elevation = IMU_vals(6,:);

%expected values
pitch_r_mean = mean(IMU_pitch_r, 'omitnan');
elevation_r_mean = mean(IMU_elevation_r, 'omitnan');
travel_r_mean = mean(IMU_travel_r, 'omitnan');

% covariances
IMU_vals_no_time = IMU_vals;
IMU_vals_no_time(1,:) = [];
R_d = cov(IMU_vals_no_time.', 'omitrows');
R_d = R_d(1:5, 1:5);


%% Lab 6 - Correction step

K = zeros(6, 5);
