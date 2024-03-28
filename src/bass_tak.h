#ifndef BASSTAK_H
#define BASSTAK_H

// based on
// https://github.com/gageas/bass_tak2.4 -- original
// https://github.com/w17/bass_tak2.4    -- my fork
// project

#include "bass.h"

#define BASS_TAK_Version 0x02040001

#if BASSVERSION != 0x204
#error conflicting BASS and BASSTAK versions
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BASSTAKDEF
#define BASSTAKDEF(f) WINAPI f
#endif

// BASS_CHANNELINFO type
#define BASS_CTYPE_STREAM_TAK	('T' | ('A' << 8) | ('K' << 16))
// the above constants should be unique (ask if unsure)

HSTREAM BASSTAKDEF(BASS_TAK_StreamCreateFile)(BOOL mem, const void *file, QWORD offset, QWORD length, DWORD flags);
HSTREAM BASSTAKDEF(BASS_TAK_StreamCreateURL)(const char *url, DWORD offset, DWORD flags, DOWNLOADPROC *proc, void *user);
HSTREAM BASSTAKDEF(BASS_TAK_StreamCreateFileUser)(DWORD system, DWORD flags, const BASS_FILEPROCS *procs, void *user);

#ifdef __cplusplus
}

#ifdef _WIN32
static inline HSTREAM BASS_TAK_StreamCreateFile(BOOL mem, const WCHAR *file, QWORD offset, QWORD length, DWORD flags)
{
	return BASS_TAK_StreamCreateFile(mem, (const void*)file, offset, length, flags | BASS_UNICODE);
}

static inline HSTREAM BASS_TAK_StreamCreateURL(const WCHAR *url, DWORD offset, DWORD flags, DOWNLOADPROC *proc, void *user)
{
	return BASS_TAK_StreamCreateURL((const char*)url, offset, flags | BASS_UNICODE, proc, user);
}
#endif
#endif

#endif
