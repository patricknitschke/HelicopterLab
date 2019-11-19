%% GYRO
gyro_90deg = load('Gyro_across_lambda_90_deg.mat');
gyro_90deg_data = gyro_90deg.Gyro_across_lambda_90_deg;

time_stamp = gyro_90deg_data(1, :);
pitch_enc  = gyro_90deg_data(2, :);
pitch_IMU = gyro_90deg_data(3, :);
elev_enc = gyro_90deg_data(4,:);
elev_IMU = gyro_90deg_data(5, :);
travel_enc = gyro_90deg_data(6, :);
travel_IMU = gyro_90deg_data(7, :);


figure(1);
subplot(3,1,1);
plot(time_stamp, pitch_enc, 'r' , 'LineWidth', 1.3);
hold on;
grid on;
plot(time_stamp, pitch_IMU,'b', 'LineWidth', 1.3);
l = legend('Encoder', 'Gyroscope');
t = title('Pitch - Gyroscope versus encoders, with 90 deg flip');
xlim([1, 8]);
xlabel('seconds [s]');
ylabel('Pitch [rad]');


subplot(3,1,2);
plot(time_stamp, elev_enc, 'r', 'LineWidth', 1.3);
hold on;
grid on;
plot(time_stamp, elev_IMU,'b', 'LineWidth', 1.3);
l = legend('Encoder','Gyroscope');
t = title('Elev. - Gyroscope versus encoders, with 90 deg flip.');
xlim([1, 8]);
xlabel('seconds [s]');
ylabel('Elevation [rad]');

subplot(3,1,3);
plot(time_stamp, travel_enc, 'r', 'LineWidth', 1.3);
hold on;
grid on;
plot(time_stamp, travel_IMU,'b', 'LineWidth', 1.3);
l = legend('Encoder', 'Gyroscope');
t = title('Travel - Gyroscope versus encoders, with 90 deg flip.');
xlim([1, 8]);
xlabel('seconds [s]');
ylabel('Travel [rad]');

%% ACC

acc_90deg_anticlock = load('acc_90deg_anticlock.mat');
acc_90deg_anticlock = acc_90deg_anticlock.acc_90deg_anticlock;

time_stamp = acc_90deg_anticlock(1, :);
pitch_enc  = acc_90deg_anticlock(2, :);
y_IMU = acc_90deg_anticlock(3, :);
elev_enc = acc_90deg_anticlock(4,:);
x_IMU = acc_90deg_anticlock(5, :);
travel_enc = acc_90deg_anticlock(6, :);
z_IMU = acc_90deg_anticlock(7, :);


figure(2);
subplot(3,1,1);
hold on;
grid on;
plot(time_stamp, x_IMU,'r', 'LineWidth', 1.4);
t = title('Acceleration on x-axis');
legend('Accelerometer_x');
xlim([1, 13]);
xlabel('seconds [s]');
ylabel('Acceleration [ms^{-2}]');


subplot(3,1,2);
hold on;
grid on;
plot(time_stamp, y_IMU,'b', 'LineWidth', 1.4);
t = title('Acceleration on y-axis');
xlim([1, 13]);
legend('Accelerometer_y');
xlabel('seconds [s]');
ylabel('Acceleration [ms^{-2}]');
subplot(3,1,3);
hold on;
grid on;
plot(time_stamp, z_IMU,'g', 'LineWidth', 1.4);
t = title('Acceleration on z-axis');
legend('Accelerometer_z');
xlim([1, 13]);
xlabel('seconds [s]');
ylabel('Acceleration [ms^{-2}]');