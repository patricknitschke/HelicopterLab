%% PLOTTING Q_p
F_11_p = load('F_11_p.mat');
F_11_p = F_11_p.F_11_p;

F_22_p = load('F_22_p.mat');
F_22_p = F_22_p.F_22_p;

Q_7050_p = load('Q_7050_p.mat');
Q_7050_p = Q_7050_p.Q_7050_p;

figure(1);
subplot(3,1,1);
plot(Q_7050_p(1,:), Q_7050_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_7050_p(1,:), Q_7050_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('F matrix as [0 1; 1 0]');

subplot(3,1,3);
plot(F_22_p(1,:), F_22_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(F_22_p(1,:), F_22_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Doubling elements in F matrix');

subplot(3,1,2);
plot(F_11_p(1,:), F_11_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(F_11_p(1,:), F_11_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('F matrix as in Task 3.2');