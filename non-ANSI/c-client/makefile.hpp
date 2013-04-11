# Program:	Portable C client makefile -- HP/UX version
#
# Author:	David L. Miller
#		Computing and Telecommunications Center
#		Washington State University Tri-Cities
#		Richland, WA 99352
#		Internet: dmiller@beta.tricity.wsu.edu
#
# Date:		11 May 1989
# Last Edited:	19 May 1992
#
# Copyright 1992 by the University of Washington
#
#  Permission to use, copy, modify, and distribute this software and its
# documentation for any purpose and without fee is hereby granted, provided
# that the above copyright notice appears in all copies and that both the
# above copyright notice and this permission notice appear in supporting
# documentation, and that the name of the University of Washington not be
# used in advertising or publicity pertaining to distribution of the software
# without specific, written prior permission.  This software is made
# available "as is", and
# THE UNIVERSITY OF WASHINGTON DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED,
# WITH REGARD TO THIS SOFTWARE, INCLUDING WITHOUT LIMITATION ALL IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, AND IN
# NO EVENT SHALL THE UNIVERSITY OF WASHINGTON BE LIABLE FOR ANY SPECIAL,
# INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, TORT
# (INCLUDING NEGLIGENCE) OR STRICT LIABILITY, ARISING OUT OF OR IN CONNECTION
# WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

CC=cc
CFLAGS = -g 
LDFLAGS = -lnet 

mtest: mtest.o c-client.a
	echo $(CFLAGS) > CFLAGS
	echo $(LDFLAGS) > LDFLAGS
	$(CC) $(CFLAGS) -o mtest mtest.o c-client.a $(LDFLAGS)

clean:
	rm -f *.o mtest c-client.a osdep.* CFLAGS LDFLAGS

mtest.o: mail.h smtp.h nntp.h misc.h osdep.h

c-client.a: $& mail.o bezerk.o tenex.o mbox.o mh.o imap2.o news.o dummy.o \
	smtp.o nntp.o rfc822.o misc.o osdep.o
	rm -f c-client.a
	ar rc c-client.a mail.o bezerk.o tenex.o mbox.o mh.o imap2.o news.o \
	dummy.o smtp.o nntp.o rfc822.o misc.o osdep.o

mail.o: mail.h misc.h osdep.h

bezerk.o: mail.h bezerk.h rfc822.h misc.h osdep.h

tenex.o: mail.h tenex.h rfc822.h misc.h osdep.h

mbox.o: mail.h mbox.h bezerk.h misc.h osdep.h

mh.o: mail.h mh.h rfc822.h misc.h osdep.h

imap2.o: mail.h imap2.h misc.h osdep.h

news.o: mail.h news.h misc.h osdep.h

dummy.o: mail.h dummy.h misc.h osdep.h

smtp.o: mail.h smtp.h rfc822.h misc.h osdep.h

nntp.o: mail.h nntp.h smtp.h rfc822.h misc.h osdep.h

rfc822.o: mail.h rfc822.h misc.h

misc.o: mail.h misc.h osdep.h

osdep.o: mail.h osdep.h os_hpp.c
	$(CC) $(CFLAGS) -c os_hpp.c
	mv os_hpp.o osdep.o

osdep.h: os_hpp.h
	rm -f osdep.h
	ln os_hpp.h osdep.h


# A monument to a hack of long ago and far away...
love:
	@echo 'not war?'

