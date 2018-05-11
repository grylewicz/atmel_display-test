################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
mini_test.lss \

FLASH_IMAGE += \
mini_test.hex \

EEPROM_IMAGE += \
mini_test.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: mini_test.elf secondary-outputs

# Tool invocations
mini_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mini_test.map -mmcu=attiny2313 -o "mini_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mini_test.lss: mini_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mini_test.elf  >"mini_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

mini_test.hex: mini_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex mini_test.elf  "mini_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

mini_test.eep: mini_test.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex mini_test.elf  "mini_test.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mini_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny2313 mini_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) mini_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
