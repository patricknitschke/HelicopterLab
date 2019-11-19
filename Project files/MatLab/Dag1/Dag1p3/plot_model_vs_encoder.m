%% start at linearisation point

model_vs_encoder_linpoint = load('model_vs_encoder_manual_control_final');
model_vs_encoder_linpoint_vals = model_vs_encoder_linpoint.model_vs_encoder_manual_control;

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
for n = 1:length(encoder_e)
    encoder_e(n) = encoder_e(n) + 0.53;
end
encoder_edot = model_vs_encoder_linpoint_vals(11,:);
encoder_lambda = model_vs_encoder_linpoint_vals(12,:);
encoder_lambdadot = model_vs_encoder_linpoint_vals(13,:);

figure(1);
x_start = 2;
x_stop = 30;

%plot pitch rate
subplot(3,1,1);

plot(timestamp, encoder_p,'r');
hold on;
plot(timestamp, model_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([0, 25]);
title('Pitch comparison, Lin. Point');

%plot e
subplot(3,1,2);
plot(timestamp, encoder_e,'r');
hold on;
plot(timestamp, model_e,'b');
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([0, 25]);
title('Elevation comparison, Lin. Point');

%plot edot
subplot(3,1,3);
plot(timestamp, encoder_lambda,'r');
hold on;
plot(timestamp, model_lambda,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([0, 25]);
title('Travel comparison, Lin. Point');

%{
%plot elevation
subplot(3,2,2);

plot(timestamp, encoder_pdot, 'r');
hold on;
plot(timestamp, model_pdot, 'b');
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([2, 50]);
title('Pitch rate comparison, Lin. Point');
%plot lambda
subplot(3,2,3);



%plot pdot
subplot(3,2,4);
plot(timestamp, encoder_edot,'r');
hold on;
plot(timestamp, model_edot,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([2, 50]);
title('Elevation rate comparison, Lin. Point');


%plot lambdadot
subplot(3,2,6);
plot(timestamp, encoder_lambdadot,'r');
hold on;
plot(timestamp, model_lambdadot,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([2, 50]);
title('Travel rate comparison, Lin. Point');


%}


%% start on table

model_vs_encoder_table = load('fly_with_open_loop_model');
model_vs_encoder_table_vals = model_vs_encoder_table.fly_with_open_loop_model;

timestamp_t = model_vs_encoder_table_vals(1,:);
model_p_t = model_vs_encoder_table_vals(2,:);
model_e_t = model_vs_encoder_table_vals(3,:);
model_lambda_t = model_vs_encoder_table_vals(4,:);
encoder_p_t = model_vs_encoder_table_vals(5,:);
encoder_e_t = model_vs_encoder_table_vals(6,:);
encoder_lambda_t = model_vs_encoder_table_vals(7,:);
for n = 1:length(encoder_e_t)
    encoder_e_t(n) = encoder_e_t(n) + 0.53;
end

x_start = 0;
x_stop = 25;
figure(2);

%plot pitch rate
subplot(3,1,1);

plot(timestamp_t, encoder_p_t,'r');
hold on;
plot(timestamp_t, model_p_t,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
xlim([x_start, x_stop]);
title('Pitch comparison, Table');

%plot elevation
subplot(3,1,2);

plot(timestamp_t, encoder_e_t,'r');
hold on;
plot(timestamp_t, model_e_t,'b');
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([x_start, x_stop]);
title('Elevation comparison, Table');

%plot lambda
subplot(3,1,3);

plot(timestamp_t, encoder_lambda_t,'r');
hold on;
plot(timestamp_t, model_lambda_t,'b');
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
%l = legend('Encoder pitch','Model pitch');
xlim([x_start, x_stop]);
title('Travel comparison, Table');
