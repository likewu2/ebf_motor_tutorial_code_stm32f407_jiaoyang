set JAVA_HOME=D:\jdk11\bin\java.exe #error
"E:\app\STMicroelectronics\MC_SDK_5.Y.2\Utilities\PC_Software\STMCWB\WB_to_Mx\WB_to_Mx.exe" -ioc "E:\app\julia\ebf_motor_tutorial_code_stm32f407_jiaoyang\improve_part2\BLDC_FOC_V5.Y.2_Hall_speed_control\BLDC_control\BLDC_control.ioc" -xdm "E:\app\julia\ebf_motor_tutorial_code_stm32f407_jiaoyang\improve_part2\BLDC_FOC_V5.Y.2_Hall_speed_control\BLDC_control\BLDC_control.wb_def"
 -stm32fw 1.26.1 -cubemx 6.4.0 -toolchain "STM32CubeIDE" -driver HAL -Q

"D:\jdk11\bin\java.exe" -classpath "E:\app\STMicroelectronics\MC_SDK_5.Y.2\Utilities\PC_Software\STMCWB\WB_to_Mx\WB_to_Mx.jar" com.st.Main -ioc "E:\app\julia\ebf_motor_tutorial_code_stm32f407_jiaoyang\improve_part2\BLDC_FOC_V5.Y.2_Hall_speed_control\BLDC_control\BLDC_control.ioc" -xdm "E:\app\julia\ebf_motor_tutorial_code_stm32f407_jiaoyang\improve_part2\BLDC_FOC_V5.Y.2_Hall_speed_control\BLDC_control\BLDC_control.wb_def" -stm32fw 1.26.1 -cubemx 6.4.0 -toolchain "STM32CubeIDE" -driver HAL -Q
