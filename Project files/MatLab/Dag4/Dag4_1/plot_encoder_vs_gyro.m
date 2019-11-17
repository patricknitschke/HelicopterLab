gyro_90deg = load('Gyro_90deg.mat');
gyro_90deg_data = gyro_90deg.Gyro_90deg;

time_stamp = gyro_90deg_data(1, :);
pitch_enc  = gyro_90deg_data(2, :);
pitch_IMU = gyro_90deg_data(3, :);
elev_enc = gyro_90deg_data(4,:);
elev_IMU = gyro_90deg_data(5, :);
travel_enc = gyro_90deg_data(6, :);
travel_IMU = gyro_90deg_data(7, :);


figure(1);
subplot(3,1,1);
plot(time_stamp, pitch_enc, 'r');
hold on;
grid on;
plot(time_stamp, pitch_IMU,'b');
l = legend(['nothing so far', 'ok']);
t = title('Pitch - Gyroscope versus encoders, with 90 deg flip');
xlabel('seconds [s]');
ylabel('Angle [rad]');


subplot(3,1,2);
plot(time_stamp, elev_enc, 'r');
hold on;
grid on;
plot(time_stamp, elev_IMU,'b');
l = legend(['nothing so far', 'ok']);
t = title('Elev. - Gyroscope versus encoders, with 90 deg flip.');
xlabel('seconds [s]');
ylabel('Angle [rad]');

subplot(3,1,3);
plot(time_stamp, travel_enc, 'r');
hold on;
grid on;
plot(time_stamp, travel_IMU,'b');
l = legend(['nothing so far', 'ok']);
t = title('Travel - Gyroscope versus encoders, with 90 deg flip.');
xlabel('seconds [s]');
ylabel('Angle [rad]');