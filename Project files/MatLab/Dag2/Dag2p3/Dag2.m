%% Task 2 - Pole placement

init_heli_d2p3;

%{
% Choose your poles, just +i to make imaginary
lambda_1 = -2; 
lambda_2 = -2;

K_pp = lambda_1*lambda_2/K_1;
K_pd = -(lambda_1+lambda_2)/K_1;
%}

%% Task 3 - Harmonic oscillator

zeta = 0.5;
w_0 = 1.5; 

K_pp = (w_0^2)/K_1;
K_pd = (2*zeta*w_0)/K_1;
