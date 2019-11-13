% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 4; 
Joystick_gain_y = 6;

%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitchS axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]


% V_s0    
V_s0 = 7;

% Motor constants
K_f = g*(2*l_h*m_p-l_c*m_c)/(V_s0*l_h);


%Helicopter moment of inertia
J_p = 2*m_p*l_p.^2;
J_e = m_c*l_c.^2 + 2*m_p*l_h.^2;
J_l = m_c*l_c.^2 + 2*m_p*(l_h.^2 + l_p.^2);

% Elevation and Pitch controller parameters
K_2 = K_f*l_h/J_e;    
K_1 = K_f*l_p/J_p;





