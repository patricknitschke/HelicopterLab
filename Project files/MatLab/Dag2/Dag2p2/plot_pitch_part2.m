%% Task 2.2 - Pole placement 
Dag2;

%% CRITICALLY DAMPED DATA

% get crit_stable pole data, (-0.7,0)(-0.7,0)
lambda_dot70dot70 = load('lambda_dot70dot70.mat');
lambda_dot70dot70_data = lambda_dot70dot70.lambda_dot70dot70;

timestamp_1     = lambda_dot70dot70_data(1,:);
lambda_dot70dot70_p_c = lambda_dot70dot70_data(2,:);
lambda_dot70dot70_p   = lambda_dot70dot70_data(3,:);


% get crit_stable pole data, (-2,0)(-2,0)
lambda_2020 = load('lambda_2020.mat');
lambda_2020_data = lambda_2020.lambda_2020;

timestamp_2     = lambda_2020_data(1,:);
lambda_2020_p_c = lambda_2020_data(2,:);
lambda_2020_p   = lambda_2020_data(3,:);


% plot crit_stable pole data, (-4,0)(-4,0)
lambda_4040 = load('lambda_4040.mat');
lambda_4040_data = lambda_4040.lambda_4040;

timestamp_3     = lambda_4040_data(1,:);
lambda_4040_p_c = lambda_4040_data(2,:);
lambda_4040_p   = lambda_4040_data(3,:);


%% OVERDAMPED DATA

% (0.5,0)(-2,0)
lambda_dot5020 = load('lambda_dot5020.mat');
lambda_dot5020_data = lambda_dot5020.lambda_dot5020;

timestamp_4     = lambda_dot5020_data(1,:);
lambda_dot5020_data_p_c = lambda_dot5020_data(2,:);
lambda_dot5020_data_p   = lambda_dot5020_data(3,:);

% (-8,0)(-2,0)
lambda_8020 = load('lambda_8020.mat');
lambda_8020_data = lambda_8020.lambda_8020;

timestamp_5     = lambda_8020_data(1,:);
lambda_8020_data_p_c = lambda_8020_data(2,:);
lambda_8020_data_p   = lambda_8020_data(3,:);

%% UNDERDAMPED DATA
%(-2,1)(-2,-1)
lambda_2121 = load('lambda_2121.mat');
lambda_2121_data = lambda_2121.lambda_2121;

timestamp_6     = lambda_2121_data(1,:);
lambda_2121_data_p_c = lambda_2121_data(2,:);
lambda_2121_data_p   = lambda_2121_data(3,:);

%(-2,8)(-2,-8)
lambda_2828 = load('lambda_2828.mat');
lambda_2828_data = lambda_2828.lambda_2828;

timestamp_7     = lambda_2828_data(1,:);
lambda_2828_data_p_c = lambda_2828_data(2,:);
lambda_2828_data_p   = lambda_2828_data(3,:);


%% UNSTABLE DATA
%(0,1)(0,-1)
lambda_0101 = load('lambda_0101.mat');
lambda_0101_data = lambda_0101.lambda_0101;

timestamp_8     = lambda_0101_data(1,:);
lambda_0101_data_p_c = lambda_0101_data(2,:);
lambda_0101_data_p   = lambda_0101_data(3,:);


%% PLOT CRITICALLY DAMPED
figure(1);
%plot pitch
subplot(3,1,1);

plot(timestamp_1, lambda_dot70dot70_p_c,'r');
hold on;
plot(timestamp_1, lambda_dot70dot70_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([15, 25]);
title('Pitch comparison, Poles = -0.7, -0.7');

%plot pitch
subplot(3,1,2);

plot(timestamp_2, lambda_2020_p_c,'r');
hold on;
plot(timestamp_2, lambda_2020_p,'b');
grid on;
xlabel('Time [s]');
l = legend('Ref. pitch','Pitch');
xlim([9, 14]);
title('Pitch comparison, Poles = -2, -2');


%plot pitch
subplot(3,1,3);

plot(timestamp_3, lambda_4040_p_c,'r');
hold on;
plot(timestamp_3, lambda_4040_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([11, 18]);
title('Pitch comparison, Poles = -4, -4');

%% PLOT OVERDAMPED

figure(2);
subplot(2,1,1);

plot(timestamp_4, lambda_dot5020_data_p_c,'r');
hold on;
plot(timestamp_4, lambda_dot5020_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([10, 16]);
title('Pitch comparison, Poles = -0.5, -2');


subplot(2,1,2);

plot(timestamp_5, lambda_8020_data_p_c,'r');
hold on;
plot(timestamp_5, lambda_8020_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([11, 16]);
title('Pitch comparison, Poles = -8, -2');

%% PLOT UNDERDAMPED
figure(3);
%plot pitch rate
subplot(3,1,1);

plot(timestamp_6, lambda_2121_data_p_c,'r');
hold on;
plot(timestamp_6, lambda_2121_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
xlim([9.5, 12]);
title('Pitch comparison, Poles = -2 ± i');
%plot pitch rate
subplot(3,1,2);

plot(timestamp_7, lambda_2828_data_p_c,'r');
hold on;
plot(timestamp_7, lambda_2828_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = -2 ± 8i');

%% PLOT UNDERDAMPED
subplot(3,1,3);
plot(timestamp_8, lambda_0101_data_p_c,'r');
hold on;
plot(timestamp_8, lambda_0101_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = ±i');
