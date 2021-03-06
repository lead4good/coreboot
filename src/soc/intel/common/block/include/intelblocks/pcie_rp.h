/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef SOC_INTEL_COMMON_BLOCK_PCIE_RP_H
#define SOC_INTEL_COMMON_BLOCK_PCIE_RP_H

#include <stdint.h>

/*
 * The PCIe Root Ports usually come in groups of up to 8 PCI-device
 * functions.
 *
 * `slot` is the PCI device/slot number of such a group.
 * `count` is the number of functions within the group. It is assumed that
 * the first group includes the RPs 1 to the first group's `count` and that
 * adjacent groups follow without gaps in the numbering.
 */
struct pcie_rp_group {
	unsigned int slot;
	unsigned int count;
};

/*
 * Update PCI paths of the root ports in the devicetree.
 *
 * Depending on the board layout and physical presence of downstream
 * devices, individual root-port functions can be hidden and reordered.
 * If we have device nodes for root ports in the static `devicetree.cb`,
 * we need to update their PCI paths, so the nodes still control the
 * correct root port. Device nodes for disabled root ports will be
 * unlinked from the bus, to not interfere with PCI enumeration.
 *
 * Call this once, after root ports have been reordered, but before PCI
 * enumeration.
 *
 * `groups` points to a list of groups terminated by an entry with `count == 0`.
 */
void pcie_rp_update_devicetree(const struct pcie_rp_group *groups);

/*
 * Return mask of PCIe root ports that are enabled by mainboard. Mask is set in the same order
 * as the root ports in pcie_rp_group groups table.
 *
 * Thus, the status of first root port in the groups table is indicated by bit 0 in the returned
 * mask, second root port by bit 1 and so on.

 * 1 in the bit position indicates root port is enabled, whereas 0 indicates root port is
 * disabled. This function assumes that the maximum count of root ports in the groups table is
 * <= 32.
 */
uint32_t pcie_rp_enable_mask(const struct pcie_rp_group *groups);

#endif /* SOC_INTEL_COMMON_BLOCK_PCIE_RP_H */
