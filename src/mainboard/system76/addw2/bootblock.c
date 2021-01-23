/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <bootblock_common.h>
#include <gpio.h>

void bootblock_mainboard_early_init(void)
{
	mainboard_configure_early_gpios();
}
