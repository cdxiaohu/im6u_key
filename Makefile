CROSS_COMPILE 	?= arm-linux-gnueabihf-
TARGET		  	?= key

CC 				:= $(CROSS_COMPILE)gcc
LD 				:= $(CROSS_COMPILE)ld
OBJCOPY			:= $(CROSS_COMPILE)objcopy
OBJDUMP			:= $(CROSS_COMPILE)objdump

INCDIRS			:= 	imx6u \
					bsp/clk \
					bsp/delay \
					bsp/led \
					project \
					bsp/beep \
					bsp/key	\
					bsp/gpio

SRCDIRS			:=	project	\
					bsp/clk	\
					bsp/delay \
					bsp/led \
					bsp/beep \
					bsp/key	\
					bsp/gpio

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENODIR		:= $(notdir $(SFILES))
CFILENODIR		:= $(notdir $(CFILES))

SOBJS			:= $(patsubst %, obj/%, $(SFILENODIR:.S=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENODIR:.c=.o))

OBJS			:= $(SOBJS)$(COBJS)

VPATH			:= $(SRCDIRS)

.PHONY:clean

$(TARGET).bin : $(OBJS)
	$(LD) -Tim6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(COBJS) $(SOBJS)

print:
	@echo INCLUDE = $(INCLUDE)
	@echo SFILES = $(SFILES)
	@echo CFILES = $(CFILES)
	@echo SFILENODIR = $(SFILENODIR)
	@echo CFILENODIR = $(CFILENODIR)
	@echo SOBJS = $(SOBJS)
	@echo COBJS = $(COBJS)
	@echo OBJS = $(OBJS)

#OBJS			:= start.o main.o

#$(NAME).bin : $(OBJS)
#	$(LD) -Tim6ul.lds -o $(NAME).elf $^
#	$(OBJCOPY) -O binary -S $(NAME).elf $@
#	$(OBJDUMP) -D -m arm $(NAME).elf > $(NAME).dis

#%.o:%.s
#	$(CC) -Wall -nostdlib -c -O2 -o $@ $<

#%.o:%.S
#	$(CC) -Wall -nostdlib -c -O2 -o $@ $<

#%.o:%.c
#	$(CC) -Wall -nostdlib -c -O2 -o $@ $<

#clean:
#	rm -rf *.o $(NAME).elf $(NAME).bin $(NAME).dis
