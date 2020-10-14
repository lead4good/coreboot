/* SPDX-License-Identifier: GPL-2.0-only */

// Hack for including GMA ACPI code
#define SYSTEM76_ACPI_NO_GFX0

#include <acpi/acpi.h>
DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	0x02,		// DSDT revision: ACPI v2.0 and up
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725	// OEM revision
)
{

	#include <soc/intel/common/block/acpi/acpi/platform.asl>
	#include <soc/intel/common/block/acpi/acpi/globalnvs.asl>
	#include <cpu/intel/common/acpi/cpu.asl>

	Scope (\_SB) {
		Device (PCI0) {
			#include <soc/intel/common/block/acpi/acpi/northbridge.asl>
			#include <soc/intel/tigerlake/acpi/southbridge.asl>
			//TODO
			#include <soc/intel/tigerlake/acpi/tcss.asl>
		}
	}

	Scope (\_SB.PCI0.LPCB) {
		#include <drivers/pc80/pc/ps2_controller.asl>
	}

	#include "acpi/mainboard.asl"

	#include <southbridge/intel/common/acpi/sleepstates.asl>
}