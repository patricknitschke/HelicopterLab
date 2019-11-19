%% PLOTTING Q_p
R_11_p = load('Q_40612_p.mat');
R_11_p = R_11_p.Q_40612_p;

R_1001_p = load('R_1001_p.mat');
R_1001_p = R_1001_p.R_1001_p;

R_1100_p = load('R_1100_p.mat');
R_1100_p = R_1100_p.R_1100_p;

R_dot1dot1_p = load('R_dot1dot1_p.mat');
R_dot1dot1_p = R_dot1dot1_p.R_dot1dot1_p;

R_dot011_p = load('R_dot011_p.mat');
R_dot011_p = R_dot011_p.R_dot011_p;

R_1dot01_p = load('R_1dot01_p.mat');
R_1dot01_p = R_1dot01_p.R_1dot01_p;

figure(1);
subplot(3,1,1);
plot(R_11_p(1,:), R_11_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_11_p(1,:), R_11_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 12.5]);
title('Pitch with R diagonal as [1 1]');

subplot(3,1,2);
plot(R_1dot01_p(1,:), R_1dot01_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_1dot01_p(1,:), R_1dot01_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 12.5]);
title('Pitch with R diagonal as [1 0.01]');

subplot(3,1,3);
plot(R_1100_p(1,:), R_1100_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_1100_p(1,:), R_1100_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 12.5]);
title('Pitch with R diagonal as [1 100]');

%% Q_p plots together
R_1001_e = load('R_1001_e.mat');
R_1001_e = R_1001_e.R_1001_e;

R_dot011_e = load('R_dot011_e.mat');
R_dot011_e = R_dot011_e.R_dot011_e;

figure(2);
subplot(2,1,1);
plot(R_1001_e(1,:), R_1001_e(4,:), 'r');
hold on;
grid on;
plot(R_1001_e(1,:), R_1001_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevation rate [rad/s]');
xlim([0 9])
title('Elevation rate with R as [100 1]');

subplot(2,1,2);
plot(R_dot011_e(1,:), R_dot011_e(4,:), 'r');
hold on;
grid on;
plot(R_dot011_e(1,:), R_dot011_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevation rate [rad/s]');
xlim([0 9])
title('Elevation rate with R as [0.01 1]');

%% PLOT FINAL Rs

R_dot1dot1_p = load('R_dot1dot1_p.mat');
R_dot1dot1_p = R_dot1dot1_p.R_dot1dot1_p;

R_dot1dot5_p = load('R_dot1dot5_p.mat');
R_dot1dot5_p = R_dot1dot5_p.R_dot1dot5_p;

R_dot8dot5_p = load('R_dot8dot5_p.mat');
R_dot8dot5_p = R_dot8dot5_p.R_dot8dot5_p;

figure(3);
subplot(2,1,1);
plot(R_dot1dot1_p(1,:), R_dot1dot1_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_dot1dot1_p(1,:), R_dot1dot1_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 10]);
title('Pitch with R diagonal as [0.1 0.1]');


subplot(2,1,2);
plot(R_dot8dot5_p(1,:), R_dot8dot5_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_dot8dot5_p(1,:), R_dot8dot5_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 10]);
title('Pitch with R diagonal as [0.5 0.8]');

