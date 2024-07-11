/*
 * include/efitab.h : EFI Header Table
 *
 * This file is part of the Vanilla project
 *
 * Copyright (C) 2024-present Sipaa Projects and the Vanilla contributors
 *
 * Use of this source file is governed by the MIT License, available at
 * https://opensource.org/license/mit.
 */

#pragma once

#include "eficon.h"
#include "efidef.h"

/* ---- Table Header ---- */
typedef struct {
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;