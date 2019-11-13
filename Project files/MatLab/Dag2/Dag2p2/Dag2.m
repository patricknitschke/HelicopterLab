%% Task 2 - Pole placement

init_heli_d2p2;

% Choose your poles, just +i to make imaginary
lambda_1 = -2 + 8i; 
lambda_2 = -2 - 8i;
K_pp = lambda_1*lambda_2/K_1;
K_pd = -(lambda_1+lambda_2)/K_1;