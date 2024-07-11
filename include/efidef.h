/*
 * include/efidef.h : EFI definitions
 *
 * This file is part of the Vanilla project
 *
 * Copyright (C) 2024-present Sipaa Projects and the Vanilla contributors
 *
 * Use of this source file is governed by the MIT License, available at
 * https://opensource.org/license/mit.
 */


#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef bool BOOLEAN;
#define FALSE false
#define TRUE true

typedef int64_t INTN;
typedef uint64_t UINTN;

typedef int8_t INT8;
typedef uint8_t UINT8;

typedef int16_t INT16;
typedef uint16_t UINT16;

typedef int32_t INT32;
typedef uint32_t UINT32;

typedef int64_t INT64;
typedef uint64_t UINT64;

typedef char CHAR8;
typedef wchar_t CHAR16;

typedef void VOID;

typedef struct {
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8 Data4[8];
} EFI_GUID;

typedef UINTN EFI_STATUS;
typedef UINTN EFI_PHYSICAL_ADDRESS;
typedef UINTN EFI_VIRTUAL_ADDRESS;

typedef VOID *EFI_HANDLE;
typedef VOID *EFI_EVENT;

typedef UINT64 EFI_LBA;

typedef UINTN EFI_TPL;

#ifndef IN
#define IN
#define OUT
#define OPTIONAL
#endif

#define CONST const

#define EFIAPI

//******************************************************
// Event Types
//******************************************************
// These types can be "ORed" together as needed - for example,
// EVT_TIMER might be "Ored" with EVT_NOTIFY_WAIT or
// EVT_NOTIFY_SIGNAL.
#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000

#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

typedef enum { TimerCancel, TimerPeriodic, TimerRelative } EFI_TIMER_DELAY;

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef enum {
  AllocateAnyPages,
  AllocateMaxAddress,
  AllocateAddress,
  MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum {
  EfiReservedMemoryType,
  EfiLoaderCode,
  EfiLoaderData,
  EfiBootServicesCode,
  EfiBootServicesData,
  EfiRuntimeServicesCode,
  EfiRuntimeServicesData,
  EfiConventionalMemory,
  EfiUnusableMemory,
  EfiACPIReclaimMemory,
  EfiACPIMemoryNVS,
  EfiMemoryMappedIO,
  EfiMemoryMappedIOPortSpace,
  EfiPalCode,
  EfiPersistentMemory,
  EfiUnacceptedMemoryType,
  EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct {
  UINT32 Type;
  EFI_PHYSICAL_ADDRESS PhysicalStart;
  EFI_VIRTUAL_ADDRESS VirtualStart;
  UINT64 NumberOfPages;
  UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_SP 0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO 0x0000000000080000
#define EFI_MEMORY_RUNTIME 0x8000000000000000
#define EFI_MEMORY_ISA_VALID 0x4000000000000000
#define EFI_MEMORY_ISA_MASK 0x0FFFF00000000000

#define EFI_MEMORY_DESCRIPTOR_VERSION 1

typedef enum { EFI_NATIVE_INTERFACE } EFI_INTERFACE_TYPE;

//******************************************************
// EFI_LOCATE_SEARCH_TYPE
//******************************************************
typedef enum {
  AllHandles,
  ByRegisterNotify,
  ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 0x00000020

typedef struct {
  EFI_HANDLE AgentHandle;
  EFI_HANDLE ControllerHandle;
  UINT32 Attributes;
  UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

#define EFI_HII_PACKAGE_LIST_PROTOCOL_GUID                                     \
  {                                                                            \
    0x6a1ee763, 0xd47a, 0x43b4, {                                              \
      0xaa, 0xbe, 0xef, 0x1d, 0xe2, 0xab, 0x56, 0xfc                           \
    }                                                                          \
  }

typedef VOID *EFI_HII_PACKAGE_LIST_PROTOCOL;

/* Console support */
#define EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_GUID                                 \
  {                                                                            \
    0xdd9e7534, 0x7762, 0x4698, {                                              \
      0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa                           \
    }                                                                          \
  }

#define EFI_CHAR_NULL 0x0000
#define EFI_CHAR_BS 0x0008
#define EFI_CHAR_TAB 0x0009
#define EFI_CHAR_LF 0x000A
#define EFI_CHAR_CR 0x000D

#define EFI_SHIFT_STATE_VALID 0x80000000
#define EFI_RIGHT_SHIFT_PRESSED 0x00000001
#define EFI_LEFT_SHIFT_PRESSED 0x00000002
#define EFI_RIGHT_CONTROL_PRESSED 0x00000004
#define EFI_LEFT_CONTROL_PRESSED 0x00000008
#define EFI_RIGHT_ALT_PRESSED 0x00000010
#define EFI_LEFT_ALT_PRESSED 0x00000020
#define EFI_RIGHT_LOGO_PRESSED 0x00000040
#define EFI_LEFT_LOGO_PRESSED 0x00000080
#define EFI_MENU_KEY_PRESSED 0x00000100
#define EFI_SYS_REQ_PRESSED 0x00000200

//*****************************************************
// EFI_KEY_TOGGLE_STATE
//*****************************************************
typedef UINT8 EFI_KEY_TOGGLE_STATE;

#define EFI_TOGGLE_STATE_VALID 0x80
#define EFI_KEY_STATE_EXPOSED 0x40
#define EFI_SCROLL_LOCK_ACTIVE 0x01
#define EFI_NUM_LOCK_ACTIVE 0x02
#define EFI_CAPS_LOCK_ACTIVE 0x04

typedef struct {
  UINT16 ScanCode;
  CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID                                   \
  {                                                                            \
    0x387477c2, 0x69c7, 0x11d2, {                                              \
      0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b                           \
    }                                                                          \
  }

typedef struct {
  INT32 MaxMode;
  // current settings
  INT32 Mode;
  INT32 Attribute;
  INT32 CursorColumn;
  INT32 CursorRow;
  BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

//******************************************************
// UNICODE DRAWING CHARACTERS
//******************************************************

#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250c
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251c
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252c
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253c

#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557

#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255a
#define BOXDRAW_UP_LEFT_DOUBLE 0x255b
#define BOXDRAW_UP_DOUBLE_LEFT 0x255c
#define BOXDRAW_DOUBLE_UP_LEFT 0x255d

#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560

#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563

#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566

#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569

#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c

//******************************************************
// EFI Required Block Elements Code Chart
//******************************************************

#define BLOCKELEMENT_FULL_BLOCK 0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591

//******************************************************
// EFI Required Geometric Shapes Code Chart
//******************************************************

#define GEOMETRICSHAPE_UP_TRIANGLE 0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25c4

//******************************************************
// EFI Required Arrow shapes
//******************************************************

#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

//*******************************************************
// Attributes
//*******************************************************
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT)
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F

#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70
//
// Macro to accept color values in their raw form to create
// a value that represents both a foreground and background
// color in a single byte.
// For Foreground, and EFI_\* value is valid from EFI_BLACK(0x00)
// to EFI_WHITE (0x0F).
// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
// EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY
// are acceptable.
//
// Do not use EFI_BACKGROUND_xxx values with this macro.
// #define EFI_TEXT_ATTR(Foreground,Background) \
((Foreground) | ((Background) << 4))

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID                                    \
  {                                                                            \
    0x387477c1, 0x69c7, 0x11d2, {                                              \
      0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b                           \
    }                                                                          \
  }

/* ---- Industry Standard Configuration Tables ---- */
#define EFI_ACPI_20_TABLE_GUID                                                 \
  {                                                                            \
    0x8868e871, 0xe4f1, 0x11d3, {                                              \
      0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81                           \
    }                                                                          \
  }

#define ACPI_TABLE_GUID                                                        \
  {                                                                            \
    0xeb9d2d30, 0x2d88, 0x11d3, {                                              \
      0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d                           \
    }                                                                          \
  }

#define SAL_SYSTEM_TABLE_GUID                                                  \
  {                                                                            \
    0xeb9d2d32, 0x2d88, 0x11d3, {                                              \
      0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d                           \
    }                                                                          \
  }

#define SMBIOS_TABLE_GUID                                                      \
  {                                                                            \
    0xeb9d2d31, 0x2d88, 0x11d3, {                                              \
      0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d                           \
    }                                                                          \
  }

#define SMBIOS3_TABLE_GUID                                                     \
  {0xf2fd1544, 0x9794, 0x4a2c,\
   {0x99,0x2e,0xe5,0xbb,0xcf,0x20,0xe3,0x94})

#define MPS_TABLE_GUID                                                         \
  {                                                                            \
    0xeb9d2d2f, 0x2d88, 0x11d3, {                                              \
      0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d                           \
    }                                                                          \
  }
//
// ACPI 2.0 or newer tables should use EFI_ACPI_TABLE_GUID
//
#define EFI_ACPI_TABLE_GUID                                                    \
  {                                                                            \
    0x8868e871, 0xe4f1, 0x11d3, {                                              \
      0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81                           \
    }                                                                          \
  }

// #define EFI_ACPI_20_TABLE_GUID EFI_ACPI_TABLE_GUID

#define ACPI_TABLE_GUID                                                        \
  {                                                                            \
    0xeb9d2d30, 0x2d88, 0x11d3, {                                              \
      0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d                           \
    }                                                                          \
  }

#define ACPI_10_TABLE_GUID ACPI_TABLE_GUID *

/* ---- JSON Configuration Tables ---- */
#define EFI_JSON_CONFIG_DATA_TABLE_GUID                                        \
  {                                                                            \
    0x87367f87, 0x1119, 0x41ce, {                                              \
      0xaa, 0xec, 0x8b, 0xe0, 0x11, 0x1f, 0x55, 0x8a                           \
    }                                                                          \
  }

#define EFI_JSON_CAPSULE_DATA_TABLE_GUID                                       \
  {                                                                            \
    0x35e7a725, 0x8dd2, 0x4cac, {                                              \
      0x80, 0x11, 0x33, 0xcd, 0xa8, 0x10, 0x90, 0x56                           \
    }                                                                          \
  }

#define EFI_JSON_CAPSULE_RESULT_TABLE_GUID                                     \
  {                                                                            \
    0xdbc461c3, 0xb3de, 0x422a, {                                              \
      0xb9, 0xb4, 0x98, 0x86, 0xfd, 0x49, 0xa1, 0xe5                           \
    }                                                                          \
  }

/* ---- Devicetree Tables ---- */
#define EFI_DTB_TABLE_GUID                                                     \
  {                                                                            \
    0xb1b621d5, 0xf19c, 0x41a5, {                                              \
      0x83, 0x0b, 0xd9, 0x15, 0x2c, 0x69, 0xaa, 0xe0                           \
    }                                                                          \
  }

/* ---- Configuration table ---- */
typedef struct {
  EFI_GUID VendorGuid;
  VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;
