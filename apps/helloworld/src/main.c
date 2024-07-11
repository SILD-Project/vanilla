/*
 * apps/helloworld/src/main.c: Source code for the "Hello, World!" example.
 *
 * This file is part of the Vanilla project
 *
 * Copyright (C) 2024-present Sipaa Projects and the Vanilla contributors
 *
 * Use of this source file is governed by the MIT License, available at
 * https://opensource.org/license/mit.
 */

#include <efi.h>

EFI_STATUS main(EFI_HANDLE *ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World from Vanilla-UEFI!!");
    
    while (1)
        ;;

    return 0x0;
}