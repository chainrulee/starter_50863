#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <time.h>
#include <signal.h>

#define SERVICE_PORT 21233
#define REGISTER_REQUEST 246 
#define REGISTER_RESPONSE 61
#define KILL_SWITCH       62
#define TPG_UPDATE        63
#define ROUTER_UPDATE     64
#define KEEP_ALIVE        65
#define BUFSIZE           2048
#define K_SEC                5

typedef struct edge {
	int node1;
	int node2;
	int bandwidth;
	int delay;
	int active;
	
} Edge;

typedef struct topology {
	Edge *edge;
	int edge_num;
	int switch_num;
	int *switches_ptr;
} Tpg;

typedef struct pair_pid_nid {
	pid_t pid;
	int nid;
	int active;
	int pipe_fd_p[2];
} PNid;

typedef struct neighbor_info {
    int nid;
    int active;
    unsigned int port;
	char* hostname;
	timer_t* monitor_timerid;
	timer_t* send_alive_timerid;
	int link_fail;
} Nbor;

typedef struct link_cmd {
	int nid;
	int link_fail;
} LinkCmd;

#endif
