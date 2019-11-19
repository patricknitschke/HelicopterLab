%% PLOTTING Q_p
Q_111_p = load('Q_111_p.mat');
Q_111_p = Q_111_p.Q_111_p;

Q_10011_p = load('Q_10011_p.mat');
Q_10011_p = Q_10011_p.Q_10011_p;

Q_11001_p = load('Q_11001_p.mat');
Q_11001_p = Q_11001_p.Q_11001_p;

Q_40112_p = load('Q_40612_p.mat');
Q_40112_p = Q_40112_p.Q_40612_p;

Q_40612_p = load('Q_40612_p.mat');
Q_40612_p = Q_40612_p.Q_40612_p;

figure(1);
subplot(3,1,1);
plot(Q_111_p(1,:), Q_111_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_111_p(1,:), Q_111_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Pitch with Q diagonal as [1 1 1]');

subplot(3,1,2);
plot(Q_111_p(1,:), Q_111_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_10011_p(1,:), Q_10011_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Pitch with Q diagonal as [100 1 1]');

subplot(3,1,3);
plot(Q_111_p(1,:), Q_111_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_11001_p(1,:), Q_11001_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 15]);
title('Pitch with Q diagonal as [1 100 1]');

%% Q_p plots together
Q_111_e = load('Q_111_e.mat');
Q_111_e = Q_111_e.Q_111_e;

Q_11100_e = load('Q_11100_e.mat');
Q_11100_e = Q_11100_e.Q_11100_e;

figure(4);
subplot(2,1,1);
plot(Q_111_e(1,:), Q_111_e(4,:), 'r');
hold on;
grid on;
plot(Q_111_e(1,:), Q_111_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevaton rate [rad/s]');
xlim([0 10])
title('Elevation rate with Q as [1 1 100]');

subplot(2,1,2);
plot(Q_111_e(1,:), Q_111_e(4,:), 'r');
hold on;
grid on;
plot(Q_11100_e(1,:), Q_11100_e(5,:), 'b');
xlabel('Time [s]');
ylabel('Elevaton rate [rad/s]');
xlim([0 10])
title('Elevation rate with Q as [1 1 100]');

%% PLOT FINAL Qs
Q_40112_p = load('Q_40112_p.mat');
Q_40112_p = Q_40112_p.Q_40112_p;

Q_40612_p = load('Q_40612_p.mat');
Q_40612_p = Q_40612_p.Q_40612_p;


figure(3);
plot(Q_40112_p(1,:), Q_40112_p(2,:), 'r', 'LineWidth', 1.2);
hold on;
grid on;
plot(Q_40612_p(1,:), Q_40612_p(3,:), 'b', 'LineWidth', 1.2);
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([0 13])
title('Pitch with Q as [40 6 12]');


