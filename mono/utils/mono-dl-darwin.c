/*
 * mono-dl.c: Interface to the dynamic linker
 *
 * Author:
 *    Mono Team (http://www.mono-project.com)
 *
 * Copyright 2001-2004 Ximian, Inc.
 * Copyright 2004-2009 Novell, Inc.
 */
#include <config.h>

#if defined (TARGET_MACH)

#include "mono/utils/mono-dl.h"
#include "mono/utils/mono-embed.h"
#include "mono/utils/mono-path.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <glib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <mach-o/dyld.h>

const char *
mono_dl_get_so_prefix (void)
{
	return "lib";
}
const char **
mono_dl_get_so_suffixes (void)
{
	static const char *suffixes[] = {
		".dylib",
		".so",
		".bundle",
		"",
	};
	return suffixes;
}

int
mono_dl_get_executable_path (char *buf, int buflen)
{
	uint32_t bsize = buflen;
	if (_NSGetExecutablePath (buf, &bsize) == 0)
		return strlen (buf);
	return -1;
}

#endif
