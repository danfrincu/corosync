/*
 * Copyright (c) 2008 Red Hat, Inc.
 *
 * All rights reserved.
 *
 * Author: Christine Caulfield (ccaulfie@redhat.com)
 *
 * This software licensed under BSD license, the text of which follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the MontaVista Software, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef IPC_QUORUM_H_DEFINED
#define IPC_QUORUM_H_DEFINED

#include <corosync/corotypes.h>
#include <corosync/mar_gen.h>

enum req_quorum_types {
	MESSAGE_REQ_QUORUM_GETQUORATE = 0,
	MESSAGE_REQ_QUORUM_TRACKSTART,
	MESSAGE_REQ_QUORUM_TRACKSTOP
};

enum res_quorum_types {
	MESSAGE_RES_QUORUM_GETQUORATE = 0,
	MESSAGE_RES_QUORUM_TRACKSTART,
	MESSAGE_RES_QUORUM_TRACKSTOP,
	MESSAGE_RES_QUORUM_NOTIFICATION
};

struct req_lib_quorum_trackstart {
        struct qb_ipc_request_header header __attribute__((aligned(8)));
	unsigned int track_flags;
};


struct res_lib_quorum_getquorate {
        struct qb_ipc_response_header header __attribute__((aligned(8)));
	mar_uint32_t quorate;
};

struct res_lib_quorum_notification {
	struct qb_ipc_response_header header __attribute__((aligned(8)));
	mar_int32_t quorate __attribute__((aligned(8)));
	mar_uint64_t ring_seq __attribute__((aligned(8)));
	mar_uint32_t view_list_entries __attribute__((aligned(8)));
	mar_uint32_t view_list[];
};

#endif
