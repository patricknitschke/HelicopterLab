%% Task 2.2 - Pole placement 
Dag2;

%% Two identical poles

% get crit damped pole data, z = 1, w_0 = 0.5
z_1_w_do5 = load('z_1_w_do5.mat');
z_1_w_do5_data = z_1_w_do5.z_1_w_do5;

timestamp_1     = z_1_w_do5_data(1,:);
z_1_w_do5_p_c = z_1_w_do5_data(2,:);
z_1_w_do5_p   = z_1_w_do5_data(3,:);


% get crit damped pole data, z = 1, w_0 = 1.5
z_1_w_1dot5 = load('z_1_w_1dot5.mat');
z_1_w_1dot5_data = z_1_w_1dot5.z_1_w_1dot5;

timestamp_2     = z_1_w_1dot5_data(1,:);
z_1_w_1dot5_p_c = z_1_w_1dot5_data(2,:);
z_1_w_1dot5_p   = z_1_w_1dot5_data(3,:);

% get crit_damped pole data, z = 1, w_0 = 4
z_1_w_4 = load('z_1_w_4.mat');
z_1_w_4_data = z_1_w_4.z_1_w_4;

timestamp_3     = z_1_w_4_data(1,:);
z_1_w_4_p_c = z_1_w_4_data(2,:);
z_1_w_4_p   = z_1_w_4_data(3,:);

% get overdamped pole data, z = 3, w_0 = 1.5
z_3_w_1dot5 = load('z_3_w_1dot5.mat');
z_3_w_1dot5_data = z_3_w_1dot5.z_3_w_1dot5;

timestamp_4     = z_3_w_1dot5_data(1,:);
z_3_w_1dot5_p_c = z_3_w_1dot5_data(2,:);
z_3_w_1dot5_p   = z_3_w_1dot5_data(3,:);

% get overdamped pole data, z = 3, w_0 = 6
z_3_w_6 = load('z_3_w_6.mat');
z_3_w_6_data = z_3_w_6.z_3_w_6;

timestamp_5     = z_3_w_6_data(1,:);
z_3_w_6_p_c = z_3_w_6_data(2,:);
z_3_w_6_p   = z_3_w_6_data(3,:);

% get underdamped pole data, z = 0.5, w_0 = 0.5
z_dot5_w_dot5 = load('z_dot5_w_dot5.mat');
z_dot5_w_dot5_data = z_dot5_w_dot5.z_dot5_w_dot5;

timestamp_6     = z_dot5_w_dot5_data(1,:);
z_dot5_w_dot5_p_c = z_dot5_w_dot5_data(2,:);
z_dot5_w_dot5_p   = z_dot5_w_dot5_data(3,:);

% get underdamped pole data, z = 0.5, w_0 = 1.5
z_dot5_w_1dot5 = load('z_dot5_w_1dot5.mat');
z_dot5_w_1dot5_data = z_dot5_w_1dot5.z_dot5_w_1dot5;

timestamp_7     = z_dot5_w_1dot5_data(1,:);
z_dot5_w_1dot5_p_c = z_dot5_w_1dot5_data(2,:);
z_dot5_w_1dot5_p   = z_dot5_w_1dot5_data(3,:);



%% PLOTTING - crit
figure(1);

%plot pitch rate
subplot(3,1,1);

plot(timestamp_1, z_1_w_do5_p_c,'r');
hold on;
plot(timestamp_1, z_1_w_do5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([13, 20]);
title('Pitch comparison, Poles: \zeta = 1, \omega_0 = 0.5');

%plot pitch rate
subplot(3,1,2);

plot(timestamp_2, z_1_w_1dot5_p_c,'r');
hold on;
plot(timestamp_2, z_1_w_1dot5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([14, 20]);
title('Pitch comparison, Poles: \zeta = 1, \omega_0 = 1.5');

subplot(3,1,3);

plot(timestamp_3, z_1_w_4_p_c,'r');
hold on;
plot(timestamp_3, z_1_w_4_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([13.8, 20]);
title('Pitch comparison, Poles: \zeta = 1, \omega_0 = 4');


%% overdamped
figure(2);
%plot pitch rate
subplot(2,1,1);

plot(timestamp_4, z_3_w_1dot5_p_c,'r');
hold on;
plot(timestamp_4, z_3_w_1dot5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([14, 20]);
title('Pitch comparison, Poles: \zeta = 3, \omega_0 = 1.5');

%plot pitch rate
subplot(2,1,2);

plot(timestamp_5, z_3_w_6_p_c,'r');
hold on;
plot(timestamp_5, z_3_w_6_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([25, 33]);
title('Pitch comparison, Poles: \zeta = 3, \omega_0 = 6');


%% underdamped 

figure(3);
%plot pitch rate
subplot(2,1,1);

plot(timestamp_6, z_dot5_w_dot5_p_c,'r');
hold on;
plot(timestamp_6, z_dot5_w_dot5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([18, 25]);
title('Pitch comparison, Poles: \zeta = 0.5, \omega_0 = 0.5');

%plot pitch rate
subplot(2,1,2);

plot(timestamp_7, z_dot5_w_1dot5_p_c,'r');
hold on;
plot(timestamp_7, z_dot5_w_1dot5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([11, 14.6]);
title('Pitch comparison, Poles: \zeta = 0.5, \omega_0 = 1.5');

%% extra

wxyz = zeros(4,1000);
x_time = zeros(1,1000,'double');
for i = 1:4
    for x = 1:100
        time = x/100;
        wxyz(i,x) = exp(-i*time)*cos(i*time);
        x_time(x) = time;
    end
end

figure(4);
plot(x_time, wxyz(1,:),'r');
hold on;
plot(x_time, wxyz(2,:),'b');
plot(x_time, wxyz(4,:), 'g');
grid on;
xlabel('Time [s]');
ylabel('Amplitude [units]');
l = legend('\omega_0 = 1','\omega_0 = 2', '\omega_0 = 4');
title('\zeta = 1, different \omega');

