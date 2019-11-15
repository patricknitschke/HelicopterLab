%% QUESTION 2
init_heli_d3p2;

% State space model
A = zeros(3,3);
B = zeros(3,2);

A(1,2) = 1;

B(2,2) = K_1;
B(3,1) = K_2;

C = zeros(2,3);
C(1,1) = 1;
C(2,3) = 1;

% LQR regulator implementation
q_p = 1;
q_pdot = 1;
q_edot = 1;

r_p = 1;
r_edot = 1;

Q = diag([q_p q_pdot q_edot]);
R = diag([r_p r_edot]);

K = lqr(A, B, Q, R);
F = inv(C*inv(B*K-A)*B);

%Reference feed-forward

%F = zeros(2,2); 
%F(2,1) = K(2,1);
%F(1,2) = K(1,3); %Based on system of equations, see notes.



 