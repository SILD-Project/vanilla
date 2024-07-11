#include <efi.h>

EFI_STATUS main(EFI_HANDLE *ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World from Vanilla-UEFI!!");
    
    while (1)
        ;;

    return 0x0;
}