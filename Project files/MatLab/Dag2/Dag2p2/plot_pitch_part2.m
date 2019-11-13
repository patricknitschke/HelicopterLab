%% Task 2.2 - Pole placement 
Dag2;

%% Two identical poles

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


figure(1);

%plot pitch rate
subplot(3,1,1);

plot(timestamp_1, lambda_dot70dot70_p_c,'r');
hold on;
plot(timestamp_1, lambda_dot70dot70_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = (-0.7,0), (-0.7,0)');

%plot elevation
subplot(3,1,2);

plot(timestamp_2, lambda_2020_p_c,'r');
hold on;
plot(timestamp_2, lambda_2020_p,'b');
grid on;
xlabel('Time [s]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = (-2,0), (-2,0)');


%plot elevation
subplot(3,1,3);

plot(timestamp_3, lambda_4040_p_c,'r');
hold on;
plot(timestamp_3, lambda_4040_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = (-4,0), (-4,0)');

%% Two real and distinct poles

% get crit_stable pole data, (-8,0)(-2,0)
lambda_8020 = load('lambda_8020.mat');
lambda_8020_data = lambda_8020.lambda_8020;

timestamp_6     = lambda_8020_data(1,:);
lambda_8020_data_p_c = lambda_8020_data(2,:);
lambda_8020_data_p   = lambda_8020_data(3,:);




figure(2);

%plot pitch rate
subplot(2,1,2);

plot(timestamp_6, lambda_8020_data_p_c,'r');
hold on;
plot(timestamp_6, lambda_8020_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = (-8,0), (-2,0)');

%% Two complex conjugates

% get crit_stable pole data, (-8,0)(-2,0)
lambda_8020 = load('lambda_8020.mat');
lambda_8020_data = lambda_8020.lambda_8020;

timestamp_6     = lambda_8020_data(1,:);
lambda_8020_data_p_c = lambda_8020_data(2,:);
lambda_8020_data_p   = lambda_8020_data(3,:);



figure(3);

%plot pitch rate
subplot(2,1,2);

plot(timestamp_6, lambda_8020_data_p_c,'r');
hold on;
plot(timestamp_6, lambda_8020_data_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Ref. pitch','Pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Poles = (-8,0), (-2,0)');

