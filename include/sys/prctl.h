/* Copyright (C) 1997-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
#ifndef _SYS_PRCTL_H_
#define _SYS_PRCTL_H_

#include <sys/cdefs.h>

__BEGIN_DECLS

#define PR_SET_DUMPABLE 0
struct tcp_info {
   u_int8_t tcpi_state;    /* TCP FSM state. */
   u_int8_t __tcpi_ca_state;
   u_int8_t __tcpi_retransmits;
   u_int8_t __tcpi_probes;
   u_int8_t __tcpi_backoff;
   u_int8_t tcpi_options;     /* Options enabled on conn. */
   u_int8_t tcpi_snd_wscale:4,   /* RFC1323 send shift value. */
         tcpi_rcv_wscale:4;   /* RFC1323 recv shift value. */

   u_int32_t   tcpi_rto;      /* Retransmission timeout (usec). */
   u_int32_t   __tcpi_ato;
   u_int32_t   tcpi_snd_mss;     /* Max segment size for send. */
   u_int32_t   tcpi_rcv_mss;     /* Max segment size for receive. */

   u_int32_t   __tcpi_unacked;
   u_int32_t   __tcpi_sacked;
   u_int32_t   __tcpi_lost;
   u_int32_t   __tcpi_retrans;
   u_int32_t   __tcpi_fackets;

   /* Times; measurements in usecs. */
   u_int32_t   __tcpi_last_data_sent;
   u_int32_t   __tcpi_last_ack_sent;   /* Also unimpl. on Linux? */
   u_int32_t   tcpi_last_data_recv; /* Time since last recv data. */
   u_int32_t   __tcpi_last_ack_recv;

   /* Metrics; variable units. */
   u_int32_t   __tcpi_pmtu;
   u_int32_t   __tcpi_rcv_ssthresh;
   u_int32_t   tcpi_rtt;      /* Smoothed RTT in usecs. */
   u_int32_t   tcpi_rttvar;      /* RTT variance in usecs. */
   u_int32_t   tcpi_snd_ssthresh;   /* Slow start threshold. */
   u_int32_t   tcpi_snd_cwnd;    /* Send congestion window. */
   u_int32_t   __tcpi_advmss;
   u_int32_t   __tcpi_reordering;

   u_int32_t   __tcpi_rcv_rtt;
   u_int32_t   tcpi_rcv_space;      /* Advertised recv window. */

   /* FreeBSD extensions to tcp_info. */
   u_int32_t   tcpi_snd_wnd;     /* Advertised send window. */
   u_int32_t   tcpi_snd_bwnd;    /* No longer used. */
   u_int32_t   tcpi_snd_nxt;     /* Next egress seqno */
   u_int32_t   tcpi_rcv_nxt;     /* Next ingress seqno */
   u_int32_t   tcpi_toe_tid;     /* HWTID for TOE endpoints */
   u_int32_t   tcpi_snd_rexmitpack; /* Retransmitted packets */
   u_int32_t   tcpi_rcv_ooopack; /* Out-of-order packets */
   u_int32_t   tcpi_snd_zerowin; /* Zero-sized windows sent */
   
   /* Padding to grow without breaking ABI. */
   u_int32_t   __tcpi_pad[26];      /* Padding. */
};

/* Control process execution.  */
extern int prctl (int __option, ...) __THROW;

__END_DECLS

#endif  /* sys/prctl.h */