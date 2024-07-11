SRCDIR    := src
BINDIR    := bin
OBJDIR    := obj

ENTRY     := main
BIN       := $(BINDIR)/helloworld-x86_64.efi

CC        := clang
LD        := clang

CFLAGS := \
	-target x86_64-pc-win32-coff \
	-fno-stack-protector \
	-ffreestanding \
	-fshort-wchar \
	-mno-red-zone \
	-MMD

CPPFLAGS := \
	-I../../include \
	-I$(SRCDIR) \
	-MMD \
	-D_X64 \

LDFLAGS := \
	-target x86_64-pc-win32-coff \
	-nostdlib -Wl,-entry:$(ENTRY) \
	-Wl,-subsystem:efi_application \
	-fuse-ld=lld-link \
	-nodefaultlibs
	
SRCS_C = $(shell find $(SRCDIR) -name '*.c')
OBJS_C = $(SRCS_C:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS_C = $(OBJS_C:$(OBJDIR)/%.o=$(OBJDIR)/%.o.d)

all: $(BIN)

$(BIN): $(OBJS_C) 
	@mkdir -p $(BINDIR)

	@echo "    LD       $(BIN)"
	@$(LD) $(LDFLAGS) $(OBJS_C) -o $(BIN)

include $(wildcard $(OBJDIR)/*.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@echo "    CC       $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean-bin:
	@rm -rf obj/
	@rm -rf bin/

clean: clean-bin
	@rm -rf ovmf/

include ./run.mk