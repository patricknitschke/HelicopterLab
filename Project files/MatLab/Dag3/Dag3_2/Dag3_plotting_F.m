F_22 = load('F_22.mat');
F_22 = F_22.F_22;

figure(1);
plot(F_22(1,:), F_22(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(F_22(1,:), F_22(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15])
title('Pitch response with doubled F matrix');