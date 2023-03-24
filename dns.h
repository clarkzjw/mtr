/*
    mtr  --  a network diagnostic tool
    Copyright (C) 1997,1998  Matt Kimball

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef DNS_H
#define DNS_H

#include <stdbool.h>
#include <netinet/in.h>
#include <resolv.h>

extern bool enable_dns;
extern struct __res_state myres;
#ifdef __OpenBSD__
#define myres _res
#endif

bool dns_init(void);
void dns_open(void);
void dns_close(void);
int dns_waitfd(int family);
void dns_ack(int fd, int family);
const char *dns_lookup(int at, int ndx);
int dns_query(int op, const char *dname, int class, int type, const unsigned char *data, int datalen,
  const unsigned char *newrr, unsigned char *buf, int buflen);

#endif
