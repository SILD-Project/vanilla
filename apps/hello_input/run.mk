ovmf-bin: 
	@mkdir -p ovmf
	@cd ovmf && curl -o OVMF-x64.fd https://retrage.github.io/edk2-nightly/bin/RELEASEX64_OVMF.fd
# @cd ovmf && curl -o OVMF-aarch64.fd https://retrage.github.io/edk2-nightly/bin/RELEASEAARCH64_QEMU_EFI.fd
# @cd ovmf && curl -o OVMF-riscv64.fd https://retrage.github.io/edk2-nightly/bin/RELEASERISCV64_VIRT_CODE.fd && dd if=/dev/zero of=OVMF-riscv64.fd bs=1 count=0 seek=33554432
# @cd ovmf && curl -o OVMF-ia32.fd https://retrage.github.io/edk2-nightly/bin/RELEASEIa32_OVMF.fd

run-uefi-x86_64: $(BIN) ovmf-bin
	@mkdir -p $(BINDIR)/mnt
	@dd if=/dev/zero of=$(BINDIR)/disk-uefi-x86_64.img bs=1M count=64
	@mkfs.fat -F 32 $(BINDIR)/disk-uefi-x86_64.img
	@sudo mount -o loop $(BINDIR)/disk-uefi-x86_64.img $(BINDIR)/mnt
	@sudo mkdir -p $(BINDIR)/mnt/EFI/BOOT
	@sudo cp $(BIN) $(BINDIR)/mnt/EFI/BOOT/BOOTX64.efi
	@sudo umount $(BINDIR)/mnt
	@qemu-system-x86_64 -accel kvm -m 1g -bios ovmf/OVMF-x64.fd -drive file=$(BINDIR)/disk-uefi-x86_64.img -usb -device usb-tablet

debug-uefi-x86_64: $(BIN) ovmf-bin
	@mkdir -p $(BINDIR)/mnt
	@dd if=/dev/zero of=$(BINDIR)/disk-uefi-x86_64.img bs=1M count=64
	@mkfs.fat -F 32 $(BINDIR)/disk-uefi-x86_64.img
	@sudo mount -o loop $(BINDIR)/disk-uefi-x86_64.img $(BINDIR)/mnt
	@sudo mkdir -p $(BINDIR)/mnt/EFI/BOOT
	@sudo cp $(BIN) $(BINDIR)/mnt/EFI/BOOT/BOOTX64.efi
	@sudo umount $(BINDIR)/mnt
	@qemu-system-x86_64 -m 1g -bios ovmf/OVMF-x64.fd -drive file=$(BINDIR)/disk-uefi-x86_64.img -d int,guest_errors --no-reboot --no-shutdown -usb -device usb-tablet

debug-gdb-uefi-x86_64: $(BIN) ovmf-bin
	@mkdir -p $(BINDIR)/mnt
	@dd if=/dev/zero of=$(BINDIR)/disk-uefi-x86_64.img bs=1M count=64
	@mkfs.fat -F 32 $(BINDIR)/disk-uefi-x86_64.img
	@sudo mount -o loop $(BINDIR)/disk-uefi-x86_64.img $(BINDIR)/mnt
	@sudo mkdir -p $(BINDIR)/mnt/EFI/BOOT
	@sudo cp $(BIN) $(BINDIR)/mnt/EFI/BOOT/BOOTX64.efi
	@sudo umount $(BINDIR)/mnt
	@qemu-system-x86_64 -accel kvm -m 1g -bios ovmf/OVMF-x64.fd -drive file=$(BINDIR)/disk-uefi-x86_64.img --no-reboot --no-shutdown -S -s -usb -device usb-tablet