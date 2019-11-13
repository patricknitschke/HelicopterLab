%% Dag 4.3 - 4.5
init_heli_d4p2;
LQR_d4p2;
%% 4.3 Observability

A_3 = zeros(6,6);
C_3 = zeros(3,6);

A_3(1,2) = 1;
A_3(3,4) = 1;
A_3(5,6) = 1;
A_3(6,1) = K_3;

C_3(1,2) = 1;
C_3(2,4) = 1;
C_3(3,6) = 1;

O_3 = obsv(A_3,C_3);
rank_O3 = rank(O_3);

%subset

A_3s = zeros(4);
C_3s = zeros(3,4);

A_3s(1,2) = 1;
A_3s(4,1) = K_3;

C_3s(1,2) = 1;
C_3s(2,3) = 1;
C_3s(3,4) = 1;

O_3s = obsv(A_3s,C_3s);
rank_O3s = rank(O_3s);


%% 4.5 Obs part 2

A_5 = zeros(6,6);
C_5 = zeros(5,6);

A_5(1,2) = 1;
A_5(3,4) = 1;
A_5(5,6) = 1;
A_5(6,1) = K_3;

C_5(1,2) = 1;
C_5(2,4) = 1;
C_5(3,6) = 1;
C_5(4,1) = 1;
C_5(5,3) = 1;

O_5 = obsv(A_5,C_5);
rank_O5 = rank(O_5);


% 4.5 subset

A_5s = zeros(5,5);
C_5s = zeros(5,5);

A_5s(1,2) = 1;
A_5s(3,4) = 1;
A_5s(5,1) = K_3;

C_5s(1,2) = 1;
C_5s(2,4) = 1;
C_5s(3,5) = 1;
C_5s(4,1) = 1;
C_5s(5,3) = 1;

O_5s = obsv(A_5s,C_5s);
rank_O5s = rank(O_5s);


