/*
 * QEMU RISC-V NUMA Helper
 *
 * Copyright (c) 2020 Western Digital Corporation or its affiliates.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RISCV_NUMA_H
#define RISCV_NUMA_H

#include "hw/sysbus.h"
#include "sysemu/numa.h"

int riscv_socket_count(const MachineState *ms);

int riscv_socket_first_hartid(const MachineState *ms, int socket_id);

int riscv_socket_last_hartid(const MachineState *ms, int socket_id);

int riscv_socket_hart_count(const MachineState *ms, int socket_id);

uint64_t riscv_socket_mem_offset(const MachineState *ms, int socket_id);

uint64_t riscv_socket_mem_size(const MachineState *ms, int socket_id);

bool riscv_socket_check_hartids(const MachineState *ms, int socket_id);

void riscv_socket_fdt_write_id(const MachineState *ms, void *fdt,
                               const char *node_name, int socket_id);

void riscv_socket_fdt_write_distance_matrix(const MachineState *ms, void *fdt);

CpuInstanceProperties
riscv_numa_cpu_index_to_props(MachineState *ms, unsigned cpu_index);

int64_t riscv_numa_get_default_cpu_node_id(const MachineState *ms, int idx);

const CPUArchIdList *riscv_numa_possible_cpu_arch_ids(MachineState *ms);

#endif /* RISCV_NUMA_H */