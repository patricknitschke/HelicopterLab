

%% For Q as 111111
P_error_cov = load('Q_11111.mat');
P_matrices = P_error_cov.P_error_cov.signals.values;
p_var  = P_matrices(1,1,:);
pdot_var  = P_matrices(2,2,:);
e_var  = P_matrices(3,3,:);
edot_var  = P_matrices(4,4,:);
l_var  = P_matrices(5,5,:);
ldot_var  = P_matrices(6,6,:);

P_length = length(P_matrices);
P_variances_Q1 = zeros(7, P_length);
for n = 1:P_length
    P_variances_Q1(1,n) = n;
    P_variances_Q1(2,n) = p_var(1,1,n);
    P_variances_Q1(3,n) = pdot_var(1,1,n);
    P_variances_Q1(4,n) = e_var(1,1,n);
    P_variances_Q1(5,n) = edot_var(1,1,n);
    P_variances_Q1(6,n) = l_var(1,1,n);
    P_variances_Q1(7,n) = ldot_var(1,1,n);
end
%% Q not as 1s
P_error_cov2 = load('Q_not1s.mat');
P_matrices = P_error_cov2.P_error_cov.signals.values;
p_var  = P_matrices(1,1,:);
pdot_var  = P_matrices(2,2,:);
e_var  = P_matrices(3,3,:);
edot_var  = P_matrices(4,4,:);
l_var  = P_matrices(5,5,:);
ldot_var  = P_matrices(6,6,:);

P_length = length(P_matrices);
P_variances_Q2 = zeros(7, P_length);
for n = 1:P_length
    P_variances_Q2(1,n) = n;
    P_variances_Q2(2,n) = p_var(1,1,n);
    P_variances_Q2(3,n) = pdot_var(1,1,n);
    P_variances_Q2(4,n) = e_var(1,1,n);
    P_variances_Q2(5,n) = edot_var(1,1,n);
    P_variances_Q2(6,n) = l_var(1,1,n);
    P_variances_Q2(7,n) = ldot_var(1,1,n);
end


%% Plot
figure(1);
subplot(3,2,1);

plot(P_variances_Q2(1,:), P_variances_Q2(2,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(2,:), 'b', 'LineWidth', 1.3);
title('Pitch covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');

subplot(3,2,2);

plot(P_variances_Q2(1,:), P_variances_Q2(3,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(3,:), 'b', 'LineWidth', 1.3);
title('Elevation covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');

subplot(3,2,3);

plot(P_variances_Q2(1,:), P_variances_Q2(4,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(4,:), 'b', 'LineWidth', 1.3);
title('Elevation covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');

subplot(3,2,4);

plot(P_variances_Q2(1,:), P_variances_Q2(5,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(5,:), 'b', 'LineWidth', 1.3);
title('Elev. rate covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');
subplot(3,2,5);

plot(P_variances_Q2(1,:), P_variances_Q2(6,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(6,:), 'b', 'LineWidth', 1.3);
title('Travel covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');
subplot(3,2,6);

plot(P_variances_Q2(1,:), P_variances_Q2(7,:), 'r', 'LineWidth', 1.3);
grid on;
hold on;
plot(P_variances_Q1(1,:), P_variances_Q1(7,:), 'b', 'LineWidth', 1.3);
title('Travel rate covariances with varying Q diag.');
xlabel('Interations');
ylabel('Variance [rad^2]');
