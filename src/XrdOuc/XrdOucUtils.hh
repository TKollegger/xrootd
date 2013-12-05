#ifndef __XRDOUCUTILS_HH__
#define __XRDOUCUTILS_HH__
/******************************************************************************/
/*                                                                            */
/*                        X r d O u c U t i l s . h h                         */
/*                                                                            */
/* (c) 2005 by the Board of Trustees of the Leland Stanford, Jr., University  */
/*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/*                                                                            */
/* This file is part of the XRootD software suite.                            */
/*                                                                            */
/* XRootD is free software: you can redistribute it and/or modify it under    */
/* the terms of the GNU Lesser General Public License as published by the     */
/* Free Software Foundation, either version 3 of the License, or (at your     */
/* option) any later version.                                                 */
/*                                                                            */
/* XRootD is distributed in the hope that it will be useful, but WITHOUT      */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public       */
/* License for more details.                                                  */
/*                                                                            */
/* You should have received a copy of the GNU Lesser General Public License   */
/* along with XRootD in a file called COPYING.LESSER (LGPL license) and file  */
/* COPYING (GPL license).  If not, see <http://www.gnu.org/licenses/>.        */
/*                                                                            */
/* The copyright holder's institutional names and contributor's names may not */
/* be used to endorse or promote products derived from this software without  */
/* specific prior written permission of the institution or contributor.       */
/******************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
  
class XrdSysError;
class XrdOucStream;

class XrdOucUtils
{
public:

static const mode_t pathMode = S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH;

static bool  endsWith(const char *text, const char *ending, int endlen);

static char *eText(int rc, char *eBuff, int eBlen, int AsIs=0);

static int   doIf(XrdSysError *eDest, XrdOucStream &Config,
                  const char *what, const char *hname, 
                                    const char *nname, const char *pname);
 
static int   fmtBytes(long long val, char *buff, int bsz);

static char *genPath(const char *path, const char *inst, const char *psfx=0);

static int   genPath(char *buff, int blen, const char *path, const char *psfx=0);

static int   GroupName(gid_t gID, char *gName, int gNsz);

static char *Ident(long long  &mySID, char *iBuff, int iBlen,
                   const char *iHost, const char *iProg, const char *iName,
                   int Port);

static const char *InstName(int TranOpt=0);

static const char *InstName(const char *name, int Fillit=1);

static int   is1of(char *val, const char **clist);

static void  makeHome(XrdSysError &eDest, const char *inst);

static int   makePath(char *path, mode_t mode);

static int   ReLink(const char *path, const char *target, mode_t mode=0);
 
static char *subLogfn(XrdSysError &eDest, const char *inst, char *logfn);

static void  Undercover(XrdSysError &eDest, int noLog, int *pipeFD = 0);

static int   UserName(uid_t uID, char *uName, int uNsz);

static bool PidFile(XrdSysError &eDest, const char *path);

       XrdOucUtils() {}
      ~XrdOucUtils() {}
};
#endif
