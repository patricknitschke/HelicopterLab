%% Day 5
init_heli_d5p3;
LQR_d5p3;

%% Task 5.1 - Discretisation

%Continuous model
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

%Continuous to discrete model
Ts = 0.002;                     % Sample time

sys_cont = ss(A,B,C,D);         % Create state-space
sys_disc = c2d(sys_cont, Ts);   % Create discrete sys

% Read discrete matrices
A_d = sys_disc.A;
B_d = sys_disc.B; 
C_d = sys_disc.C;

%% Find stochastic variables Q_d and R_d

% Measurement noise
Noise_flying_still = load('Noise_flying_still_final.mat');
Noise_flying_still_vals = Noise_flying_still.Noise_flying_still(:, 10000:end); % remove incorrect start data
IMU_timestamp = Noise_flying_still_vals(1,:);
IMU_pitch_r = Noise_flying_still_vals(2,:);
IMU_elevation_r = Noise_flying_still_vals(3,:);
IMU_travel_r = Noise_flying_still_vals(4,:);
IMU_pitch = Noise_flying_still_vals(5,:);
IMU_elevation = Noise_flying_still_vals(6,:);

%expected values
pitch_r_mean = mean(IMU_pitch_r, 'omitnan');
elevation_r_mean = mean(IMU_elevation_r, 'omitnan');
travel_r_mean = mean(IMU_travel_r, 'omitnan');

% covariances
Noise_flying_vals_no_time = Noise_flying_still_vals;
Noise_flying_vals_no_time(1,:) = [];

% Find R_d
R_d = cov(Noise_flying_vals_no_time.', 'omitrows');

% Test out different
Q_d_p = 0;
Q_d_pdot = 0;
Q_d_e = 0;
Q_d_edot = 0;
Q_d_l = 0;
Q_d_ldot = 0;

Q_d = diag([Q_d_p Q_d_pdot Q_d_e Q_d_edot Q_d_l Q_d_ldot]);


