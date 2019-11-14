%% Task 6 - Noise

Noise_flying_still = load('Noise_flying_still_final.mat');
Noise_flying_still_vals = Noise_flying_still.Noise_flying_still(:, 10000:end); % remove incorrect start data

IMU_timestamp = Noise_flying_still_vals(1,:);
IMU_pitch_r = Noise_flying_still_vals(2,:);
IMU_elevation_r = Noise_flying_still_vals(3,:);
IMU_travel_r = Noise_flying_still_vals(4,:);
IMU_pitch = Noise_flying_still_vals(5,:);
IMU_elevation = Noise_flying_still_vals(6,:);


figure(1);
x_start = 20;
x_stop = 120;

%plot pitch rate
subplot(5,1,1);

plot(IMU_timestamp, IMU_pitch_r,'r');
hold on;
grid on;
xlabel('seconds [s]');
ylabel('Pitch rate [rad/s]');
xlim([x_start, x_stop]);
title('IMU Pitch rate');

%plot elevation rate
subplot(5,1,2);

plot(IMU_timestamp, IMU_elevation_r,'b');
hold on;
grid on;
xlabel('seconds [s]');
ylabel('Elevation rate [rad/s]');
xlim([x_start, x_stop]);
title('IMU Elevation rate');

%plot lambda rate
subplot(5,1,3);

plot(IMU_timestamp, IMU_travel_r,'g');
hold on;
grid on;
xlabel('seconds [s]');
ylabel('Travel rate [rad/s]');
xlim([x_start, x_stop]);
title('IMU Travel rate');

%plot pitch
subplot(5,1,4);

plot(IMU_timestamp, IMU_pitch,'r');
hold on;
grid on;
xlabel('seconds [s]');
ylabel('Pitch [rad]');
xlim([x_start, x_stop]);
title('IMU Pitch');

%plot elevation
subplot(5,1,5);

plot(IMU_timestamp, IMU_elevation,'b');
hold on;
grid on;
xlabel('seconds [s]');
ylabel('Elevation [rad]');
xlim([x_start, x_stop]);
title('IMU Elevation');

%expected values
pitch_r_mean = mean(IMU_pitch_r, 'omitnan');
elevation_r_mean = mean(IMU_elevation_r, 'omitnan');
travel_r_mean = mean(IMU_travel_r, 'omitnan');

% covariances
IMU_vals_no_time = Noise_flying_still_vals;
IMU_vals_no_time(1,:) = [];
Cov_matrix = cov(IMU_vals_no_time.', 'omitrows');