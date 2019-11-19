Q_7050_p = load('Q_7050_p.mat');
Q_7050_p = Q_7050_p.Q_7050_p;

figure(1);
subplot(2,1,2);
plot(Q_7050_p(1,:), Q_7050_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_7050_p(1,:), Q_7050_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 13.3]);
title('With integral action');

R_dot8dot5_p = load('R_dot8dot5_p.mat');
R_dot8dot5_p = R_dot8dot5_p.R_dot8dot5_p;


subplot(2,1,1);
plot(R_dot8dot5_p(1,:), R_dot8dot5_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(R_dot8dot5_p(1,:), R_dot8dot5_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 13.3]);
title('No integral action');