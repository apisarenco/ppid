#include <libproc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <unordered_map>

using namespace std;

struct pidinfo {
    pid_t ppid;
    char* name;
};

void find_parents()
{
    unordered_map<int, pidinfo> info_map;
    pid_t pids[4096];

    int bytes = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    int n_proc = bytes / sizeof(pids[0]);

    for (int i = 0; i < n_proc; i++) {
        struct proc_bsdinfo proc;
        int st = proc_pidinfo(pids[i], PROC_PIDTBSDINFO, 0, &proc, PROC_PIDTBSDINFO_SIZE);
        info_map[pids[i]].ppid = proc.pbi_ppid;
        info_map[pids[i]].name = strdup(proc.pbi_comm);
    }
    pid_t pid = getpid();
    while (pid != 1) {
        printf("%d %s\n", pid, info_map[pid].name);
        if (info_map[pid].ppid == pid) {
            break;
        }
        pid = info_map[pid].ppid;
    }
}

int main(int args, char *argv[])
{
    find_parents();
    return 0;
}
