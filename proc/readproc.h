#ifndef PROCPS_PROC_READPROC_H
#define PROCPS_PROC_READPROC_H

// New Interface to Process Table -- PROCTAB Stream (a la Directory streams)
// Copyright 1996 Charles L. Blake.
// Copyright 1998 Michael K. Johnson
// Copyright 1998-2003 Albert Cahalan
// May be distributed under the terms of the
// GNU Library General Public License, a copy of which is provided
// in the file COPYING


#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <proc/misc.h>

// the following is development only, forcing display of "[ duplicate ENUM ]" strings
// #define FALSE_THREADS        /* set most child string fields to NULL */


// This is to help document a transition from pid to tgid/tid caused
// by the introduction of thread support. It is used in cases where
// neither tgid nor tid seemed correct. (in other words, FIXME)
#define XXXID tid

// Basic data structure which holds all information we can get about a process.
// (unless otherwise specified, fields are read from /proc/#/stat)
//
// Most of it comes from task_struct in linux/sched.h
//
typedef struct proc_t {
    int
        tid,            // (special)       task id, the POSIX thread ID (see also: tgid)
        ppid;           // stat,status     pid of parent process
    char
        state,          // stat,status     single-char code for process state (S=sleeping)
#ifdef FALSE_THREADS
        pad_1,          // n/a             padding (psst, also used if multi-threaded)
#else
        pad_1,          // n/a             padding
#endif
        pad_2,          // n/a             padding
        pad_3;          // n/a             padding
    unsigned long long
        utime,          // stat            user-mode CPU time accumulated by process
        stime,          // stat            kernel-mode CPU time accumulated by process
        cutime,         // stat            cumulative utime of process and reaped children
        cstime,         // stat            cumulative stime of process and reaped children
        start_time,     // stat            start time of process -- seconds since system boot
        blkio_tics,     // stat            time spent waiting for block IO
        gtime,          // stat            guest time of the task in jiffies
        cgtime;         // stat            guest time of the task children in jiffies
    int                 // next 3 fields are NOT filled in by readproc
        pcpu,           // stat (special)  elapsed tics for %CPU usage calculation
        maj_delta,      // stat (special)  major page faults since last update
        min_delta;      // stat (special)  minor page faults since last update
    char
        // Linux 2.1.7x and up have 64 signals. Allow 64, plus '\0' and padding.
        signal[18],     // status          mask of pending signals
        blocked[18],    // status          mask of blocked signals
        sigignore[18],  // status          mask of ignored signals
        sigcatch[18],   // status          mask of caught  signals
        _sigpnd[18];    // status          mask of PER TASK pending signals
    unsigned long
        start_code,     // stat            address of beginning of code segment
        end_code,       // stat            address of end of code segment
        start_stack,    // stat            address of the bottom of stack for the process
        kstk_esp,       // stat            kernel stack pointer
        kstk_eip,       // stat            kernel instruction pointer
        wchan,          // stat (special)  address of kernel wait channel proc is sleeping in
        rss,            // stat            identical to 'resident'
        alarm;          // stat            ?
    int
        priority,       // stat            kernel scheduling priority
        nice;           // stat            standard unix nice level of process
    unsigned long
    // the next 7 members come from /proc/#/statm
        size,           // statm           total virtual memory (as # pages)
        resident,       // statm           resident non-swapped memory (as # pages)
        share,          // statm           shared (mmap'd) memory (as # pages)
        trs,            // statm           text (exe) resident set (as # pages)
        lrs,            // statm           library resident set (always 0 w/ 2.6)
        drs,            // statm           data+stack resident set (as # pages)
        dt;             // statm           dirty pages (always 0 w/ 2.6)
    unsigned long
        vm_size,        // status          equals 'size' (as kb)
        vm_lock,        // status          locked pages (as kb)
        vm_rss,         // status          equals 'rss' and/or 'resident' (as kb)
        vm_rss_anon,    // status          the 'anonymous' portion of vm_rss (as kb)
        vm_rss_file,    // status          the 'file-backed' portion of vm_rss (as kb)
        vm_rss_shared,  // status          the 'shared' portion of vm_rss (as kb)
        vm_data,        // status          data only size (as kb)
        vm_stack,       // status          stack only size (as kb)
        vm_swap,        // status          based on linux-2.6.34 "swap ents" (as kb)
        vm_exe,         // status          equals 'trs' (as kb)
        vm_lib,         // status          total, not just used, library pages (as kb)
        vsize,          // stat            number of pages of virtual memory ...
        rss_rlim,       // stat            resident set size limit?
        flags,          // stat            kernel flags for the process
        min_flt,        // stat            number of minor page faults since process start
        maj_flt,        // stat            number of major page faults since process start
        cmin_flt,       // stat            cumulative min_flt of process and child processes
        cmaj_flt;       // stat            cumulative maj_flt of process and child processes
    char
        *environ,       // (special)       environment as string (/proc/#/environ)
        *cmdline,       // (special)       command line as string (/proc/#/cmdline)
        *cgroup,        // (special)       cgroup as string (/proc/#/cgroup)
        *cgname,        // (special)       name portion of above (if possible)
        *supgid,        // status          supplementary gids as comma delimited str
        *supgrp,        // supp grp names as comma delimited str, derived from supgid
       **environ_v,     // (special)       environment string vectors (/proc/#/environ)
       **cmdline_v,     // (special)       command line string vectors (/proc/#/cmdline)
       **cgroup_v;      // (special)       cgroup string vectors (/proc/#/cgroup)
    char
        *euser,         // stat(),status   effective user name
        *ruser,         // status          real user name
        *suser,         // status          saved user name
        *fuser,         // status          filesystem user name
        *rgroup,        // status          real group name
        *egroup,        // status          effective group name
        *sgroup,        // status          saved group name
        *fgroup,        // status          filesystem group name
        *cmd;           // stat,status     basename of executable file in call to exec(2)
    int
        rtprio,         // stat            real-time priority
        sched,          // stat            scheduling class
        pgrp,           // stat            process group id
        session,        // stat            session id
        nlwp,           // stat,status     number of threads, or 0 if no clue
        tgid,           // (special)       thread group ID, the POSIX PID (see also: tid)
        tty,            // stat            full device number of controlling terminal
        /* FIXME: int uids & gids should be uid_t or gid_t from pwd.h */
        euid, egid,     // stat(),status   effective
        ruid, rgid,     // status          real
        suid, sgid,     // status          saved
        fuid, fgid,     // status          fs (used for file access only)
        tpgid,          // stat            terminal process group id
        exit_signal,    // stat            might not be SIGCHLD
        processor;      // stat            current (or most recent?) CPU
    int
        oom_score,      // oom_score       (badness for OOM killer)
        oom_adj;        // oom_adj         (adjustment to OOM score)
    struct procps_ns ns; // (ns subdir)     inode number of namespaces
    char
        *sd_mach,       // n/a             systemd vm/container name
        *sd_ouid,       // n/a             systemd session owner uid
        *sd_seat,       // n/a             systemd login session seat
        *sd_sess,       // n/a             systemd login session id
        *sd_slice,      // n/a             systemd slice unit
        *sd_unit,       // n/a             systemd system unit id
        *sd_uunit;      // n/a             systemd user unit id
    char
        *lxcname,       // n/a             lxc container name
        *exe;           // exe             executable path + name
    int
        luid;           // loginuid        user id at login
} proc_t;

// PROCTAB: data structure holding the persistent information readproc needs
// from openproc().  The setup is intentionally similar to the dirent interface
// and other system table interfaces (utmp+wtmp come to mind).

#define PROCPATHLEN 64  // must hold /proc/2000222000/task/2000222000/cmdline

typedef struct PROCTAB {
    DIR*        procfs;
//    char deBug0[64];
    DIR*        taskdir;  // for threads
//    char deBug1[64];
    pid_t       taskdir_user;  // for threads
    int(*finder)(struct PROCTAB *__restrict const, proc_t *__restrict const);
    proc_t*(*reader)(struct PROCTAB *__restrict const, proc_t *__restrict const);
    int(*taskfinder)(struct PROCTAB *__restrict const, const proc_t *__restrict const, proc_t *__restrict const, char *__restrict const);
    proc_t*(*taskreader)(struct PROCTAB *__restrict const, proc_t *__restrict const, char *__restrict const);
    pid_t*      pids;   // pids of the procs
    uid_t*      uids;   // uids of procs
    int         nuid;   // cannot really sentinel-terminate unsigned short[]
    int         i;  // generic
    unsigned    flags;
    unsigned    u;  // generic
    void *      vp; // generic
    char        path[PROCPATHLEN];  // must hold /proc/2000222000/task/2000222000/cmdline
    unsigned pathlen;        // length of string in the above (w/o '\0')
} PROCTAB;


// openproc/readproctab:
//
// Return PROCTAB* / *proc_t[] or NULL on error ((probably) "/proc" cannot be
// opened.)  By default readproc will consider all processes as valid to parse
// and return, but not actually fill in the cmdline, environ, and /proc/#/statm
// derived memory fields.
//
// `flags' (a bitwise-or of PROC_* below) modifies the default behavior.  The
// "fill" options will cause more of the proc_t to be filled in.  The "filter"
// options all use the second argument as the pointer to a list of objects:
// process status', process id's, user id's.  The third
// argument is the length of the list (currently only used for lists of user
// id's since uid_t supports no convenient termination sentinel.)

#define PROC_FILLMEM         0x0001 // read statm
#define PROC_FILLARG         0x0002 // alloc and fill in `cmdline' vectors
#define PROC_FILLENV         0x0004 // alloc and fill in `environ' vectors
#define PROC_FILLUSR         0x0008 // resolve user id number -> user name
#define PROC_FILLGRP         0x0010 // resolve group id number -> group name
#define PROC_FILLSTATUS      0x0020 // read status
#define PROC_FILLSTAT        0x0040 // read stat
#define PROC_FILLCGROUP      0x0200 // alloc and fill in `cgroup` vectors
#define PROC_FILLSUPGRP      0x0400 // resolve supplementary group id -> group name
#define PROC_FILLOOM         0x0800 // fill in proc_t oom_score and oom_adj
#define PROC_FILLNS          0x8000 // fill in proc_t namespace information
#define PROC_FILLSYSTEMD    0x80000 // fill in proc_t systemd information
#define PROC_FILL_LXC      0x800000 // fill in proc_t lxcname, if possible
#define PROC_FILL_LUID     0x400000 // fill in proc_t luid (login user id)
#define PROC_FILL_EXE      0x200000 // fill in proc_t exe path + pgm name

// consider only processes with one of the passed:
#define PROC_PID             0x1000  // process id numbers ( 0   terminated)
#define PROC_UID             0x4000  // user id numbers    ( length needed )
// Note: the above 2 values must NOT change without also changing pids.h !!!

#define PROC_EDITCGRPCVT    0x10000 // edit `cgroup' as regular string
#define PROC_EDITCMDLCVT    0x20000 // edit `cmdline' as regular string
#define PROC_EDITENVRCVT    0x40000 // edit `environ' as regular string

// it helps to give app code a few spare bits
#define PROC_SPARE_1     0x01000000
#define PROC_SPARE_2     0x02000000
#define PROC_SPARE_3     0x04000000
#define PROC_SPARE_4     0x08000000

// Function definitions
// Initialize a PROCTAB structure holding needed call-to-call persistent data
PROCTAB* openproc(unsigned flags, ... /* pid_t*|uid_t*|dev_t*|char* [, int n] */ );
// Retrieve the next process or task matching the criteria set by the openproc().
//
// Note: When NULL is used as the readproc 'p' or readeither 'x'
//       parameter, the library will allocate the necessary proc_t storage.
//
//       Alternatively, you may provide your own reuseable buffer address
//       in which case that buffer *MUST* be initialized to zero one time
//       only before first use.  Thereafter, the library will manage such
//       a passed proc_t, freeing any additional acquired memory associated
//       with the previous process or thread.
proc_t* readproc(PROCTAB *__restrict const PT, proc_t *__restrict p);
proc_t* readeither(PROCTAB *__restrict const PT, proc_t *__restrict x);
int look_up_our_self(proc_t *p);
void closeproc(PROCTAB* PT);
char** vectorize_this_str(const char* src);

#endif
