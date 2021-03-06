
/*
 * !!! DO NOT EDIT DIRECTLY !!!
 * This file was automatically generated from the following template:
 *
 * src/subsys/ngx_subsys_lua_semaphore.h.tt2
 */


/*
 * Copyright (C) Yichun Zhang (agentzh)
 * Copyright (C) cuiweixie
 * I hereby assign copyright in this code to the lua-nginx-module project,
 * to be licensed under the same terms as the rest of the code.
 */


#ifndef _NGX_STREAM_LUA_SEMAPHORE_H_INCLUDED_
#define _NGX_STREAM_LUA_SEMAPHORE_H_INCLUDED_


#include "ngx_stream_lua_common.h"


typedef struct ngx_stream_lua_sema_mm_block_s {
    ngx_uint_t                               used;
    ngx_stream_lua_sema_mm_t                *mm;
    ngx_uint_t                               epoch;
} ngx_stream_lua_sema_mm_block_t;


struct ngx_stream_lua_sema_mm_s {
    ngx_queue_t                          free_queue;
    ngx_uint_t                           total;
    ngx_uint_t                           used;
    ngx_uint_t                           num_per_block;
    ngx_uint_t                           cur_epoch;
    ngx_stream_lua_main_conf_t          *lmcf;
};


typedef struct ngx_stream_lua_sema_s {
    ngx_queue_t                                  wait_queue;
    ngx_queue_t                                  chain;
    ngx_event_t                                  sem_event;
    ngx_stream_lua_sema_mm_block_t              *block;
    int                                          resource_count;
    unsigned                                     wait_count;
} ngx_stream_lua_sema_t;


void ngx_stream_lua_sema_mm_cleanup(void *data);
ngx_int_t ngx_stream_lua_sema_mm_init(ngx_conf_t *cf,
    ngx_stream_lua_main_conf_t *lmcf);


#endif /* _NGX_STREAM_LUA_SEMAPHORE_H_INCLUDED_ */

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */
