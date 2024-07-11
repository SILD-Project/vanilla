<p align="center">
  <img src="Logo.png#gh-light-mode-only" alt="Vanilla UEFI"/>
  <img src="Logo-darkmode.png#gh-dark-mode-only" alt="Vanilla UEFI" />
  <p align="center">The header-only UEFI library, straight from the docs.</p>
</p>

Vanlla is an UEFI 2.10 implementation made from scratch, using only the online [UEFI specification](https://uefi.org/specs/UEFI/2.10/index.html)

## Why is it named Vanilla
Vanilla is meant to be a 1/1 with the UEFI 2.10 specification at https://uefi.org/specs/UEFI/2.10/index.html

## What is implemented right now?
* Definitions used by everything below (efidef)
* System Table (efist)
* Boot Services (efibs)
* Simple Text Output Protocol (eficon)
* Simple Text Input Ex Protocol (eficon)
* Simple Text Input Protocol (eficon)

It's enougth to write a Hello, World! application, but not enougth for a fully-fledged UEFI application, driver or OS loader.

## How to use Vanilla?
Vanilla is a header-only library: It doesn't need any C files to be linked to your UEFI program.

To use Vanilla in your EFI project:
* Remove all EFI libraries used in your project (GNU-EFI, EDK2, POSIX-UEFI...)
* Add this compiler argument: `-Ipath/to/vanilla/include`
* Compile & link (don't forget to specify your entry point to the linker)!

## Licensing
Vanilla is licensed under the MIT License. You can find a copy of the MIT License at the repo's root, and at https://opensource.org/license/mit.