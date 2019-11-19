%% Fly with kalman

model_vs_encoder_linpoint = load('fly_with_kalman_feedback_final.mat');
model_vs_encoder_linpoint_vals = model_vs_encoder_linpoint.fly_with_kalman_feedback;

timestamp = model_vs_encoder_linpoint_vals(1,:);
model_p = model_vs_encoder_linpoint_vals(2,:);
model_pdot = model_vs_encoder_linpoint_vals(3,:);
model_e = model_vs_encoder_linpoint_vals(4,:);
model_edot = model_vs_encoder_linpoint_vals(5,:);
model_lambda = model_vs_encoder_linpoint_vals(6,:);
model_lambdadot = model_vs_encoder_linpoint_vals(7,:);
encoder_p = model_vs_encoder_linpoint_vals(8,:);
encoder_pdot = model_vs_encoder_linpoint_vals(9,:);
encoder_e = model_vs_encoder_linpoint_vals(10,:);
for n = 1:length(model_e)
    model_e(n) = model_e(n) + 0.53;
end
encoder_edot = model_vs_encoder_linpoint_vals(11,:);
encoder_lambda = model_vs_encoder_linpoint_vals(12,:);
encoder_lambdadot = model_vs_encoder_linpoint_vals(13,:);

figure(1);
xstart = 2;
xstop = 40;

%plot pitch rate
subplot(3,2,1);

plot(timestamp, encoder_p,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_p,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Pitch comparison, Open-loop feedback');


%plot pdot
subplot(3,2,2);

plot(timestamp, encoder_pdot, 'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_pdot, 'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Pitch rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Pitch rate comparison, Open-loop feedback');
%plot lambda

%plot e
subplot(3,2, 3);
plot(timestamp, encoder_e,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_e,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Elevation comparison, Open-loop feedback');

%plot edot
subplot(3,2,4);
plot(timestamp, encoder_edot,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_edot,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Elevation rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Elevation rate comparison, Open-loop feedback');

%plot lambda
subplot(3,2,5);
plot(timestamp, encoder_lambda,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_lambda,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Travel comparison, Open-loop feedback');


%plot lambdadot
subplot(3,2,6);
plot(timestamp, encoder_lambdadot,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_lambdadot,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Travel rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Travel rate comparison, Open-loop feedback');




%% Encoder versus kalman values

model_vs_encoder_linpoint = load('encoder_vs_kalman_final2.mat');
model_vs_encoder_linpoint_vals = model_vs_encoder_linpoint.encoder_vs_kalman;

timestamp = model_vs_encoder_linpoint_vals(1,:);
model_p = model_vs_encoder_linpoint_vals(2,:);
model_pdot = model_vs_encoder_linpoint_vals(3,:);
model_e = model_vs_encoder_linpoint_vals(4,:);
model_edot = model_vs_encoder_linpoint_vals(5,:);
model_lambda = model_vs_encoder_linpoint_vals(6,:);
model_lambdadot = model_vs_encoder_linpoint_vals(7,:);
encoder_p = model_vs_encoder_linpoint_vals(8,:);
encoder_pdot = model_vs_encoder_linpoint_vals(9,:);
encoder_e = model_vs_encoder_linpoint_vals(10,:);
for n = 1:length(model_e)
    model_e(n) = model_e(n) + 0.53;
end
encoder_edot = model_vs_encoder_linpoint_vals(11,:);
encoder_lambda = model_vs_encoder_linpoint_vals(12,:);
encoder_lambdadot = model_vs_encoder_linpoint_vals(13,:);

figure(3);
xstart = 0;
xstop = 25;

%plot pitch rate
subplot(3,2,1);

plot(timestamp, encoder_p,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_p,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Pitch comparison, Lin. Point');


%plot pdot
subplot(3,2,2);

plot(timestamp, encoder_pdot, 'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_pdot, 'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Pitch rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Pitch rate comparison, Lin. Point');
%plot lambda

%plot e
subplot(3,2, 3);
plot(timestamp, encoder_e,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_e,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Elevation comparison, Lin. Point');

%plot edot
subplot(3,2,4);
plot(timestamp, encoder_edot,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_edot,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Elevation rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Elevation rate comparison, Lin. Point');

%plot lambda
subplot(3,2,5);
plot(timestamp, encoder_lambda,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_lambda,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Travel comparison, Lin. Point');


%plot lambdadot
subplot(3,2,6);
plot(timestamp, encoder_lambdadot,'r','LineWidth', 1.3);
hold on;
plot(timestamp, model_lambdadot,'b','LineWidth', 1.3);
grid on;
xlabel('Time [s]');
ylabel('Travel rate [rad/s]');
%l = legend('Encoder pitch','Model pitch');
xlim([xstart, xstop]);
title('Travel rate comparison, Lin. Point');



