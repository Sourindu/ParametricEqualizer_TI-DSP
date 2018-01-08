################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1

ORDERED_OBJS += \
"./oled.obj" \
"./pushbuttons.obj" \
"./sar.obj" \
"./usbstk5505.obj" \
"./usbstk5505_gpio.obj" \
"./usbstk5505_i2c.obj" \
"./usbstk5505_led.obj" \
"./src/asmIIR.obj" \
"./src/parametricEQ.obj" \
"./src/realtime_parametricTest.obj" \
"./src/vector.obj" \
"../c5505.cmd" \
"../lib/myC55xUtil.lib" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include lib/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include lib/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
realtime_parametricEQ.out \

EXE_OUTPUTS__QUOTED += \
"realtime_parametricEQ.out" \


# All Target
all: realtime_parametricEQ.out

# Tool invocations
realtime_parametricEQ.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic -z -m"realtime_parametricEQ.map" --stack_size=1000 --warn_sections -i"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/include" -i"C:/ti/bios_5_42_01_09/packages/ti/rtdx/lib/c5500" -i"C:/ti/bios_5_42_01_09/packages/ti/bios/lib" -i"C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/realtime_parametricEQ" --reread_libs --xml_link_info="realtime_parametricEQ_linkInfo.xml" --entry_point=reset_isr --rom_model --sys_stacksize=1000 -o "realtime_parametricEQ.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_HDRS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RM) "oled.pp" "pushbuttons.pp" "sar.pp" "usbstk5505.pp" "usbstk5505_gpio.pp" "usbstk5505_i2c.pp" "usbstk5505_led.pp" "src\parametricEQ.pp" "src\realtime_parametricTest.pp" 
	-$(RM) "oled.obj" "pushbuttons.obj" "sar.obj" "usbstk5505.obj" "usbstk5505_gpio.obj" "usbstk5505_i2c.obj" "usbstk5505_led.obj" "src\asmIIR.obj" "src\parametricEQ.obj" "src\realtime_parametricTest.obj" "src\vector.obj" 
	-$(RM) "src\asmIIR.pp" "src\vector.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

