#ifndef __LD3320_H__
#define __LD3320_H__

#include "MP3_TF_16P.h"
#include <string.h>
#include <stdio.h>

#define MP3_PLAY_MUSIC               ("PLAYMUSIC")
#define MP3_PLAYON_MUSIC             ("PLAYON")
#define MP3_RANDOM_PLAY_MUSIC        ("RANDOMPLAY")
#define MP3_STOP_MUSIC               ("STOPMUSIC")
#define MP3_SUSPEND_MUSIC            ("SUSPENDMUSIC")
#define MP3_NEXT_SONG                ("NEXTSONG")
#define MP3_LAST_SONG                ("LASTSONG")
#define MP3_ADD_VOLUME               ("ADDVOLUME")
#define MP3_REDUCE_VOLUME            ("REDUCEVOLUME")

void MP3_Play();

#endif 