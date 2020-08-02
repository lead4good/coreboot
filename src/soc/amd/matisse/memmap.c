/* SPDX-License-Identifier: GPL-2.0-only */

#define __SIMPLE_DEVICE__

#include <assert.h>
#include <stdint.h>
#include <cbmem.h>
#include <console/console.h>
#include <cpu/x86/smm.h>
#include <cpu/amd/msr.h>
#include <arch/bert_storage.h>
#include <memrange.h>
#include <soc/memmap.h>

#if CONFIG(PLATFORM_USES_FSP2_0)
#include <FspGuids.h>
#include <fsp/util.h>
#else
 #if CONFIG_SMM_TSEG_SIZE == 0x0
  #define BERT_REGION_MAX_SIZE 0x100000
 #else
  /* SMM_TSEG_SIZE must stay on a boundary appropriate for its granularity */
  #define BERT_REGION_MAX_SIZE CONFIG_SMM_TSEG_SIZE
 #endif

void *cbmem_top_chipset(void)
{
	// 3 gigs, just for shits and giggles
	return (void *)ALIGN_DOWN(0xC0000000
			- CONFIG_SMM_TSEG_SIZE
			- BERT_REGION_MAX_SIZE, 8*MiB);
}
#endif

/*
 * For data stored in TSEG, ensure TValid is clear so R/W access can reach
 * the DRAM when not in SMM.
 */
static void clear_tvalid(void)
{
	msr_t hwcr = rdmsr(HWCR_MSR);
	msr_t mask = rdmsr(SMM_MASK_MSR);
	int tvalid = !!(mask.lo & SMM_TSEG_VALID);

	if (hwcr.lo & SMM_LOCK) {
		if (!tvalid) /* not valid but locked means still accessible */
			return;

		printk(BIOS_ERR, "Error: can't clear TValid, already locked\n");
		return;
	}

	mask.lo &= ~SMM_TSEG_VALID;
	wrmsr(SMM_MASK_MSR, mask);
}

void smm_region(uintptr_t *start, size_t *size)
{
	static int once;
#if CONFIG(PLATFORM_USES_FSP2_0)
	struct range_entry tseg;
	int status;

	*start = 0;
	*size = 0;

	status = fsp_find_range_hob(&tseg, AMD_FSP_TSEG_HOB_GUID.b);

	if (status < 0) {
		printk(BIOS_ERR, "Error: unable to find TSEG HOB\n");
		return;
	}

	*start = (uintptr_t)range_entry_base(&tseg);
	*size = range_entry_size(&tseg);
#else
	*start = (uintptr_t)cbmem_top() + BERT_REGION_MAX_SIZE;
	*size = CONFIG_SMM_TSEG_SIZE;
#endif

	if (!once) {
		clear_tvalid();
		once = 1;
	}
}

void bert_reserved_region(void **start, size_t *size)
{
#if CONFIG(PLATFORM_USES_FSP2_0)
	struct range_entry bert;
	int status;

	*start = NULL;
	*size = 0;

	status = fsp_find_range_hob(&bert, AMD_FSP_BERT_HOB_GUID.b);

	if (status < 0) {
		printk(BIOS_ERR, "Error: unable to find BERT HOB\n");
		return;
	}

	*start = (void *)(uintptr_t)range_entry_base(&bert);
	*size = range_entry_size(&bert);
#else
	//TODO: better definition
	*start = cbmem_top();
	*size = BERT_REGION_MAX_SIZE;
#endif
}

void memmap_stash_early_dram_usage(void)
{
	struct memmap_early_dram *e;

	e = cbmem_add(CBMEM_ID_CB_EARLY_DRAM, sizeof(*e));

	if (!e)
		die("ERROR: Failed to stash early dram usage!\n");

	e->base = (uint32_t)(uintptr_t)_early_reserved_dram;
	e->size = REGION_SIZE(early_reserved_dram);
}

const struct memmap_early_dram *memmap_get_early_dram_usage(void)
{
	struct memmap_early_dram *e = cbmem_find(CBMEM_ID_CB_EARLY_DRAM);

	if (!e)
		die("ERROR: Failed to read early dram usage!\n");

	return e;
}
