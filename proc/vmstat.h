/*
 * libprocps - Library to read proc filesystem
 *
 * Copyright (C) 1995 Martin Schulze <joey@infodrom.north.de>
 * Copyright (C) 1996 Charles Blake <cblake@bbn.com>
 * Copyright (C) 2003 Albert Cahalan
 * Copyright (C) 2015 Craig Small <csmall@enc.com.au>
 * Copyright (C) 2016 Jim Warner <james.warner@comcast.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef PROCPS_VMSTAT_H
#define PROCPS_VMSTAT_H

#include <sys/cdefs.h>

__BEGIN_DECLS

enum vmstat_item {
    VMSTAT_noop,                                 //       ( never altered )
    VMSTAT_extra,                                //       ( reset to zero )

    VMSTAT_ALLOCSTALL,                           // ul_int
    VMSTAT_BALLOON_DEFLATE,                      // ul_int
    VMSTAT_BALLOON_INFLATE,                      // ul_int
    VMSTAT_BALLOON_MIGRATE,                      // ul_int
    VMSTAT_COMPACT_FAIL,                         // ul_int
    VMSTAT_COMPACT_FREE_SCANNED,                 // ul_int
    VMSTAT_COMPACT_ISOLATED,                     // ul_int
    VMSTAT_COMPACT_MIGRATE_SCANNED,              // ul_int
    VMSTAT_COMPACT_STALL,                        // ul_int
    VMSTAT_COMPACT_SUCCESS,                      // ul_int
    VMSTAT_DROP_PAGECACHE,                       // ul_int
    VMSTAT_DROP_SLAB,                            // ul_int
    VMSTAT_HTLB_BUDDY_ALLOC_FAIL,                // ul_int
    VMSTAT_HTLB_BUDDY_ALLOC_SUCCESS,             // ul_int
    VMSTAT_KSWAPD_HIGH_WMARK_HIT_QUICKLY,        // ul_int
    VMSTAT_KSWAPD_INODESTEAL,                    // ul_int
    VMSTAT_KSWAPD_LOW_WMARK_HIT_QUICKLY,         // ul_int
    VMSTAT_NR_ACTIVE_ANON,                       // ul_int
    VMSTAT_NR_ACTIVE_FILE,                       // ul_int
    VMSTAT_NR_ALLOC_BATCH,                       // ul_int
    VMSTAT_NR_ANON_PAGES,                        // ul_int
    VMSTAT_NR_ANON_TRANSPARENT_HUGEPAGES,        // ul_int
    VMSTAT_NR_BOUNCE,                            // ul_int
    VMSTAT_NR_DIRTIED,                           // ul_int
    VMSTAT_NR_DIRTY,                             // ul_int
    VMSTAT_NR_DIRTY_BACKGROUND_THRESHOLD,        // ul_int
    VMSTAT_NR_DIRTY_THRESHOLD,                   // ul_int
    VMSTAT_NR_FILE_PAGES,                        // ul_int
    VMSTAT_NR_FREE_CMA,                          // ul_int
    VMSTAT_NR_FREE_PAGES,                        // ul_int
    VMSTAT_NR_INACTIVE_ANON,                     // ul_int
    VMSTAT_NR_INACTIVE_FILE,                     // ul_int
    VMSTAT_NR_ISOLATED_ANON,                     // ul_int
    VMSTAT_NR_ISOLATED_FILE,                     // ul_int
    VMSTAT_NR_KERNEL_STACK,                      // ul_int
    VMSTAT_NR_MAPPED,                            // ul_int
    VMSTAT_NR_MLOCK,                             // ul_int
    VMSTAT_NR_PAGES_SCANNED,                     // ul_int
    VMSTAT_NR_PAGE_TABLE_PAGES,                  // ul_int
    VMSTAT_NR_SHMEM,                             // ul_int
    VMSTAT_NR_SLAB_RECLAIMABLE,                  // ul_int
    VMSTAT_NR_SLAB_UNRECLAIMABLE,                // ul_int
    VMSTAT_NR_UNEVICTABLE,                       // ul_int
    VMSTAT_NR_UNSTABLE,                          // ul_int
    VMSTAT_NR_VMSCAN_IMMEDIATE_RECLAIM,          // ul_int
    VMSTAT_NR_VMSCAN_WRITE,                      // ul_int
    VMSTAT_NR_WRITEBACK,                         // ul_int
    VMSTAT_NR_WRITEBACK_TEMP,                    // ul_int
    VMSTAT_NR_WRITTEN,                           // ul_int
    VMSTAT_NUMA_FOREIGN,                         // ul_int
    VMSTAT_NUMA_HINT_FAULTS,                     // ul_int
    VMSTAT_NUMA_HINT_FAULTS_LOCAL,               // ul_int
    VMSTAT_NUMA_HIT,                             // ul_int
    VMSTAT_NUMA_HUGE_PTE_UPDATES,                // ul_int
    VMSTAT_NUMA_INTERLEAVE,                      // ul_int
    VMSTAT_NUMA_LOCAL,                           // ul_int
    VMSTAT_NUMA_MISS,                            // ul_int
    VMSTAT_NUMA_OTHER,                           // ul_int
    VMSTAT_NUMA_PAGES_MIGRATED,                  // ul_int
    VMSTAT_NUMA_PTE_UPDATES,                     // ul_int
    VMSTAT_PAGEOUTRUN,                           // ul_int
    VMSTAT_PGACTIVATE,                           // ul_int
    VMSTAT_PGALLOC_DMA,                          // ul_int
    VMSTAT_PGALLOC_DMA32,                        // ul_int
    VMSTAT_PGALLOC_MOVABLE,                      // ul_int
    VMSTAT_PGALLOC_NORMAL,                       // ul_int
    VMSTAT_PGDEACTIVATE,                         // ul_int
    VMSTAT_PGFAULT,                              // ul_int
    VMSTAT_PGFREE,                               // ul_int
    VMSTAT_PGINODESTEAL,                         // ul_int
    VMSTAT_PGMAJFAULT,                           // ul_int
    VMSTAT_PGMIGRATE_FAIL,                       // ul_int
    VMSTAT_PGMIGRATE_SUCCESS,                    // ul_int
    VMSTAT_PGPGIN,                               // ul_int
    VMSTAT_PGPGOUT,                              // ul_int
    VMSTAT_PGREFILL_DMA,                         // ul_int
    VMSTAT_PGREFILL_DMA32,                       // ul_int
    VMSTAT_PGREFILL_MOVABLE,                     // ul_int
    VMSTAT_PGREFILL_NORMAL,                      // ul_int
    VMSTAT_PGROTATED,                            // ul_int
    VMSTAT_PGSCAN_DIRECT_DMA,                    // ul_int
    VMSTAT_PGSCAN_DIRECT_DMA32,                  // ul_int
    VMSTAT_PGSCAN_DIRECT_MOVABLE,                // ul_int
    VMSTAT_PGSCAN_DIRECT_NORMAL,                 // ul_int
    VMSTAT_PGSCAN_DIRECT_THROTTLE,               // ul_int
    VMSTAT_PGSCAN_KSWAPD_DMA,                    // ul_int
    VMSTAT_PGSCAN_KSWAPD_DMA32,                  // ul_int
    VMSTAT_PGSCAN_KSWAPD_MOVEABLE,               // ul_int
    VMSTAT_PGSCAN_KSWAPD_NORMAL,                 // ul_int
    VMSTAT_PGSTEAL_DIRECT_DMA,                   // ul_int
    VMSTAT_PGSTEAL_DIRECT_DMA32,                 // ul_int
    VMSTAT_PGSTEAL_DIRECT_MOVABLE,               // ul_int
    VMSTAT_PGSTEAL_DIRECT_NORMAL,                // ul_int
    VMSTAT_PGSTEAL_KSWAPD_DMA,                   // ul_int
    VMSTAT_PGSTEAL_KSWAPD_DMA32,                 // ul_int
    VMSTAT_PGSTEAL_KSWAPD_MOVABLE,               // ul_int
    VMSTAT_PGSTEAL_KSWAPD_NORMAL,                // ul_int
    VMSTAT_PSWPIN,                               // ul_int
    VMSTAT_PSWPOUT,                              // ul_int
    VMSTAT_SLABS_SCANNED,                        // ul_int
    VMSTAT_THP_COLLAPSE_ALLOC,                   // ul_int
    VMSTAT_THP_COLLAPSE_ALLOC_FAILED,            // ul_int
    VMSTAT_THP_FAULT_ALLOC,                      // ul_int
    VMSTAT_THP_FAULT_FALLBACK,                   // ul_int
    VMSTAT_THP_SPLIT,                            // ul_int
    VMSTAT_THP_ZERO_PAGE_ALLOC,                  // ul_int
    VMSTAT_THP_ZERO_PAGE_ALLOC_FAILED,           // ul_int
    VMSTAT_UNEVICTABLE_PGS_CLEARED,              // ul_int
    VMSTAT_UNEVICTABLE_PGS_CULLED,               // ul_int
    VMSTAT_UNEVICTABLE_PGS_MLOCKED,              // ul_int
    VMSTAT_UNEVICTABLE_PGS_MUNLOCKED,            // ul_int
    VMSTAT_UNEVICTABLE_PGS_RESCUED,              // ul_int
    VMSTAT_UNEVICTABLE_PGS_SCANNED,              // ul_int
    VMSTAT_UNEVICTABLE_PGS_STRANDED,             // ul_int
    VMSTAT_WORKINGSET_ACTIVATE,                  // ul_int
    VMSTAT_WORKINGSET_NODERECLAIM,               // ul_int
    VMSTAT_WORKINGSET_REFAULT,                   // ul_int
    VMSTAT_ZONE_RECLAIM_FAILED,                  // ul_int

    VMSTAT_DELTA_ALLOCSTALL,                     // sl_int
    VMSTAT_DELTA_BALLOON_DEFLATE,                // sl_int
    VMSTAT_DELTA_BALLOON_INFLATE,                // sl_int
    VMSTAT_DELTA_BALLOON_MIGRATE,                // sl_int
    VMSTAT_DELTA_COMPACT_FAIL,                   // sl_int
    VMSTAT_DELTA_COMPACT_FREE_SCANNED,           // sl_int
    VMSTAT_DELTA_COMPACT_ISOLATED,               // sl_int
    VMSTAT_DELTA_COMPACT_MIGRATE_SCANNED,        // sl_int
    VMSTAT_DELTA_COMPACT_STALL,                  // sl_int
    VMSTAT_DELTA_COMPACT_SUCCESS,                // sl_int
    VMSTAT_DELTA_DROP_PAGECACHE,                 // sl_int
    VMSTAT_DELTA_DROP_SLAB,                      // sl_int
    VMSTAT_DELTA_HTLB_BUDDY_ALLOC_FAIL,          // sl_int
    VMSTAT_DELTA_HTLB_BUDDY_ALLOC_SUCCESS,       // sl_int
    VMSTAT_DELTA_KSWAPD_HIGH_WMARK_HIT_QUICKLY,  // sl_int
    VMSTAT_DELTA_KSWAPD_INODESTEAL,              // sl_int
    VMSTAT_DELTA_KSWAPD_LOW_WMARK_HIT_QUICKLY,   // sl_int
    VMSTAT_DELTA_NR_ACTIVE_ANON,                 // sl_int
    VMSTAT_DELTA_NR_ACTIVE_FILE,                 // sl_int
    VMSTAT_DELTA_NR_ALLOC_BATCH,                 // sl_int
    VMSTAT_DELTA_NR_ANON_PAGES,                  // sl_int
    VMSTAT_DELTA_NR_ANON_TRANSPARENT_HUGEPAGES,  // sl_int
    VMSTAT_DELTA_NR_BOUNCE,                      // sl_int
    VMSTAT_DELTA_NR_DIRTIED,                     // sl_int
    VMSTAT_DELTA_NR_DIRTY,                       // sl_int
    VMSTAT_DELTA_NR_DIRTY_BACKGROUND_THRESHOLD,  // sl_int
    VMSTAT_DELTA_NR_DIRTY_THRESHOLD,             // sl_int
    VMSTAT_DELTA_NR_FILE_PAGES,                  // sl_int
    VMSTAT_DELTA_NR_FREE_CMA,                    // sl_int
    VMSTAT_DELTA_NR_FREE_PAGES,                  // sl_int
    VMSTAT_DELTA_NR_INACTIVE_ANON,               // sl_int
    VMSTAT_DELTA_NR_INACTIVE_FILE,               // sl_int
    VMSTAT_DELTA_NR_ISOLATED_ANON,               // sl_int
    VMSTAT_DELTA_NR_ISOLATED_FILE,               // sl_int
    VMSTAT_DELTA_NR_KERNEL_STACK,                // sl_int
    VMSTAT_DELTA_NR_MAPPED,                      // sl_int
    VMSTAT_DELTA_NR_MLOCK,                       // sl_int
    VMSTAT_DELTA_NR_PAGES_SCANNED,               // sl_int
    VMSTAT_DELTA_NR_PAGE_TABLE_PAGES,            // sl_int
    VMSTAT_DELTA_NR_SHMEM,                       // sl_int
    VMSTAT_DELTA_NR_SLAB_RECLAIMABLE,            // sl_int
    VMSTAT_DELTA_NR_SLAB_UNRECLAIMABLE,          // sl_int
    VMSTAT_DELTA_NR_UNEVICTABLE,                 // sl_int
    VMSTAT_DELTA_NR_UNSTABLE,                    // sl_int
    VMSTAT_DELTA_NR_VMSCAN_IMMEDIATE_RECLAIM,    // sl_int
    VMSTAT_DELTA_NR_VMSCAN_WRITE,                // sl_int
    VMSTAT_DELTA_NR_WRITEBACK,                   // sl_int
    VMSTAT_DELTA_NR_WRITEBACK_TEMP,              // sl_int
    VMSTAT_DELTA_NR_WRITTEN,                     // sl_int
    VMSTAT_DELTA_NUMA_FOREIGN,                   // sl_int
    VMSTAT_DELTA_NUMA_HINT_FAULTS,               // sl_int
    VMSTAT_DELTA_NUMA_HINT_FAULTS_LOCAL,         // sl_int
    VMSTAT_DELTA_NUMA_HIT,                       // sl_int
    VMSTAT_DELTA_NUMA_HUGE_PTE_UPDATES,          // sl_int
    VMSTAT_DELTA_NUMA_INTERLEAVE,                // sl_int
    VMSTAT_DELTA_NUMA_LOCAL,                     // sl_int
    VMSTAT_DELTA_NUMA_MISS,                      // sl_int
    VMSTAT_DELTA_NUMA_OTHER,                     // sl_int
    VMSTAT_DELTA_NUMA_PAGES_MIGRATED,            // sl_int
    VMSTAT_DELTA_NUMA_PTE_UPDATES,               // sl_int
    VMSTAT_DELTA_PAGEOUTRUN,                     // sl_int
    VMSTAT_DELTA_PGACTIVATE,                     // sl_int
    VMSTAT_DELTA_PGALLOC_DMA,                    // sl_int
    VMSTAT_DELTA_PGALLOC_DMA32,                  // sl_int
    VMSTAT_DELTA_PGALLOC_MOVABLE,                // sl_int
    VMSTAT_DELTA_PGALLOC_NORMAL,                 // sl_int
    VMSTAT_DELTA_PGDEACTIVATE,                   // sl_int
    VMSTAT_DELTA_PGFAULT,                        // sl_int
    VMSTAT_DELTA_PGFREE,                         // sl_int
    VMSTAT_DELTA_PGINODESTEAL,                   // sl_int
    VMSTAT_DELTA_PGMAJFAULT,                     // sl_int
    VMSTAT_DELTA_PGMIGRATE_FAIL,                 // sl_int
    VMSTAT_DELTA_PGMIGRATE_SUCCESS,              // sl_int
    VMSTAT_DELTA_PGPGIN,                         // sl_int
    VMSTAT_DELTA_PGPGOUT,                        // sl_int
    VMSTAT_DELTA_PGREFILL_DMA,                   // sl_int
    VMSTAT_DELTA_PGREFILL_DMA32,                 // sl_int
    VMSTAT_DELTA_PGREFILL_MOVABLE,               // sl_int
    VMSTAT_DELTA_PGREFILL_NORMAL,                // sl_int
    VMSTAT_DELTA_PGROTATED,                      // sl_int
    VMSTAT_DELTA_PGSCAN_DIRECT_DMA,              // sl_int
    VMSTAT_DELTA_PGSCAN_DIRECT_DMA32,            // sl_int
    VMSTAT_DELTA_PGSCAN_DIRECT_MOVABLE,          // sl_int
    VMSTAT_DELTA_PGSCAN_DIRECT_NORMAL,           // sl_int
    VMSTAT_DELTA_PGSCAN_DIRECT_THROTTLE,         // sl_int
    VMSTAT_DELTA_PGSCAN_KSWAPD_DMA,              // sl_int
    VMSTAT_DELTA_PGSCAN_KSWAPD_DMA32,            // sl_int
    VMSTAT_DELTA_PGSCAN_KSWAPD_MOVEABLE,         // sl_int
    VMSTAT_DELTA_PGSCAN_KSWAPD_NORMAL,           // sl_int
    VMSTAT_DELTA_PGSTEAL_DIRECT_DMA,             // sl_int
    VMSTAT_DELTA_PGSTEAL_DIRECT_DMA32,           // sl_int
    VMSTAT_DELTA_PGSTEAL_DIRECT_MOVABLE,         // sl_int
    VMSTAT_DELTA_PGSTEAL_DIRECT_NORMAL,          // sl_int
    VMSTAT_DELTA_PGSTEAL_KSWAPD_DMA,             // sl_int
    VMSTAT_DELTA_PGSTEAL_KSWAPD_DMA32,           // sl_int
    VMSTAT_DELTA_PGSTEAL_KSWAPD_MOVABLE,         // sl_int
    VMSTAT_DELTA_PGSTEAL_KSWAPD_NORMAL,          // sl_int
    VMSTAT_DELTA_PSWPIN,                         // sl_int
    VMSTAT_DELTA_PSWPOUT,                        // sl_int
    VMSTAT_DELTA_SLABS_SCANNED,                  // sl_int
    VMSTAT_DELTA_THP_COLLAPSE_ALLOC,             // sl_int
    VMSTAT_DELTA_THP_COLLAPSE_ALLOC_FAILED,      // sl_int
    VMSTAT_DELTA_THP_FAULT_ALLOC,                // sl_int
    VMSTAT_DELTA_THP_FAULT_FALLBACK,             // sl_int
    VMSTAT_DELTA_THP_SPLIT,                      // sl_int
    VMSTAT_DELTA_THP_ZERO_PAGE_ALLOC,            // sl_int
    VMSTAT_DELTA_THP_ZERO_PAGE_ALLOC_FAILED,     // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_CLEARED,        // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_CULLED,         // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_MLOCKED,        // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_MUNLOCKED,      // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_RESCUED,        // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_SCANNED,        // sl_int
    VMSTAT_DELTA_UNEVICTABLE_PGS_STRANDED,       // sl_int
    VMSTAT_DELTA_WORKINGSET_ACTIVATE,            // sl_int
    VMSTAT_DELTA_WORKINGSET_NODERECLAIM,         // sl_int
    VMSTAT_DELTA_WORKINGSET_REFAULT,             // sl_int
    VMSTAT_DELTA_ZONE_RECLAIM_FAILED             // sl_int
};


struct vmstat_result {
    enum vmstat_item item;
    union {
        signed long    sl_int;
        unsigned long  ul_int;
    } result;
};

struct vmstat_stack {
    struct vmstat_result *head;
};


#define VMSTAT_GET( info, actual_enum, type ) ( { \
    struct vmstat_result *r = procps_vmstat_get( info, actual_enum ); \
    r ? r->result . type : 0; } )

#define VMSTAT_VAL( relative_enum, type, stack, info ) \
    stack -> head [ relative_enum ] . result . type


struct vmstat_info;

int procps_vmstat_new   (struct vmstat_info **info);
int procps_vmstat_ref   (struct vmstat_info  *info);
int procps_vmstat_unref (struct vmstat_info **info);

struct vmstat_result *procps_vmstat_get (
    struct vmstat_info *info,
    enum vmstat_item item);

struct vmstat_stack *procps_vmstat_select (
    struct vmstat_info *info,
    enum vmstat_item *items,
    int numitems);

__END_DECLS
#endif
