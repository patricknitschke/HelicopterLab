%% PLOTTING Q_p
Q_11_p = load('Q_11_p.mat');
Q_11_p = Q_11_p.Q_11_p;

Q_1001_p = load('Q_1001_p.mat');
Q_1001_p = Q_1001_p.Q_1001_p;

figure(1);
subplot(2,1,1);
plot(Q_11_p(1,:), Q_11_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_11_p(1,:), Q_11_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Pitch with Q diagonal as [40 6 12 1 1]');

subplot(2,1,2);
plot(Q_1001_p(1,:), Q_1001_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_1001_p(1,:), Q_1001_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Pitch with Q diagonal as [40 6 12 100 1]');


%% Q_p plots together
Q_11_e = load('Q_11_e.mat');
Q_11_e = Q_11_e.Q_11_e;

Q_150_e = load('Q_150_e.mat');
Q_150_e = Q_150_e.Q_150_e;

Q_1100_e = load('Q_1100_e.mat');
Q_1100_e = Q_1100_e.Q_1100_e;

figure(2);
subplot(3,1,1);
plot(Q_11_e(1,:), Q_11_e(4,:), 'r');
hold on;
grid on;
plot(Q_11_e(1,:), Q_11_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevaton rate [rad/s]');
xlim([4 10])
title('Elevation rate with Q as [40 6 12 1 1]');

subplot(3,1,2);
plot(Q_150_e(1,:), Q_150_e(4,:), 'r');
hold on;
grid on;
plot(Q_150_e(1,:), Q_150_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevaton rate [rad/s]');
xlim([4 10])
title('Elevation rate with Q as [40 6 12 1 50]');

subplot(3,1,3);
plot(Q_1100_e(1,:), Q_1100_e(4,:), 'r');
hold on;
grid on;
plot(Q_1100_e(1,:), Q_1100_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevaton rate [rad/s]');
xlim([4 10])
title('Elevation rate with Q as [40 6 12 1 100]');

%% PLOT FINAL Qs
Q_7050_p = load('Q_7050_p.mat');
Q_7050_p = Q_7050_p.Q_7050_p;


figure(3);
plot(Q_7050_p(1,:), Q_7050_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_7050_p(1,:), Q_7050_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 18])
title('Pitch with Q as [40 6 12 70 50]');


