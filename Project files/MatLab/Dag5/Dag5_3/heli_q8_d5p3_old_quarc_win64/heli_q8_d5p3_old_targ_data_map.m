  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_d5p3_old_P)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.A_d
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.B_d
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% heli_q8_d5p3_old_P.F
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 48;
	
	  ;% heli_q8_d5p3_old_P.Joystick_gain_x
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 52;
	
	  ;% heli_q8_d5p3_old_P.Joystick_gain_y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 53;
	
	  ;% heli_q8_d5p3_old_P.K
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 54;
	
	  ;% heli_q8_d5p3_old_P.Q_d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 64;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_input_maxi
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 100;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_input_mini
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 101;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_output_max
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 102;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_output_min
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 103;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_final_analog_outp
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 104;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_final_pwm_outputs
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 105;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_initial_analog_ou
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 106;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_initial_pwm_outpu
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 107;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_frequency
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 108;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_leading_deadb
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 109;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_trailing_dead
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 110;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_other_outputs
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 111;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_other_outpu_m
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 112;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_other_outpu_k
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 113;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_other_outpu_j
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 114;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_watchdog_analog_o
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 115;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_watchdog_pwm_outp
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 116;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_d5p3_old_P.HILReadEncoderTimebase_channels
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_d5p3_old_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_encoder_channels
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 21;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_pwm_channels
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 29;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_quadrature
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 37;
	
	  ;% heli_q8_d5p3_old_P.HILReadEncoderTimebase_samples_
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_inpu_m
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_b
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_e
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_j
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_c
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_out_ex
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_analog_outp_p
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_clock_frequ_e
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_clock_param_c
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_out_b
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_out_c
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_ou_c1
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_out_a
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 61;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_digital_out_m
	  section.data(23).logicalSrcIdx = 62;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 63;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_encoder_cou_k
	  section.data(25).logicalSrcIdx = 64;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 65;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_encoder_par_m
	  section.data(27).logicalSrcIdx = 66;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_other_outpu_l
	  section.data(28).logicalSrcIdx = 67;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 68;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_g
	  section.data(30).logicalSrcIdx = 69;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_p
	  section.data(31).logicalSrcIdx = 70;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_output_ap
	  section.data(32).logicalSrcIdx = 71;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 72;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 73;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_d5p3_old_P.HILInitialize_set_pwm_params__f
	  section.data(35).logicalSrcIdx = 74;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.UnitDelay1_InitialCondition
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_d5p3_old_P.RateTransitionx_X0
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 7;
	
	  ;% heli_q8_d5p3_old_P.DeadZonex_Start
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 8;
	
	  ;% heli_q8_d5p3_old_P.DeadZonex_End
	  section.data(5).logicalSrcIdx = 79;
	  section.data(5).dtTransOffset = 9;
	
	  ;% heli_q8_d5p3_old_P.Gainx_Gain
	  section.data(6).logicalSrcIdx = 80;
	  section.data(6).dtTransOffset = 10;
	
	  ;% heli_q8_d5p3_old_P.RateTransitiony_X0
	  section.data(7).logicalSrcIdx = 81;
	  section.data(7).dtTransOffset = 11;
	
	  ;% heli_q8_d5p3_old_P.DeadZoney_Start
	  section.data(8).logicalSrcIdx = 82;
	  section.data(8).dtTransOffset = 12;
	
	  ;% heli_q8_d5p3_old_P.DeadZoney_End
	  section.data(9).logicalSrcIdx = 83;
	  section.data(9).dtTransOffset = 13;
	
	  ;% heli_q8_d5p3_old_P.Gainy_Gain
	  section.data(10).logicalSrcIdx = 84;
	  section.data(10).dtTransOffset = 14;
	
	  ;% heli_q8_d5p3_old_P.Constant2_Value_b
	  section.data(11).logicalSrcIdx = 85;
	  section.data(11).dtTransOffset = 15;
	
	  ;% heli_q8_d5p3_old_P.PitchCounttorad_Gain
	  section.data(12).logicalSrcIdx = 86;
	  section.data(12).dtTransOffset = 16;
	
	  ;% heli_q8_d5p3_old_P.PitchTransferFcn_A
	  section.data(13).logicalSrcIdx = 87;
	  section.data(13).dtTransOffset = 17;
	
	  ;% heli_q8_d5p3_old_P.PitchTransferFcn_C
	  section.data(14).logicalSrcIdx = 88;
	  section.data(14).dtTransOffset = 18;
	
	  ;% heli_q8_d5p3_old_P.PitchTransferFcn_D
	  section.data(15).logicalSrcIdx = 89;
	  section.data(15).dtTransOffset = 19;
	
	  ;% heli_q8_d5p3_old_P.Constant1_Value
	  section.data(16).logicalSrcIdx = 90;
	  section.data(16).dtTransOffset = 20;
	
	  ;% heli_q8_d5p3_old_P.ElevationCounttorad_Gain
	  section.data(17).logicalSrcIdx = 91;
	  section.data(17).dtTransOffset = 21;
	
	  ;% heli_q8_d5p3_old_P.ElevationTransferFcn_A
	  section.data(18).logicalSrcIdx = 92;
	  section.data(18).dtTransOffset = 22;
	
	  ;% heli_q8_d5p3_old_P.ElevationTransferFcn_C
	  section.data(19).logicalSrcIdx = 93;
	  section.data(19).dtTransOffset = 23;
	
	  ;% heli_q8_d5p3_old_P.ElevationTransferFcn_D
	  section.data(20).logicalSrcIdx = 94;
	  section.data(20).dtTransOffset = 24;
	
	  ;% heli_q8_d5p3_old_P.Integrategammazeta_IC
	  section.data(21).logicalSrcIdx = 95;
	  section.data(21).dtTransOffset = 25;
	
	  ;% heli_q8_d5p3_old_P.UnitDelay2_InitialCondition
	  section.data(22).logicalSrcIdx = 96;
	  section.data(22).dtTransOffset = 26;
	
	  ;% heli_q8_d5p3_old_P.TravelCounttorad_Gain
	  section.data(23).logicalSrcIdx = 97;
	  section.data(23).dtTransOffset = 62;
	
	  ;% heli_q8_d5p3_old_P.TravelTransferFcn_A
	  section.data(24).logicalSrcIdx = 98;
	  section.data(24).dtTransOffset = 63;
	
	  ;% heli_q8_d5p3_old_P.TravelTransferFcn_C
	  section.data(25).logicalSrcIdx = 99;
	  section.data(25).dtTransOffset = 64;
	
	  ;% heli_q8_d5p3_old_P.TravelTransferFcn_D
	  section.data(26).logicalSrcIdx = 100;
	  section.data(26).dtTransOffset = 65;
	
	  ;% heli_q8_d5p3_old_P.Constant_Value
	  section.data(27).logicalSrcIdx = 101;
	  section.data(27).dtTransOffset = 66;
	
	  ;% heli_q8_d5p3_old_P.Constant1_Value_f
	  section.data(28).logicalSrcIdx = 102;
	  section.data(28).dtTransOffset = 67;
	
	  ;% heli_q8_d5p3_old_P.Gain2_Gain
	  section.data(29).logicalSrcIdx = 103;
	  section.data(29).dtTransOffset = 68;
	
	  ;% heli_q8_d5p3_old_P.Gain1_Gain
	  section.data(30).logicalSrcIdx = 104;
	  section.data(30).dtTransOffset = 77;
	
	  ;% heli_q8_d5p3_old_P.V_s0_Value
	  section.data(31).logicalSrcIdx = 105;
	  section.data(31).dtTransOffset = 86;
	
	  ;% heli_q8_d5p3_old_P.Backgain_Gain
	  section.data(32).logicalSrcIdx = 106;
	  section.data(32).dtTransOffset = 88;
	
	  ;% heli_q8_d5p3_old_P.Frontgain_Gain
	  section.data(33).logicalSrcIdx = 107;
	  section.data(33).dtTransOffset = 89;
	
	  ;% heli_q8_d5p3_old_P.FrontmotorSaturation_UpperSat
	  section.data(34).logicalSrcIdx = 108;
	  section.data(34).dtTransOffset = 90;
	
	  ;% heli_q8_d5p3_old_P.FrontmotorSaturation_LowerSat
	  section.data(35).logicalSrcIdx = 109;
	  section.data(35).dtTransOffset = 91;
	
	  ;% heli_q8_d5p3_old_P.BackmotorSaturation_UpperSat
	  section.data(36).logicalSrcIdx = 110;
	  section.data(36).dtTransOffset = 92;
	
	  ;% heli_q8_d5p3_old_P.BackmotorSaturation_LowerSat
	  section.data(37).logicalSrcIdx = 111;
	  section.data(37).dtTransOffset = 93;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.StreamCall1_SendBufferSize
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.StreamCall1_ReceiveBufferSize
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.StreamFormattedWrite_MaxUnits
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.StringConstant_Value
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.StreamCall1_URI
	  section.data(2).logicalSrcIdx = 117;
	  section.data(2).dtTransOffset = 255;
	
	  ;% heli_q8_d5p3_old_P.StreamCall1_Endian
	  section.data(3).logicalSrcIdx = 118;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_q8_d5p3_old_P.GameController_ControllerNumber
	  section.data(4).logicalSrcIdx = 119;
	  section.data(4).dtTransOffset = 257;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_P.StreamCall1_Active
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_d5p3_old_P.HILWriteAnalog_Active
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_d5p3_old_P.GameController_AutoCenter
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_d5p3_old_P.GameController_Enabled
	  section.data(5).logicalSrcIdx = 124;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_d5p3_old_B)
    ;%
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_B.UnitDelay1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_B.A_d
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% heli_q8_d5p3_old_B.B_d
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 42;
	
	  ;% heli_q8_d5p3_old_B.Q_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 54;
	
	  ;% heli_q8_d5p3_old_B.RateTransitionx
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 90;
	
	  ;% heli_q8_d5p3_old_B.Joystick_gain_x
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 91;
	
	  ;% heli_q8_d5p3_old_B.RateTransitiony
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 92;
	
	  ;% heli_q8_d5p3_old_B.Joystick_gain_y
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 93;
	
	  ;% heli_q8_d5p3_old_B.Fr
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 94;
	
	  ;% heli_q8_d5p3_old_B.Sum1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 96;
	
	  ;% heli_q8_d5p3_old_B.PitchTransferFcn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 97;
	
	  ;% heli_q8_d5p3_old_B.Sum2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 98;
	
	  ;% heli_q8_d5p3_old_B.ElevationTransferFcn
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 99;
	
	  ;% heli_q8_d5p3_old_B.UnitDelay2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 100;
	
	  ;% heli_q8_d5p3_old_B.TravelCounttorad
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 136;
	
	  ;% heli_q8_d5p3_old_B.TravelTransferFcn
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 137;
	
	  ;% heli_q8_d5p3_old_B.Gain2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 138;
	
	  ;% heli_q8_d5p3_old_B.TrigonometricFunction1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 141;
	
	  ;% heli_q8_d5p3_old_B.TrigonometricFunction
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 142;
	
	  ;% heli_q8_d5p3_old_B.V_s0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 143;
	
	  ;% heli_q8_d5p3_old_B.Sum1_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 145;
	
	  ;% heli_q8_d5p3_old_B.FrontmotorSaturation
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 147;
	
	  ;% heli_q8_d5p3_old_B.BackmotorSaturation
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 148;
	
	  ;% heli_q8_d5p3_old_B.GameController_o4
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 149;
	
	  ;% heli_q8_d5p3_old_B.GameController_o5
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 150;
	
	  ;% heli_q8_d5p3_old_B.Sum3
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 151;
	
	  ;% heli_q8_d5p3_old_B.x_k2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 153;
	
	  ;% heli_q8_d5p3_old_B.P_k2
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 159;
	
	  ;% heli_q8_d5p3_old_B.euler_rates
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 195;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_d5p3_old_DW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_DW.UnitDelay2_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 42;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 50;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 58;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 66;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 74;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 82;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POSortedFreqs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 90;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POValues
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 98;
	
	  ;% heli_q8_d5p3_old_DW.RateTransitionx_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 106;
	
	  ;% heli_q8_d5p3_old_DW.RateTransitiony_Buffer0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 107;
	
	  ;% heli_q8_d5p3_old_DW.HILWriteAnalog_Buffer
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 108;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.P_scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_DW.e_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 2;
	
	  ;% heli_q8_d5p3_old_DW.edot_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_d5p3_old_DW.lambda_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 6;
	
	  ;% heli_q8_d5p3_old_DW.lambdadot_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 8;
	
	  ;% heli_q8_d5p3_old_DW.p_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 10;
	
	  ;% heli_q8_d5p3_old_DW.pdot_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 12;
	
	  ;% heli_q8_d5p3_old_DW.e_PWORK_n.LoggedData
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 14;
	
	  ;% heli_q8_d5p3_old_DW.edot_PWORK_f.LoggedData
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 16;
	
	  ;% heli_q8_d5p3_old_DW.lambdadot_PWORK_o.LoggedData
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 18;
	
	  ;% heli_q8_d5p3_old_DW.p_PWORK_g.LoggedData
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 20;
	
	  ;% heli_q8_d5p3_old_DW.pdot_PWORK_i.LoggedData
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 22;
	
	  ;% heli_q8_d5p3_old_DW.noisetofile_PWORK.FilePtr
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 24;
	
	  ;% heli_q8_d5p3_old_DW.Vs_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 25;
	
	  ;% heli_q8_d5p3_old_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 26;
	
	  ;% heli_q8_d5p3_old_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 27;
	
	  ;% heli_q8_d5p3_old_DW.PitchScoperad_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 28;
	
	  ;% heli_q8_d5p3_old_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 29;
	
	  ;% heli_q8_d5p3_old_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 30;
	
	  ;% heli_q8_d5p3_old_DW.TravelScoperad_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 31;
	
	  ;% heli_q8_d5p3_old_DW.HILWriteAnalog_PWORK
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 32;
	
	  ;% heli_q8_d5p3_old_DW.Connected_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 33;
	
	  ;% heli_q8_d5p3_old_DW.x_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 39;
	  section.data(23).dtTransOffset = 34;
	
	  ;% heli_q8_d5p3_old_DW.y_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 40;
	  section.data(24).dtTransOffset = 35;
	
	  ;% heli_q8_d5p3_old_DW.z_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 41;
	  section.data(25).dtTransOffset = 36;
	
	  ;% heli_q8_d5p3_old_DW.XScope_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 42;
	  section.data(26).dtTransOffset = 37;
	
	  ;% heli_q8_d5p3_old_DW.YScope_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 43;
	  section.data(27).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_d5p3_old_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.noisetofile_IWORK.Count
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_d5p3_old_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2849901800;
  targMap.checksum1 = 140512230;
  targMap.checksum2 = 3112153293;
  targMap.checksum3 = 2152022075;

