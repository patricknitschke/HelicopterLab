%% Task 2.2 - Pole placement 
Dag2;

%% Two identical poles

% get crit_stable pole data, z = 1, w_0 = 1
z_1_w_1 = load('z_1_w_1.mat');
z_1_w_1_data = z_1_w_1.z_1_w_1;

timestamp_1     = z_1_w_1_data(1,:);
z_1_w_1_p_c = z_1_w_1_data(2,:);
z_1_w_1_p   = z_1_w_1_data(3,:);


% get crit_stable pole data, z = 1, w_0 = 1.5
z_1_w_1dot5 = load('z_1_w_1dot5.mat');
z_1_w_1dot5_data = z_1_w_1dot5.z_1_w_1dot5;

timestamp_2     = z_1_w_1dot5_data(1,:);
z_1_w_1dot5_p_c = z_1_w_1dot5_data(2,:);
z_1_w_1dot5_p   = z_1_w_1dot5_data(3,:);



figure(1);

%plot pitch rate
subplot(3,1,1);

plot(timestamp_1, z_1_w_1_p_c,'r');
hold on;
plot(timestamp_1, z_1_w_1_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles =  z = 1, w_0 = 1');

%plot pitch rate
subplot(3,1,2);

plot(timestamp_2, z_1_w_1dot5_p_c,'r');
hold on;
plot(timestamp_2, z_1_w_1dot5_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, z = 1, w_0 = 1.5');


%% Two real and distinct poles


%% Two real and distinct poles


