#include <efi.h>

#define GETCHAR_ENTER 0xFFFF

EFI_STATUS status;
EFI_SYSTEM_TABLE *gST;
CHAR16 buf[1024];

CHAR16 getchar() {
  UINTN EventIndex;
  EFI_INPUT_KEY Key;
  int cr_passed = 0;

  while (TRUE) {
    status = gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
    /**if (EFI_ERROR(status)) {
        continue;
    }**/

    if (Key.UnicodeChar == EFI_CHAR_NULL)
      continue;

    if (Key.UnicodeChar == EFI_CHAR_CR) {
      return GETCHAR_ENTER;
    }

    // char cs2;

    // wctomb(&cs2, Key.UnicodeChar);

    return Key.UnicodeChar;
  }
}

CHAR16 *readline() {
  for (int i = 0; i < 1024; i++) {
    buf[i] = 0;
  }

  int buf_pos = 0;

  while (1) {
    CHAR16 c = getchar();

    if (c == GETCHAR_ENTER) {
      gST->ConOut->OutputString(gST->ConOut, L"\r\n");
      buf[buf_pos] = '\0';
      return buf;
    } else {
      CHAR16 ch[2] = {c, '\0'};
      gST->ConOut->OutputString(gST->ConOut, ch);
      buf[buf_pos] = c;
      goto end;
    }
  end:
    buf_pos++;
  }

  return buf;
}

EFI_STATUS main(EFI_HANDLE *ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  gST = SystemTable;

  gST->ConOut->ClearScreen(gST->ConOut);
  gST->ConOut->OutputString(gST->ConOut, L"Hello, Input!\r\n");
  gST->ConOut->OutputString(
      gST->ConOut,
      L"Type anything below, and then we will print it again for you.\r\n\r\n");

  while (1) {
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"> ");
    CHAR16 *ch = readline();

    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"You wrote \"");
    SystemTable->ConOut->OutputString(SystemTable->ConOut, ch);
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L"\"\r\n");
  }

  return 0x0;
}