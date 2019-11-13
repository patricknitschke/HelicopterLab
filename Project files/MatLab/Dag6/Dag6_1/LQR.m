
%QUESTION 2

% State space model
A_LQR = zeros(3,3);
B_LQR = zeros(3,2);

A_LQR(1,2) = 1;
B_LQR(2,2) = K_1;
B_LQR(3,1) = K_2;

C = zeros(2,3);
C(1,1) = 1;
C(2,3) = 1;

% LQR regulator
q_p = 15;
q_pdot = 12;
q_edot = 12;
r_p = 7;
r_edot = 10;

Q = diag([q_p q_pdot q_edot]);
R = diag([r_p r_edot]);
K_x = lqr(A_LQR, B_LQR, Q, R);

%Reference feed-forward
%F = zeros(2,2);
%F(2,1) = K(2,1);
%F(1,2) = K(1,3);
F = inv(C*inv(B_LQR*K_x-A_LQR)*B_LQR);



%{
QUESTION 3
%}
% State space model
A_LQR = zeros(5,5);
B_LQR = zeros(5,2);

A_LQR(1,2) = 1;
A_LQR(4,1) = 1;
A_LQR(5,3) = 1;
B_LQR(2,2) = K_1;
B_LQR(3,1) = K_2;

C = zeros(2,5);
C(1,1) = 1;
C(2,3) = 1;


% LQR regulator
q_gamma = 10;
q_zeta = 10;

Q = diag([q_p q_pdot q_edot q_gamma q_zeta]);
R = diag([r_p r_edot]);
K_x = lqr(A_LQR, B_LQR, Q, R);

%Reference feed-forward
%F = inv(C*inv(B*K-A)*B);
F = [0 1; 1 0];

%Reference for integral effect
R_r = zeros(5, 2);
R_r(4,1) = -1;
R_r(5,2) = -1;

LOOK = C*inv(B_LQR*K_x-A_LQR)*R_r; % = I
LOOK_2 = C*inv(B_LQR*K_x-A_LQR)*B_LQR; % = 0 coeff. for F


 