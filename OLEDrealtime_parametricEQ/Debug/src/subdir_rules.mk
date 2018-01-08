################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/asmIIR.obj: ../src/asmIIR.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/inc" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/asmIIR.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/parametricEQ.obj: ../src/parametricEQ.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/inc" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/parametricEQ.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/realtime_parametricTest.obj: ../src/realtime_parametricTest.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/inc" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/realtime_parametricTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/vector.obj: ../src/vector.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="G:/TheDevelopmentKitCodeComposerv6/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/inc" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --include_path="C:/Users/SOURINDU/OneDrive/CodeComp6Workspace/OLEDrealtime_parametricEQ/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/vector.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


