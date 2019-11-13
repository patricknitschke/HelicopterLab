%% start at linearisation point

model_vs_encoder_linpoint = load('model_vs_encoder_linpoint');
model_vs_encoder_linpoint_vals = model_vs_encoder_linpoint.model_vs_encoder;

timestamp = model_vs_encoder_linpoint_vals(1,:);
model_p = model_vs_encoder_linpoint_vals(2,:);
model_e = model_vs_encoder_linpoint_vals(3,:);
model_lambda = model_vs_encoder_linpoint_vals(4,:);
encoder_p = model_vs_encoder_linpoint_vals(5,:);
encoder_e = model_vs_encoder_linpoint_vals(6,:);
encoder_lambda = model_vs_encoder_linpoint_vals(7,:);

figure(1);
x_start = 0;
x_stop = 120;

%plot pitch rate
subplot(3,1,1);

plot(timestamp, encoder_p,'r');
hold on;
plot(timestamp, model_p,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Lin. Point');

%plot elevation
subplot(3,1,2);

plot(timestamp, encoder_e,'r');
hold on;
plot(timestamp, model_e,'b');
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Elevation comparison, Lin. Point');

%plot lambda
subplot(3,1,3);

plot(timestamp, encoder_lambda,'r');
hold on;
plot(timestamp, model_lambda,'b');
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Travel comparison, Lin. Point');

%% start on table

model_vs_encoder_table = load('model_vs_encoder_table');
model_vs_encoder_table_vals = model_vs_encoder_table.model_vs_encoder;

timestamp_t = model_vs_encoder_table_vals(1,:);
model_p_t = model_vs_encoder_table_vals(2,:);
model_e_t = model_vs_encoder_table_vals(3,:);
model_lambda_t = model_vs_encoder_table_vals(4,:);
encoder_p_t = model_vs_encoder_table_vals(5,:);
encoder_e_t = model_vs_encoder_table_vals(6,:);
encoder_lambda_t = model_vs_encoder_table_vals(7,:);

figure(2);
x_start = 0;
x_stop = 120;

%plot pitch rate
subplot(3,1,1);

plot(timestamp_t, encoder_p_t,'r');
hold on;
plot(timestamp_t, model_p_t,'b');
grid on;
xlabel('Time [s]');
ylabel('Pitch [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Pitch comparison, Table');

%plot elevation
subplot(3,1,2);

plot(timestamp, encoder_e,'r');
hold on;
plot(timestamp, model_e,'b');
grid on;
xlabel('Time [s]');
ylabel('Elevation [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Elevation comparison, Table');

%plot lambda
subplot(3,1,3);

plot(timestamp, encoder_lambda,'r');
hold on;
plot(timestamp, model_lambda,'b');
grid on;
xlabel('Time [s]');
ylabel('Travel [rad]');
l = legend('Encoder pitch','Model pitch');
%xlim([x_start, x_stop]);
title('Travel comparison, Table');
