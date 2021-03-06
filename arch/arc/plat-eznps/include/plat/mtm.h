/*
* Copyright (c) 2016, Mellanox Technologies. All rights reserved.
*
* This software is available to you under a choice of one of two
* licenses.  You may choose to be licensed under the terms of the GNU
* General Public License (GPL) Version 2, available from the file
* COPYING in the main directory of this source tree, or the
* OpenIB.org BSD license below:
*
*     Redistribution and use in source and binary forms, with or
*     without modification, are permitted provided that the following
*     conditions are met:
*
*      - Redistributions of source code must retain the above
*        copyright notice, this list of conditions and the following
*        disclaimer.
*
*      - Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials
*        provided with the distribution.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef _PLAT_EZNPS_MTM_H
#define _PLAT_EZNPS_MTM_H

#ifdef CONFIG_EZNPS_MTM_EXT
#include <plat/ctop.h>
#include <plat/smp.h>

/* MTM registers */
#define MTM_CFG(cpu)			nps_mtm_reg_addr(cpu, 0x81)
#define MTM_THR_INIT(cpu)		nps_mtm_reg_addr(cpu, 0x92)
#define MTM_THR_INIT_STS(cpu)		nps_mtm_reg_addr(cpu, 0x93)

#define get_thread(map) map.thread
#define eznps_max_cpus 4096
#define eznps_cpus_per_cluster	256

void mtm_enable_core(unsigned int cpu);
int mtm_enable_thread(int cpu);
#else

#define get_thread(map) 0
#define eznps_max_cpus 256
#define eznps_cpus_per_cluster	16
#define mtm_enable_core(cpu)
#define mtm_enable_thread(cpu) 1

#endif /* CONFIG_EZNPS_MTM_EXT */

#endif /* _PLAT_EZNPS_MTM_H */
