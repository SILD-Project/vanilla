/*
 * include/efibs.h : EFI Boot Services definitions
 *
 * This file is part of the Vanilla project
 *
 * Copyright (C) 2024-present Sipaa Projects and the Vanilla contributors
 *
 * Use of this source file is governed by the MIT License, available at
 * https://opensource.org/license/mit.
 */


#pragma once

#include "efidef.h"
#include "efitab.h"

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION
#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES \
 {0x27abf055, 0xb1b8, 0x4c26, 0x80, 0x48, 0x74, 0x8f, 0x37,\
 0xba, 0xa2, 0xdf}}

#define EFI_EVENT_GROUP_BEFORE_EXIT_BOOT_SERVICES \
  { 0x8be0e274, 0x3970, 0x4b44, { 0x80, 0xc5, 0x1a, 0xb9, 0x50, 0x2f, 0x3b, 0xfc } }

#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE \
  {0x13fa7698, 0xc831, 0x49c7, 0x87, 0xea, 0x8f, 0x43, 0xfc,\
  0xc2, 0x51, 0x96}

#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE \
 {0x78bee926, 0x692f, 0x48fd, 0x9e, 0xdb, 0x1, 0x42, 0x2e, \
 0xf0, 0xd7, 0xab}

#define EFI_EVENT_GROUP_READY_TO_BOOT \
 {0x7ce88fb3, 0x4bd7, 0x4679, 0x87, 0xa8, 0xa8, 0xd8, 0xde,\
 0xe5,0xd, 0x2b}

#define EFI_EVENT_GROUP_AFTER_READY_TO_BOOT \
  { 0x3a2a00ad, 0x98b9, 0x4cdf, { 0xa4, 0x78, 0x70, 0x27, 0x77, \
0xf1, 0xc1, 0xb } }

#define EFI_EVENT_GROUP_RESET_SYSTEM \
{ 0x62da6a56, 0x13fb, 0x485a, { 0xa8, 0xda, 0xa3, 0xdd, 0x79, 0x12, 0xcb, 0x6b \
 } }


typedef
VOID
(EFIAPI *EFI_EVENT_NOTIFY) (
  IN EFI_EVENT          Event,
  IN VOID              *Context
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT) (
   IN UINT32                   Type,
   IN EFI_TPL                  NotifyTpl,
   IN EFI_EVENT_NOTIFY         NotifyFunction, OPTIONAL
   IN VOID                     *NotifyContext, OPTIONAL
   OUT EFI_EVENT               *Event
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT_EX) (
   IN UINT32                  Type,
   IN EFI_TPL                 NotifyTpl,
   IN EFI_EVENT_NOTIFY        NotifyFunction OPTIONAL,
   IN CONST VOID              *NotifyContext OPTIONAL,
   IN CONST EFI_GUID          *EventGroup OPTIONAL,
   OUT EFI_EVENT              *Event
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT) (
  IN EFI_EVENT      Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT) (
  IN EFI_EVENT Event
    );

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
   IN UINTN             NumberOfEvents,
   IN EFI_EVENT         *Event,
   OUT UINTN            *Index
  );

typedef
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT) (
  IN EFI_EVENT                Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER) (
   IN EFI_EVENT               Event,
   IN EFI_TIMER_DELAY         Type,
   IN UINT64                  TriggerTime
   );

  typedef
EFI_TPL
(EFIAPI   *EFI_RAISE_TPL) (
  IN EFI_TPL   NewTpl
  );

typedef
VOID
(EFIAPI *EFI_RESTORE_TPL) (
   IN EFI_TPL OldTpl
   );

typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_PAGES) (
   IN EFI_ALLOCATE_TYPE                   Type,
   IN EFI_MEMORY_TYPE                     MemoryType,
   IN UINTN                               Pages,
   IN OUT EFI_PHYSICAL_ADDRESS            *Memory
   );

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_PAGES) (
IN EFI_PHYSICAL_ADDRESS    Memory,
IN UINTN                   Pages
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP) (
   IN OUT UINTN                  *MemoryMapSize,
   OUT EFI_MEMORY_DESCRIPTOR     *MemoryMap,
   OUT UINTN                     *MapKey,
   OUT UINTN                     *DescriptorSize,
   OUT UINT32                    *DescriptorVersion
  );

typedef
EFI_STATUS
(EFIAPI  *EFI_ALLOCATE_POOL) (
   IN EFI_MEMORY_TYPE            PoolType,
   IN UINTN                      Size,
   OUT VOID                      **Buffer
   );

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_POOL) (
   IN VOID           *Buffer
   );

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) (
   IN OUT EFI_HANDLE             *Handle,
   IN EFI_GUID                   *Protocol,
   IN EFI_INTERFACE_TYPE         InterfaceType,
   IN VOID                       *Interface
   );

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) (
   IN EFI_HANDLE        Handle,
   IN EFI_GUID          *Protocol,
   IN VOID              *Interface
   );

  typedef
EFI_STATUS
(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) (
   IN EFI_HANDLE           Handle,
   IN EFI_GUID             *Protocol,
   IN VOID                 *OldInterface,
   IN VOID                 *NewInterface
   );

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY) (
   IN EFI_GUID                         *Protocol,
   IN EFI_EVENT                        Event,
   OUT VOID                            **Registration
   );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE) (
   IN EFI_LOCATE_SEARCH_TYPE                 SearchType,
   IN EFI_GUID                               *Protocol OPTIONAL,
   IN VOID                                   *SearchKey OPTIONAL,
   IN OUT UINTN                              *BufferSize,
   OUT EFI_HANDLE                            *Buffer
   );

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL) (
   IN EFI_HANDLE                    Handle,
   IN EFI_GUID                      *Protocol,
   OUT VOID                         **Interface OPTIONAL,
   IN EFI_HANDLE                    AgentHandle,
   IN EFI_HANDLE                    ControllerHandle,
   IN UINT32                        Attributes
   );

typedef
EFI_STATUS
(EFIAPI *EFI_HANDLE_PROTOCOL) (
   IN EFI_HANDLE                    Handle,
   IN EFI_GUID                      *Protocol,
   OUT VOID                         **Interface
   );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_DEVICE_PATH) (
   IN EFI_GUID                         *Protocol,
   IN OUT VOID     **DevicePath, // EFI_DEVICE_PATH_PROTOCOL
   OUT EFI_HANDLE                      *Device
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL) (
   IN EFI_HANDLE                 Handle,
   IN EFI_GUID                   *Protocol,
   IN EFI_HANDLE                 AgentHandle,
   IN EFI_HANDLE                 ControllerHandle
   );

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) (
   IN EFI_HANDLE                             Handle,
   IN EFI_GUID                               *Protocol,
   OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY   **EntryBuffer,
   OUT UINTN                                 *EntryCount
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER) (
   IN EFI_HANDLE                       ControllerHandle,
   IN EFI_HANDLE                       *DriverImageHandle OPTIONAL,
   IN VOID         *RemainingDevicePath OPTIONAL, // EFI_DEVICE_PATH_PROTOCOL
   IN BOOLEAN Recursive
   );

typedef
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER) (
   IN EFI_HANDLE                       ControllerHandle,
   IN EFI_HANDLE                       DriverImageHandle OPTIONAL,
   IN EFI_HANDLE                       ChildHandle OPTIONAL
   );

typedef
EFI_STATUS
(EFIAPI *EFI_PROTOCOLS_PER_HANDLE) (
   IN EFI_HANDLE                             Handle,
   OUT EFI_GUID                              ***ProtocolBuffer,
   OUT UINTN                                 *ProtocolBufferCount
   );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
   IN EFI_LOCATE_SEARCH_TYPE                    SearchType,
   IN EFI_GUID                                  *Protocol OPTIONAL,
   IN VOID                                      *SearchKey OPTIONAL,
   OUT UINTN                                    *NoHandles,
   OUT EFI_HANDLE                               **Buffer
   );

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL) (
  IN EFI_GUID                            *Protocol,
  IN VOID                                *Registration OPTIONAL,
  OUT VOID                               **Interface
 );

typedef
EFI_STATUS
(*EFIAPI EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
   IN OUT EFI_HANDLE                               *Handle,
   ...
   );
typedef
EFI_STATUS
(*EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
   IN EFI_HANDLE Handle,
   ...
  );

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_LOAD) (
   IN BOOLEAN                          BootPolicy,
   IN EFI_HANDLE                       ParentImageHandle,
   IN VOID         *DevicePath   OPTIONAL, // DEVICE PATH
   IN VOID                             *SourceBuffer OPTIONAL,
   IN UINTN                            SourceSize,
   OUT EFI_HANDLE                      *ImageHandle
   );

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_START) (
   IN EFI_HANDLE                             ImageHandle,
   OUT UINTN                                 *ExitDataSize,
   OUT CHAR16                                **ExitData OPTIONAL
   );

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD) (
   IN EFI_HANDLE           ImageHandle
   );

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT) (
   IN EFI_HANDLE                      ImageHandle,
   IN EFI_STATUS                      ExitStatus,
   IN UINTN                           ExitDataSize,
   IN CHAR16                          *ExitData OPTIONAL
   );

typedef EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES) (
  IN EFI_HANDLE                       ImageHandle,
  IN UINTN                            MapKey
  );

typedef
EFI_STATUS
(EFIAPI *EFI_SET_WATCHDOG_TIMER) (
   IN UINTN                          Timeout,
   IN UINT64                         WatchdogCode,
   IN UINTN                          DataSize,
   IN CHAR16                         *WatchdogData OPTIONAL
   );

typedef
EFI_STATUS
(EFIAPI *EFI_STALL) (
   IN UINTN                Microseconds
   );

typedef
VOID
(EFIAPI *EFI_COPY_MEM) (
   IN VOID                       *Destination,
   IN VOID                       *Source,
   IN UINTN                      Length
   );

typedef
VOID
(EFIAPI *EFI_SET_MEM) (
   IN VOID                             *Buffer,
   IN UINTN                            Size,
   IN UINT8                            Value
   );

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) (
   OUT UINT64                       *Count
   );

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE) (
   IN EFI_GUID                               *Guid,
   IN VOID                                   *Table
   );

typedef
EFI_STATUS
(EFIAPI *EFI_CALCULATE_CRC32) (
   IN VOID                          *Data,
   IN UINTN                         DataSize,
   OUT UINT32                       *Crc32
   );

typedef struct {
  EFI_TABLE_HEADER Hdr;

  //
  // Task Priority Services
  //
  EFI_RAISE_TPL RaiseTPL;     // EFI 1.0+
  EFI_RESTORE_TPL RestoreTPL; // EFI 1.0+

  //
  // Memory Services
  //
  EFI_ALLOCATE_PAGES AllocatePages; // EFI 1.0+
  EFI_FREE_PAGES FreePages;         // EFI 1.0+
  EFI_GET_MEMORY_MAP GetMemoryMap;  // EFI 1.0+
  EFI_ALLOCATE_POOL AllocatePool;   // EFI 1.0+
  EFI_FREE_POOL FreePool;           // EFI 1.0+

  //
  // Event & Timer Services
  //
  EFI_CREATE_EVENT CreateEvent;    // EFI 1.0+
  EFI_SET_TIMER SetTimer;          // EFI 1.0+
  EFI_WAIT_FOR_EVENT WaitForEvent; // EFI 1.0+
  EFI_SIGNAL_EVENT SignalEvent;    // EFI 1.0+
  EFI_CLOSE_EVENT CloseEvent;      // EFI 1.0+
  EFI_CHECK_EVENT CheckEvent;      // EFI 1.0+

  //
  // Protocol Handler Services
  //
  EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;     // EFI 1.0+
  EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface; // EFI 1.0+
  EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface; // EFI 1.0+
  EFI_HANDLE_PROTOCOL HandleProtocol;                          // EFI 1.0+
  VOID *Reserved;                                              // EFI 1.0+
  EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;         // EFI  1.0+
  EFI_LOCATE_HANDLE LocateHandle;                              // EFI 1.0+
  EFI_LOCATE_DEVICE_PATH LocateDevicePath;                     // EFI 1.0+
  EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;   // EFI 1.0+

  //
  // Image Services
  //
  EFI_IMAGE_UNLOAD LoadImage;              // EFI 1.0+
  EFI_IMAGE_START StartImage;              // EFI 1.0+
  EFI_EXIT Exit;                           // EFI 1.0+
  EFI_IMAGE_UNLOAD UnloadImage;            // EFI 1.0+
  EFI_EXIT_BOOT_SERVICES ExitBootServices; // EFI 1.0+

  //
  // Miscellaneous Services
  //
  EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount; // EFI 1.0+
  EFI_STALL Stall;                                    // EFI 1.0+
  EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;            // EFI 1.0+

  //
  // DriverSupport Services
  //
  EFI_CONNECT_CONTROLLER ConnectController;       // EFI 1.1
  EFI_DISCONNECT_CONTROLLER DisconnectController; // EFI 1.1+

  //
  // Open and Close Protocol Services
  //
  EFI_OPEN_PROTOCOL OpenProtocol;                        // EFI 1.1+
  EFI_CLOSE_PROTOCOL CloseProtocol;                      // EFI 1.1+
  EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation; // EFI 1.1+

  //
  // Library Services
  //
  EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle; // EFI 1.1+
  EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer; // EFI 1.1+
  EFI_LOCATE_PROTOCOL LocateProtocol;          // EFI 1.1+
  EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES
  InstallMultipleProtocolInterfaces; // EFI 1.1+
  EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES
  UninstallMultipleProtocolInterfaces; // EFI 1.1+*

  //
  // 32-bit CRC Services
  //
  EFI_CALCULATE_CRC32 CalculateCrc32; // EFI 1.1+

  //
  // Miscellaneous Services
  //
  EFI_COPY_MEM CopyMem;              // EFI 1.1+
  EFI_SET_MEM SetMem;                // EFI 1.1+
  EFI_CREATE_EVENT_EX CreateEventEx; // UEFI 2.0+
} EFI_BOOT_SERVICES;