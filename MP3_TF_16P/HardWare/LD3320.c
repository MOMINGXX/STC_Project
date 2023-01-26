#include "LD3320.h"

void MP3_Play()
{
    if(1 == Flag1)
    {
        if(NULL != strstr(RX1_DAT,MP3_PLAY_MUSIC))
        {
            Uart_SendCMD(Specify_Music,0x00,36);
        }
        else if(NULL != strstr(RX1_DAT,MP3_STOP_MUSIC))
        {
            Uart_SendCMD(Stop_Song,0x00,0);
        }
        else if(NULL != strstr(RX1_DAT,MP3_PLAYON_MUSIC))
        {
            Uart_SendCMD(Play,0x00,0);
        }
        else if(NULL != strstr(RX1_DAT,MP3_SUSPEND_MUSIC))
        {
            Uart_SendCMD(Suspended,0x00,0);
        }
        else if(NULL != strstr(RX1_DAT,MP3_NEXT_SONG))
        {
            Uart_SendCMD(Next_Song,0x00,36);
        }
        else if(NULL != strstr(RX1_DAT,MP3_LAST_SONG))
        {
            Uart_SendCMD(Last_Song,0x00,36);
        }
        else if(NULL != strstr(RX1_DAT,MP3_ADD_VOLUME))
        {
            Uart_SendCMD(Add_Volume,0x00,1);
        }
        else if(NULL != strstr(RX1_DAT,MP3_REDUCE_VOLUME))
        {
            Uart_SendCMD(Reduce_Volume,0x00,1);
        }
        else if(NULL != strstr(RX1_DAT,MP3_RANDOM_PLAY_MUSIC))
        {
            Uart_SendCMD(Random_Broadcast,0x00,0);
        }
        Flag1 = 0;
    }
}